#include "global.h"
#include "main.h"
#include "menu.h"
#include "bg.h"
#include "window.h"
#include "text.h"
#include "string_util.h"
#include "international_string_util.h"
#include "script_menu.h"
#include "field_message_box.h"
#include "graphics.h"
#include "script.h"
#include "field_name_box.h"
#include "event_data.h"
#include "match_call.h"
#include "malloc.h"
#include "constants/speaker_names.h"
#include "data/speaker_names.h"

#include "sprite.h"
#include "decompress.h"

#define TAG_MUGSHOT_METACABALLERO 0xF431
#define TAG_MUGSHOT_BATEMAGICO    0xF432
#define TAG_MUGSHOT_MANOLIN       0xF433
#define TAG_MUGSHOT_EL_PIEDRAS    0xF434
#define TAG_MUGSHOT_YAMI          0xF435
#define TAG_MUGSHOT_RIVAL         0xF436

static EWRAM_INIT u8 sNameboxWindowId = WINDOW_NONE;
static EWRAM_INIT u8 sMugshotSpriteId = 0xFF;
static EWRAM_INIT u16 sActiveMugshotTag = TAG_NONE;
EWRAM_DATA const u8 *gSpeakerName = NULL;

static const u32 sNameBoxDefaultGfx[] = INCBIN_U32("graphics/text_window/name_box.4bpp");
static const u32 sNameBoxPokenavGfx[] = INCBIN_U32("graphics/pokenav/name_box.4bpp");
static const u32 sMugshotMetacaballeroGfx[] = INCBIN_U32("graphics/text_window/mugshot_metacaballero.4bpp");
static const u32 sMugshotBatemagicoGfx[]    = INCBIN_U32("graphics/text_window/mugshot_batemagico.4bpp");
static const u32 sMugshotManolinGfx[]       = INCBIN_U32("graphics/text_window/mugshot_manolin.4bpp");
static const u32 sMugshotElPiedrasGfx[]     = INCBIN_U32("graphics/text_window/mugshot_elpiedras.4bpp");
static const u32 sMugshotYamiGfx[]          = INCBIN_U32("graphics/text_window/mugshot_yami.4bpp");
static const u32 sMugshotRivalGfx[]         = INCBIN_U32("graphics/text_window/mugshot_rival.4bpp");

extern const u16 gObjectEventPal_Npc1_hns[];
extern const u16 gObjectEventPal_Npc2_hns[];
extern const u16 gObjectEventPal_Npc2[];
extern const u16 gObjectEventPal_Npc3[];
extern const u16 gObjectEventPal_Npc3_hns[];
extern const u16 gObjectEventPal_Silver_hns[];

