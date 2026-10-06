static const u8 sAdvancedAbility_Technician[] = _(
    "Aumenta x1,5 la potencia base\n"
    "de movimientos de potencia 60\n"
    "o menos. Se aplica después de\n"
    "calcular la potencia variable.");
static const u8 sAdvancedAbility_Intimidate[] = _(
    "Al entrar, baja 1 nivel el Ataque\n"
    "de cada rival sin Sustituto.\n"
    "No afecta a Foco Interno,\n"
    "Revoltoso, Ritmo Propio u Oblivio.");
static const u8 sAdvancedAbility_Drought[] = _(
    "Al entrar, activa el sol 5 turnos;\n"
    "8 si lleva Roca Calor.\n"
    "Fuego x1,5 y Agua x0,5\n"
    "para ambos bandos.");
static const u8 sAdvancedAbility_WaterVeil[] = _(
    "Evita cualquier quemadura.\n"
    "Si obtiene o recupera Velo Agua\n"
    "estando quemado, elimina ese\n"
    "estado.");
static const u8 sAdvancedAbility_Drizzle[] = _(
    "Al entrar, activa lluvia 5 turnos;\n"
    "8 si lleva Roca Lluvia.\n"
    "Agua x1,5 y Fuego x0,5\n"
    "para ambos bandos.");
static const u8 sAdvancedAbility_SandStream[] = _(
    "Al entrar, activa arena 5 turnos;\n"
    "8 si lleva Roca Suave. Daña 1/16\n"
    "por turno salvo inmunidades y sube\n"
    "x1,5 la Def. Esp. de tipo Roca.");
static const u8 sAdvancedAbility_SnowWarning[] = _(
    "Al entrar, activa nieve 5 turnos;\n"
    "8 si lleva Roca Helada. La nieve\n"
    "sube x1,5 la Defensa de los\n"
    "Pokémon de tipo Hielo.");
static const u8 sAdvancedAbility_Levitate[] = _(
    "Inmune a movimientos de Tierra\n"
    "mientras no quede en tierra por\n"
    "Gravedad, Antiaéreo, Arraigo,\n"
    "Bola Férrea u otro efecto.");
static const u8 sAdvancedAbility_Sturdy[] = _(
    "Bloquea movimientos fulminantes.\n"
    "Con la regla Robustez activa, si\n"
    "está a PS completos sobrevive al\n"
    "golpe con 1 PS.");
static const u8 sAdvancedAbility_HugePower[] = _(
    "Duplica el Ataque al calcular el\n"
    "daño de movimientos físicos.\n"
    "No duplica el valor mostrado en la\n"
    "pantalla de características.");
static const u8 sAdvancedAbility_PurePower[] = _(
    "Duplica el Ataque al calcular el\n"
    "daño de movimientos físicos.\n"
    "No duplica el valor mostrado en la\n"
    "pantalla de características.");
static const u8 sAdvancedAbility_Adaptability[] = _(
    "El bonus por usar un movimiento\n"
    "del mismo tipo pasa de x1,5 a x2.\n"
    "No afecta a movimientos de tipos\n"
    "distintos a los del usuario.");
static const u8 sAdvancedAbility_Guts[] = _(
    "Con cualquier problema de estado,\n"
    "los movimientos físicos ganan x1,5.\n"
    "Además, la quemadura no reduce su\n"
    "daño físico.");
static const u8 sAdvancedAbility_MarvelScale[] = _(
    "Con cualquier problema de estado,\n"
    "multiplica la Defensa por x1,5.\n"
    "No aumenta la Defensa Especial.");
static const u8 sAdvancedAbility_SwiftSwim[] = _(
    "Duplica la Velocidad bajo lluvia.\n"
    "El efecto se anula si lleva\n"
    "Parasol Multiuso.");
static const u8 sAdvancedAbility_Chlorophyll[] = _(
    "Duplica la Velocidad bajo sol.\n"
    "El efecto se anula si lleva\n"
    "Parasol Multiuso.");
static const u8 sAdvancedAbility_SandRush[] = _(
    "Duplica la Velocidad durante una\n"
    "tormenta de arena y evita el daño\n"
    "causado por ese clima.");
