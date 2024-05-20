#ifndef GUARD_BATTLE_MAIN_H
#define GUARD_BATTLE_MAIN_H

#include "pokemon.h"
#include "data.h"

// For displaying a multi battle partner's Pokémon in the party menu
struct MultiPartnerMenuPokemon
{
    /*0x00*/ u16 species;
    /*0x02*/ u16 heldItem;
    /*0x04*/ u8 nickname[POKEMON_NAME_LENGTH + 1];
    /*0x0F*/ u8 level;
    /*0x10*/ u16 hp;
    /*0x12*/ u16 maxhp;
    /*0x14*/ u32 status;
    /*0x18*/ u32 personality;
    /*0x1C*/ u8 gender;
    /*0x1D*/ u8 language;
};

// defines for the 'DoBounceEffect' function
#define BOUNCE_MON          0x0
#define BOUNCE_HEALTHBOX    0x1

void CB2_InitBattle(void);
void BattleMainCB2(void);
void CB2_QuitRecordedBattle(void);
void VBlankCB_Battle(void);
void SpriteCB_VsLetterDummy(struct Sprite *sprite);
void SpriteCB_VsLetterInit(struct Sprite *sprite);
void CB2_InitEndLinkBattle(void);
u32 GetBattleBgTemplateData(u8 arrayId, u8 caseId);
u32 GetBattleWindowTemplatePixelWidth(u32 setId, u32 tableId);
void SpriteCB_WildMon(struct Sprite *sprite);
void SpriteCallbackDummy_2(struct Sprite *sprite);
void SpriteCB_FaintOpponentMon(struct Sprite *sprite);
void SpriteCB_ShowAsMoveTarget(struct Sprite *sprite);
void SpriteCB_HideAsMoveTarget(struct Sprite *sprite);
void SpriteCB_OpponentMonFromBall(struct Sprite *sprite);
void SpriteCB_BattleSpriteStartSlideLeft(struct Sprite *sprite);
void SpriteCB_FaintSlideAnim(struct Sprite *sprite);
void DoBounceEffect(u8 battler, u8 which, s8 delta, s8 amplitude);
void EndBounceEffect(u8 battler, u8 which);
void SpriteCB_PlayerMonFromBall(struct Sprite *sprite);
void SpriteCB_TrainerThrowObject(struct Sprite *sprite);
void AnimSetCenterToCornerVecX(struct Sprite *sprite);
void BeginBattleIntroDummy(void);
void BeginBattleIntro(void);
void SwitchInClearSetData(u32 battler);
const u8* FaintClearSetData(u32 battler);
void BattleTurnPassed(void);
u8 IsRunningFromBattleImpossible(u32 battler);
void SwitchTwoBattlersInParty(u32 battler, u32 battler2);
void SwitchPartyOrder(u32 battlerId);
void SwapTurnOrder(u8 id1, u8 id2);
u32 GetBattlerTotalSpeedStatArgs(u32 battler, u32 ability, u32 holdEffect);
u32 GetBattlerTotalSpeedStat(u32 battler);
s8 GetChosenMovePriority(u32 battlerId);
s8 GetMovePriority(u32 battlerId, u16 move);
s32 GetWhichBattlerFasterArgs(u32 battler1, u32 battler2, bool32 ignoreChosenMoves, u32 ability1, u32 ability2,
                              u32 holdEffectBattler1, u32 holdEffectBattler2, u32 speedBattler1, u32 speedBattler2, s32 priority1, s32 priority2);
s32 GetWhichBattlerFaster(u32 battler1, u32 battler2, bool32 ignoreChosenMoves);
void RunBattleScriptCommands_PopCallbacksStack(void);
void RunBattleScriptCommands(void);
void SpecialStatusesClear(void);
void SetTypeBeforeUsingMove(u32 move, u32 battlerAtk);
bool32 IsWildMonSmart(void);
u8 CreateNPCTrainerPartyFromTrainer(struct Pokemon *party, const struct Trainer *trainer, bool32 firstTrainer, u32 battleTypeFlags);
void ModifyPersonalityForNature(u32 *personality, u32 newNature);
u32 GeneratePersonalityForGender(u32 gender, u32 species);
void CustomTrainerPartyAssignMoves(struct Pokemon *mon, const struct TrainerMon *partyEntry);

extern struct MultiPartnerMenuPokemon gMultiPartnerParty[MULTI_PARTY_SIZE];

extern const struct SpriteTemplate gUnusedBattleInitSprite;
extern const struct OamData gOamData_BattleSpriteOpponentSide;
extern const struct OamData gOamData_BattleSpritePlayerSide;
extern const struct TypeInfo gTypesInfo[NUMBER_OF_MON_TYPES];

