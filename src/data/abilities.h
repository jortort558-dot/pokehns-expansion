const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
        .description = COMPOUND_STRING("Sin habilidad especial."),
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
        .name = _("Hedor"),
        .description = COMPOUND_STRING("Puede hacer retroceder\n"
        "al rival."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Llovizna"),
        .description = COMPOUND_STRING("Invoca lluvia al entrar\n"
        "en combate."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Motor Impulso"),
        .description = COMPOUND_STRING("Aumenta la Velocidad\n"
        "cada turno."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Armadura Batalla"),
        .description = COMPOUND_STRING("Bloquea los golpes\n"
        "críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Robustez"),
        .description = COMPOUND_STRING("Evita ser abatido\n"
        "de un golpe KO."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Humedad"),
        .description = COMPOUND_STRING("Evita la autodestrucción\n"
        "en combate."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
        .name = _("Flexibilidad"),
        .description = COMPOUND_STRING("Evita la parálisis."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
        .name = _("Velo Arena"),
        .description = COMPOUND_STRING("Sube la evasión en\n"
        "tormenta de arena."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Estática"),
        .description = COMPOUND_STRING("Puede paralizar al\n"
        "contacto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Absorbe Electr."),
        .description = COMPOUND_STRING("Convierte la electricidad\n"
        "en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Absorbe Agua"),
        .description = COMPOUND_STRING("Convierte el agua\n"
        "en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivio"),
        .description = COMPOUND_STRING("Evita la atracción\n"
        "y la provocación."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Nublado"),
        .description = COMPOUND_STRING("Anula los efectos\n"
        "del clima."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Ojo Compuesto"),
        .description = COMPOUND_STRING("Aumenta la precisión\n"
        "de los movimientos."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnio"),
        .description = COMPOUND_STRING("Evita el sueño."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Cambio Color"),
        .description = COMPOUND_STRING("Toma el tipo del último\n"
        "ataque recibido."),
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
        .name = _("Inmunidad"),
        .description = COMPOUND_STRING("Evita el envenenamiento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
        .name = _("Absorbefuego"),
        .description = COMPOUND_STRING("Sube el Fuego si recibe\n"
        "ataques de ese tipo."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Polvo Escudo"),
        .description = COMPOUND_STRING("Evita los efectos\n"
        "secundarios de ataques."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
        .name = _("Ritmo Propio"),
        .description = COMPOUND_STRING("Evita la confusión."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
        .name = _("Ventosas"),
        .description = COMPOUND_STRING("Fija el cuerpo para\n"
        "evitar expulsiones."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidación"),
        .description = COMPOUND_STRING("Baja el Ataque del\n"
        "rival al entrar."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Sombra Trampa"),
        .description = COMPOUND_STRING("Evita que el rival\n"
        "huya del combate."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Piel Tosca"),
        .description = COMPOUND_STRING("Hiere al rival al\n"
        "contacto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Guardián"),
        .description = COMPOUND_STRING("Solo le dañan ataques\n"
        "súpereficaces."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitación"),
        .description = COMPOUND_STRING("Inmune a los ataques\n"
        "de tipo Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Espora Efecto"),
        .description = COMPOUND_STRING("Puede dormir, paralizar\n"
        "o envenenar al contacto."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Sincronía"),
        .description = COMPOUND_STRING("Contagia envenenamiento,\n"
        "parálisis o quemaduras."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Cuerpo Puro"),
        .description = COMPOUND_STRING("Evita que el rival baje\n"
        "las características."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Curación Natural"),
        .description = COMPOUND_STRING("Cura problemas de estado\n"
        "al cambiar."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Pararrayos"),
        .description = COMPOUND_STRING("Atrae y anula los\n"
        "ataques Eléctricos."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Don Serenidad"),
        .description = COMPOUND_STRING("Aumenta las opciones de\n"
        "efectos secundarios."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Nado Rápido"),
        .description = COMPOUND_STRING("Aumenta la Velocidad\n"
        "bajo la lluvia."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Clorofila"),
        .description = COMPOUND_STRING("Aumenta la Velocidad\n"
        "bajo el sol."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Iluminar"),
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
        "de hallar Pokémon."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Calcador"),
        .description = COMPOUND_STRING("Copia la habilidad\n"
        "del rival."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Gran Potencia"),
        .description = COMPOUND_STRING("Duplica la estadística\n"
        "de Ataque."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Punto Venenoso"),
        .description = COMPOUND_STRING("Puede envenenar al\n"
        "contacto."),
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
        .name = _("Foco Interno"),
        .description = COMPOUND_STRING("Evita el retroceso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
        .name = _("Armadura Magma"),
        .description = COMPOUND_STRING("Evita el congelamiento."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
        .name = _("Velo Acuático"),
        .description = COMPOUND_STRING("Evita las quemaduras."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
        .name = _("Magnetismo"),
        .description = COMPOUND_STRING("Impide huir a los\n"
        "Pokémon de Acero."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Insonorización"),
        .description = COMPOUND_STRING("Inmune a movimientos\n"
        "sonoros."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Coge Lluvia"),
        .description = COMPOUND_STRING("Recupera PS de forma\n"
        "gradual bajo lluvia."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Torrearena"),
        .description = COMPOUND_STRING("Crea una tormenta de\n"
        "arena en combate."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Presión"),
        .description = COMPOUND_STRING("Hace que el rival gaste\n"
        "más PP de lo habitual."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Grueso Gordo"),
        .description = COMPOUND_STRING("Atenúa ataques de tipo\n"
        "Fuego e Hielo."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Madrugar"),
        .description = COMPOUND_STRING("Se despierta el doble\n"
        "de rápido."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Cuerpo Llama"),
        .description = COMPOUND_STRING("Puede quemar al\n"
        "contacto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Fuga"),
        .description = COMPOUND_STRING("Garantiza la huida ante\n"
        "Pokémon salvajes."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Visión Lince"),
        .description = COMPOUND_STRING("Evita que baje la\n"
        "precisión."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hipercorte"),
        .description = COMPOUND_STRING("Evita que el rival baje\n"
        "el Ataque."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Recoger"),
        .description = COMPOUND_STRING("Puede recoger objetos\n"
        "tras un combate."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Holgazán"),
        .description = COMPOUND_STRING("Solo ataca cada dos\n"
        "turnos."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Entusiasmo"),
        .description = COMPOUND_STRING("Aumenta el Ataque a costa\n"
        "de la precisión."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Encanto"),
        .description = COMPOUND_STRING("Puede enamorar al\n"
        "contacto."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Sube el Ataque Especial\n"
        "junto a Menos."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Menos"),
        .description = COMPOUND_STRING("Sube el Ataque Especial\n"
        "junto a Plus."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Predicción"),
        .description = COMPOUND_STRING("Se transforma según el\n"
        "tiempo atmosférico."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Pegajoso"),
        .description = COMPOUND_STRING("Evita el robo del objeto\n"
        "que lleva equipado."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Mudar"),
        .description = COMPOUND_STRING("Puede curar problemas de\n"
        "estado al mudar."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Agallas"),
        .description = COMPOUND_STRING("Sube el Ataque si sufre\n"
        "un problema de estado."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Escama Especial"),
        .description = COMPOUND_STRING("Sube la Defensa si sufre\n"
        "un problema de estado."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Rezuma"),
        .description = COMPOUND_STRING("Daña al rival si este\n"
        "intenta drenar PS."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Espesura"),
        .description = COMPOUND_STRING("Potencia ataques Planta\n"
        "cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Mar Llamas"),
        .description = COMPOUND_STRING("Potencia ataques Fuego\n"
        "cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrente"),
        .description = COMPOUND_STRING("Potencia ataques Agua\n"
        "cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Enjambre"),
        .description = COMPOUND_STRING("Potencia ataques Bicho\n"
        "cuando le quedan pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Roca Dura"),
        .description = COMPOUND_STRING("Protege contra el daño\n"
        "de retroceso."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Sequía"),
        .description = COMPOUND_STRING("Crea un sol abrasador\n"
        "al entrar en combate."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Trampa Arena"),
        .description = COMPOUND_STRING("Evita que los rivales\n"
        "puedan huir."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Espíritu Vital"),
        .description = COMPOUND_STRING("Evita el sueño."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("Humo Blanco"),
        .description = COMPOUND_STRING("Evita que el rival baje\n"
        "las características."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pura Potencia"),
        .description = COMPOUND_STRING("Duplica la estadística\n"
        "de Ataque."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Armadura Concha"),
        .description = COMPOUND_STRING("Bloquea los golpes\n"
        "críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Éter"),
        .description = COMPOUND_STRING("Anula los efectos\n"
        "del clima."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Pies Largos"),
        .description = COMPOUND_STRING("Sube la evasión si el\n"
        "Pokémon está confuso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Eléctrico"),
        .description = COMPOUND_STRING("Sube la Velocidad si\n"
        "recibe ataques Eléctricos."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalidad"),
        .description = COMPOUND_STRING("Sube Ataque ante el mismo\n"
        "sexo y baja ante el opuesto."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Constante"),
        .description = COMPOUND_STRING("Sube la Velocidad si el\n"
        "Pokémon retrocede."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Velo Nieve"),
        .description = COMPOUND_STRING("Sube la evasión si hay\n"
        "tormenta de nieve."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gula"),
        .description = COMPOUND_STRING("Consume bayas antes de\n"
        "lo habitual."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Punto Ira"),
        .description = COMPOUND_STRING("Sube el Ataque al máximo\n"
        "tras recibir un crítico."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Ligereza"),
        .description = COMPOUND_STRING("Sube la Velocidad si pierde\n"
        "el objeto equipado."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Ignífugo"),
        .description = COMPOUND_STRING("Atenúa el daño del fuego\n"
        "y de quemaduras."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simpleza"),
        .description = COMPOUND_STRING("Duplica las variaciones\n"
        "de características."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Piel Seca"),
        .description = COMPOUND_STRING("Recupera PS con agua y\n"
        "sufre más con fuego."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Descarga"),
        .description = COMPOUND_STRING("Ajusta su Ataque según\n"
        "las defensas rivales."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Puño Férreo"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de puñetazos."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Cura Veneno"),
        .description = COMPOUND_STRING("Recupera PS si resulta\n"
        "envenenado."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptable"),
        .description = COMPOUND_STRING("Potencia movimientos del\n"
        "mismo tipo del usuario."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Enlace Destreza"),
        .description = COMPOUND_STRING("Asegura que los golpes\n"
        "multigolpe acierten 5 veces."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hidratación"),
        .description = COMPOUND_STRING("Cura problemas de estado\n"
        "si está lloviendo."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Energía Solar"),
        .description = COMPOUND_STRING("Sube At. Esp. con sol,\n"
        "pero pierde PS."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Pies Rápidos"),
        .description = COMPOUND_STRING("Sube la Velocidad si sufre\n"
        "un problema de estado."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalizador"),
        .description = COMPOUND_STRING("Todos los movimientos\n"
        "pasan a tipo Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Francotirador"),
        .description = COMPOUND_STRING("Potencia más los golpes\n"
        "críticos."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Guardia Mágica"),
        .description = COMPOUND_STRING("Solo sufre daño por\n"
        "ataques directos."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("Sin Guardia"),
        .description = COMPOUND_STRING("Todos los ataques de ambos\n"
        "bancos aciertan."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Remolón"),
        .description = COMPOUND_STRING("Ataca siempre en último\n"
        "lugar en su prioridad."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Técnico"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "más débiles."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Guardia Hoja"),
        .description = COMPOUND_STRING("Evita problemas de estado\n"
        "cuando hay sol."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Torpe"),
        .description = COMPOUND_STRING("No puede usar objetos\n"
        "equipados."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Rompemoldes"),
        .description = COMPOUND_STRING("Ignora las habilidades\n"
        "defensivas del rival."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Suerte"),
        .description = COMPOUND_STRING("Aumenta la probabilidad\n"
        "de asestar críticos."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Consecuencias"),
        .description = COMPOUND_STRING("Daña al rival al caer\n"
        "debilitado por contacto."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipación"),
        .description = COMPOUND_STRING("Detecta si el rival tiene\n"
        "ataques peligrosos."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Premonición"),
        .description = COMPOUND_STRING("Revela el movimiento más\n"
        "potente del rival."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Ignorante"),
        .description = COMPOUND_STRING("Ignora los cambios de\n"
        "características rivales."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Lente de Color"),
        .description = COMPOUND_STRING("Potencia ataques que no\n"
        "son muy eficaces."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filtro"),
        .description = COMPOUND_STRING("Reduce el daño de los\n"
        "ataques súpereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Inicio Lento"),
        .description = COMPOUND_STRING("Reduce Ataque y Velocidad\n"
        "durante 5 turnos."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Revoltoso"),
        .description = COMPOUND_STRING("Permite golpear a tipos\n"
        "Fantasma con Normal/Lucha."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Imán Agua"),
        .description = COMPOUND_STRING("Atrae ataques de Agua y\n"
        "sube su Ataque Especial."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Cuerpo Hielo"),
        .description = COMPOUND_STRING("Recupera PS de forma\n"
        "gradual bajo la nieve."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Roca Sólida"),
        .description = COMPOUND_STRING("Reduce el daño de los\n"
        "ataques súpereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Granizo"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Invoca nieve o granizo\n"
        "al entrar en combate."),
    #else
        .description = COMPOUND_STRING("Invoca nieve o granizo\n"
        "al entrar en combate."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Colecta Miel"),
        .description = COMPOUND_STRING("Puede recolectar Miel\n"
        "tras el combate."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Cacheo"),
        .description = COMPOUND_STRING("Permite ver el objeto\n"
        "que lleva el rival."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Temerario"),
        .description = COMPOUND_STRING("Potencia ataques que causan\n"
        "daño de retroceso."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitipo"),
        .description = COMPOUND_STRING("Cambia su tipo según la\n"
        "Tabla que lleve."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
        .name = _("Don Floral"),
        .description = COMPOUND_STRING("Potencia a los aliados si\n"
        "hace sol."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Mal Sueño"),
        .description = COMPOUND_STRING("Daña a los rivales que\n"
        "estén dormidos."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Carterista"),
        .description = COMPOUND_STRING("Roba el objeto al rival\n"
        "si recibe contacto."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Fuerza Bruta"),
        .description = COMPOUND_STRING("Sube potencia anulando\n"
        "efectos secundarios."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contrario"),
        .description = COMPOUND_STRING("Invierte los cambios de\n"
        "características."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Tensión"),
        .description = COMPOUND_STRING("Impide al rival consumir\n"
        "bayas."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Desafío"),
        .description = COMPOUND_STRING("Sube mucho el Ataque si el\n"
        "rival baja sus estadísticas."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Derrotista"),
        .description = COMPOUND_STRING("Baja Ataque y At. Esp.\n"
        "si los PS bajan a la mitad."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cuerpo Maldito"),
        .description = COMPOUND_STRING("Puede anular el ataque\n"
        "que le golpee."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Sanador"),
        .description = COMPOUND_STRING("Puede curar problemas de\n"
        "estado de sus aliados."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Guardia Amigo"),
        .description = COMPOUND_STRING("Reduce el daño que sufren\n"
        "sus aliados."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Armadura Frágil"),
        .description = COMPOUND_STRING("Baja Defensa y sube la\n"
        "Velocidad al ser golpeado."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Metal Pesado"),
        .description = COMPOUND_STRING("Duplica el peso del\n"
        "Pokémon."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Metal Ligero"),
        .description = COMPOUND_STRING("Reduce a la mitad el peso\n"
        "del Pokémon."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiescama"),
        .description = COMPOUND_STRING("Reduce el daño si tiene\n"
        "todos los PS al máximo."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Potencia Tóxica"),
        .description = COMPOUND_STRING("Aumenta el Ataque si está\n"
        "envenenado."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Impulso Ardiente"),
        .description = COMPOUND_STRING("Aumenta el At. Esp. si\n"
        "está quemado."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Cosecha"),
        .description = COMPOUND_STRING("Puede recuperar bayas ya\n"
        "consumidas."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepatía"),
        .description = COMPOUND_STRING("Elude los ataques de sus\n"
        "compañeros en dobles."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Variable"),
        .description = COMPOUND_STRING("Sube una estadística y baja\n"
        "otra cada turno."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Sobretodo"),
        .description = COMPOUND_STRING("Inmune al clima y a ataques\n"
        "de polvo o esporas."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Toque Venenoso"),
        .description = COMPOUND_STRING("Puede envenenar al rival\n"
        "al contacto."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regeneración"),
        .description = COMPOUND_STRING("Recupera un tercio de PS\n"
        "al cambiar."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Pectorales"),
        .description = COMPOUND_STRING("Evita que el rival baje\n"
        "la Defensa."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Ímpetu Arena"),
        .description = COMPOUND_STRING("Duplica la Velocidad en\n"
        "tormenta de arena."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Piel Mística"),
        .description = COMPOUND_STRING("Dificulta que le afecten\n"
        "ataques de estado."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analítico"),
        .description = COMPOUND_STRING("Aumenta la potencia si ataca\n"
        "en último lugar."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Ilusión"),
        .description = COMPOUND_STRING("Adopta la apariencia del\n"
        "último Pokémon del equipo."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Impostor"),
        .description = COMPOUND_STRING("Se transforma en el rival\n"
        "al entrar en combate."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrador"),
        .description = COMPOUND_STRING("Atraviesa barreras y\n"
        "sustitutos del rival."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Momia"),
        .description = COMPOUND_STRING("Contagia la habilidad\n"
        "Momia al contacto."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Agresividad"),
        .description = COMPOUND_STRING("Sube el Ataque al noquear\n"
        "a un rival."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Templado"),
        .description = COMPOUND_STRING("Sube el Ataque si recibe un\n"
        "ataque de tipo Siniestro."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Turbador"),
        .description = COMPOUND_STRING("Sube Velocidad ante tipos\n"
        "Bicho, Fantasma y Siniestro."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Rebote Mágico"),
        .description = COMPOUND_STRING("Devuelve al rival los\n"
        "ataques de estado."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Come Hierba"),
        .description = COMPOUND_STRING("Inmune a Planta y sube su\n"
        "Ataque al recibirla."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Bromista"),
        .description = COMPOUND_STRING("Otorga prioridad a los\n"
        "movimientos de estado."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Fuerza Arena"),
        .description = COMPOUND_STRING("Potencia ataques Tierra,\n"
        "Roca y Acero en arena."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Puas Hierro"),
        .description = COMPOUND_STRING("Daña al rival que le golpee\n"
        "con contacto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Modo Zen"),
        .description = COMPOUND_STRING("Cambia de forma si sus PS\n"
        "bajan de la mitad."),
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
        .name = _("Estr. Victoria"),
        .description = COMPOUND_STRING("Aumenta la precisión de\n"
        "todo el equipo."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboflama"),
        .description = COMPOUND_STRING("Ignora las habilidades\n"
        "defensivas del rival."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravoltio"),
        .description = COMPOUND_STRING("Ignora las habilidades\n"
        "defensivas del rival."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Velo Aromático"),
        .description = COMPOUND_STRING("Protege a los aliados de\n"
        "efectos mentales."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Velo Floral"),
        .description = COMPOUND_STRING("Evita que bajen los stats\n"
        "de aliados tipo Planta."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Bolsa Carrillo"),
        .description = COMPOUND_STRING("Restaura PS al consumir\n"
        "cualquier baya."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Multicolor"),
        .description = COMPOUND_STRING("Cambia su tipo al del ataque\n"
        "que vaya a usar."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Piel Peluda"),
        .description = COMPOUND_STRING("Reduce a la mitad el daño\n"
        "físico recibido."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Mago"),
        .description = COMPOUND_STRING("Roba el objeto al rival\n"
        "al golpearle."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Antibalas"),
        .description = COMPOUND_STRING("Inmune a bombas, balas y\n"
        "proyectiles."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitivo"),
        .description = COMPOUND_STRING("Sube mucho el At. Esp. si\n"
        "el rival baja sus stats."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Mandíbula Fuerte"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de mordiscos."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Frigorífico"),
        .description = COMPOUND_STRING("Movimientos Normales pasan\n"
        "a Hielo y se potencian."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Velo Dulce"),
        .description = COMPOUND_STRING("Evita que los aliados se\n"
        "queden dormidos."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Cambio Forma"),
        .description = COMPOUND_STRING("Cambia de forma según el\n"
        "movimiento que use."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
        .name = _("Alas Vendaval"),
        .description = COMPOUND_STRING("Otorga prioridad a ataques\n"
        "Volador con PS al máximo."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Megalanzador"),
        .description = COMPOUND_STRING("Potencia los ataques de\n"
        "pulsos y auras."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Piel Herbácea"),
        .description = COMPOUND_STRING("Sube la Defensa en Campo\n"
        "de Hierba."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Simbiosis"),
        .description = COMPOUND_STRING("Pasa su objeto al aliado\n"
        "si este consume el suyo."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Garras Fuertes"),
        .description = COMPOUND_STRING("Potencia los ataques que\n"
        "hacen contacto."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Feérico"),
        .description = COMPOUND_STRING("Movimientos Normales pasan\n"
        "a Hada y se potencian."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Viscoso"),
        .description = COMPOUND_STRING("Baja la Velocidad del rival\n"
        "al contacto."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Viento"),
        .description = COMPOUND_STRING("Movimientos Normales pasan\n"
        "a Volador y se potencian."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Lazo Parental"),
        .description = COMPOUND_STRING("La cría ataca también tras\n"
        "el primer golpe."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Aura Oscura"),
        .description = COMPOUND_STRING("Potencia los ataques de\n"
        "tipo Siniestro en combate."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Aura Feérica"),
        .description = COMPOUND_STRING("Potencia los ataques de\n"
        "tipo Hada en combate."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Antiura"),
        .description = COMPOUND_STRING("Invierte el efecto de las\n"
        "auras Oscura y Hada."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Mar Primigenio"),
        .description = COMPOUND_STRING("Provoca un diluvio que\n"
        "anula ataques de Fuego."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Tierra Desolada"),
        .description = COMPOUND_STRING("Provoca un sol abrasador\n"
        "que anula ataques de Agua."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Corriente"),
        .description = COMPOUND_STRING("Provoca turbulencias que\n"
        "protegen a tipos Volador."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("STAMINA"),
        .description = COMPOUND_STRING("Sube la Defensa cada vez\n"
        "que recibe un golpe."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("WIMP OUT"),
        .description = COMPOUND_STRING("Huye o cambia de Pokémon si\n"
        "los PS bajan de la mitad."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("EMERGENCY EXIT"),
        .description = COMPOUND_STRING("Cambia de Pokémon si los\n"
        "PS bajan de la mitad."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("WATER COMPACTION"),
        .description = COMPOUND_STRING("Sube mucho la Defensa si\n"
        "recibe un ataque de Agua."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("MERCILESS"),
        .description = COMPOUND_STRING("Asesta golpes críticos si el\n"
        "rival está envenenado."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("SHIELDS DOWN"),
        .description = COMPOUND_STRING("Rompe su coraza si los PS\n"
        "bajan de la mitad."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
        .name = _("Acecho"),
        .description = COMPOUND_STRING("Duplica el daño si el rival\n"
        "acaba de ser cambiado."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Burbuja Agua"),
        .description = COMPOUND_STRING("Reduce el daño de Fuego y\n"
        "potencia los de Agua."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Metalúrgico"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de tipo Acero."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserker"),
        .description = COMPOUND_STRING("Sube el At. Esp. cuando sus\n"
        "PS bajan de la mitad."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Ímpetu Nieve"),
        .description = COMPOUND_STRING("Duplica la Velocidad en\n"
        "tormenta de nieve."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Largo Alcance"),
        .description = COMPOUND_STRING("Usa ataques sin hacer\n"
        "contacto directo."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Voz Acuática"),
        .description = COMPOUND_STRING("Movimientos de sonido pasan\n"
        "a ser de tipo Agua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triaje"),
        .description = COMPOUND_STRING("Otorga gran prioridad a los\n"
        "ataques curativos."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanización"),
        .description = COMPOUND_STRING("Movimientos Normales pasan\n"
        "a Eléctrico y se potencian."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surf Eléctrico"),
        .description = COMPOUND_STRING("Duplica la Velocidad en\n"
        "Campo Eléctrico."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Cardumen"),
        .description = COMPOUND_STRING("Forma un banco enorme si\n"
        "tiene suficientes PS."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
        .name = _("Disfraz"),
        .description = COMPOUND_STRING("Protege totalmente de un\n"
        "único golpe."),
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
        .name = _("Lazo de Combate"),
        .description = COMPOUND_STRING("Adopta la Forma Ash al\n"
        "derrotar a un rival."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
        .name = _("Construir Fuerza"),
        .description = COMPOUND_STRING("Pasa a su Forma Completa\n"
        "si los PS bajan de mitad."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
        .name = _("Corrosión"),
        .description = COMPOUND_STRING("Permite envenenar a tipos\n"
        "Acero y Veneno."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Comatoso"),
        .description = COMPOUND_STRING("Actúa como si estuviera\n"
        "siempre dormido."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
        .name = _("Majestad Regia"),
        .description = COMPOUND_STRING("Bloquea los movimientos\n"
        "con prioridad rivales."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Reflejar Daño"),
        .description = COMPOUND_STRING("Daña al rival al caer por\n"
        "la cantidad de PS perdida."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Bailarín"),
        .description = COMPOUND_STRING("Repite inmediatamente los\n"
        "movimientos de danza."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Batería"),
        .description = COMPOUND_STRING("Sube el At. Esp. de sus\n"
        "aliados en combate."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Pelusa"),
        .description = COMPOUND_STRING("Mitiga golpes físicos pero\n"
        "es débil al fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Deslumbrante"),
        .description = COMPOUND_STRING("Bloquea los ataques con\n"
        "prioridad del rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Alma Corazón"),
        .description = COMPOUND_STRING("Sube el At. Esp. cada vez\n"
        "que un Pokémon cae."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Cabello Enredado"),
        .description = COMPOUND_STRING("Baja la Velocidad del rival\n"
        "al contacto."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receptor"),
        .description = COMPOUND_STRING("Hereda la habilidad de un\n"
        "aliado debilitado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Poder Alquimia"),
        .description = COMPOUND_STRING("Hereda la habilidad de un\n"
        "aliado debilitado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Ultraimpulso"),
        .description = COMPOUND_STRING("Sube la estadística más alta\n"
        "al debilitar un rival."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("Sistema RKS"),
        .description = COMPOUND_STRING("Cambia su tipo según el\n"
        "Disco que lleve."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
        .name = _("Electricidad"),
        .description = COMPOUND_STRING("Crea un Campo Eléctrico\n"
        "al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psíquico"),
        .description = COMPOUND_STRING("Crea un Campo Psíquico\n"
        "al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Niebla"),
        .description = COMPOUND_STRING("Crea un Campo de Niebla\n"
        "al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Hierba"),
        .description = COMPOUND_STRING("Crea un Campo de Hierba\n"
        "al entrar en combate."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Cuerpo Férreo"),
        .description = COMPOUND_STRING("Evita que el rival baje\n"
        "sus características."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Escudo Sombra"),
        .description = COMPOUND_STRING("Reduce el daño si tiene\n"
        "todos los PS al máximo."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Armadura Prisma"),
        .description = COMPOUND_STRING("Reduce el daño de los\n"
        "ataques súpereficaces."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neurofuerza"),
        .description = COMPOUND_STRING("Potencia aún más los ataques\n"
        "súpereficaces."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Espada Valiente"),
        .description = COMPOUND_STRING("Sube el Ataque al entrar\n"
        "en combate."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Escudo Constante"),
        .description = COMPOUND_STRING("Sube la Defensa al entrar\n"
        "en combate."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LIBERO"),
        .description = COMPOUND_STRING("Cambia su tipo al del ataque\n"
        "que vaya a usar."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Busca Bola"),
        .description = COMPOUND_STRING("Recupera la primera Poké\n"
        "Ball que haya fallado."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Plumón Algodón"),
        .description = COMPOUND_STRING("Baja la Velocidad de todos\n"
        "al ser golpeado."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Cola Hélice"),
        .description = COMPOUND_STRING("Ignora las habilidades que\n"
        "atraen ataques."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Armadura Espejo"),
        .description = COMPOUND_STRING("Devuelve las bajadas de\n"
        "estadísticas al rival."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Misil Tragado"),
        .description = COMPOUND_STRING("Atrapa presas y contraataca\n"
        "al ser golpeado."),
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
        .name = _("Valiente"),
        .description = COMPOUND_STRING("Ignora las habilidades que\n"
        "atraen ataques."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Motor Vapor"),
        .description = COMPOUND_STRING("Sube al máximo la Velocidad\n"
        "con Fuego o Agua."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Potencia ataques de sonido\n"
        "y resiste los del rival."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Escupir Arena"),
        .description = COMPOUND_STRING("Crea una tormenta de arena\n"
        "al recibir un golpe."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Escamas Hielo"),
        .description = COMPOUND_STRING("Reduce a la mitad el daño\n"
        "especial recibido."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Madurar"),
        .description = COMPOUND_STRING("Duplica los efectos de las\n"
        "bayas que consume."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Cara Hielo"),
        .description = COMPOUND_STRING("Bloquea un golpe físico y\n"
        "regenera con granizo."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
        .name = _("Punto Potencia"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de sus aliados."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimetismo"),
        .description = COMPOUND_STRING("Cambia su tipo según el\n"
        "terreno de combate."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Rompe Pantallas"),
        .description = COMPOUND_STRING("Elimina pantallas como\n"
        "Reflejo y Pantalla Luz."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Espíritu Férreo"),
        .description = COMPOUND_STRING("Potencia los ataques de tipo\n"
        "Acero del equipo."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Cuerpo Mortal"),
        .description = COMPOUND_STRING("Ambos Pokémon se debilitan\n"
        "en 3 turnos al contacto."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Espíritu Errante"),
        .description = COMPOUND_STRING("Intercambia la habilidad\n"
        "con el rival al contacto."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Tácticas Gorila"),
        .description = COMPOUND_STRING("Sube Ataque pero solo puede\n"
        "usar un movimiento."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Gas Neutraliz."),
        .description = COMPOUND_STRING("Anula los efectos de todas\n"
        "las habilidades."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Velo Pastel"),
        .description = COMPOUND_STRING("Inmune y cura el veneno\n"
        "de sus aliados."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Alternancia"),
        .description = COMPOUND_STRING("Cambia de forma al final\n"
        "de cada turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Saque Rápido"),
        .description = COMPOUND_STRING("Puede moverse en primer\n"
        "lugar por sorpresa."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Puño Invisible"),
        .description = COMPOUND_STRING("Atraviesa protecciones con\n"
        "ataques de contacto."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Medicina Curiosa"),
        .description = COMPOUND_STRING("Restaura los cambios de\n"
        "stats de los aliados."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de tipo Eléctrico."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("DRAGON'S MAW"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de tipo Dragón."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Relincho Frío"),
        .description = COMPOUND_STRING("Sube el Ataque al noquear\n"
        "a un Pokémon."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Relincho Sombrío"),
        .description = COMPOUND_STRING("Sube el At. Esp. al noquear\n"
        "a un Pokémon."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Une Nerviosismo y Relincho\n"
        "Blanco en combate."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Une Nerviosismo y Relincho\n"
        "Negro en combate."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
        .name = _("LINGERING AROMA"),
        .description = COMPOUND_STRING("Contagia Olor Persistente\n"
        "al contacto."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("SEED SOWER"),
        .description = COMPOUND_STRING("Crea un Campo de Hierba\n"
        "al recibir un golpe."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("THERMAL EXCHANGE"),
        .description = COMPOUND_STRING("Sube Ataque al recibir fuego\n"
        "y es inmune a quemarse."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("ANGER SHELL"),
        .description = COMPOUND_STRING("Baja Defensas y sube Ataque\n"
        "y Velocidad a mitad PS."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("PURIFYING SALT"),
        .description = COMPOUND_STRING("Resiste tipo Fantasma y es\n"
        "inmune a estados."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("WELL-BAKED BODY"),
        .description = COMPOUND_STRING("Inmune a Fuego y sube mucho\n"
        "su Defensa al recibirlo."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Jinete Viento"),
        .description = COMPOUND_STRING("Sube Ataque con viento y\n"
        "es inmune a ataques de viento."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Perro Guardián"),
        .description = COMPOUND_STRING("Inmune a Intimidación y sube\n"
        "Ataque si intentan bajarlo."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Carga Rocosa"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de tipo Roca."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Poder del Viento"),
        .description = COMPOUND_STRING("Se carga de electricidad\n"
        "al recibir viento."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("De Cero a Héroe"),
        .description = COMPOUND_STRING("Pasa a su Forma Heroica al\n"
        "regresar al combate."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
        .name = _("Comandante"),
        .description = COMPOUND_STRING("Entra en la boca de Dondozo\n"
        "para potenciarlo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
        .name = _("Electromorfosis"),
        .description = COMPOUND_STRING("Se carga de electricidad\n"
        "al recibir un golpe."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protoestasis"),
        .description = COMPOUND_STRING("Potencia su mejor stat con\n"
        "sol o Energía Potenciadora."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Cuark Motor"),
        .description = COMPOUND_STRING("Potencia su mejor stat en\n"
        "campo eléctrico o energía."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Oro Puro"),
        .description = COMPOUND_STRING("Inmune a todos los ataques\n"
        "de estado rivales."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Vasija Ruinosa"),
        .description = COMPOUND_STRING("Reduce el At. Esp. de todos\n"
        "los demás Pokémon."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Espada Ruinosa"),
        .description = COMPOUND_STRING("Reduce la Defensa de todos\n"
        "los demás Pokémon."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tableta Ruinosa"),
        .description = COMPOUND_STRING("Reduce el Ataque de todos\n"
        "los demás Pokémon."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Cuentas Ruinosas"),
        .description = COMPOUND_STRING("Reduce la Def. Esp. de todos\n"
        "los demás Pokémon."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Pulso Oricalco"),
        .description = COMPOUND_STRING("Pone sol y sube Ataque\n"
        "bajo luz solar intensa."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Motor Hadrón"),
        .description = COMPOUND_STRING("Pone Campo Eléctrico y sube\n"
        "At. Esp. en dicho campo."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Oportunista"),
        .description = COMPOUND_STRING("Copia las subidas de stats\n"
        "que realice el rival."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Rumia"),
        .description = COMPOUND_STRING("Vuelve a consumir la baya\n"
        "al final del turno."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Filo"),
        .description = COMPOUND_STRING("Potencia los movimientos\n"
        "de corte."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Sumo Señor"),
        .description = COMPOUND_STRING("Sube Ataque por cada aliado\n"
        "caído en el combate."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Coestrella"),
        .description = COMPOUND_STRING("Copia los cambios de stats\n"
        "del aliado al entrar."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Escombros Tox."),
        .description = COMPOUND_STRING("Esparce Púas Tóxicas al\n"
        "recibir daño físico."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Cola Blindada"),
        .description = COMPOUND_STRING("Bloquea los movimientos\n"
        "con prioridad rivales."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Come Tierra"),
        .description = COMPOUND_STRING("Recupera PS al recibir un\n"
        "ataque de tipo Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("MYCELIUM MIGHT"),
        .description = COMPOUND_STRING("Ataques de estado van lento\n"
        "pero ignoran habilidades."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("HOSPITALITY"),
        .description = COMPOUND_STRING("Restaura algunos PS del\n"
        "aliado al entrar."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("MIND'S EYE"),
        .description = COMPOUND_STRING("Ignora evasión y permite\n"
        "golpear a Fantasmas."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Sube la Velocidad al\n"
        "entrar en combate."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Sube el Ataque al entrar\n"
        "en combate."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Sube la Def. Esp. al\n"
        "entrar en combate."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Sube la Defensa al entrar\n"
        "en combate."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("TOXIC CHAIN"),
        .description = COMPOUND_STRING("Puede envenenar gravemente\n"
        "al golpear al rival."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("SUPERSWEET SYRUP"),
        .description = COMPOUND_STRING("Baja la evasión de los\n"
        "rivales al entrar."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Cambio"),
        .description = COMPOUND_STRING("Adopta su Forma Teracristal\n"
        "al entrar al combate."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
        .name = _("Tera Caparazón"),
        .description = COMPOUND_STRING("Resiste todo si tiene los\n"
        "PS al máximo."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Teraforma Cero"),
        .description = COMPOUND_STRING("Anula el clima y el campo\n"
        "al entrar al combate."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Titerero Veneno"),
        .description = COMPOUND_STRING("Confunde al rival al que\n"
        "logre envenenar."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
