#ifndef RADIOTIDE_MAIN
#define RADIOTIDE_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/main.h"


int main() {
    // reset random
    srand(time(NULL));

    RadioTide_Map rt_map = RadioTideMap_newMap();
    int x = 40;
    int y = 15;

    // Generate a map and print it
    printf("Terrain Map\n");
    printf("===========\n");
    printf("\n");
    RadioTideMap_generateMap(x, y, &rt_map);
    RadioTideMap_printMapToTerminal(&rt_map);

    printf("\n");

    printf("Weather Map\n");
    printf("===========\n");
    printf("\n");
    // Create a weather map only when map is decided
    RadioTide_Weather_Map rt_weather_map = RadioTideWeather_newWeatherMap(&rt_map);

    RadioTideWeather_generateWeatherMap(&rt_weather_map);
    RadioTideWeather_printWeatherMapToTerminal(&rt_weather_map);

    // RadioTideWeather_releaseWeatherMap(&rt_weather_map);
    RadioTideMap_releaseMap(&rt_map);


    return 0;
}

#endif
