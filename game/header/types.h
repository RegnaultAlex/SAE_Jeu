// REGNAULT ALEX & DUSSAUTOIS TOM

#ifndef INV
#define INV

typedef struct
{
    int water;
    int coins;
    int map_fragment;
    int handgun;
    int rifle;
    int mechanical_piece;
    int armor;
    int health_potion;
    int energy_potion;
    int blue_fragment;
    int cursed_map;
} Inventory;

#endif

#ifndef PLAYER
#define PLAYER

typedef struct
{
    char name[20];
    char pclass[20];
    int health;
    int energy;
    int hydration;
    float lootMultiplier;
    float armorMultiplier;
    float attackMultiplier;
} Player;

#endif

#ifndef NPC
#define NPC

typedef struct {
    int damage;
    int health;
} Npc;


#endif