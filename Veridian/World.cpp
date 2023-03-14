#include "World.h"
#include <math.h>

World::World() {
	for (int i = 0; i < 32; i++) {
		for (int k = 0; k < 32; k++) {
			
			tilemap[i][k] = 0;
		}
	}
	tilemap[1][0] = 2;
	tilemap[0][1] = 1;
}