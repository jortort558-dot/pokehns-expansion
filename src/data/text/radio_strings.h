// Radio station strings ported from pokecrystal
// Lines fit ~32 char width for 28-tile window

#ifndef GUARD_DATA_TEXT_RADIO_STRINGS_H
#define GUARD_DATA_TEXT_RADIO_STRINGS_H

// ==========================================================
// Station Names (displayed at top of radio UI)
// ==========================================================

static const u8 sRadioStationName_OaksPkmnTalk[]    = _("Charla POKéMON de OAK");
static const u8 sRadioStationName_PokedexShow[]     = _("Show de la POKéDEX");
static const u8 sRadioStationName_PokemonMusic[]    = _("Música POKéMON");
static const u8 sRadioStationName_LuckyChannel[]    = _("Canal de la Suerte");
static const u8 sRadioStationName_BuenasPassword[]  = _("CONTRASEÑA DE BUENA");
static const u8 sRadioStationName_Unown[]           = _("?????");
static const u8 sRadioStationName_PlacesAndPeople[] = _("Lugares y gente");
static const u8 sRadioStationName_LetsAllSing[]     = _("¡Cantemos todos!");
static const u8 sRadioStationName_PokeFlute[]       = _("POKé FLAUTA");

static const u8 sRadioStationName_HoennSound[]  = _("Sonidos de Hoenn");

// ==========================================================
// Hoenn Sound
// ==========================================================

static const u8 sRadioText_Hoenn1[] = _("Una melodía POKéMON de una");
static const u8 sRadioText_Hoenn2[] = _("¡lejana región llamada HOENN!");
static const u8 sRadioText_Hoenn3[] = _("¡Los POKéMON salvajes de allí");
static const u8 sRadioText_Hoenn4[] = _("podrían aparecer cerca!");

// ==========================================================
// POKéDEX Show
// ==========================================================

static const u8 sRadioText_PokedexShow_Intro[] = _("¡SHOW DE LA POKéDEX DE OAK!");
static const u8 sRadioText_PokedexShow_TodaysPrefix[] = _("OAK: El POKéMON de hoy es ");

// ==========================================================
// Oak's POKéMON Talk
// ==========================================================

static const u8 sRadioText_OPT_Intro[] = _("MARY: ¡CHARLA POKéMON DE OAK!");
static const u8 sRadioText_OPT_WithMeMary[] = _("¡Conmigo, MARY!");
static const u8 sRadioText_OPT_OakPrefix[] = _("OAK: ");
static const u8 sRadioText_OPT_SeenAround[] = _("puede verse por");
static const u8 sRadioText_OPT_MaryPrefix[] = _("MARY: ");
static const u8 sRadioText_OPT_MaryIs[] = _(" es ");

// Pokemon Channel interlude
static const u8 sRadioText_OPT_PokemonChannel[] = _("Canal POKéMON");

// Adverbs (randomly selected)
static const u8 sRadioText_OPT_Adverb_SweetAdorably[]      = _("dulce y adorablemente");
static const u8 sRadioText_OPT_Adverb_WigglySlickly[]      = _("ágil y escurridizo");
static const u8 sRadioText_OPT_Adverb_AptlyNamed[]         = _("de nombre acertado y");
static const u8 sRadioText_OPT_Adverb_UndeniablyKindOf[]   = _("sin duda bastante");
static const u8 sRadioText_OPT_Adverb_Unbearably[]         = _("tan insoportablemente");
static const u8 sRadioText_OPT_Adverb_WowImpressively[]    = _("vaya, increíblemente");
static const u8 sRadioText_OPT_Adverb_AlmostPoisonously[]  = _("casi venenosamente");
static const u8 sRadioText_OPT_Adverb_Sensually[]          = _("oh, muy sensualmente");
static const u8 sRadioText_OPT_Adverb_Mischievously[]      = _("muy travieso");
static const u8 sRadioText_OPT_Adverb_Topically[]          = _("muy apropiado");
static const u8 sRadioText_OPT_Adverb_Addictively[]        = _("muy adictivo");
static const u8 sRadioText_OPT_Adverb_LooksInWater[]       = _("bajo el agua parece");
static const u8 sRadioText_OPT_Adverb_EvolutionMustBe[]    = _("su evolución debe ser");
static const u8 sRadioText_OPT_Adverb_Provocatively[]      = _("provocadoramente");
static const u8 sRadioText_OPT_Adverb_FlippedOut[]         = _("muy alocado y");
static const u8 sRadioText_OPT_Adverb_HeartMeltingly[]     = _("enternecedor");

