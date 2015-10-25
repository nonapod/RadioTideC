#ifndef RADIOTIDE_MAIN
#define RADIOTIDE_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/main.h"

int main() {
    // reset random
    /*srand(time(NULL));

    RadioTide_Map rt_map = RadioTideMap_newMap();
    int x = 40;
    int y = 15;

    // Generate a map and print it
    RadioTideMap_generateMap(x, y, &rt_map);
    RadioTideMap_printMapToTerminal(&rt_map);

    // Create a weather map only when settled on a map
    RadioTide_Weather_Map rt_weather_map = RadioTideWeather_newWeatherMap(&rt_map);

    RadioTideWeather_generateWeatherMap(&rt_weather_map);
    RadioTideWeather_printWeatherMapToTerminal(&rt_weather_map);



    // RadioTideWeather_releaseWeatherMap(&rt_weather_map);
    RadioTideMap_releaseMap(&rt_map);*/


    // directional node testing
    Node *node = initNode();
    node->data = "tits";
    node->append(node, "bollocks");
    node->append(node, "wank");
    node->append(node, "flange");
    node->append(node, "teapot");
    node->shift(&node);
    node->pop(&node);
    node->pop(&node);
    node->pop(&node);
    printf("%d\n", node->length(node));

    Node *current = node;
    while (current != NULL) {
        printf("this: %s ", current->data);
        if (current->next != NULL) {
            printf("next: %s ", current->next->data);
        }
        if (current->prev != NULL) {
            printf("prev: %s ", current->prev->data);
        }
        printf("\n");
        current = current->next;
    }



    return 0;
}

#endif
