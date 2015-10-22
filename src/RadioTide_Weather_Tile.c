#ifndef RADIOTIDE_WEATHER_TILE_C
#define RADIOTIDE_WEATHER_TILE_C

#include "RadioTide_Weather_Tile.h"


/**
 * RadioTideWeatherTile_getTileIdx().
 *
 * gets a weather map tile idx if it is defined in the map_tiles
 * variable in tile.h
 */
int RadioTideWeatherTile_getTileIdx(char *tile_name) {
    int tile_count = sizeof(weather_map_tiles) / sizeof(RadioTide_Weather_Tile);

    for (int i = 0; i < tile_count; i++) {
        if (!strncmp(weather_map_tiles[i].name, tile_name, TILE_NAME_SIZE)) {
            return i;
        }
    }

    return -1;

}

/**
 * RadioTideWeatherTile_getRandomTile()
 *
 * gets a random tile from the map_tiles variable defined
 * in tile.h
 */
RadioTide_Weather_Tile RadioTideWeatherTile_getRandomTile() {

    int tile_count = sizeof(weather_map_tiles) / sizeof(RadioTide_Weather_Tile);
    int random_tile_idx = (rand() % (tile_count + 1 - 0) + 0) - 1;

    random_tile_idx = (random_tile_idx < 0) ? 0 : random_tile_idx;
    return weather_map_tiles[random_tile_idx];

}


#endif