static const u8 sAdvancedAbility_SlushRush[] = _(
    "Duplica la Velocidad mientras haya\n"
    "granizo o nieve en el campo.");
static const u8 sAdvancedAbility_SpeedBoost[] = _(
    "Al final de cada turno en combate,\n"
    "sube 1 nivel la Velocidad, hasta\n"
    "un máximo de +6 niveles.");
static const u8 sAdvancedAbility_Moxie[] = _(
    "Sube 1 nivel el Ataque por cada\n"
    "rival debilitado directamente por\n"
    "el usuario, hasta un máximo de +6.");
static const u8 sAdvancedAbility_Regenerator[] = _(
    "Al retirarse del combate, recupera\n"
    "1/3 de sus PS máximos. No se activa\n"
    "si ya está a PS completos.");
static const u8 sAdvancedAbility_MagicGuard[] = _(
    "Evita daño que no proceda de un\n"
    "ataque directo: clima, veneno,\n"
    "trampas, objetos o retroceso.");
static const u8 sAdvancedAbility_PoisonHeal[] = _(
    "Si está envenenado, recupera 1/8\n"
    "de sus PS máximos al final del turno\n"
    "en vez de sufrir daño por veneno.");
static const u8 sAdvancedAbility_Multiscale[] = _(
    "Con todos sus PS, reduce a la mitad\n"
    "el daño recibido de los ataques.\n"
    "Deja de actuar tras perder PS.");
static const u8 sAdvancedAbility_Prankster[] = _(
    "Suma +1 de prioridad a movimientos\n"
    "de estado. Los dirigidos contra un\n"
    "rival Siniestro no le afectan.");

static const u8 *const sAdvancedAbilityDescriptions[ABILITIES_COUNT] =
{
    [ABILITY_TECHNICIAN] = sAdvancedAbility_Technician,
    [ABILITY_INTIMIDATE] = sAdvancedAbility_Intimidate,
    [ABILITY_DROUGHT] = sAdvancedAbility_Drought,
    [ABILITY_WATER_VEIL] = sAdvancedAbility_WaterVeil,
    [ABILITY_DRIZZLE] = sAdvancedAbility_Drizzle,
    [ABILITY_SAND_STREAM] = sAdvancedAbility_SandStream,
    [ABILITY_SNOW_WARNING] = sAdvancedAbility_SnowWarning,
    [ABILITY_LEVITATE] = sAdvancedAbility_Levitate,
    [ABILITY_STURDY] = sAdvancedAbility_Sturdy,
    [ABILITY_HUGE_POWER] = sAdvancedAbility_HugePower,
    [ABILITY_PURE_POWER] = sAdvancedAbility_PurePower,
    [ABILITY_ADAPTABILITY] = sAdvancedAbility_Adaptability,
    [ABILITY_GUTS] = sAdvancedAbility_Guts,
    [ABILITY_MARVEL_SCALE] = sAdvancedAbility_MarvelScale,
    [ABILITY_SWIFT_SWIM] = sAdvancedAbility_SwiftSwim,
    [ABILITY_CHLOROPHYLL] = sAdvancedAbility_Chlorophyll,
    [ABILITY_SAND_RUSH] = sAdvancedAbility_SandRush,
    [ABILITY_SLUSH_RUSH] = sAdvancedAbility_SlushRush,
    [ABILITY_SPEED_BOOST] = sAdvancedAbility_SpeedBoost,
    [ABILITY_MOXIE] = sAdvancedAbility_Moxie,
    [ABILITY_REGENERATOR] = sAdvancedAbility_Regenerator,
    [ABILITY_MAGIC_GUARD] = sAdvancedAbility_MagicGuard,
    [ABILITY_POISON_HEAL] = sAdvancedAbility_PoisonHeal,
    [ABILITY_MULTISCALE] = sAdvancedAbility_Multiscale,
    [ABILITY_PRANKSTER] = sAdvancedAbility_Prankster,
};

static const u8 sAdvancedMove_Flamethrower[] = _(
    "10% de quemar al objetivo.\n"
    "No hace contacto. Lo bloquean\n"
    "Protección y efectos equivalentes.");
