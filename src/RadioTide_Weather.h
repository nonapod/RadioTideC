#ifndef RADIOTIDE_RADIOTIDE_WEATHER_H
#define RADIOTIDE_RADIOTIDE_WEATHER_H

#include "RadioTide_Type.h"
#include "RadioTide_Weather_Tile.h"

RadioTide_Weather_Map RadioTideWeather_newWeatherMap(RadioTide_Map *rt_map);

void RadioTideWeather_generateWeatherMap(RadioTide_Weather_Map *rt_weather_map);

void RadioTideWeather_freeWeatherMapTiles(RadioTide_Weather_Map *rt_weather_map);

void RadioTideWeather_releaseWeatherMap(RadioTide_Weather_Map *rt_weather_map);

void RadioTideWeather_printWeatherMapToTerminal(RadioTide_Weather_Map *rt_weather);

#endif