static const u8 *const sRadioText_OPT_Adverbs[] =
{
    sRadioText_OPT_Adverb_SweetAdorably,
    sRadioText_OPT_Adverb_WigglySlickly,
    sRadioText_OPT_Adverb_AptlyNamed,
    sRadioText_OPT_Adverb_UndeniablyKindOf,
    sRadioText_OPT_Adverb_Unbearably,
    sRadioText_OPT_Adverb_WowImpressively,
    sRadioText_OPT_Adverb_AlmostPoisonously,
    sRadioText_OPT_Adverb_Sensually,
    sRadioText_OPT_Adverb_Mischievously,
    sRadioText_OPT_Adverb_Topically,
    sRadioText_OPT_Adverb_Addictively,
    sRadioText_OPT_Adverb_LooksInWater,
    sRadioText_OPT_Adverb_EvolutionMustBe,
    sRadioText_OPT_Adverb_Provocatively,
    sRadioText_OPT_Adverb_FlippedOut,
    sRadioText_OPT_Adverb_HeartMeltingly,
};

// Adjectives (randomly selected)
static const u8 sRadioText_OPT_Adj_Cute[]           = _("adorable.");
static const u8 sRadioText_OPT_Adj_Weird[]          = _("extraño.");
static const u8 sRadioText_OPT_Adj_Pleasant[]       = _("agradable.");
static const u8 sRadioText_OPT_Adj_BoldSortOf[]     = _("algo osado.");
static const u8 sRadioText_OPT_Adj_Frightening[]    = _("aterrador.");
static const u8 sRadioText_OPT_Adj_SuaveDebonair[]  = _("¡suave y elegante!");
static const u8 sRadioText_OPT_Adj_Powerful[]        = _("poderoso.");
static const u8 sRadioText_OPT_Adj_Exciting[]        = _("emocionante.");
static const u8 sRadioText_OPT_Adj_Groovy[]          = _("¡marchoso!");
static const u8 sRadioText_OPT_Adj_Inspiring[]       = _("inspirador.");
static const u8 sRadioText_OPT_Adj_Friendly[]        = _("amistoso.");
static const u8 sRadioText_OPT_Adj_HotHotHot[]       = _("¡ardiente, ardiente!");
static const u8 sRadioText_OPT_Adj_Stimulating[]     = _("estimulante.");
static const u8 sRadioText_OPT_Adj_Guarded[]         = _("reservado.");
static const u8 sRadioText_OPT_Adj_Lovely[]          = _("encantador.");
static const u8 sRadioText_OPT_Adj_Speedy[]          = _("veloz.");

static const u8 *const sRadioText_OPT_Adjectives[] =
{
    sRadioText_OPT_Adj_Cute,
    sRadioText_OPT_Adj_Weird,
    sRadioText_OPT_Adj_Pleasant,
    sRadioText_OPT_Adj_BoldSortOf,
    sRadioText_OPT_Adj_Frightening,
    sRadioText_OPT_Adj_SuaveDebonair,
    sRadioText_OPT_Adj_Powerful,
    sRadioText_OPT_Adj_Exciting,
    sRadioText_OPT_Adj_Groovy,
    sRadioText_OPT_Adj_Inspiring,
    sRadioText_OPT_Adj_Friendly,
    sRadioText_OPT_Adj_HotHotHot,
    sRadioText_OPT_Adj_Stimulating,
    sRadioText_OPT_Adj_Guarded,
    sRadioText_OPT_Adj_Lovely,
    sRadioText_OPT_Adj_Speedy,
};

// ==========================================================
// POKéMON Music Channel (Ben & Fern)
// ==========================================================