static const u8 sAdvancedMove_RainDance[] = _(
    "Lluvia: 5 turnos; 8 con Roca\n"
    "Lluvia. Agua x1,5 y Fuego x0,5.\n"
    "Afecta a ambos bandos.");
static const u8 sAdvancedMove_Acrobatics[] = _(
    "Potencia 110 si no lleva objeto\n"
    "o si consume una Gema Voladora.\n"
    "Hace contacto. Prioridad 0.");
static const u8 sAdvancedMove_Protect[] = _(
    "Prioridad +4. Bloquea casi todos\n"
    "los ataques durante ese turno.\n"
    "Repetir: 100%, 33%, 11% y 4%.");
static const u8 sAdvancedMove_BulletSeed[] = _(
    "Golpea 2-5 veces: 35%, 35%,\n"
    "15% y 15%. Cada golpe: 25.\n"
    "Dado Trucado: 4-5; Enlace\n"
    "Destreza: 5. Es balístico.");
static const u8 sAdvancedMove_Psychic[] = _(
    "10% de bajar 1 nivel la Defensa\n"
    "Especial rival. No hace contacto.\n"
    "Lo bloquean Protección y efectos\n"
    "equivalentes.");
static const u8 sAdvancedMove_Thunderbolt[] = _(
    "10% de paralizar al objetivo.\n"
    "No hace contacto. Lo bloquean\n"
    "Protección y efectos equivalentes.");
static const u8 sAdvancedMove_IceBeam[] = _(
    "10% de causar helada al objetivo.\n"
    "No hace contacto. Lo bloquean\n"
    "Protección y efectos equivalentes.");
static const u8 sAdvancedMove_SludgeBomb[] = _(
    "30% de envenenar al objetivo.\n"
    "Es un movimiento balístico y no\n"
    "hace contacto.");
static const u8 sAdvancedMove_ShadowBall[] = _(
    "20% de bajar 1 nivel la Defensa\n"
    "Especial rival. Es balístico y no\n"
    "hace contacto.");
static const u8 sAdvancedMove_RockSlide[] = _(
    "30% de hacer retroceder a cada\n"
    "objetivo. Golpea a ambos rivales\n"
    "y no hace contacto.");
static const u8 sAdvancedMove_AirSlash[] = _(
    "30% de hacer retroceder. Es un\n"
    "movimiento de corte y no hace\n"
    "contacto.");
static const u8 sAdvancedMove_Scald[] = _(
    "30% de quemar al objetivo. Puede\n"
    "usarse estando helado para eliminar\n"
    "ese estado. No hace contacto.");
static const u8 sAdvancedMove_EnergyBall[] = _(
    "10% de bajar 1 nivel la Defensa\n"
    "Especial rival. Es balístico y no\n"
    "hace contacto.");
static const u8 sAdvancedMove_Crunch[] = _(
    "20% de bajar 1 nivel la Defensa.\n"
    "Hace contacto y cuenta como mordisco\n"
    "para habilidades relacionadas.");
static const u8 sAdvancedMove_IronHead[] = _(
    "30% de hacer retroceder al objetivo.\n"
    "Hace contacto. El retroceso solo\n"
    "sirve si el usuario actúa primero.");
static const u8 sAdvancedMove_Waterfall[] = _(
    "20% de hacer retroceder al objetivo.\n"
    "Hace contacto. El retroceso solo\n"
    "sirve si el usuario actúa primero.");
static const u8 sAdvancedMove_AncientPower[] = _(
    "10% de subir 1 nivel Ataque, Defensa,\n"
    "At. Esp., Def. Esp. y Velocidad.\n"
    "No hace contacto.");
static const u8 sAdvancedMove_CloseCombat[] = _(
    "Tras golpear, baja 1 nivel la Defensa\n"
    "y la Defensa Especial del usuario.\n"
    "Hace contacto.");
static const u8 sAdvancedMove_Superpower[] = _(
    "Tras golpear, baja 1 nivel el Ataque\n"
    "y la Defensa del usuario.\n"
    "Hace contacto.");
static const u8 sAdvancedMove_Overheat[] = _(
    "Tras golpear, baja 2 niveles el\n"
    "Ataque Especial del usuario.\n"
    "No hace contacto.");
static const u8 sAdvancedMove_DracoMeteor[] = _(
    "Tras golpear, baja 2 niveles el\n"
    "Ataque Especial del usuario.\n"
    "No hace contacto.");
