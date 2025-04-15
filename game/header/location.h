// REGNAULT ALEX & DUSSAUTOIS TOM

#include <stdbool.h>
#include "./readFile.h"


#define COORDS 2       // X & Y axis



// Shows the correct text depending on the position of the player and if he already passed the location
void handleLocation(int location[COORDS], int visited, char defaultPath[], char name[], char language);

// Shows if the location is visited
bool isVisited(int visited);



