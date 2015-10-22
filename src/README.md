RadioTide
=========

Everything begins with the initial map, and then other maps are then created off of
the map, as all components are needed to run RadioTide successfully; a Map, a Weather
Map, a Population Map, Territory Map and Tile Map. Every tile on the initial map must have its own
Tile map nested within it, which will have its own share of maps within that for people,
objects etc.

- First start by creating a new map and generating it, it can be generated multiple times until happy with it, it can be
  displayed to console also with a console function, but a GUI should be used to display it:
  
    RadioTide_Map rt_map = RadioTideMap_newMap();
    RadioTideMap_generateMap(x, y, &rt_map);
    RadioTideMap_printMapToTerminal(&rt_map);
    
- Then create a new Weather Map and then generate it:

    RadioTide_Weather_Map rt_weather_map = RadioTideWeather_newWeatherMap(&rt_map);
    RadioTideWeather_generateWeatherMap(&rt_weather_map);
    
    
    
    
- Finalize by releasing the maps in sequence:

    RadioTideMap_releaseMap(&rt_map);
