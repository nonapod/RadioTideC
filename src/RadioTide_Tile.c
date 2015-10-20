#ifndef RADIOTIDE_TILE_C
#define RADIOTIDE_TILE_C

#include <string.h>
#include "RadioTide_Tile.h"



/**
 * RadioTide_Tile_getTileIdx().
 *
 * gets a map tile idx if it is defined in the map_tiles
 * variable in tile.h
 */
int RadioTide_Tile_getTileIdx(char *tile_name) {
    int tile_count = sizeof(map_tiles) / sizeof(RadioTide_Tile);

    for (int i = 0; i < tile_count; i++) {
        if (!strncmp(map_tiles[i].name, tile_name, TILE_NAME_SIZE)) {
            return i;
        }
    }

    return -1;

}

/**
 * RadioTide_Tile_getRandomTile()
 *
 * gets a random tile from the map_tiles variable defined
 * in tile.h
 */
RadioTide_Tile RadioTide_Tile_getRandomTile() {

    int tile_count = sizeof(map_tiles) / sizeof(RadioTide_Tile);
    int random_tile_idx = (rand() % (tile_count + 1 - 0) + 0) - 1;

    random_tile_idx = (random_tile_idx < 0) ? 0 : random_tile_idx;
    return map_tiles[random_tile_idx];

}

/**
 * RadioTide_Tile_getRandomTileIdxOfCharacteristic()
 *
 * takes in a characteristic and loops over all of the tiles
 * by random numbers until it arrives at a tile of the given
 * characteristic type. In order to prevent a while loop,
 * an exhaust value is given, when it reaches 0 the while loop
 * breaks and -1 is returned.
 */
int RadioTide_Tile_getRandomTileIdxOfCharacteristic(Characteristic characteristic) {
    int exhaust = 100;
    int tile_count = sizeof(map_tiles) / sizeof(RadioTide_Tile);

    while (exhaust > 0) {
        int random_tile_idx = rand() % tile_count +  0;
        if (map_tiles[random_tile_idx].characteristic == characteristic) {
            return random_tile_idx;
        }
        exhaust--;
    }

    return -0;
}

/**
 * RadioTide_Tile_getRandomTileByProximity()
 *
 * gets a random tile from the map_tiles variable defined
 * in tile.h, by cross referencing a proximity set and
 * existing map.
 */
RadioTide_Tile RadioTide_Tile_getRandomTileByProximity(RadioTide_Proximity *proximity, RadioTide_Map *rt_map) {

    // predefine a random tile idx, we'll try to get another one depending on proximity
    int tile_count = sizeof(map_tiles) / sizeof(RadioTide_Tile);
    int final_tile_idx = rand() % tile_count +  0;

    int tile_idxs[TILE_DIRECTIONS];

    // get the proximity tile indexes
    tile_idxs[0] = RadioTide_Tile_getTileIdx(proximity->up_left);
    tile_idxs[1] = RadioTide_Tile_getTileIdx(proximity->up);
    tile_idxs[2] = RadioTide_Tile_getTileIdx(proximity->up_right);
    tile_idxs[3] = RadioTide_Tile_getTileIdx(proximity->left);
    tile_idxs[4] = RadioTide_Tile_getTileIdx(proximity->center);
    tile_idxs[5] = RadioTide_Tile_getTileIdx(proximity->right);
    tile_idxs[6] = RadioTide_Tile_getTileIdx(proximity->down_left);
    tile_idxs[7] = RadioTide_Tile_getTileIdx(proximity->down);
    tile_idxs[8] = RadioTide_Tile_getTileIdx(proximity->down_right);

    for (int i = 0; i < TILE_DIRECTIONS; i++) {

        if (tile_idxs[i] > -1) {

            Characteristic characteristic = map_tiles[tile_idxs[i]].characteristic;
            int chance = rt_map->characteristic_chance[characteristic];
            int roll = (rand() % 100 + 1);

            // set the final tile idx to the new random tile type
            if (chance > roll) {
                int new_tile_idx = RadioTide_Tile_getRandomTileIdxOfCharacteristic(characteristic);
                if (new_tile_idx > -1) {
                    final_tile_idx = new_tile_idx;
                }
            }


        }

    }
    // exit(0);

    return map_tiles[final_tile_idx];
}

#endif