static const u8 sRadioText_BenIntro[] = _("BEN: ¡CANAL MÚSICA POKéMON!");
static const u8 sRadioText_BenIntro2[] = _("¡Soy yo, DJ BEN!");
static const u8 sRadioText_FernIntro[] = _("FERN: ¡POKéMÚSICA!");
static const u8 sRadioText_FernIntro2[] = _("¡Con DJ FERN!");
// "Today's {DAY}," built dynamically
static const u8 sRadioText_BenFern_TodayIs[] = _("Hoy es ");
static const u8 sRadioText_BenFern_JamTo[] = _("así que marchemos con");
static const u8 sRadioText_BenFern_ChillTo[] = _("relajémonos con");
static const u8 sRadioText_BenFern_March[] = _("¡Marcha POKéMON!");
static const u8 sRadioText_BenFern_Lullaby[] = _("¡Nana POKéMON!");

// ==========================================================
// Lucky Channel
// ==========================================================

static const u8 sRadioText_LC1[] = _("REED: ¡Yuju! ¿Cómo estáis");
static const u8 sRadioText_LC2[] = _("hoy? Estéis arriba o muy");
static const u8 sRadioText_LC3[] = _("abajo, no os perdáis el");
static const u8 sRadioText_LC4[] = _("¡SHOW DEL NÚMERO DE LA SUERTE!");
static const u8 sRadioText_LC5[] = _("El Número de la Suerte es");
// "{number}!" built dynamically
static const u8 sRadioText_LC_Repeat[] = _("¡Lo repetiré!");
static const u8 sRadioText_LC_Match[] = _("Si coincide, ve a");
static const u8 sRadioText_LC_Tower[] = _("¡la TORRE RADIO!");
static const u8 sRadioText_LC_Drag1[] = _("…Repetirme tanto");
static const u8 sRadioText_LC_Drag2[] = _("acaba cansando…");

// ==========================================================
// Places and People
// ==========================================================

static const u8 sRadioText_PnP_Intro[] = _("¡LUGARES Y GENTE! Presentado");
static const u8 sRadioText_PnP_Intro2[] = _("por mí, ¡DJ LILY!");
static const u8 sRadioText_PnP_Space[] = _(" ");

// People adjectives
static const u8 sRadioText_PnP_Cute[]       = _("es adorable.");
static const u8 sRadioText_PnP_Lazy[]       = _("es algo perezoso.");
static const u8 sRadioText_PnP_Happy[]      = _("siempre está feliz.");
static const u8 sRadioText_PnP_Noisy[]      = _("es bastante ruidoso.");
static const u8 sRadioText_PnP_Precocious[] = _("es precoz.");
static const u8 sRadioText_PnP_Bold[]       = _("es algo osado.");
static const u8 sRadioText_PnP_Picky[]      = _("¡es muy exigente!");
static const u8 sRadioText_PnP_SortOfOK[]   = _("está bastante bien.");
static const u8 sRadioText_PnP_SoSo[]       = _("es normalito.");
static const u8 sRadioText_PnP_Great[]       = _("es realmente genial.");
static const u8 sRadioText_PnP_MyType[]      = _("es justo mi tipo.");
static const u8 sRadioText_PnP_Cool[]        = _("es genial, ¿no?");
static const u8 sRadioText_PnP_Inspiring[]   = _("¡es inspirador!");
static const u8 sRadioText_PnP_Weird[]       = _("es algo extraño.");
static const u8 sRadioText_PnP_RightForMe[]  = _("¿es ideal para mí?");
static const u8 sRadioText_PnP_Odd[]         = _("¡es muy peculiar!");

static const u8 *const sRadioText_PnP_PeopleAdj[] =
{
    sRadioText_PnP_Cute,
    sRadioText_PnP_Lazy,
    sRadioText_PnP_Happy,
    sRadioText_PnP_Noisy,
    sRadioText_PnP_Precocious,
    sRadioText_PnP_Bold,
    sRadioText_PnP_Picky,
    sRadioText_PnP_SortOfOK,
    sRadioText_PnP_SoSo,
    sRadioText_PnP_Great,
    sRadioText_PnP_MyType,
    sRadioText_PnP_Cool,
    sRadioText_PnP_Inspiring,
    sRadioText_PnP_Weird,
    sRadioText_PnP_RightForMe,
    sRadioText_PnP_Odd,
};

// ==========================================================
// Rocket Radio
// ==========================================================

