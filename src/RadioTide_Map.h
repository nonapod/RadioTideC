#ifndef RADIOTIDE_MAP_H
#define RADIOTIDE_MAP_H

#include "RadioTide_Type.h"
#include "RadioTide_Tile.h"

/* ------------------- */
/* Function Prototypes */
/* ------------------- */

RadioTide_Map RadioTideMap_newMap();

void RadioTideMap_generateMap(int x, int y, RadioTide_Map *rt_map);

void RadioTideMap_printMapToTerminal(RadioTide_Map *rt_map);

char *RadioTideMap_tileColorCode(Color color);

void RadioTideMap_freeMapTiles(RadioTide_Map *rt_map);

void RadioTideMap_checkProximity(int bound_x, int bound_y, int pos_x, int pos_y, RadioTide_Map *rt_map, RadioTide_Proximity *rt_proximity);

void RadioTideMap_releaseMap(RadioTide_Map *rt_map);

void RadioTideMap_freeCharacteristicChances(RadioTide_Map *rt_map);

void RadioTideMap_setCharacteristicChance(Characteristic characteristic, int chance, RadioTide_Map *rt_map);

#endif