extern const u8 gStatusConditionString_PoisonJpn[8];
extern const u8 gStatusConditionString_SleepJpn[8];
extern const u8 gStatusConditionString_ParalysisJpn[8];
extern const u8 gStatusConditionString_BurnJpn[8];
extern const u8 gStatusConditionString_IceJpn[8];
extern const u8 gStatusConditionString_ConfusionJpn[8];
extern const u8 gStatusConditionString_LoveJpn[8];

extern const u8 *const gStatusConditionStringsTable[7][2];

#define BULBASAUR_STARTER 0
#define CHARMANDER_STARTER 1
#define SQUIRTLE_STARTER 2
#define CATERPIE_STARTER 3
#define WEEDLE_STARTER 4
#define PIDGEY_STARTER 5
#define PICHU_STARTER 6
#define NIDORAN_F_STARTER 7
#define NIDORAN_M_STARTER 8
#define CLEFFA_STARTER 9
#define IGGLYBUFF_STARTER 10
#define ODDISH_STARTER 11
#define POLIWAG_STARTER 12
#define ABRA_STARTER 13
#define MACHOP_STARTER 14
#define BELLSPROUT_STARTER 15
#define GEODUDE_STARTER 16
#define GASTLY_STARTER 17
#define DRATINI_STARTER 18
#define CHIKORITA_STARTER 19
#define CYNDAQUIL_STARTER 20
#define TOTODILE_STARTER 21
#define ZUBAT_STARTER 22
#define MAREEP_STARTER 23
#define AZURILL_STARTER 24
#define HOPPIP_STARTER 25
#define HORSEA_STARTER 26
#define HAPPINY_STARTER 27
#define LARVITAR_STARTER 28
#define TREECKO_STARTER 29
#define TORCHIC_STARTER 30
#define MUDKIP_STARTER 31
#define LOTAD_STARTER 32
#define SEEDOT_STARTER 33
#define RALTS_STARTER 34
#define SLAKOTH_STARTER 35
#define WHISMUR_STARTER 36
#define ARON_STARTER 37
#define TRAPINCH_STARTER 38
#define SPHEAL_STARTER 39
#define BAGON_STARTER 40
#define BELDUM_STARTER 41
#define BUDEW_STARTER 42
#define MAGNEMITE_STARTER 43
#define RHYNHORN_STARTER 44
#define ELEKID_STARTER 45
#define MAGBY_STARTER 46
#define TOGEPI_STARTER 47
#define SWINUB_STARTER 48
#define PORYGON_STARTER 49
#define DUSKULL_STARTER 50
#define ZIGZAGOON_GALARIAN_STARTER 51
#define MIME_JR_STARTER 52
#define TEDDIURSA_STARTER 53
#define GEODUDE_ALOLAN_STARTER 54
#define MANKEY_STARTER 55
#define NUM_DEFINED_STARTERS MANKEY_STARTER +1

#define FIRST_SCOTT_FIGHT_ITEM_1 ITEM_ORAN_BERRY

u8 GetDefinedStarterPokemon(u16 starterId);