static const u8 sRadioStationName_Rocket[] = _("TEAM ROCKET");
static const u8 sRadioText_Rocket1[]  = _("… …Ejem, somos el");
static const u8 sRadioText_Rocket2[]  = _("TEAM ROCKET!");
static const u8 sRadioText_Rocket3[]  = _("Tras tres años");
static const u8 sRadioText_Rocket4[]  = _("de preparación, hemos");
static const u8 sRadioText_Rocket5[]  = _("resurgido de nuevo");
static const u8 sRadioText_Rocket6[]  = _("¡de nuestras cenizas!");
static const u8 sRadioText_Rocket7[]  = _("GIOVANNI!");
static const u8 sRadioText_Rocket8[]  = _("¿Puedes oírnos?");
static const u8 sRadioText_Rocket9[]  = _("");
static const u8 sRadioText_Rocket10[] = _("");

// ==========================================================
// Buena's Password
// ==========================================================

static const u8 sRadioText_Buena1[] = _("BUENA: ¡Soy BUENA!");
static const u8 sRadioText_Buena2[] = _("¡La contraseña de hoy!");
static const u8 sRadioText_Buena3[] = _("A ver… Es");
// "{password}!" built dynamically with STR_VAR_1
static const u8 sRadioText_Buena4[] = _("{STR_VAR_1}!");
static const u8 sRadioText_Buena5[] = _("¡No la olvides! Estoy en");
static const u8 sRadioText_Buena6[] = _("¡la TORRE RADIO de TRIGAL!");


// ==========================================================
// Buena's Password Categories & Options
// ==========================================================

static const u8 sRadioBuenaPassword_NewBarkTown[]     = _("PUEBLO PRIMAVERA");
static const u8 sRadioBuenaPassword_CherrygroveCity[]  = _("CIUDAD CEREZO");
static const u8 sRadioBuenaPassword_AzaleaTown[]      = _("PUEBLO AZALEA");
static const u8 sRadioBuenaPassword_Flying[]          = _("VOLADOR");
static const u8 sRadioBuenaPassword_Bug[]             = _("BICHO");
static const u8 sRadioBuenaPassword_Grass[]           = _("PLANTA");
static const u8 sRadioBuenaPassword_PkmnTalk[]        = _("Charla POKéMON");
static const u8 sRadioBuenaPassword_PkmnMusic[]       = _("Música POKéMON");
static const u8 sRadioBuenaPassword_LuckyChannel[]    = _("Canal de la Suerte");

// ==========================================================
// Oak's POKéMON Talk - Special Reports
// ==========================================================

static const u8 sOPT_Report_Clefairy_0[]  = _("MARY: Esta noche, un raro evento");
static const u8 sOPT_Report_Clefairy_1[]  = _("lunar en CHARLA POKéMON.");
static const u8 sOPT_Report_Clefairy_2[]  = _("OAK: Hoy destacamos al");
static const u8 sOPT_Report_Clefairy_3[]  = _("¡místico CLEFAIRY!");
static const u8 sOPT_Report_Clefairy_4[]  = _("Se reúnen en el MT. MOON");
static const u8 sOPT_Report_Clefairy_5[]  = _("durante la luna llena.");
static const u8 sOPT_Report_Clefairy_6[]  = _("MARY: ¡Bailan en círculos!");
static const u8 sOPT_Report_Clefairy_7[]  = _("¡Son adorables y extraños!");
static const u8 sOPT_Report_Clefairy_8[]  = _("OAK: Un misterio eterno");
static const u8 sOPT_Report_Clefairy_9[]  = _("¡digno de contemplar!");

static const u8 sOPT_Report_Lapras_0[]  = _("MARY: ¡Un gigante amable ocupa");
static const u8 sOPT_Report_Lapras_1[]  = _("el escenario de hoy!");
static const u8 sOPT_Report_Lapras_2[]  = _("OAK: Es el transporte marino,");
static const u8 sOPT_Report_Lapras_3[]  = _("¡nuestro querido LAPRAS!");
static const u8 sOPT_Report_Lapras_4[]  = _("Se ve en CUEVA UNIÓN, pero");
static const u8 sOPT_Report_Lapras_5[]  = _("en ningún otro sitio. ¡Curioso!");
static const u8 sOPT_Report_Lapras_6[]  = _("MARY: ¡Tan raro y pacífico!");
static const u8 sOPT_Report_Lapras_7[]  = _("¡Y también canta!");
static const u8 sOPT_Report_Lapras_8[]  = _("OAK: Dicen que sus cantos calman");
static const u8 sOPT_Report_Lapras_9[]  = _("el alma del mar.");

