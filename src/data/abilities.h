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
        .description = COMPOUND_STRING("Aleja a Pokémon salvajes."),
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
        .name = _("Llovizna"),
        .description = COMPOUND_STRING("Hace que llueva en combate."),
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
        .name = _("Motor Impulso"),
        .description = COMPOUND_STRING("Va subiendo la velocidad."),
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
        .name = _("Armadura Batalla"),
        .description = COMPOUND_STRING("Bloquea golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
        .name = _("Robustez"),
        .description = COMPOUND_STRING("Anula golpes fulminantes."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
        .name = _("Humedad"),
        .description = COMPOUND_STRING("Evita la autodestrucción."),
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
        .description = COMPOUND_STRING("Más evasión en Arena."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
        .name = _("Estática"),
        .description = COMPOUND_STRING("Paraliza al contacto."),
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
        .name = _("Absorbe Electr."),
        .description = COMPOUND_STRING("Cambia electricidad por PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
        .name = _("Absorbe Agua"),
        .description = COMPOUND_STRING("Convierte agua en PS."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
        .name = _("Oblivio"),
        .description = COMPOUND_STRING("Evita la atracción."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
        .name = _("Nublado"),
        .description = COMPOUND_STRING("Anula los efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
        .name = _("Ojo Compuesto"),
        .description = COMPOUND_STRING("Aumenta la precisión."),
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
        .name = _("Insomnio"),
        .description = COMPOUND_STRING("Evita el quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
        .name = _("Cambio Color"),
        .description = COMPOUND_STRING("Cambia tipo al ataque rival."),
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
        .description = COMPOUND_STRING("Se carga si recibe Fuego."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
        .name = _("Polvo Escudo"),
        .description = COMPOUND_STRING("Evita efectos secundarios."),
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
        .description = COMPOUND_STRING("Fija el cuerpo con firmeza."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
        .name = _("Intimidación"),
        .description = COMPOUND_STRING("Baja el ataque del rival."),
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
        .name = _("Sombra Trampa"),
        .description = COMPOUND_STRING("Evita que el enemigo huya."),
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
        .name = _("Piel Tosca"),
        .description = COMPOUND_STRING("Hiere al tacto."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
        .name = _("Guardián"),
        .description = COMPOUND_STRING("Solo “super efectivo” le daña."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
        .name = _("Levitación"),
        .description = COMPOUND_STRING("Inmune a Tierra."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
        .name = _("Espora Efecto"),
        .description = COMPOUND_STRING("Deja esporas al contacto."),
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
        .name = _("Sincronía"),
        .description = COMPOUND_STRING("Transmite cambios de estado."),
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
        .name = _("Cuerpo Puro"),
        .description = COMPOUND_STRING("Evita bajón de estadísticas."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
        .name = _("Curación Natural"),
        .description = COMPOUND_STRING("Se cura al salir."),
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
        .name = _("Pararrayos"),
        .description = COMPOUND_STRING("Frena ataques eléctricos."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
        .name = _("Don Serenidad"),
        .description = COMPOUND_STRING("Añade efectos secundarios."),
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
        .name = _("Nado Rápido"),
        .description = COMPOUND_STRING("Con lluvia, sube velocidad."),
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
        .name = _("Clorofila"),
        .description = COMPOUND_STRING("Con Sol, sube la velocidad."),
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
        .name = _("Iluminar"),
        .description = COMPOUND_STRING("Facilita el encuentro."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
        .name = _("Calcador"),
        .description = COMPOUND_STRING("Copia habilidad especial."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
        .name = _("Gran Potencia"),
        .description = COMPOUND_STRING("Aumenta el ataque."),
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
        .name = _("Punto Venenoso"),
        .description = COMPOUND_STRING("Envenena al contacto."),
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
        .description = COMPOUND_STRING("Atrapa Pokémon de Acero."),
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
        .name = _("Insonorización"),
        .description = COMPOUND_STRING("Evita ataques de sonido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
        .name = _("Coge Lluvia"),
        .description = COMPOUND_STRING("Sube PS cuando llueve."),
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
        .name = _("Torrearena"),
        .description = COMPOUND_STRING("Crea Tormenta de Arena."),
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
        .name = _("Presión"),
        .description = COMPOUND_STRING("Baja los PP del enemigo."),
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
        .name = _("Grueso Gordo"),
        .description = COMPOUND_STRING("Protege del frío y calor."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
        .name = _("Madrugar"),
        .description = COMPOUND_STRING("Despierta rápido."),
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
        .name = _("Cuerpo Llama"),
        .description = COMPOUND_STRING("Quema al contacto."),
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
        .name = _("Fuga"),
        .description = COMPOUND_STRING("Facilita la huida."),
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
        .name = _("Visión Lince"),
        .description = COMPOUND_STRING("Evita que baje precisión."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
        .name = _("Hipercorte"),
        .description = COMPOUND_STRING("Evita que baje el ataque."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
        .name = _("Recoger"),
        .description = COMPOUND_STRING("Puede tomar objetos."),
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
        .name = _("Holgazán"),
        .description = COMPOUND_STRING("Interviene cada 2 turnos."),
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
        .name = _("Entusiasmo"),
        .description = COMPOUND_STRING("Cambia precisión por ataque."),
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
        .name = _("Encanto"),
        .description = COMPOUND_STRING("Emboba al mínimo contacto."),
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
        .name = _("Plus"),
        .description = COMPOUND_STRING("Mejora con habilidad Menos."),
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
        .name = _("Menos"),
        .description = COMPOUND_STRING("Mejora con habilidad Más."),
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
        .name = _("Predicción"),
        .description = COMPOUND_STRING("Cambia con el clima."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
        .name = _("Pegajoso"),
        .description = COMPOUND_STRING("Evita el robo de objetos."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
        .name = _("Mudar"),
        .description = COMPOUND_STRING("Se cura mudando la piel."),
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
        .name = _("Agallas"),
        .description = COMPOUND_STRING("Sube el ataque si sufre."),
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
        .name = _("Escama Especial"),
        .description = COMPOUND_STRING("Sube la defensa si sufre."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
        .name = _("Rezuma"),
        .description = COMPOUND_STRING("En vez de ser drenado, daña."),
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
        .name = _("Espesura"),
        .description = COMPOUND_STRING("Sube ataques tipo Planta."),
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
        .name = _("Mar Llamas"),
        .description = COMPOUND_STRING("Sube ataques tipo Fuego."),
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
        .name = _("Torrente"),
        .description = COMPOUND_STRING("Sube ataques tipo Agua."),
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
        .name = _("Enjambre"),
        .description = COMPOUND_STRING("Sube ataques tipo Bicho."),
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
        .name = _("Roca Dura"),
        .description = COMPOUND_STRING("Evita volver a ser golpeado."),
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
        .name = _("Sequía"),
        .description = COMPOUND_STRING("Toma luz solar en batalla."),
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
        .name = _("Trampa Arena"),
        .description = COMPOUND_STRING("Evita la huida."),
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
        .name = _("Espíritu Vital"),
        .description = COMPOUND_STRING("Evita quedarse dormido."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
        .name = _("Humo Blanco"),
        .description = COMPOUND_STRING("Evita que baje la habilidad."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
        .name = _("Pura Potencia"),
        .description = COMPOUND_STRING("Aumenta el ataque."),
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
        .name = _("Armadura Concha"),
        .description = COMPOUND_STRING("Bloquea golpes críticos."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
        .name = _("Éter"),
        .description = COMPOUND_STRING("Anula los efectos del clima."),
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
        .name = _("Pies Largos"),
        .description = COMPOUND_STRING("Sube evasión si está confundido."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
        .name = _("Motor Eléctrico"),
        .description = COMPOUND_STRING("Sube velocidad si recibe Electricidad."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
        .name = _("Rivalidad"),
        .description = COMPOUND_STRING("Sube ataque de mismo sexo."),
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
        .name = _("Constante"),
        .description = COMPOUND_STRING("Retroceder sube velocidad."),
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
        .name = _("Velo Nieve"),
        .description = COMPOUND_STRING("Sube evasión en Granizo."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
        .name = _("Gula"),
        .description = COMPOUND_STRING("Come bayas antes."),
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
        .name = _("Punto Ira"),
        .description = COMPOUND_STRING("Golpe crítico sube ataque."),
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
        .name = _("Ligereza"),
        .description = COMPOUND_STRING("Sube velocidad si usa objeto."),
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
        .name = _("Ignífugo"),
        .description = COMPOUND_STRING("Resiste calor y quemaduras."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
        .name = _("Simpleza"),
        .description = COMPOUND_STRING("Duplica cambios de estadísticas."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
        .name = _("Piel Seca"),
        .description = COMPOUND_STRING("Pierde PS si hace calor."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
        .name = _("Descarga"),
        .description = COMPOUND_STRING("Ajusta ataque favorablemente."),
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
        .name = _("Puño Férreo"),
        .description = COMPOUND_STRING("Potencia puñetazos."),
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
        .name = _("Cura Veneno"),
        .description = COMPOUND_STRING("Recupera PS con veneno."),
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
        .name = _("Adaptable"),
        .description = COMPOUND_STRING("Potencia ataques de mismo tipo."),
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
        .name = _("Enlace Destreza"),
        .description = COMPOUND_STRING("Múltiples golpes aciertan todos."),
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
        .name = _("Hidratación"),
        .description = COMPOUND_STRING("Cura estado si llueve."),
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
        .name = _("Energía Solar"),
        .description = COMPOUND_STRING("Sube el ataque con Sol."),
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
        .name = _("Pies Rápidos"),
        .description = COMPOUND_STRING("Sube velocidad con estado."),
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
        .name = _("Normalizador"),
        .description = COMPOUND_STRING("Ataques son tipo Normal."),
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
        .name = _("Francotirador"),
        .description = COMPOUND_STRING("Potencia críticos."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
        .name = _("Guardia Mágica"),
        .description = COMPOUND_STRING("Solo se daña por ataques."),
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
        .name = _("Sin Guardia"),
        .description = COMPOUND_STRING("Todos los ataques aciertan."),
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
        .name = _("Remolón"),
        .description = COMPOUND_STRING("Ejecuta ataques el último."),
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
        .name = _("Técnico"),
        .description = COMPOUND_STRING("Potencia ataques débiles."),
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
        .name = _("Guardia Hoja"),
        .description = COMPOUND_STRING("Evita estados con Sol."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
        .name = _("Torpe"),
        .description = COMPOUND_STRING("No puede usar objetos."),
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
        .name = _("Rompemoldes"),
        .description = COMPOUND_STRING("Suprime habilidad rival."),
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
        .name = _("Suerte"),
        .description = COMPOUND_STRING("Los críticos aciertan más."),
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
        .name = _("Consecuencias"),
        .description = COMPOUND_STRING("Ser vencido daña al rival."),
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
        .name = _("Anticipación"),
        .description = COMPOUND_STRING("Prevé ataques peligrosos."),
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
        .name = _("Premonición"),
        .description = COMPOUND_STRING("Dice ataque rival fuerte."),
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
        .name = _("Ignorante"),
        .description = COMPOUND_STRING("Ignora cambios de estado."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
        .name = _("Lente de Color"),
        .description = COMPOUND_STRING("Potencia ataques no eficaces."),
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
        .name = _("Filtro"),
        .description = COMPOUND_STRING("Reduce supereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
        .name = _("Inicio Lento"),
        .description = COMPOUND_STRING("Tarda poco en prepararse."),
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
        .name = _("Revoltoso"),
        .description = COMPOUND_STRING("Golpea a Fantasmas."),
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
        .name = _("Imán Agua"),
        .description = COMPOUND_STRING("Atrae movimientos de Agua."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
        .name = _("Cuerpo Hielo"),
        .description = COMPOUND_STRING("Recupera PS con Granizo."),
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
        .name = _("Roca Sólida"),
        .description = COMPOUND_STRING("Debilita supereficaces."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
        .name = _("Granizo"),
    #if B_SNOW_WARNING >= GEN_9
        .description = COMPOUND_STRING("Trae Nieve al combate"),
    #else
        .description = COMPOUND_STRING("Invoca nieve o granizo\n"
        "al entrar en combate."),
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
        .name = _("Colecta Miel"),
        .description = COMPOUND_STRING("Puede encontrar miel."),
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
        .name = _("Cacheo"),
        .description = COMPOUND_STRING("Puede ver el objeto rival."),
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
        .name = _("Temerario"),
        .description = COMPOUND_STRING("Potencia ataques de retroceso."),
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
        .name = _("Multitipo"),
        .description = COMPOUND_STRING("Cambio tipo según tabla."),
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
        .description = COMPOUND_STRING("Se transforma con Sol."),
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
        .name = _("Mal Sueño"),
        .description = COMPOUND_STRING("Daña al rival dormido."),
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
        .name = _("Carterista"),
        .description = COMPOUND_STRING("Roba el objeto al rival."),
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
        .name = _("Fuerza Bruta"),
        .description = COMPOUND_STRING("Cambia efecto por potencia."),
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
        .name = _("Contrario"),
        .description = COMPOUND_STRING("Invierte cambios en estadísticas."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
        .name = _("Tensión"),
        .description = COMPOUND_STRING("Rival no puede comer baya."),
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
        .name = _("Desafío"),
        .description = COMPOUND_STRING("Bajón de estadísticas sube ataque."),
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
        .name = _("Derrotista"),
        .description = COMPOUND_STRING("Se rinde con mitad de PS."),
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
        .name = _("Cuerpo Maldito"),
        .description = COMPOUND_STRING("Anula ataques al contacto."),
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
        .name = _("Sanador"),
        .description = COMPOUND_STRING("Cura estado del aliado."),
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
        .name = _("Guardia Amigo"),
        .description = COMPOUND_STRING("Reduce el daño a aliados."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
        .name = _("Armadura Frágil"),
        .description = COMPOUND_STRING("Sube velocidad si sufre daño físico."),
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
        .name = _("Metal Pesado"),
        .description = COMPOUND_STRING("Duplica su peso."),
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
        .name = _("Metal Ligero"),
        .description = COMPOUND_STRING("Reduce a la mitad su peso."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
        .name = _("Multiescama"),
        .description = COMPOUND_STRING("Reduce daño si PS 100%."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
        .name = _("Potencia Tóxica"),
        .description = COMPOUND_STRING("Sube ataque si es envenenado."),
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
        .name = _("Impulso Ardiente"),
        .description = COMPOUND_STRING("Sube ataque si está quemado."),
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
        .name = _("Cosecha"),
        .description = COMPOUND_STRING("Puede reutilizar bayas."),
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
        .name = _("Telepatía"),
        .description = COMPOUND_STRING("Elude los ataques aliados."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
        .name = _("Variable"),
        .description = COMPOUND_STRING("Sube estadística al azar."),
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
        .name = _("Sobretodo"),
        .description = COMPOUND_STRING("Bloquea clima y polvo."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
        .name = _("Toque Venenoso"),
        .description = COMPOUND_STRING("Envenena al contacto."),
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
        .name = _("Regeneración"),
        .description = COMPOUND_STRING("Cura al cambio."),
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
        .name = _("Pectorales"),
        .description = COMPOUND_STRING("Impide bajón de defensa."),
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
        .name = _("Ímpetu Arena"),
        .description = COMPOUND_STRING("Sube velocidad con Arena."),
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
        .name = _("Piel Mística"),
        .description = COMPOUND_STRING("Reduce problemas de estado."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
        .name = _("Analítico"),
        .description = COMPOUND_STRING("Ser último sube potencia."),
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
        .name = _("Ilusión"),
        .description = COMPOUND_STRING("Adopta aspecto compañero."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
        .name = _("Impostor"),
        .description = COMPOUND_STRING("Se transforma en el rival."),
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
        .name = _("Infiltrador"),
        .description = COMPOUND_STRING("Atraviesa barrera rival."),
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
        .name = _("Momia"),
        .description = COMPOUND_STRING("Se propaga con contacto."),
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
        .name = _("Agresividad"),
        .description = COMPOUND_STRING("Debilitar sube el ataque."),
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
        .name = _("Templado"),
        .description = COMPOUND_STRING("Siniestro sube ataque."),
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
        .name = _("Turbador"),
        .description = COMPOUND_STRING("Sube velocidad con susto."),
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
        .name = _("Rebote Mágico"),
        .description = COMPOUND_STRING("Refleja movientos de estado."),
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
        .name = _("Come Hierba"),
        .description = COMPOUND_STRING("Planta sube ataque."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
        .name = _("Bromista"),
        .description = COMPOUND_STRING("Estado tienen prioridad."),
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
        .name = _("Fuerza Arena"),
        .description = COMPOUND_STRING("Sube ataque en Arena."),
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
        .name = _("Puas Hierro"),
        .description = COMPOUND_STRING("Hiere al contacto."),
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
        .name = _("Modo Zen"),
        .description = COMPOUND_STRING("Transforma a mitad de PS."),
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
        .description = COMPOUND_STRING("Sube precisión del equipo."),
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
        .name = _("Turboflama"),
        .description = COMPOUND_STRING("Rompe habilidades."),
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
        .name = _("Teravoltio"),
        .description = COMPOUND_STRING("Rompe habilidades."),
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
        .name = _("Velo Aromático"),
        .description = COMPOUND_STRING("Previene límite de ataques."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
        .name = _("Velo Floral"),
        .description = COMPOUND_STRING("Protege al tipo Planta."),
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
        .name = _("Bolsa Carrillo"),
        .description = COMPOUND_STRING("Restaura PS si come bayas."),
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
        .name = _("Multicolor"),
        .description = COMPOUND_STRING("Cambia tipo al ataque usado."),
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
        .name = _("Piel Peluda"),
        .description = COMPOUND_STRING("Reduce el daño físico."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
        .name = _("Mago"),
        .description = COMPOUND_STRING("Roba objeto rival."),
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
        .name = _("Antibalas"),
        .description = COMPOUND_STRING("Evita algunos proyectiles."),
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
        .name = _("Competitivo"),
        .description = COMPOUND_STRING("Sube ataque especial si baja estadística."),
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
        .name = _("Mandíbula Fuerte"),
        .description = COMPOUND_STRING("Potencia mordiscos."),
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
        .name = _("Frigorífico"),
        .description = COMPOUND_STRING("Ataques Normales pasan a Hielo."),
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
        .name = _("Velo Dulce"),
        .description = COMPOUND_STRING("Previene sueño de equipo."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
        .name = _("Cambio Forma"),
        .description = COMPOUND_STRING("Transforma según combate."),
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
        .description = COMPOUND_STRING("Volador tiene prioridad."),
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
        .name = _("Megalanzador"),
        .description = COMPOUND_STRING("Potencia pulsos."),
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
        .name = _("Piel Herbácea"),
        .description = COMPOUND_STRING("Sube defensa en hierba."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
        .name = _("Simbiosis"),
        .description = COMPOUND_STRING("Pasa objeto a aliado."),
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
        .name = _("Garras Fuertes"),
        .description = COMPOUND_STRING("Potencia contacto."),
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
        .name = _("Feérico"),
        .description = COMPOUND_STRING("Ataques Normales pasan a Hada."),
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
        .name = _("Viscoso"),
        .description = COMPOUND_STRING("Baja velocidad al contacto."),
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
        .name = _("Viento"),
        .description = COMPOUND_STRING("Ataques Normales pasan a Volador."),
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
        .name = _("Lazo Parental"),
        .description = COMPOUND_STRING("Golpea 2 veces."),
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
        .name = _("Aura Oscura"),
        .description = COMPOUND_STRING("Potencia Siniestro."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
        .name = _("Aura Feérica"),
        .description = COMPOUND_STRING("Potencia Hada."),
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
        .name = _("Antiura"),
        .description = COMPOUND_STRING("Invierte habilidades de aura."),
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
        .name = _("Mar Primigenio"),
        .description = COMPOUND_STRING("Invoca Diluvio."),
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
        .name = _("Tierra Desolada"),
        .description = COMPOUND_STRING("Invoca Sol abrasador."),
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
        .name = _("Delta Corriente"),
        .description = COMPOUND_STRING("Invoca Turbulencias."),
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
        .name = _("STAMINA"),
        .description = COMPOUND_STRING("Sube defensa con cada golpe."),
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
        .name = _("WIMP OUT"),
        .description = COMPOUND_STRING("Huye con mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
        .name = _("EMERGENCY EXIT"),
        .description = COMPOUND_STRING("Huye a la mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
        .name = _("WATER COMPACTION"),
        .description = COMPOUND_STRING("Agua potencia defensa."),
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
        .name = _("MERCILESS"),
        .description = COMPOUND_STRING("Golpe crítico a envenenado."),
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
        .name = _("SHIELDS DOWN"),
        .description = COMPOUND_STRING("Se rompe con mitad de PS."),
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
        .description = COMPOUND_STRING("Duplica daño si cambian."),
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
        .name = _("Burbuja Agua"),
        .description = COMPOUND_STRING("Protege de Fuego y quemaduras."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
        .name = _("Metalúrgico"),
        .description = COMPOUND_STRING("Potencia Acero."),
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
        .name = _("Berserker"),
        .description = COMPOUND_STRING("Sube ataque especial si pocos PS."),
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
        .name = _("Ímpetu Nieve"),
        .description = COMPOUND_STRING("Sube velocidad en Granizo/Nieve."),
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
        .name = _("Largo Alcance"),
        .description = COMPOUND_STRING("Nunca hace contacto."),
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
        .name = _("Voz Acuática"),
        .description = COMPOUND_STRING("Sonido pasa a Agua."),
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
        .name = _("Triaje"),
        .description = COMPOUND_STRING("Curación tiene prioridad."),
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
        .name = _("Galvanización"),
        .description = COMPOUND_STRING("Normal pasa a Eléctrico."),
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
        .name = _("Surf Eléctrico"),
        .description = COMPOUND_STRING("Rápido en electricidad."),
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
        .name = _("Cardumen"),
        .description = COMPOUND_STRING("Forma banco con muchos PS."),
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
        .description = COMPOUND_STRING("Protege de un golpe."),
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
        .description = COMPOUND_STRING("Cambia forma después de KO."),
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
        .description = COMPOUND_STRING("Células ayudan si está débil."),
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
        .description = COMPOUND_STRING("Envenena todos los tipos."),
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
        .name = _("Comatoso"),
        .description = COMPOUND_STRING("Actúa como dormido."),
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
        .description = COMPOUND_STRING("Protege de prioridad."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
        .name = _("Reflejar Daño"),
        .description = COMPOUND_STRING("Hiere al agresor al KO."),
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
        .name = _("Bailarín"),
        .description = COMPOUND_STRING("Copia bailes."),
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
        .name = _("Batería"),
        .description = COMPOUND_STRING("Sube ataque especial aliado."),
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
        .name = _("Pelusa"),
        .description = COMPOUND_STRING("Sube defensa, débil a fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
        .name = _("Deslumbrante"),
        .description = COMPOUND_STRING("Protege de prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
        .name = _("Alma Corazón"),
        .description = COMPOUND_STRING("Debilitar sube ataque especial."),
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
        .name = _("Cabello Enredado"),
        .description = COMPOUND_STRING("Baja velococidad al contacto."),
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
        .name = _("Receptor"),
        .description = COMPOUND_STRING("Copia habilidad de aliado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
        .name = _("Poder Alquimia"),
        .description = COMPOUND_STRING("Copia habilidad de aliado."),
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
        .name = _("Ultraimpulso"),
        .description = COMPOUND_STRING("KO sube mejor estadística."),
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
        .name = _("Sistema RKS"),
        .description = COMPOUND_STRING("Disco cambia su tipo."),
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
        .description = COMPOUND_STRING("Pone Campo Eléctrico."),
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
        .name = _("Psíquico"),
        .description = COMPOUND_STRING("Pone Campo Psíquico."),
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
        .name = _("Niebla"),
        .description = COMPOUND_STRING("Pone Campo de Niebla."),
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
        .name = _("Hierba"),
        .description = COMPOUND_STRING("Pone Campo de Hierba."),
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
        .name = _("Cuerpo Férreo"),
        .description = COMPOUND_STRING("Previene reducción de estadísticas."),
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
        .name = _("Escudo Sombra"),
        .description = COMPOUND_STRING("Reduce daño si PS 100%."),
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
        .name = _("Armadura Prisma"),
        .description = COMPOUND_STRING("Debilita supereficaces."),
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
        .name = _("Neurofuerza"),
        .description = COMPOUND_STRING("Potencia supereficaces."),
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
        .name = _("Espada Valiente"),
        .description = COMPOUND_STRING("Sube ataque al entrar."),
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
        .name = _("Escudo Constante"),
        .description = COMPOUND_STRING("Sube defensa al entrar."),
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
        .name = _("LIBERO"),
        .description = COMPOUND_STRING("Cambia tipo al ataque usado."),
    },

    [ABILITY_BALL_FETCH] =
    {
        .name = _("Busca Bola"),
        .description = COMPOUND_STRING("Recupera Poké Balls."),
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
        .name = _("Plumón Algodón"),
        .description = COMPOUND_STRING("Baja velocidad al contacto."),
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
        .name = _("Cola Hélice"),
        .description = COMPOUND_STRING("Ignora cambios de posición."),
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
        .name = _("Armadura Espejo"),
        .description = COMPOUND_STRING("Refleja reducción de estadísticas."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
        .name = _("Misil Tragado"),
        .description = COMPOUND_STRING("Escupe presa si es golpeado."),
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
        .description = COMPOUND_STRING("Ignora cambios de posición."),
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
        .name = _("Motor Vapor"),
        .description = COMPOUND_STRING("Sube velocidad con Fuego y Agua."),
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Sube y resiste sonido."),
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
        .name = _("Escupir Arena"),
        .description = COMPOUND_STRING("Pone Arena si lo golpean."),
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
        .name = _("Escamas Hielo"),
        .description = COMPOUND_STRING("Reduce daño especial."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
        .name = _("Madurar"),
        .description = COMPOUND_STRING("Duplica efecto de bayas."),
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
        .name = _("Cara Hielo"),
        .description = COMPOUND_STRING("Cara regenera con Granizo."),
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
        .description = COMPOUND_STRING("Potencia ataques aliados."),
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
        .name = _("Mimetismo"),
        .description = COMPOUND_STRING("Cambia tipo al campo."),
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
        .name = _("Rompe Pantallas"),
        .description = COMPOUND_STRING("Elimina las barreras."),
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
        .name = _("Espíritu Férreo"),
        .description = COMPOUND_STRING("Potencia Acero aliado."),
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
        .name = _("Cuerpo Mortal"),
        .description = COMPOUND_STRING("Debilita al rival en 3 turnos."),
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
        .name = _("Espíritu Errante"),
        .description = COMPOUND_STRING("Cambia habilidad al contacto."),
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
        .name = _("Tácticas Gorila"),
        .description = COMPOUND_STRING("Sube ataque pero solo 1 movimiento."),
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
        .name = _("Gas Neutraliz."),
        .description = COMPOUND_STRING("Desactiva todas las habilidades."),
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
        .name = _("Velo Pastel"),
        .description = COMPOUND_STRING("Protege equipo del veneno."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
        .name = _("Alternancia"),
        .description = COMPOUND_STRING("Cambia forma cada turno."),
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
        .name = _("Saque Rápido"),
        .description = COMPOUND_STRING("A veces se mueve primero."),
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
        .name = _("Puño Invisible"),
        .description = COMPOUND_STRING("Evade protección física."),
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
        .name = _("Medicina Curiosa"),
        .description = COMPOUND_STRING("Anula cambios de estadísticas en equipo."),
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Potencia Eléctricidad."),
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
        .name = _("DRAGON'S MAW"),
        .description = COMPOUND_STRING("Sube ataques Dragón."),
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
        .name = _("Relincho Frío"),
        .description = COMPOUND_STRING("KOs suben ataque."),
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
        .name = _("Relincho Sombrío"),
        .description = COMPOUND_STRING("KOs suben ataque especial."),
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Nerviosismo + Relincho negro."),
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
        .description = COMPOUND_STRING("Nerviosismo + Relincho blanco."),
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
        .description = COMPOUND_STRING("Se propaga con contacto."),
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
        .name = _("SEED SOWER"),
        .description = COMPOUND_STRING("Cambia terreno al ser golpeado."),
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
        .name = _("THERMAL EXCHANGE"),
        .description = COMPOUND_STRING("El fuego aumenta el ataque."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
        .name = _("ANGER SHELL"),
        .description = COMPOUND_STRING("Se enfada a mitad de PS."),
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
        .name = _("PURIFYING SALT"),
        .description = COMPOUND_STRING("Protección de sales puras."),
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
        .name = _("WELL-BAKED BODY"),
        .description = COMPOUND_STRING("Aumenta defensa si recibe fuego."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
        .name = _("Jinete Viento"),
        .description = COMPOUND_STRING("Volador aumenta el ataque."),
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
        .name = _("Perro Guardián"),
        .description = COMPOUND_STRING("Imposible de intimidar."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
        .name = _("Carga Rocosa"),
        .description = COMPOUND_STRING("Potencia Roca."),
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
        .name = _("Poder del Viento"),
        .description = COMPOUND_STRING("Recupera energía con Volador."),
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
        .name = _("De Cero a Héroe"),
        .description = COMPOUND_STRING("Cambia de forma al salir."),
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
        .description = COMPOUND_STRING("Da órdenes a Dondozo."),
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
        .description = COMPOUND_STRING("Se recarga al contacto."),
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
        .name = _("Protoestasis"),
        .description = COMPOUND_STRING("Sol sube mejor estadística."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
        .name = _("Cuark Motor"),
        .description = COMPOUND_STRING("Campo elécrico sube mejor estadística."),
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
        .name = _("Oro Puro"),
        .description = COMPOUND_STRING("Evita movimientos de estado."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
        .name = _("Vasija Ruinosa"),
        .description = COMPOUND_STRING("Reduce ataque especial rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
        .name = _("Espada Ruinosa"),
        .description = COMPOUND_STRING("Reduce defensa rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
        .name = _("Tableta Ruinosa"),
        .description = COMPOUND_STRING("Reduce ataque rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
        .name = _("Cuentas Ruinosas"),
        .description = COMPOUND_STRING("Reduce defensa especial rival."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
        .name = _("Pulso Oricalco"),
        .description = COMPOUND_STRING("Invoca el Sol en combate."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
        .name = _("Motor Hadrón"),
        .description = COMPOUND_STRING("Pone campo eléctrico y potencia."),
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
        .name = _("Oportunista"),
        .description = COMPOUND_STRING("Copia cambios de estadísticas rivales."),
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
        .name = _("Rumia"),
        .description = COMPOUND_STRING("Consume una baya ya usada."),
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
        .name = _("Filo"),
        .description = COMPOUND_STRING("Potencia cortes."),
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
        .name = _("Sumo Señor"),
        .description = COMPOUND_STRING("Recupera fuerza de caídos."),
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
        .name = _("Coestrella"),
        .description = COMPOUND_STRING("Copia cambios aliados de estadísticas."),
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
        .name = _("Escombros Tox."),
        .description = COMPOUND_STRING("Al golpear, caen puás tóxicas."),
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
        .name = _("Cola Blindada"),
        .description = COMPOUND_STRING("Protege de la prioridad."),
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
        .name = _("Come Tierra"),
        .description = COMPOUND_STRING("Come Tierra para curarse."),
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
        .name = _("MYCELIUM MIGHT"),
        .description = COMPOUND_STRING("Movimientos de estado no fallan."),
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
        .name = _("HOSPITALITY"),
        .description = COMPOUND_STRING("Recupera PS de aliados."),
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
        .name = _("MIND'S EYE"),
        .description = COMPOUND_STRING("Vista lince + Intrépido."),
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Aumenta velocidad"),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Aumenta ataque."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Aumenta defensa especial."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Aumenta defensa."),
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
        .name = _("TOXIC CHAIN"),
        .description = COMPOUND_STRING("Ataques pueden envenenar."),
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
        .name = _("SUPERSWEET SYRUP"),
        .description = COMPOUND_STRING("Baja la evasion rival."),
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
        .name = _("Tera Cambio"),
        .description = COMPOUND_STRING("Teracristaliza al entrar."),
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
        .description = COMPOUND_STRING("Si PS al 100%, resiste ataques."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
        .name = _("Teraforma Cero"),
        .description = COMPOUND_STRING("Elimina clima y terreno."),
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
        .name = _("Titerero Veneno"),
        .description = COMPOUND_STRING("Confunde si envenena."),
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