static const u8 sAdvancedMove_SolarBeam[] = _(
    "Carga un turno; ataca al siguiente.\n"
    "Bajo sol ataca de inmediato. Lluvia,\n"
    "arena, nieve o niebla reducen su\n"
    "potencia a la mitad.");
static const u8 sAdvancedMove_Thunder[] = _(
    "30% de paralizar. Bajo lluvia no\n"
    "comprueba precisión; bajo sol su\n"
    "precisión baja al 50%. Puede golpear\n"
    "a objetivos en pleno vuelo.");
static const u8 sAdvancedMove_Blizzard[] = _(
    "10% de causar helada. Bajo granizo\n"
    "o nieve no comprueba precisión.\n"
    "Golpea a ambos rivales.");
static const u8 sAdvancedMove_SwordsDance[] = _(
    "Sube 2 niveles el Ataque del usuario,\n"
    "hasta un máximo de +6. Cuenta como\n"
    "movimiento de danza.");
static const u8 sAdvancedMove_NastyPlot[] = _(
    "Sube 2 niveles el Ataque Especial\n"
    "del usuario, hasta un máximo de +6.");
static const u8 sAdvancedMove_CalmMind[] = _(
    "Sube 1 nivel el Ataque Especial y\n"
    "la Defensa Especial del usuario,\n"
    "hasta un máximo de +6.");
static const u8 sAdvancedMove_DragonDance[] = _(
    "Sube 1 nivel el Ataque y la Velocidad\n"
    "del usuario, hasta un máximo de +6.\n"
    "Cuenta como movimiento de danza.");

static const u8 *const sAdvancedMoveDescriptions[MOVES_COUNT_ALL] =
{
    [MOVE_FLAMETHROWER] = sAdvancedMove_Flamethrower,
    [MOVE_RAIN_DANCE] = sAdvancedMove_RainDance,
    [MOVE_ACROBATICS] = sAdvancedMove_Acrobatics,
    [MOVE_PROTECT] = sAdvancedMove_Protect,
    [MOVE_BULLET_SEED] = sAdvancedMove_BulletSeed,
    [MOVE_PSYCHIC] = sAdvancedMove_Psychic,
    [MOVE_THUNDERBOLT] = sAdvancedMove_Thunderbolt,
    [MOVE_ICE_BEAM] = sAdvancedMove_IceBeam,
    [MOVE_SLUDGE_BOMB] = sAdvancedMove_SludgeBomb,
    [MOVE_SHADOW_BALL] = sAdvancedMove_ShadowBall,
    [MOVE_ROCK_SLIDE] = sAdvancedMove_RockSlide,
    [MOVE_AIR_SLASH] = sAdvancedMove_AirSlash,
    [MOVE_SCALD] = sAdvancedMove_Scald,
    [MOVE_ENERGY_BALL] = sAdvancedMove_EnergyBall,
    [MOVE_CRUNCH] = sAdvancedMove_Crunch,
    [MOVE_IRON_HEAD] = sAdvancedMove_IronHead,
    [MOVE_WATERFALL] = sAdvancedMove_Waterfall,
    [MOVE_ANCIENT_POWER] = sAdvancedMove_AncientPower,
    [MOVE_CLOSE_COMBAT] = sAdvancedMove_CloseCombat,
    [MOVE_SUPERPOWER] = sAdvancedMove_Superpower,
    [MOVE_OVERHEAT] = sAdvancedMove_Overheat,
    [MOVE_DRACO_METEOR] = sAdvancedMove_DracoMeteor,
    [MOVE_SOLAR_BEAM] = sAdvancedMove_SolarBeam,
    [MOVE_THUNDER] = sAdvancedMove_Thunder,
    [MOVE_BLIZZARD] = sAdvancedMove_Blizzard,
    [MOVE_SWORDS_DANCE] = sAdvancedMove_SwordsDance,
    [MOVE_NASTY_PLOT] = sAdvancedMove_NastyPlot,
    [MOVE_CALM_MIND] = sAdvancedMove_CalmMind,
    [MOVE_DRAGON_DANCE] = sAdvancedMove_DragonDance,
};
