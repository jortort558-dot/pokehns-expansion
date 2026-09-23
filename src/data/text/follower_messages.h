extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} empezó a darte toques\nen la barriga.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} está feliz,\npero tímido.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} te sigue muy contento.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} mantiene la compostura.");
static const u8 sHappyMsg04[] = _("¡{STR_VAR_1} parece encantado de\npasear contigo!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} rebosa salud.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} parece muy feliz.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} se ha esforzado de más.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} olfatea los aromas\ndel ambiente.");
static const u8 sHappyMsg09[] = _("¡{STR_VAR_1} salta de alegría!");
static const u8 sHappyMsg10[] = _("¡{STR_VAR_1} sigue\nsintiéndose genial!");
static const u8 sHappyMsg11[] = _("Tu POKéMON ha percibido olor\na humo.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} te da toques\nen la barriga.");
static const u8 sHappyMsg13[] = _("Tu POKéMON se ha estirado\ny se está relajando.");
static const u8 sHappyMsg14[] = _("¡{STR_VAR_1} parece querer ir\nen cabeza!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} hace lo posible por\nseguirte el ritmo.");
static const u8 sHappyMsg16[] = _("¡{STR_VAR_1} se acurruca feliz\na tu lado!");
static const u8 sHappyMsg17[] = _("¡{STR_VAR_1} está lleno de vida!");
static const u8 sHappyMsg18[] = _("¡{STR_VAR_1} parece muy feliz!");
static const u8 sHappyMsg19[] = _("¡{STR_VAR_1} está tan feliz que\nno puede estarse quieto!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} asintió despacio.");
static const u8 sHappyMsg21[] = _("¡{STR_VAR_1} está impaciente!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} deambula mientras\nescucha distintos sonidos.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} parece muy interesado.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} se obliga a seguir\navanzando como puede.");
static const u8 sHappyMsg25[] = _("¡{STR_VAR_1} te miró con alegría!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} te mira contento\ny sonríe.");
static const u8 sHappyMsg27[] = _("Tu POKéMON está oliendo\nlas flores.");
static const u8 sHappyMsg28[] = _("¡{STR_VAR_1} parece muy feliz\nde verte!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} se giró hacia ti\ny sonrió.");
static const u8 sHappyMsg30[] = _("¡{STR_VAR_1} se acurrucó feliz\na tu lado!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Tu POKéMON parece feliz por\nel buen tiempo.");
static const u8 sHappyMsg32[] = _("¡{STR_VAR_1} mantiene la calma\ny confía mucho en sí mismo!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} da golpecitos\nen el suelo sin parar.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} está montando guardia.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} mira pacientemente\na la nada.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} está deambulando.");
static const u8 sNeutralMsg04[] = _("¡Tu POKéMON ha bostezado\nmuy fuerte!");
static const u8 sNeutralMsg05[] = _("Tu POKéMON mira alrededor\ncon inquietud.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} mira hacia aquí\ny sonríe.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} observa alrededor\ncon inquietud.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} lanzó un grito\nde guerra.");
static const u8 sNeutralMsg09[] = _("¡{STR_VAR_1} hizo un baile\nmaravilloso!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} está impaciente.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} contempla fijamente\nla lejanía.");
static const u8 sNeutralMsg12[] = _("¡{STR_VAR_1} está al acecho!");
static const u8 sNeutralMsg13[] = _("¡{STR_VAR_1} miró a lo lejos\ny ladró!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} está mareado.");
static const u8 sSadMsg01[] = _("¡{STR_VAR_1} te está pisando\nlos pies!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} parece algo cansado.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} no está contento.");
static const u8 sSadMsg04[] = _("¡{STR_VAR_1} va a caerse!\n");
static const u8 sSadMsg05[] = _("¡Parece que {STR_VAR_1} está\na punto de caerse!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} se esfuerza mucho\npor seguirte el ritmo…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} está nervioso.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} parece disgustado…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} pone cara\nde disgusto.");
static const u8 sUpsetMsg02[] = _("…Tu POKéMON parece tener\nalgo de frío.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} se refugia de la lluvia\nbajo la hierba.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("¡{STR_VAR_1} lanzó un rugido!");
static const u8 sAngryMsg01[] = _("¡{STR_VAR_1} pone cara\nde enfado!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} parece enfadado\npor algún motivo.");
static const u8 sAngryMsg03[] = _("Tu POKéMON se dio la vuelta\ncon gesto desafiante.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} lanzó un grito.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} mira fijamente\nhacia abajo.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} examina la zona.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} mira hacia abajo.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} intenta vencer\nel sueño…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} parece estar\ndeambulando.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} mira a su alrededor\ndistraído.");
static const u8 sPensiveMsg06[] = _("¡{STR_VAR_1} ha bostezado\nmuy fuerte!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} se relaja cómodamente.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} te mira fijamente\na la cara.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} observa tu rostro\ncon atención.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} centra toda\nsu atención en ti.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} mira fijamente\na las profundidades.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} olfatea el suelo.");
static const u8 sPensiveMsg13[] = _("Tu POKéMON mira fijamente\na la nada.");
static const u8 sPensiveMsg14[] = _("¡{STR_VAR_1} se concentró\ncon una mirada penetrante!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} está concentrándose.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} se volvió hacia ti\ny asintió.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} parece algo nervioso…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} observa tus huellas.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} te mira directamente\na los ojos.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("¡{STR_VAR_1} empezó a caminar\nmás cerca de ti!");
static const u8 sLoveMsg01[] = _("¡A {STR_VAR_1} se le sonrojan\nlas mejillas!");
static const u8 sLoveMsg02[] = _("¡Hala! ¡{STR_VAR_1} te ha abrazado\nde repente!");
static const u8 sLoveMsg03[] = _("¡Hala! ¡{STR_VAR_1} quiere jugar\nde repente!");
static const u8 sLoveMsg04[] = _("¡{STR_VAR_1} se frota contra\ntus piernas!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} se sonroja.");
static const u8 sLoveMsg06[] = _("¡Ah! ¡{STR_VAR_1} se acurruca\ncontigo!");
static const u8 sLoveMsg07[] = _("¡{STR_VAR_1} te mira con adoración!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} se acercó a ti.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} permanece cerca\nde tus pies.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("¡{STR_VAR_1} corre peligro\nde caerse!");
static const u8 sSurpriseMsg01[] = _("¡{STR_VAR_1} ha chocado contigo!");
static const u8 sSurpriseMsg02[] = _("Parece que {STR_VAR_1} aún no\nse acostumbra a su nombre.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} mira hacia abajo.");
static const u8 sSurpriseMsg04[] = _("¡Tu POKéMON tropezó y casi\nse cae!");
static const u8 sSurpriseMsg05[] = _("¡{STR_VAR_1} ha notado algo\ny está aullando!");
static const u8 sSurpriseMsg06[] = _("¡{STR_VAR_1} parece revitalizado!");
static const u8 sSurpriseMsg07[] = _("¡{STR_VAR_1} se giró de repente\ny empezó a ladrar!");
static const u8 sSurpriseMsg08[] = _("¡{STR_VAR_1} se giró de repente!");
static const u8 sSurpriseMsg09[] = _("¡Tu POKéMON se sorprendió\nal hablarle de repente!");
static const u8 sSurpriseMsg10[] = _("¡Snif, snif! ¡Algo huele\nmuy bien!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} se siente revitalizado.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} se tambalea y parece\na punto de caerse.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} corre peligro\nde caerse.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} avanza con cautela.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} se pone tenso\npor los nervios.");
static const u8 sSurpriseMsg16[] = _("¡{STR_VAR_1} percibió algo extraño\ny se sorprendió!");
static const u8 sSurpriseMsg17[] = _("¡{STR_VAR_1} tiene miedo y\nse ha acurrucado contigo!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} percibe una presencia\nextraña…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} se pone tenso\npor los nervios.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("¡{STR_VAR_1} parece muy sorprendido\nde que esté lloviendo!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Tu POKéMON busca algo a su\nalrededor con inquietud.");
static const u8 sCuriousMsg01[] = _("¡Tu POKéMON no miraba por dónde\niba y ha chocado contigo!");
static const u8 sCuriousMsg02[] = _("¡Snif, snif! ¿Hay algo cerca?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} juega haciendo rodar\nuna piedrecita.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} deambula buscando\nalgo.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} te está olfateando.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} parece algo indeciso…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("¡{STR_VAR_1} presume de agilidad!");
static const u8 sMusicMsg01[] = _("¡{STR_VAR_1} se mueve con alegría!");
static const u8 sMusicMsg02[] = _("¡Hala! ¡{STR_VAR_1} se puso\na bailar de alegría!");
static const u8 sMusicMsg03[] = _("¡{STR_VAR_1} te sigue el ritmo\nsin problemas!");
static const u8 sMusicMsg04[] = _("Parece que {STR_VAR_1} quiere\njugar contigo.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} da saltitos de alegría.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} canta y tararea.");
static const u8 sMusicMsg07[] = _("¡{STR_VAR_1} te mordisquea\nlos pies!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} se gira y te mira.");
static const u8 sMusicMsg09[] = _("¡{STR_VAR_1} se esfuerza por\ndemostrar su enorme poder!");
static const u8 sMusicMsg10[] = _("¡Hala! ¡{STR_VAR_1} se puso\na bailar de alegría!");
static const u8 sMusicMsg11[] = _("¡{STR_VAR_1} está muy alegre!");
static const u8 sMusicMsg12[] = _("¡{STR_VAR_1} salta despreocupado\nde un lado a otro!");
static const u8 sMusicMsg13[] = _("Tu POKéMON parece percibir\nun aroma familiar y nostálgico…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} está muy contento\ncon la lluvia.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} tiembla por los efectos\ndel envenenamiento.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
