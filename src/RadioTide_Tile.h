#ifndef RADIOTIDE_TILE_H
#define RADIOTIDE_TILE_H

#include "RadioTide_Type.h"

RadioTide_Tile map_tiles[] = {
        {"mountains",  DISPLAY_MOUNTAIN,   4,  -2, 10, 2,  false, ELEVATION},
        {"flat",       DISPLAY_FLAT,       6,  -2, 10, 1,  false, WILDERNESS},
        {"grassland",  DISPLAY_FLAT,       6,  -2, 10, 1,  false, WILDERNESS},
        {"clearing",   DISPLAY_SMALL_TREE, 6,  -2, 10, 1,  false, FOLIAGE},
        {"ruins",      DISPLAY_RUINS,      6,  -2, 10, 1,  false, URBAN},
        {"barren",     DISPLAY_FLAT,       6,  -2, 10, 1,  false, WILDERNESS},
        {"badlands",   DISPLAY_FLAT,       6,  -2, 10, 1,  false, WILDERNESS},
        // {"radiated", DISPLAY_RADIATED, 6, -2, 10, 1, false, WILDERNESS},
        {"woodland",   DISPLAY_TREE,       -2, 4,  10, 1,  false, FOLIAGE},
        {"forest",     DISPLAY_TREE,       -2, 4,  10, 1,  false, FOLIAGE},
        {"water",      DISPLAY_WATER,      -2, -1, 0,  1,  true,  WATER},
        {"city",       DISPLAY_CITY,       6,  5,  10, -2, false, URBAN},
        {"settlement", DISPLAY_SETTLEMENT, -2, 6,  5,  -2, false, URBAN},
        // {"redoubt", DISPLAY_REDOUBT, -2, 6, 5, -2, false, BROWN, URBAN},
};

/* ------------------- */
/* Function Prototypes */
/* ------------------- */
RadioTide_Tile RadioTide_Tile_getRandomTile();

int RadioTideTile_getTileIdx(char *);

RadioTide_Tile RadioTideTile_getRandomTileByProximity(RadioTide_Proximity *proximity, RadioTide_Map *rt_map);

int RadioTideTile_getRandomTileIdxOfCharacteristic(Characteristic characteristic);


#endif
