//
// Created by Leslie Cordell on 15-10-22.
//

#ifndef RADIOTIDE_RADIOTIDE_WEATHER_TILE_H
#define RADIOTIDE_RADIOTIDE_WEATHER_TILE_H

#include "RadioTide_Type.h"


/*
 * The base weather tiles, these values will be changed on init
 */
RadioTide_Weather_Tile weather_map_tiles[] = {
        {"rain", "'", 0, -1, -1, RAIN},
        {"wind", "~", 0, -1, -1, WIND},
        {"sandstorm", "#", 0, -1, -1, SANDSTORM},
        {"fog", "x", 0, -1, -1, FOG},
        {"clear", ".", 0, -1, -1, CLEAR},
        {"overcast", "+", 0, -1, -1, OVERCAST},
        {"snow", "*", 0, -1, -1, SNOW},
};


int RadioTideWeatherTile_getTileIdx(char *tile_name);

RadioTide_Weather_Tile RadioTideWeatherTile_getRandomTile();

#endif
