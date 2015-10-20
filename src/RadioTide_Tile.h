#ifndef RADIOTIDE_TILE_H
#define RADIOTIDE_TILE_H

#include "RadioTide_Type.h"

RadioTide_Tile map_tiles[] = {
    {"mountains",  DISPLAY_MOUNTAIN,   4,  -2, 10, 2,  false, BROWN,      ELEVATION},
    {"flat",       DISPLAY_FLAT,       6,  -2, 10, 1,  false, YELLOW,     WILDERNESS},
    {"grassland",  DISPLAY_FLAT,       6,  -2, 10, 1,  false, GREEN,      WILDERNESS},
    {"clearing",   DISPLAY_SMALL_TREE, 6,  -2, 10, 1,  false, GREEN,      FOLIAGE},
    {"ruins",      DISPLAY_RUINS,      6,  -2, 10, 1,  false, PURPLE,     URBAN},
    {"barren",     DISPLAY_FLAT,       6,  -2, 10, 1,  false, RED,        WILDERNESS},
    {"badlands",   DISPLAY_FLAT,       6,  -2, 10, 1,  false, RED,        WILDERNESS},
    // {"radiated", DISPLAY_RADIATED, 6, -2, 10, 1, false, YELLOW, WILDERNESS},
    {"woodland",   DISPLAY_TREE,       -2, 4,  10, 1,  false, GREEN,      FOLIAGE},
    {"forest",     DISPLAY_TREE,       -2, 4,  10, 1,  false, LIGHTGREEN, FOLIAGE},
    {"water",      DISPLAY_WATER,      -2, -1, 0,  1,  true,  LIGHTBLUE,  WATER},
    {"city",       DISPLAY_CITY,       6,  5,  10, -2, false, WHITE,      URBAN},
    {"settlement", DISPLAY_SETTLEMENT, -2, 6,  5,  -2, false, WHITE,      URBAN},
    // {"redoubt", DISPLAY_REDOUBT, -2, 6, 5, -2, false, BROWN, URBAN},
};

/* ------------------- */
/* Function Prototypes */
/* ------------------- */
RadioTide_Tile RadioTide_Tile_getRandomTile();

int RadioTide_Tile_getTileIdx(char *);

RadioTide_Tile RadioTide_Tile_getRandomTileByProximity(RadioTide_Proximity *proximity, RadioTide_Map *rt_map);

int RadioTide_Tile_getRandomTileIdxOfCharacteristic(Characteristic characteristic);


#endif
