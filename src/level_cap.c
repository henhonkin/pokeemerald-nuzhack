#include 'event_data.h'
#include 'level_cap.h'

static u8 calcLevelCap() {
    u8 obedienceLevel = 7;
    if (FlagGet(FLAG_HIDE_ROUTE_103_RIVAL))
        obedienceLevel = 10;
    if (FlagGet(FLAG_VISITED_RUSTBORO_CITY))
        obedienceLevel = 15;
    if (FlagGet(FLAG_BADGE01_GET)) // Stone Badge
        obedienceLevel = 20;
    if (FlagGet(FLAG_BADGE02_GET)) // Knuckle Badge
        obedienceLevel = 30;
    if (FlagGet(FLAG_BADGE03_GET)) // Dynamo Badge
        obedienceLevel = 40;
    if (FlagGet(FLAG_BADGE04_GET)) // Heat Badge
        obedienceLevel = 50;
    if (FlagGet(FLAG_BADGE05_GET)) // Balance Badge
        obedienceLevel = 60;
    if (FlagGet(FLAG_BADGE06_GET)) // Feather Badge
        obedienceLevel = 70;
    if (FlagGet(FLAG_BADGE07_GET)) // Mind Badge
        obedienceLevel = 80;
    return obedienceLevel;
}