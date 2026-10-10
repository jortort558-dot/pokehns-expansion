#include "global.h"
#include "hns_live_telemetry.h"
#include "load_save.h"
#include "pokemon.h"
#include "constants/battle.h"
#include "constants/characters.h"

#define HNS_LIVE_VERSION 1
#define HNS_LIVE_INTERVAL_FRAMES 60
#define HNS_LIVE_NAME_LENGTH 11

enum HnsLiveStatus
{
    HNS_LIVE_STATUS_NONE,
    HNS_LIVE_STATUS_SLEEP,
    HNS_LIVE_STATUS_POISON,
    HNS_LIVE_STATUS_BURN,
    HNS_LIVE_STATUS_FREEZE,
    HNS_LIVE_STATUS_PARALYSIS,
    HNS_LIVE_STATUS_TOXIC,
    HNS_LIVE_STATUS_FAINTED,
};

struct PACKED HnsLivePartyMon
{
    u16 species;
    u8 level;
    u8 status;
    u16 hp;
    u16 maxHp;
    u8 nickname[HNS_LIVE_NAME_LENGTH];
    u8 reserved;
};

struct PACKED HnsLiveTelemetry
{
    u8 signature[4];
    u16 version;
    u16 length;
    u32 sequenceStart;
    u16 trainerId;
    u16 secretId;
    u8 trainerName[PLAYER_NAME_LENGTH + 1];
    u8 mapGroup;
    u8 mapNum;
    s16 x;
    s16 y;
    u8 partyCount;
    u8 reserved;
    struct HnsLivePartyMon party[PARTY_SIZE];
    u32 checksum;
    u32 sequenceEnd;
};

// La seccion se enlaza al principio de EWRAM. El fork de mGBA usado por
// EmulatorJS expone esa zona mediante RETRO_MEMORY_SYSTEM_RAM.
__attribute__((section(".ewram.hns")))
static volatile struct HnsLiveTelemetry sHnsLiveTelemetry =
{
    .signature = {'H', 'N', 'S', '1'},
    .version = HNS_LIVE_VERSION,
    .length = sizeof(struct HnsLiveTelemetry),
};

static u8 GetLiveStatus(u32 status, u16 hp)
{
    if (hp == 0)
        return HNS_LIVE_STATUS_FAINTED;
    if (status & STATUS1_SLEEP)
        return HNS_LIVE_STATUS_SLEEP;
    if (status & STATUS1_TOXIC_POISON)
        return HNS_LIVE_STATUS_TOXIC;
    if (status & STATUS1_POISON)
        return HNS_LIVE_STATUS_POISON;
    if (status & STATUS1_BURN)
        return HNS_LIVE_STATUS_BURN;
    if (status & STATUS1_FREEZE)
        return HNS_LIVE_STATUS_FREEZE;
    if (status & STATUS1_PARALYSIS)
        return HNS_LIVE_STATUS_PARALYSIS;
    return HNS_LIVE_STATUS_NONE;
}

static u32 CalculatePayloadChecksum(void)
{
    const volatile u8 *data = (const volatile u8 *)&sHnsLiveTelemetry.trainerId;
    const u32 length = (const volatile u8 *)&sHnsLiveTelemetry.checksum - data;
    u32 hash = 2166136261u;
    u32 i;

    for (i = 0; i < length; i++)
    {
        hash ^= data[i];
        hash *= 16777619u;
    }
    return hash;
}

void HnsLiveTelemetry_Update(void)
{
    static u8 sFrameCounter;
    u32 sequence;
    u32 trainerId;
    u8 i;

    if (++sFrameCounter < HNS_LIVE_INTERVAL_FRAMES)
        return;
    sFrameCounter = 0;

    // Durante el arranque aun no hay una identidad de partida valida. No se
    // publica 0:0 para evitar que el servidor lo interprete como partida nueva.
    if (gSaveBlock2Ptr->playerName[0] == 0 || gSaveBlock2Ptr->playerName[0] == EOS)
        return;

    sequence = (sHnsLiveTelemetry.sequenceEnd + 2) & ~1u;
    if (sequence == 0)
        sequence = 2;
    sHnsLiveTelemetry.sequenceStart = sequence - 1;

    trainerId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);
    sHnsLiveTelemetry.trainerId = trainerId;
    sHnsLiveTelemetry.secretId = trainerId >> 16;
    memcpy((void *)sHnsLiveTelemetry.trainerName, gSaveBlock2Ptr->playerName, sizeof(sHnsLiveTelemetry.trainerName));

    if (gSaveBlock1Ptr != NULL)
    {
        sHnsLiveTelemetry.mapGroup = gSaveBlock1Ptr->location.mapGroup;
        sHnsLiveTelemetry.mapNum = gSaveBlock1Ptr->location.mapNum;
        sHnsLiveTelemetry.x = gSaveBlock1Ptr->pos.x;
        sHnsLiveTelemetry.y = gSaveBlock1Ptr->pos.y;
    }

    sHnsLiveTelemetry.partyCount = min(gPlayerPartyCount, PARTY_SIZE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        volatile struct HnsLivePartyMon *dst = &sHnsLiveTelemetry.party[i];
        if (i < sHnsLiveTelemetry.partyCount)
        {
            struct Pokemon *mon = &gPlayerParty[i];
            u16 hp = GetMonData(mon, MON_DATA_HP);
            dst->species = GetMonData(mon, MON_DATA_SPECIES);
            dst->level = GetMonData(mon, MON_DATA_LEVEL);
            dst->status = GetLiveStatus(GetMonData(mon, MON_DATA_STATUS), hp);
            dst->hp = hp;
            dst->maxHp = GetMonData(mon, MON_DATA_MAX_HP);
            GetMonData(mon, MON_DATA_NICKNAME, (u8 *)dst->nickname);
            dst->reserved = 0;
        }
        else
        {
            memset((void *)dst, 0, sizeof(*dst));
        }
    }

    sHnsLiveTelemetry.checksum = CalculatePayloadChecksum();
    sHnsLiveTelemetry.sequenceEnd = sequence;
    sHnsLiveTelemetry.sequenceStart = sequence;
}
