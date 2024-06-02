#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "level_caps.h"
#include "pokemon.h"

u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_HIDE_ROUTE_103_RIVAL, 7},
        {TRAINER_FLAG(TRAINER_CALVIN_1), 7},
	{TRAINER_FLAG(TRAINER_RICK), 9},
	{FLAG_SCOTT_1, 10},
        {TRAINER_FLAG(TRAINER_CINDY_1), 11},
        {TRAINER_FLAG(TRAINER_GRUNT_PETALBURG_WOODS), 12},
        {TRAINER_FLAG(TRAINER_WINSTON_1), 13},
	{FLAG_VISITED_RUSTBORO_CITY, 14},
        {TRAINER_FLAG(TRAINER_JOSH), 15},
        {FLAG_BADGE01_GET, 16},
        {TRAINER_FLAG(TRAINER_GRUNT_RUSTURF_TUNNEL), 17},
        {FLAG_BADGE02_GET, 20},
        {FLAG_BADGE03_GET, 28},
        {FLAG_BADGE04_GET, 35},
        {FLAG_BADGE05_GET, 37},
        {FLAG_BADGE06_GET, 43},
        {FLAG_BADGE07_GET, 53},
        {FLAG_BADGE08_GET, 60},
        {FLAG_IS_CHAMPION, 66},
    };

    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (B_LEVEL_CAP_EXP_UP && level < currentLevelCap)
    {
        levelDifference = currentLevelCap - level;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingDown) - 1]);
        else
            return expValue + (expValue / sExpScalingUp[levelDifference]);
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT && level >= currentLevelCap)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else if (level < currentLevelCap)
    {
       return expValue;
    }
    else
    {
        return 0;
    }

}