static const struct TrainerMon rivallyPokes[NUM_DEFINED_STARTERS] = {
    [BULBASAUR_STARTER] = {
        .species = SPECIES_BULBASAUR,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_LEECH_SEED, MOVE_VINE_WHIP},
    },
    [CHARMANDER_STARTER] = {
        .species = SPECIES_CHARMANDER,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_GROWL, MOVE_EMBER, MOVE_METAL_CLAW},
    },
    [SQUIRTLE_STARTER] = {
        .species = SPECIES_SQUIRTLE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_TAIL_WHIP, MOVE_WATER_GUN, MOVE_BITE},
    },
    [CATERPIE_STARTER] = {
        .species = SPECIES_CATERPIE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_STRING_SHOT, MOVE_BUG_BITE, MOVE_NONE},
    },
    [WEEDLE_STARTER] = {
        .species = SPECIES_WEEDLE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POISON_STING, MOVE_STRING_SHOT, MOVE_BUG_BITE, MOVE_TACKLE},
    },
    [PIDGEY_STARTER] = {
        .species = SPECIES_PIDGEY,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GUST, MOVE_QUICK_ATTACK, MOVE_NONE},
    },
    [PICHU_STARTER] = {
        .species = SPECIES_PICHU,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_THUNDERSHOCK, MOVE_CHARM, MOVE_QUICK_ATTACK, MOVE_THUNDER_WAVE},
    },
    [NIDORAN_F_STARTER] = {
        .species = SPECIES_NIDORAN_F,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_TAIL_WHIP, MOVE_DOUBLE_KICK, MOVE_POISON_STING},
    },
    [NIDORAN_M_STARTER] = {
        .species = SPECIES_NIDORAN_M,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_LEER, MOVE_PECK, MOVE_DOUBLE_KICK, MOVE_POISON_STING},
    },
    [CLEFFA_STARTER] = {
        .species = SPECIES_CLEFFA,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POUND, MOVE_ENCORE, MOVE_SING, MOVE_NONE},
    },
    [IGGLYBUFF_STARTER] = {
        .species = SPECIES_IGGLYBUFF,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SING, MOVE_DEFENSE_CURL, MOVE_POUND, MOVE_DISABLE},
    },
    [ODDISH_STARTER] = {
        .species = SPECIES_ODDISH,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_ABSORB, MOVE_SWEET_SCENT, MOVE_ACID, MOVE_POISON_POWDER},
    },
    [POLIWAG_STARTER] = {
        .species = SPECIES_POLIWAG,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_BUBBLE, MOVE_HYPNOSIS, MOVE_WATER_GUN, MOVE_DOUBLESLAP},
    },
    [ABRA_STARTER] = {
        .species = SPECIES_ABRA,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TELEPORT, MOVE_KINESIS, MOVE_CONFUSION, MOVE_DISABLE},
    },
    [MACHOP_STARTER] = {
        .species = SPECIES_MACHOP,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SEISMIC_TOSS, MOVE_LEER, MOVE_LOW_KICK, MOVE_FOCUS_ENERGY},
    },
    [BELLSPROUT_STARTER] = {
        .species = SPECIES_BELLSPROUT,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_VINE_WHIP, MOVE_GROWTH, MOVE_WRAP, MOVE_POISON_POWDER},
    },
    [GEODUDE_STARTER] = {
        .species = SPECIES_GEODUDE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_SANDSTORM, MOVE_ROCK_POLISH},
    },
    [GASTLY_STARTER] = {
        .species = SPECIES_GASTLY,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_LICK, MOVE_SPITE, MOVE_NONE, MOVE_CURSE},
    },
    [DRATINI_STARTER] = {
        .species = SPECIES_DRATINI,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_WRAP, MOVE_LEER, MOVE_THUNDER_WAVE, MOVE_NONE},
    },
    [CHIKORITA_STARTER] = {
        .species = SPECIES_CHIKORITA,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GROWTH, MOVE_RAZOR_LEAF, MOVE_POISON_POWDER},
    },
    [CYNDAQUIL_STARTER] = {
        .species = SPECIES_CYNDAQUIL,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_LEER, MOVE_SMOKESCREEN, MOVE_EMBER},
    },
    [TOTODILE_STARTER] = {
        .species = SPECIES_TOTODILE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_WATER_GUN, MOVE_RAGE},
    },
    [ZUBAT_STARTER] = {
        .species = SPECIES_ZUBAT,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_LEECH_LIFE, MOVE_SUPERSONIC, MOVE_ASTONISH, MOVE_BITE},
    },
    [MAREEP_STARTER] = {
        .species = SPECIES_MAREEP,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_THUNDER_SHOCK, MOVE_COTTON_SPORE},
    },
    [AZURILL_STARTER] = {
        .species = SPECIES_AZURILL,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SPLASH, MOVE_CHARM, MOVE_BUBBLE, MOVE_WATER_GUN},
    },
    [HOPPIP_STARTER] = {
        .species = SPECIES_HOPPIP,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SPLASH, MOVE_SYNTHESIS, MOVE_TAIL_WHIP, MOVE_TACKLE},
    },
    [HORSEA_STARTER] = {
        .species = SPECIES_HORSEA,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_BUBBLE, MOVE_SMOKESCREEN, MOVE_LEER, MOVE_WATER_GUN},
    },
    [HAPPINY_STARTER] = {
        .species = SPECIES_HAPPINY,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POUND, MOVE_CHARM, MOVE_COPYCAT, MOVE_NONE},
    },
    [LARVITAR_STARTER] = {
        .species = SPECIES_LARVITAR,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_BITE, MOVE_LEER, MOVE_SANDSTORM, MOVE_SCREECH},
    },
    [TREECKO_STARTER] = {
        .species = SPECIES_TREECKO,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POUND, MOVE_LEER, MOVE_ABSORB, MOVE_QUICK_ATTACK},
    },
    [TORCHIC_STARTER] = {
        .species = SPECIES_TORCHIC,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_GROWL, MOVE_FOCUS_ENERGY, MOVE_EMBER},
    },
    [MUDKIP_STARTER] = {
        .species = SPECIES_MUDKIP,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_MUD_SLAP, MOVE_WATER_GUN},
    },
    [LOTAD_STARTER] = {
        .species = SPECIES_LOTAD,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_ASTONISH, MOVE_GROWTH, MOVE_NATURE_POWER, MOVE_MIST},
    },
    [SEEDOT_STARTER] = {
        .species = SPECIES_SEEDOT,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_BIDE, MOVE_HARDEN, MOVE_GROWTH, MOVE_NATURE_POWER},
    },
    [RALTS_STARTER] = {
        .species = SPECIES_RALTS,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_GROWL, MOVE_CONFUSION, MOVE_DOUBLE_TEAM, MOVE_TELEPORT},
    },
    [SLAKOTH_STARTER] = {
        .species = SPECIES_SLAKOTH,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_YAWN, MOVE_ENCORE, MOVE_SLACK_OFF},
    },
    [WHISMUR_STARTER] = {
        .species = SPECIES_WHISMUR,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POUND, MOVE_SCREECH, MOVE_HOWL, MOVE_SUPERSONIC},
    },
    [ARON_STARTER] = {
        .species = SPECIES_ARON,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_HARDEN, MOVE_NONE, MOVE_NONE},
    },
    [TRAPINCH_STARTER] = {
        .species = SPECIES_TRAPINCH,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_BITE, MOVE_SAND_ATTACK, MOVE_FEINT_ATTACK, MOVE_MUD_SLAP},
    },
    [SPHEAL_STARTER] = {
        .species = SPECIES_SPHEAL,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POWDER_SNOW, MOVE_GROWL, MOVE_WATER_GUN, MOVE_DEFENSE_CURL},
    },
    [BAGON_STARTER] = {
        .species = SPECIES_BAGON,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_RAGE, MOVE_BITE, MOVE_LEER, MOVE_TACKLE},
    },
    [BELDUM_STARTER] = {
        .species = SPECIES_BELDUM,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TAKE_DOWN, MOVE_CONFUSION, MOVE_SCARY_FACE, MOVE_IRON_DEFENSE},
    },
    [BUDEW_STARTER] = {
        .species = SPECIES_BUDEW,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_ABSORB, MOVE_GROWTH, MOVE_POISONPOWDER, MOVE_STUN_SPORE},
    },
    [MAGNEMITE_STARTER] = {
        .species = SPECIES_MAGNEMITE,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_THUNDERSHOCK, MOVE_SUPERSONIC, MOVE_THUNDER_WAVE},
    },
    [RHYNHORN_STARTER] = {
        .species = SPECIES_RHYHORN,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_MUD_SLAP, MOVE_TAIL_WHIP, MOVE_FURY_ATTACK},
    },
    [ELEKID_STARTER] = {
        .species = SPECIES_ELEKID,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_QUICK_ATTACK, MOVE_LEER, MOVE_THUNDER_SHOCK, MOVE_SCREECH},
    },
    [MAGBY_STARTER] = {
        .species = SPECIES_MAGBY,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_EMBER, MOVE_LEER, MOVE_SMOKESCREEN, MOVE_NONE},
    },
    [TOGEPI_STARTER] = {
        .species = SPECIES_TOGEPI,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_GROWL, MOVE_CHARM, MOVE_METRONOME, MOVE_SWEET_KISS},
    },
    [SWINUB_STARTER] = {
        .species = SPECIES_SWINUB,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POWDER_SNOW, MOVE_MUD_SLAP, MOVE_ENDURE, MOVE_NONE},
    },
    [PORYGON_STARTER] = {
        .species = SPECIES_PORYGON,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_CONVERSION, MOVE_AGILITY, MOVE_NONE},
    },
    [DUSKULL_STARTER] = {
        .species = SPECIES_DUSKULL,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_LEER, MOVE_NIGHT_SHADE, MOVE_DISABLE, MOVE_FUTURE_SIGHT},
    },
    [ZIGZAGOON_GALARIAN_STARTER] = {
        .species = SPECIES_ZIGZAGOON_GALARIAN,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_GROWL, MOVE_SAND_ATTACK, MOVE_HEADBUTT},
    },
    [MIME_JR_STARTER] = {
        .species = SPECIES_MIME_JR,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_POUND, MOVE_CONFUSION, MOVE_MIMIC, MOVE_ENCORE},

    },
    [TEDDIURSA_STARTER] = {
        .species = SPECIES_TEDDIURSA,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_LICK, MOVE_FAKE_TEARS},
    },
    [GEODUDE_ALOLAN_STARTER] = {
        .species = SPECIES_GEODUDE_ALOLAN,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_POLISH}
    },
    [MANKEY_STARTER] = {
        .species = SPECIES_MANKEY,
        .heldItem = FIRST_SCOTT_FIGHT_ITEM_1,
        .lvl = 200,
        .moves = {MOVE_SCRATCH, MOVE_LEER, MOVE_LOW_KICK, MOVE_SEISMIC_TOSS},
    },
};

#endif // GUARD_BATTLE_MAIN_H
