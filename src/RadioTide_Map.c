#ifndef RADIOTIDE_MAP_C
#define RADIOTIDE_MAP_C

#include "RadioTide_Map.h"
#include "main.h"


/**
 * RadioTideMap_newMap()
 *
 * returns a new map object with the proper
 * characteristics enabled, and some default
 * x and y values, an actual map won't be
 * created and will remain as uninitialised until
 * generateMap is called
 */
RadioTide_Map RadioTideMap_newMap() {
    RadioTide_Map rt_map;

    rt_map.x = 0;
    rt_map.y = 0;

    // allocate memory for characteristic chances
    int rows = (int)CharacteristicEnumEnd;
    rt_map.characteristic_chance = malloc(rows * sizeof(int));

    for(size_t i = 0; i < rows; i++) {
        rt_map.characteristic_chance[i] = 0;
    }

    // Now set the known defaults
    rt_map.characteristic_chance[ELEVATION] = ELEVATION_DEFAULT_CHANCE;
    rt_map.characteristic_chance[WILDERNESS] = WILDERNESS_DEFAULT_CHANCE;
    rt_map.characteristic_chance[FOLIAGE] = FOLIAGE_DEFAULT_CHANCE;
    rt_map.characteristic_chance[URBAN] = URBAN_DEFAULT_CHANCE;
    rt_map.characteristic_chance[WATER] = WATER_DEFAULT_CHANCE;

    return rt_map;

}

/**
 * RadioTideMap_setCharacteristicChance()
 *
 * sets the chance from MIN/MAX CHANCE of a tile generation
 * occurrence
 * */
void RadioTideMap_setCharacteristicChance(Characteristic characteristic, int chance, RadioTide_Map *rt_map) {

    chance = (chance <= CHARACTERISTIC_MAX_CHANCE && chance >= CHARACTERISTIC_MIN_CHANCE) ? chance : 0;

    if (characteristic < CharacteristicEnumEnd) {
        rt_map->characteristic_chance[characteristic] = chance;
    }

}

/**
 * RadioTideMap_generateMap()
 *
 * takes an x and y value for map size, including
 * a RadioTide_Map instance, the original map is
 * freed and the new map is created with x and y values.
 */
void RadioTideMap_generateMap(int x, int y, RadioTide_Map *rt_map) {

    // free the map if not null on every map generation
    RadioTideMap_freeMapTiles(rt_map);
    rt_map->x = x;
    rt_map->y = y;

    rt_map->tiles = malloc(sizeof(RadioTide_Tile) * rt_map->y);

    for (int y = 0; y < rt_map->y; y++) {

        rt_map->tiles[y] = malloc(sizeof(RadioTide_Tile) * rt_map->x);

        for (int x = 0; x < rt_map->x; x++) {

            // get and fill a new set of proximity parameters,
            // add a new tile depending on tile proximity
            RadioTide_Proximity rt_proximity;
            RadioTideMap_checkProximity(x, y, x, y, rt_map, &rt_proximity);
            rt_map->tiles[y][x] = RadioTideTile_getRandomTileByProximity(&rt_proximity, rt_map);

        }

    }

}

/**
 * RadioTideMap_freeMapTiles()
 *
 * free the map tiles from memory
 */
void RadioTideMap_freeMapTiles(RadioTide_Map *rt_map) {

    if (rt_map->tiles != NULL) {

        for (int y = 0; y < rt_map->y; y++) {

            if (rt_map->tiles[y] != NULL) {
                free(rt_map->tiles[y]);
            }

        }

        free(rt_map->tiles);

    }

}

/**
 * RadioTideMap_freeCharacteristicChances()
 *
 * frees the characteristic chances from the map
 */
void RadioTideMap_freeCharacteristicChances(RadioTide_Map *rt_map) {

    if (rt_map->characteristic_chance != NULL) {
        free(rt_map->characteristic_chance);
    }

}

/**
 * RadioTideMap_releaseMap()
 *
 * frees everything allocated within the map
 * and nullifies the map instance.
 */
void RadioTideMap_releaseMap(RadioTide_Map *rt_map) {

    RadioTideMap_freeCharacteristicChances(rt_map);
    RadioTideMap_freeMapTiles(rt_map);

}

/**
 * RadioTideMap_checkProximity()
 *
 * checks all of the tiles surrounding a current tile position (x, y)
 * to the current bounds of the tile set (x, y), if being used while
 * building the map, the bounds will likely be the same as the position.
 *
 */
void RadioTideMap_checkProximity(int bound_x, int bound_y, int pos_x, int pos_y, RadioTide_Map *rt_map, RadioTide_Proximity *rt_proximity) {

    int UP = pos_y - 1;
    int DOWN = pos_y + 1;
    int LEFT = pos_x - 1;
    int RIGHT = pos_x + 1;

    strncpy(rt_proximity->center, rt_map->tiles[pos_y][pos_x].name, TILE_NAME_SIZE);

    // Straight proximity
    if (UP >= 0 && UP <= bound_y) {
        strncpy(rt_proximity->up, rt_map->tiles[UP][pos_x].name, TILE_NAME_SIZE);
    }
    if (DOWN >= 0 && DOWN <= bound_y) {
        strncpy(rt_proximity->down, rt_map->tiles[DOWN][pos_x].name, TILE_NAME_SIZE);
    }
    if (LEFT >= 0 && LEFT <= bound_x) {
        strncpy(rt_proximity->left, rt_map->tiles[pos_y][LEFT].name, TILE_NAME_SIZE);
    }
    if (RIGHT >= 0 && RIGHT <= bound_x) {
        strncpy(rt_proximity->right, rt_map->tiles[pos_y][RIGHT].name, TILE_NAME_SIZE);
    }

    // Diagonal Proximity
    if ((UP >= 0 && UP <= bound_y) && (LEFT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->up_left, rt_map->tiles[UP][LEFT].name, TILE_NAME_SIZE);
    }

    if ((UP >= 0 && UP <= bound_y) && (RIGHT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->up_right, rt_map->tiles[UP][RIGHT].name, TILE_NAME_SIZE);
    }

    if ((DOWN >= 0 && DOWN <= bound_y) && (LEFT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->down_left, rt_map->tiles[DOWN][LEFT].name, TILE_NAME_SIZE);
    }

    if ((DOWN >= 0 && DOWN <= bound_y) && (RIGHT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->down_right, rt_map->tiles[DOWN][RIGHT].name, TILE_NAME_SIZE);
    }

}

/**
 * RadioTideMap_printMapToTerminal()
 *
 * takes in an x and y size, and a map of
 * tiles map[x][y]. The map is looped,
 * and color characters are printed,
 * to the terminal screen.
 *
 */
void RadioTideMap_printMapToTerminal(RadioTide_Map *rt_map) {

    for (int y = 0; y < rt_map->y; y++) {

        for (int x = 0; x < rt_map->x; x++) {

            printf("%s ", rt_map->tiles[y][x].term_display);

        }

        printf("\n");

    }

}

#endif