static const u8 sOPT_Report_Ampharos_0[]  = _("MARY: ¡Bienvenidos de nuevo!");
static const u8 sOPT_Report_Ampharos_1[]  = _("¡Hora de CHARLA POKéMON!");
static const u8 sOPT_Report_Ampharos_2[]  = _("OAK: Centremos la luz en");
static const u8 sOPT_Report_Ampharos_3[]  = _("¡nuestro amigo AMPHAROS!");
static const u8 sOPT_Report_Ampharos_4[]  = _("Su cola brillante atraviesa la");
static const u8 sOPT_Report_Ampharos_5[]  = _("niebla y guía a los perdidos.");
static const u8 sOPT_Report_Ampharos_6[]  = _("MARY: Poderoso, elegante");
static const u8 sOPT_Report_Ampharos_7[]  = _("¡y sin duda amistoso!");
static const u8 sOPT_Report_Ampharos_8[]  = _("OAK: Protagoniza muchas");
static const u8 sOPT_Report_Ampharos_9[]  = _("¡historias de faros!");

static const u8 sOPT_Report_Sudowoodo_0[]  = _("MARY: Ahora, un ser muy raro");
static const u8 sOPT_Report_Sudowoodo_1[]  = _("en la RUTA 36…");
static const u8 sOPT_Report_Sudowoodo_2[]  = _("OAK: ¡SUDOWOODO! Parece un");
static const u8 sOPT_Report_Sudowoodo_3[]  = _("árbol, ¡pero no lo es!");
static const u8 sOPT_Report_Sudowoodo_4[]  = _("Bloquea el camino y no se");
static const u8 sOPT_Report_Sudowoodo_5[]  = _("mueve sin agua.");
static const u8 sOPT_Report_Sudowoodo_6[]  = _("MARY: Solo reacciona a una");
static const u8 sOPT_Report_Sudowoodo_7[]  = _("¡REGADERA!");
static const u8 sOPT_Report_Sudowoodo_8[]  = _("OAK: No es un arbusto, sino un");
static const u8 sOPT_Report_Sudowoodo_9[]  = _("¡tipo ROCA disfrazado!");

static const u8 sOPT_Report_RedGyarados_0[]  = _("MARY: La historia de hoy llega");
static const u8 sOPT_Report_RedGyarados_1[]  = _("desde JOHTO y es impactante.");
static const u8 sOPT_Report_RedGyarados_2[]  = _("OAK: Han visto un GYARADOS");
static const u8 sOPT_Report_RedGyarados_3[]  = _("ROJO en el LAGO DE LA FURIA.");
static const u8 sOPT_Report_RedGyarados_4[]  = _("A diferencia de los azules,");
static const u8 sOPT_Report_RedGyarados_5[]  = _("¡este es rojo carmesí!");
static const u8 sOPT_Report_RedGyarados_6[]  = _("MARY: Dicen que está ligado");
static const u8 sOPT_Report_RedGyarados_7[]  = _("a unas extrañas ondas de radio.");
static const u8 sOPT_Report_RedGyarados_8[]  = _("OAK: Una evolución misteriosa…");
static const u8 sOPT_Report_RedGyarados_9[]  = _("Quizá antinatural.");

static const u8 sOPT_Report_Unown_0[]  = _("MARY: ¿Has visitado las RUINAS");
static const u8 sOPT_Report_Unown_1[]  = _("ALFA? ¡Dan escalofríos!");
static const u8 sOPT_Report_Unown_2[]  = _("OAK: Hay extraños símbolos en");
static const u8 sOPT_Report_Unown_3[]  = _("los muros, como runas antiguas.");
static const u8 sOPT_Report_Unown_4[]  = _("Dentro encontrarás UNOWN…");
static const u8 sOPT_Report_Unown_5[]  = _("¡todos con forma de letras!");
static const u8 sOPT_Report_Unown_6[]  = _("MARY: Quizá formen palabras…");
static const u8 sOPT_Report_Unown_7[]  = _("¡o solo quieran asustarnos!");
static const u8 sOPT_Report_Unown_8[]  = _("OAK: Un verdadero enigma natural");
static const u8 sOPT_Report_Unown_9[]  = _("aún sin resolver.");

