// REGNAULT ALEX & DUSSAUTOIS TOM

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./types.h"
#include <stdbool.h>


#define SIZE 3


// Sets the default inventory items of the player
void SetInventory(Inventory *inv);

// Manages the number of coins that the player the gets when he kills an enemy
void FindCoins(Inventory *inv, Player *player, char language);

// Shows the inventory of the player
void showInventory(Inventory *inv, char language, Player *player, int max_health, int max_energy);

// Allows the player to consume or interact with the items of his inventory
void interactInventory(Inventory *inv, char language, Player *player, int max_health, int max_energy);

// Sets a random inventory for the merchant
void SetTraderInventory(Inventory *inv);

// Shows what the merchant is selling
void ShowTraderInventory(Inventory *inv, char language);

// Allows to buy items from the merchant
void BuyTrader(Inventory *trader, Inventory *player, char language);

// Determine if the player will success or fail to steal the merchant
bool ProbaSteal();

// Determine what the player stole to the merchant
void StealTrader(Player *player, Inventory *playerinv, Inventory *traderinv, char language, bool *finished);

// Generate a random map
void generateRandomMap();



