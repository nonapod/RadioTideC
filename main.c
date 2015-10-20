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

    RadioTideMap_generateMap(x, y, &rt_map);
    RadioTideMap_printMapToTerminal(&rt_map);

    RadioTideMap_releaseMap(&rt_map);

    return 0;
}

#endif