static const u8 sOPT_Report_Snubbull_0[]  = _("MARY: ¡En CIUDAD TRIGAL buscan");
static const u8 sOPT_Report_Snubbull_1[]  = _("por todas partes!");
static const u8 sOPT_Report_Snubbull_2[]  = _("OAK: Un SNUBBULL se ha escapado");
static const u8 sOPT_Report_Snubbull_3[]  = _("¡y anda suelto!");
static const u8 sOPT_Report_Snubbull_4[]  = _("Suele ser tímido y delicado;");
static const u8 sOPT_Report_Snubbull_5[]  = _("lo vieron cerca de la estación.");
static const u8 sOPT_Report_Snubbull_6[]  = _("MARY: Quizá busque amor…");
static const u8 sOPT_Report_Snubbull_7[]  = _("¡o simplemente aventuras!");
static const u8 sOPT_Report_Snubbull_8[]  = _("OAK: Mantén los ojos abiertos");
static const u8 sOPT_Report_Snubbull_9[]  = _("y la correa preparada.");

static const u8 sOPT_Report_Slowpoke_0[]  = _("MARY: ¡Grandes noticias desde");
static const u8 sOPT_Report_Slowpoke_1[]  = _("PUEBLO AZALEA esta semana!");
static const u8 sOPT_Report_Slowpoke_2[]  = _("OAK: Los SLOWPOKE han vuelto");
static const u8 sOPT_Report_Slowpoke_3[]  = _("al pozo tras una crisis.");
static const u8 sOPT_Report_Slowpoke_4[]  = _("¡El TEAM ROCKET les cortaba");
static const u8 sOPT_Report_Slowpoke_5[]  = _("la cola! ¡Qué horror!");
static const u8 sOPT_Report_Slowpoke_6[]  = _("MARY: Pero un joven y valiente");
static const u8 sOPT_Report_Slowpoke_7[]  = _("entrenador los detuvo.");
static const u8 sOPT_Report_Slowpoke_8[]  = _("OAK: Los SLOWPOKE están a salvo");
static const u8 sOPT_Report_Slowpoke_9[]  = _("y vuelven a dormir felices.");

static const u8 sOPT_Report_LavenderTower_0[]  = _("MARY: La torre de PUEBLO LAVANDA");
static const u8 sOPT_Report_LavenderTower_1[]  = _("¡ha cambiado de sintonía!");
static const u8 sOPT_Report_LavenderTower_2[]  = _("OAK: La vieja torre fantasma es");
static const u8 sOPT_Report_LavenderTower_3[]  = _("¡ahora una EMISORA DE RADIO!");
static const u8 sOPT_Report_LavenderTower_4[]  = _("Algunos vecinos dicen que aún");
static const u8 sOPT_Report_LavenderTower_5[]  = _("da… escalofríos.");
static const u8 sOPT_Report_LavenderTower_6[]  = _("MARY: ¡Juro que vi un GASTLY");
static const u8 sOPT_Report_LavenderTower_7[]  = _("junto al micrófono!");
static const u8 sOPT_Report_LavenderTower_8[]  = _("OAK: Quizá fueran interferencias…");
static const u8 sOPT_Report_LavenderTower_9[]  = _("¡o espectros!");

static const u8 sOPT_Report_Tentacruel_0[]  = _("MARY: Extrañas noticias desde");
static const u8 sOPT_Report_Tentacruel_1[]  = _("las ISLAS REMOLINO.");
static const u8 sOPT_Report_Tentacruel_2[]  = _("OAK: Varios TENTACRUEL rodean");
static const u8 sOPT_Report_Tentacruel_3[]  = _("¡las entradas de las cuevas!");
static const u8 sOPT_Report_Tentacruel_4[]  = _("Son enormes y actúan de forma");
static const u8 sOPT_Report_Tentacruel_5[]  = _("muy territorial.");
static const u8 sOPT_Report_Tentacruel_6[]  = _("MARY: Bloquean el paso");
static const u8 sOPT_Report_Tentacruel_7[]  = _("sin atacar…");
static const u8 sOPT_Report_Tentacruel_8[]  = _("OAK: Como si protegieran algo");
static const u8 sOPT_Report_Tentacruel_9[]  = _("en las profundidades.");

#define OPT_REPORT_LINES 10
#define NUM_OPT_REPORTS 10

