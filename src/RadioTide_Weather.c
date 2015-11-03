#ifndef RADIOTIDE_WEATHER_C
#define RADIOTIDE_WEATHER_C

#include "RadioTide_Weather.h"
#include "main.h"

/**
 * RadioTideWeather_newWeatherMap()
 *
 * returns a new weather map, requires an initialised radio tide map,
 * returns.
 */
RadioTide_Weather_Map RadioTideWeather_newWeatherMap(RadioTide_Map *rt_map) {
    RadioTide_Weather_Map rt_weather_map;

    rt_weather_map.rt_map = rt_map;
    rt_weather_map.tiles = NULL;
    rt_weather_map.wind_direction = LEFT;

    return rt_weather_map;
}

/**
 * RadioTideWeather_generateWeatherMap()
 *
 * generates a new weather map, which creates an entirely new weather
 * topography
 *
 * @TODO don't use a random weather tile, make sure that weather is formed
 *       in a more clearer fashion, with more chance of heat or cold in certain
 *       tiles.
 */
void RadioTideWeather_generateWeatherMap(RadioTide_Weather_Map *rt_weather_map) {

    RadioTideWeather_freeWeatherMapTiles(rt_weather_map);

    rt_weather_map->tiles = malloc(sizeof(RadioTide_Weather_Tile) * rt_weather_map->rt_map->y);

    for (int y = 0; y < rt_weather_map->rt_map->y; y++) {

        rt_weather_map->tiles[y] = malloc(sizeof(RadioTide_Weather_Tile) * rt_weather_map->rt_map->x);

        for (int x = 0; x < rt_weather_map->rt_map->x; x++) {

            // get and fill a new set of proximity parameters,
            // add a new tile depending on tile proximity
            RadioTide_Proximity rt_proximity;
            RadioTideWeather_checkProximity(x, y, x, y, rt_weather_map, &rt_proximity);

            rt_weather_map->tiles[y][x] = RadioTideWeatherTile_getRandomTile();

        }

    }

}

/**
 * RadioTideWeather_checkProximity()
 *
 * checks all of the tiles surrounding a current tile position (x, y)
 * to the current bounds of the tile set (x, y), if being used while
 * building the map, the bounds will likely be the same as the position.
 *
 */
void RadioTideWeather_checkProximity(int bound_x, int bound_y, int pos_x, int pos_y, RadioTide_Weather_Map *rt_weather_map, RadioTide_Proximity *rt_proximity) {

    int UP = pos_y - 1;
    int DOWN = pos_y + 1;
    int LEFT = pos_x - 1;
    int RIGHT = pos_x + 1;

    strncpy(rt_proximity->center, rt_weather_map->tiles[pos_y][pos_x].name, TILE_NAME_SIZE);

    // Straight proximity
    if (UP >= 0 && UP <= bound_y) {
        strncpy(rt_proximity->up, rt_weather_map->tiles[UP][pos_x].name, TILE_NAME_SIZE);
    }
    if (DOWN >= 0 && DOWN <= bound_y) {
        strncpy(rt_proximity->down, rt_weather_map->tiles[DOWN][pos_x].name, TILE_NAME_SIZE);
    }
    if (LEFT >= 0 && LEFT <= bound_x) {
        strncpy(rt_proximity->left, rt_weather_map->tiles[pos_y][LEFT].name, TILE_NAME_SIZE);
    }
    if (RIGHT >= 0 && RIGHT <= bound_x) {
        strncpy(rt_proximity->right, rt_weather_map->tiles[pos_y][RIGHT].name, TILE_NAME_SIZE);
    }

    // Diagonal Proximity
    if ((UP >= 0 && UP <= bound_y) && (LEFT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->up_left, rt_weather_map->tiles[UP][LEFT].name, TILE_NAME_SIZE);
    }

    if ((UP >= 0 && UP <= bound_y) && (RIGHT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->up_right, rt_weather_map->tiles[UP][RIGHT].name, TILE_NAME_SIZE);
    }

    if ((DOWN >= 0 && DOWN <= bound_y) && (LEFT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->down_left, rt_weather_map->tiles[DOWN][LEFT].name, TILE_NAME_SIZE);
    }

    if ((DOWN >= 0 && DOWN <= bound_y) && (RIGHT >= 0 && LEFT <= bound_x)) {
        strncpy(rt_proximity->down_right, rt_weather_map->tiles[DOWN][RIGHT].name, TILE_NAME_SIZE);
    }

}

/**
 * RadioTideWeather_freeWeatherMapTiles()
 *
 * free the weather map tiles from memory
 */
void RadioTideWeather_freeWeatherMapTiles(RadioTide_Weather_Map *rt_weather_map) {

    if (rt_weather_map->tiles != NULL) {

        for (int y = 0; y < rt_weather_map->rt_map->y; y++) {

            if (rt_weather_map->tiles[y] != NULL) {
                free(rt_weather_map->tiles[y]);
            }

        }

        free(rt_weather_map->tiles);
        rt_weather_map->tiles = NULL;

    }

}

/**
 * RadioTideWeather_releaseWeatherMap()
 *
 * frees everything allocated within the weather map
 * and nullifies the map instance.
 */
void RadioTideWeather_releaseWeatherMap(RadioTide_Weather_Map *rt_weather_map) {

    RadioTideWeather_freeWeatherMapTiles(rt_weather_map);

}

/**
 * RadioTideWeather_printWeatherMapToTerminal()
 *
 * takes in an x and y size, and a weather map of
 * weather tiles [x][y]. The weather map is looped,
 * and characters are printed,
 * to the terminal screen.
 *
 */
void RadioTideWeather_printWeatherMapToTerminal(RadioTide_Weather_Map *rt_weather_map) {

    for (int y = 0; y < rt_weather_map->rt_map->y; y++) {

        for (int x = 0; x < rt_weather_map->rt_map->x; x++) {

            printf("%s ", rt_weather_map->tiles[y][x].term_display);

        }

        printf("\n");

    }

}

#endif