#include "../header/playerCharacts.h"


Player SetPlayerCharacts(char defaultPath[], Player player)
{

    char language[10];

    // If the default path is the english path then we add the language English, otherwise we add the language French
    strcmp(defaultPath, "../text/ig-text/English") == 0 ? strcpy(language, "English") : strcpy(language, "French");

    // name
    strcmp(language, "English") == 0 ? printf("\nPlease enter a name for your character : ") : printf("\nVeuillez entrer un nom pour votre personnage : ");
    scanf("%s", player.name);

    do
    {
        strcmp(language, "English") == 0 ? printf("\nPlease, %s choose the class of your character : \n\n\
Soldier : Heavy attacks but less health \n\
Looter  : Weak attacks loots more coins \n\
Guard   : Weak attacks but hight health \n\n",
                                                  player.name)
                                         : printf("\n%s, veuillez choisir une classe pour votre personnage : \n\n\
Soldat  : Attaques lourdes mais peu de points de points de vie \n\
Pillard : Attaques faibles, points de vie moyen et recupere plus de pieces sur les mobs \n\
Garde : Attaque faible mais points de vie eleves \n\n",
                                                  player.name);
        scanf("%s", player.pclass);

        // Set the characters of the string choice to lowercase characters
        for (int i = 0; player.pclass[i] != '\0'; i++)
        {
            player.pclass[i] = tolower(player.pclass[i]);
        }

    } while (strcmp(player.pclass, "soldat") != 0 &&
             strcmp(player.pclass, "soldier") != 0 &&
             strcmp(player.pclass, "looter") != 0 &&
             strcmp(player.pclass, "pillard") != 0 &&
             strcmp(player.pclass, "guard") != 0 &&
             strcmp(player.pclass, "garde") != 0);

    if (strcmp(player.pclass, "soldat") == 0 || strcmp(player.pclass, "soldier") == 0)
    {
        player.health = 85;
        player.attackMultiplier = 1.7;
        player.lootMultiplier = 1;
    }
    else if (strcmp(player.pclass, "looter") == 0 || strcmp(player.pclass, "pillard") == 0)
    {
        player.health = 110;
        player.attackMultiplier = 0.7;
        player.lootMultiplier = 1.5;
    }
    else
    {
        player.health = 135;
        player.attackMultiplier = 0.8;
        player.lootMultiplier = 1;
    }

    player.hydration = 100;
    player.energy = 100;
    player.armorMultiplier = 1;

    return player;
}

void ShowStats(Player *player, char language)
{
    if (language == 'E')
    {
        printf("\nName : %s\n", player->name);
        printf("Health : %d\n", player->health);
        printf("Hydration : %d\n", player->hydration);
        printf("Energy : %d\n\n", player->energy);

        if (player->hydration <= 40)
            printf("Drink otherwise you will die !\n\n");
    }
    else
    {
        printf("\nNom : %s\n", player->name);
        printf("Vie : %d\n", player->health);
        printf("Hydratation : %d\n", player->hydration);
        printf("Energie : %d\n\n", player->energy);

        if (player->hydration <= 40)
            printf("Buvez sinon vous allez mourir !\n\n");
    }
}


void HydrationEnergy(Player *player, char language)
{

    if (player->hydration <= 20 || player->energy <= 25)
    {
        if (player->energy <= 25)
        {
            language == 'E' 
                ? printf("\n\nYou can t change your position, you do not have enough energy to move\nDrink an energy potion\n")
                : printf("\n\nVous ne pouvez pas changer de position, vous n avez pas assez d energie pour vous deplacer\nVeuillez boire une potion d energie\n");
        }
        else 
        {
            language == 'E' 
                ? printf("\n\nYou can t change your position, you re not hydrated enough\nDrink water !\n")
                : printf("\n\nVous ne pouvez pas changer de position, vous n etes pas assez hydrater\nVeuillez boire !\n");
        }
    }
    else 
    {
        player->hydration -= 20;
        player->energy -= 25;
    }



}