static const struct OamData sOamData_Mugshot16x16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = 0,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_MugshotMetacaballero =
{
    .data = sMugshotMetacaballeroGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_METACABALLERO,
};
static const struct SpritePalette sSpritePalette_MugshotMetacaballero =
{
    .data = gObjectEventPal_Npc1_hns,
    .tag = TAG_MUGSHOT_METACABALLERO,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotMetacaballero =
{
    .tileTag = TAG_MUGSHOT_METACABALLERO,
    .paletteTag = TAG_MUGSHOT_METACABALLERO,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSpriteSheet_MugshotBatemagico =
{
    .data = sMugshotBatemagicoGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_BATEMAGICO,
};
static const struct SpritePalette sSpritePalette_MugshotBatemagico =
{
    .data = gObjectEventPal_Npc2_hns,
    .tag = TAG_MUGSHOT_BATEMAGICO,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotBatemagico =
{
    .tileTag = TAG_MUGSHOT_BATEMAGICO,
    .paletteTag = TAG_MUGSHOT_BATEMAGICO,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSpriteSheet_MugshotManolin =
{
    .data = sMugshotManolinGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_MANOLIN,
};
static const struct SpritePalette sSpritePalette_MugshotManolin =
{
    .data = gObjectEventPal_Npc3,
    .tag = TAG_MUGSHOT_MANOLIN,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotManolin =
{
    .tileTag = TAG_MUGSHOT_MANOLIN,
    .paletteTag = TAG_MUGSHOT_MANOLIN,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSpriteSheet_MugshotElPiedras =
{
    .data = sMugshotElPiedrasGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_EL_PIEDRAS,
};
static const struct SpritePalette sSpritePalette_MugshotElPiedras =
{
    .data = gObjectEventPal_Npc2,
    .tag = TAG_MUGSHOT_EL_PIEDRAS,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotElPiedras =
{
    .tileTag = TAG_MUGSHOT_EL_PIEDRAS,
    .paletteTag = TAG_MUGSHOT_EL_PIEDRAS,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSpriteSheet_MugshotYami =
{
    .data = sMugshotYamiGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_YAMI,
};
static const struct SpritePalette sSpritePalette_MugshotYami =
{
    .data = gObjectEventPal_Npc3_hns,
    .tag = TAG_MUGSHOT_YAMI,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotYami =
{
    .tileTag = TAG_MUGSHOT_YAMI,
    .paletteTag = TAG_MUGSHOT_YAMI,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSpriteSheet_MugshotRival =
{
    .data = sMugshotRivalGfx,
    .size = 128,
    .tag = TAG_MUGSHOT_RIVAL,
};
static const struct SpritePalette sSpritePalette_MugshotRival =
{
    .data = gObjectEventPal_Silver_hns,
    .tag = TAG_MUGSHOT_RIVAL,
};
static const struct SpriteTemplate sSpriteTemplate_MugshotRival =
{
    .tileTag = TAG_MUGSHOT_RIVAL,
    .paletteTag = TAG_MUGSHOT_RIVAL,
    .oam = &sOamData_Mugshot16x16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void WindowFunc_DrawNamebox(u32, u32, u32, u32, u32, u32, u32);
static void WindowFunc_ClearNamebox(u8, u8, u8, u8, u8, u8);

void TrySpawnNamebox(u32 tileNum)
{
    u8 *strbuf = AllocZeroed(32 * sizeof(u8));
    if ((OW_FLAG_SUPPRESS_NAME_BOX != 0 && FlagGet(OW_FLAG_SUPPRESS_NAME_BOX)) || gSpeakerName == NULL || !strbuf)
    {
        // Re-check again in case anything but !strbuf is TRUE.
        if (strbuf)
            Free(strbuf);

        DestroyNamebox();
        return;
    }

    StringExpandPlaceholders(strbuf, gSpeakerName);

    u32 fontId = FONT_SMALL;
    u32 winWidth = OW_NAME_BOX_DEFAULT_WIDTH;

    if (OW_NAME_BOX_USE_DYNAMIC_WIDTH)
    {
        winWidth = ConvertPixelWidthToTileWidth(GetStringWidth(fontId, strbuf, -1));
        if (winWidth > OW_NAME_BOX_DEFAULT_WIDTH)
            winWidth = OW_NAME_BOX_DEFAULT_WIDTH;
    }

    if (sNameboxWindowId != WINDOW_NONE)
    {
        DestroyNamebox();
        RedrawDialogueFrame();
    }

    bool32 matchCall = IsMatchCallTaskActive();

    struct WindowTemplate template =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 13,
        .width = winWidth,
        .height = OW_NAME_BOX_DEFAULT_HEIGHT,
        .paletteNum = matchCall ? 14 : DLG_WINDOW_PALETTE_NUM,
        .baseBlock = tileNum,
    };

    sNameboxWindowId = AddWindow(&template);
    FillNamebox();

    u8 colors[3] = {TEXT_COLOR_TRANSPARENT, OW_NAME_BOX_FOREGROUND_COLOR, OW_NAME_BOX_SHADOW_COLOR};
    int strX = GetStringCenterAlignXOffset(fontId, strbuf, (winWidth * 8));
    if (matchCall)
    {
        colors[1] = 1;
        colors[2] = 0;
    }

    union TextColor savedTextColors = SaveTextColors();
    AddTextPrinterParameterized3(sNameboxWindowId, fontId, strX, 0, colors, 0, strbuf);
    RestoreTextColors(savedTextColors);
    PutWindowTilemap(sNameboxWindowId);

    // Spawn mugshot sprite above namebox for special characters
    if (sMugshotSpriteId == 0xFF)
    {
        const struct SpriteSheet *sheet = NULL;
        const struct SpritePalette *palette = NULL;
        const struct SpriteTemplate *templatePtr = NULL;
        u16 tag = TAG_NONE;

        if (StringCompare(strbuf, COMPOUND_STRING("METACABALLERO")) == 0)
        {
            sheet = &sSpriteSheet_MugshotMetacaballero;
            palette = &sSpritePalette_MugshotMetacaballero;
            templatePtr = &sSpriteTemplate_MugshotMetacaballero;
            tag = TAG_MUGSHOT_METACABALLERO;
        }
        else if (StringCompare(strbuf, COMPOUND_STRING("BATEMÁGICO")) == 0)
        {
            sheet = &sSpriteSheet_MugshotBatemagico;
            palette = &sSpritePalette_MugshotBatemagico;
            templatePtr = &sSpriteTemplate_MugshotBatemagico;
            tag = TAG_MUGSHOT_BATEMAGICO;
        }
        else if (StringCompare(strbuf, COMPOUND_STRING("MANOLÍN")) == 0)
        {
            sheet = &sSpriteSheet_MugshotManolin;
            palette = &sSpritePalette_MugshotManolin;
            templatePtr = &sSpriteTemplate_MugshotManolin;
            tag = TAG_MUGSHOT_MANOLIN;
        }
        else if (StringCompare(strbuf, COMPOUND_STRING("EL PIEDRAS")) == 0)
        {
            sheet = &sSpriteSheet_MugshotElPiedras;
            palette = &sSpritePalette_MugshotElPiedras;
            templatePtr = &sSpriteTemplate_MugshotElPiedras;
            tag = TAG_MUGSHOT_EL_PIEDRAS;
        }
        else if (StringCompare(strbuf, COMPOUND_STRING("YAMI")) == 0)
        {
            sheet = &sSpriteSheet_MugshotYami;
            palette = &sSpritePalette_MugshotYami;
            templatePtr = &sSpriteTemplate_MugshotYami;
            tag = TAG_MUGSHOT_YAMI;
        }
        else if (StringCompare(strbuf, gSaveBlock2Ptr->rivalName) == 0)
        {
            sheet = &sSpriteSheet_MugshotRival;
            palette = &sSpritePalette_MugshotRival;
            templatePtr = &sSpriteTemplate_MugshotRival;
            tag = TAG_MUGSHOT_RIVAL;
        }

        if (sheet != NULL)
        {
            LoadSpriteSheet(sheet);
            LoadSpritePalette(palette);
            // Position above namebox: X=24 (aligns with left of box), Y=96 (16px above namebox top)
            sMugshotSpriteId = CreateSprite(templatePtr, 24, 96, 0);
            sActiveMugshotTag = tag;
        }
    }

    Free(strbuf);
}

u32 GetNameboxWindowId(void)
{
    return sNameboxWindowId;
}

static void FreeActiveMugshot(void)
{
    if (sMugshotSpriteId != 0xFF)
    {
        DestroySprite(&gSprites[sMugshotSpriteId]);
        if (sActiveMugshotTag != TAG_NONE)
        {
            FreeSpriteTilesByTag(sActiveMugshotTag);
            FreeSpritePaletteByTag(sActiveMugshotTag);
            sActiveMugshotTag = TAG_NONE;
        }
        sMugshotSpriteId = 0xFF;
    }
}

void ResetNameboxData(void)
{
    FreeActiveMugshot();
    sNameboxWindowId = WINDOW_NONE;
    gSpeakerName = NULL;
}

void DestroyNamebox(void)
{
    FreeActiveMugshot();

    if (sNameboxWindowId == WINDOW_NONE)
        return;

    ClearNamebox(sNameboxWindowId, TRUE);
    ClearWindowTilemap(sNameboxWindowId);
    RemoveWindow(sNameboxWindowId);
    sNameboxWindowId = WINDOW_NONE;
    gSpeakerName = NULL;
}

u32 GetNameboxWidth(void)
{
    return gWindows[sNameboxWindowId].window.width;
}

static const u32 *GetNameboxGraphics(void)
{
    if (IsMatchCallTaskActive())
        return sNameBoxPokenavGfx;
    else
        return sNameBoxDefaultGfx;
}

void FillNamebox(void)
{
    u32 winSize = GetNameboxWidth();
    const u32 *gfx = GetNameboxGraphics();

    for (u32 i = 0; i < winSize; i++)
    {
        #define TILE(x) (8 * x)
        CopyToWindowPixelBuffer(sNameboxWindowId, &gfx[TILE(1)], TILE_SIZE_4BPP, i);
        CopyToWindowPixelBuffer(sNameboxWindowId, &gfx[TILE(4)], TILE_SIZE_4BPP, i + winSize);
        #undef TILE
    }
}

void DrawNamebox(u32 windowId, u32 tileNum, bool32 copyToVram)
{
    // manual instead of using CallWindowFunction for extra tileNum param
    struct WindowTemplate *w = &gWindows[windowId].window;
    u32 size = TILE_OFFSET_4BPP(NAME_BOX_BASE_TILES_TOTAL);

    LoadBgTiles(GetWindowAttribute(sNameboxWindowId, WINDOW_BG), GetNameboxGraphics(), size, tileNum);
    WindowFunc_DrawNamebox(w->bg, w->tilemapLeft, w->tilemapTop, w->width, w->height, w->paletteNum, tileNum);
    PutWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

void ClearNamebox(u32 windowId, bool32 copyToVram)
{
    CallWindowFunction(windowId, WindowFunc_ClearNamebox);
    ClearWindowTilemap(windowId);
    if (copyToVram == TRUE)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void WindowFunc_DrawNamebox(u32 bg, u32 L, u32 T, u32 w, u32 h, u32 p, u32 tileNum)
{
    // left-most
    FillBgTilemapBufferRect(bg, tileNum,     L - 1, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, tileNum + 3, L - 1, T + 1, 1, 1, p);

    // right-most
    FillBgTilemapBufferRect(bg, tileNum + 2, L + w, T,     1, 1, p);
    FillBgTilemapBufferRect(bg, tileNum + 5, L + w, T + 1, 1, 1, p);
}

static void WindowFunc_ClearNamebox(u8 bg, u8 L, u8 T, u8 w, u8 h, u8 p)
{
    FillBgTilemapBufferRect(bg, 0, L - 1, T, w + 2, h, 0); // palette doesn't matter
}

void SetSpeaker(struct ScriptContext *ctx)
{
    u32 arg = ScriptReadWord(ctx);
    const u8 *speaker = NULL;

    if (arg < SP_NAME_COUNT)
        speaker = gSpeakerNamesTable[arg];
    else if (arg >= ROM_START && arg < ROM_END)
        speaker = (const u8 *)arg;

    gSpeakerName = speaker;
}

// useful for other context e.g. match call
void TrySpawnAndShowNamebox(const u8 *speaker, u32 tileNum)
{
    gSpeakerName = speaker;
    TrySpawnNamebox(tileNum);
    if (sNameboxWindowId != WINDOW_NONE)
        DrawNamebox(sNameboxWindowId, tileNum - NAME_BOX_BASE_TILES_TOTAL, TRUE);
    else // either NULL or SP_NAME_NONE
        RedrawDialogueFrame();
}