static const u8 *const sOPT_Reports[NUM_OPT_REPORTS][OPT_REPORT_LINES] =
{
    { sOPT_Report_Clefairy_0, sOPT_Report_Clefairy_1, sOPT_Report_Clefairy_2, sOPT_Report_Clefairy_3, sOPT_Report_Clefairy_4, sOPT_Report_Clefairy_5, sOPT_Report_Clefairy_6, sOPT_Report_Clefairy_7, sOPT_Report_Clefairy_8, sOPT_Report_Clefairy_9 },
    { sOPT_Report_Lapras_0, sOPT_Report_Lapras_1, sOPT_Report_Lapras_2, sOPT_Report_Lapras_3, sOPT_Report_Lapras_4, sOPT_Report_Lapras_5, sOPT_Report_Lapras_6, sOPT_Report_Lapras_7, sOPT_Report_Lapras_8, sOPT_Report_Lapras_9 },
    { sOPT_Report_Ampharos_0, sOPT_Report_Ampharos_1, sOPT_Report_Ampharos_2, sOPT_Report_Ampharos_3, sOPT_Report_Ampharos_4, sOPT_Report_Ampharos_5, sOPT_Report_Ampharos_6, sOPT_Report_Ampharos_7, sOPT_Report_Ampharos_8, sOPT_Report_Ampharos_9 },
    { sOPT_Report_Sudowoodo_0, sOPT_Report_Sudowoodo_1, sOPT_Report_Sudowoodo_2, sOPT_Report_Sudowoodo_3, sOPT_Report_Sudowoodo_4, sOPT_Report_Sudowoodo_5, sOPT_Report_Sudowoodo_6, sOPT_Report_Sudowoodo_7, sOPT_Report_Sudowoodo_8, sOPT_Report_Sudowoodo_9 },
    { sOPT_Report_RedGyarados_0, sOPT_Report_RedGyarados_1, sOPT_Report_RedGyarados_2, sOPT_Report_RedGyarados_3, sOPT_Report_RedGyarados_4, sOPT_Report_RedGyarados_5, sOPT_Report_RedGyarados_6, sOPT_Report_RedGyarados_7, sOPT_Report_RedGyarados_8, sOPT_Report_RedGyarados_9 },
    { sOPT_Report_Unown_0, sOPT_Report_Unown_1, sOPT_Report_Unown_2, sOPT_Report_Unown_3, sOPT_Report_Unown_4, sOPT_Report_Unown_5, sOPT_Report_Unown_6, sOPT_Report_Unown_7, sOPT_Report_Unown_8, sOPT_Report_Unown_9 },
    { sOPT_Report_Snubbull_0, sOPT_Report_Snubbull_1, sOPT_Report_Snubbull_2, sOPT_Report_Snubbull_3, sOPT_Report_Snubbull_4, sOPT_Report_Snubbull_5, sOPT_Report_Snubbull_6, sOPT_Report_Snubbull_7, sOPT_Report_Snubbull_8, sOPT_Report_Snubbull_9 },
    { sOPT_Report_Slowpoke_0, sOPT_Report_Slowpoke_1, sOPT_Report_Slowpoke_2, sOPT_Report_Slowpoke_3, sOPT_Report_Slowpoke_4, sOPT_Report_Slowpoke_5, sOPT_Report_Slowpoke_6, sOPT_Report_Slowpoke_7, sOPT_Report_Slowpoke_8, sOPT_Report_Slowpoke_9 },
    { sOPT_Report_LavenderTower_0, sOPT_Report_LavenderTower_1, sOPT_Report_LavenderTower_2, sOPT_Report_LavenderTower_3, sOPT_Report_LavenderTower_4, sOPT_Report_LavenderTower_5, sOPT_Report_LavenderTower_6, sOPT_Report_LavenderTower_7, sOPT_Report_LavenderTower_8, sOPT_Report_LavenderTower_9 },
    { sOPT_Report_Tentacruel_0, sOPT_Report_Tentacruel_1, sOPT_Report_Tentacruel_2, sOPT_Report_Tentacruel_3, sOPT_Report_Tentacruel_4, sOPT_Report_Tentacruel_5, sOPT_Report_Tentacruel_6, sOPT_Report_Tentacruel_7, sOPT_Report_Tentacruel_8, sOPT_Report_Tentacruel_9 },
};

#endif // GUARD_DATA_TEXT_RADIO_STRINGS_H
