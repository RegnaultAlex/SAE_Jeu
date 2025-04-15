// REGNAULT ALEX & DUSSAUTOIS TOM

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "types.h"



// Types of enemies : BANDITS, GOLEM, SANDWORM, BEETLE, GUARDIAN


// Sets the default stats of the enemy depending on his type
void SetDefaultNpcStats(char enemytype, Npc *enemy);

// Gets the best weapon own by the player
char getBestWeapon(Inventory *inv);

// Manages fights between the player and the enemy
void Fight(Player *player, Inventory *playerInv, Npc *enemy, char language, bool *isFinished, int max_health, int max_energy);

// Shows if the player is dead
bool isPlayerDead(Player *player);

