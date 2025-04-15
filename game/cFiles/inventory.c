#include "../header/inventory.h"

void SetInventory(Inventory *inv)
// Sets default inventory values
{

    inv->water = 2; // Bottle that reloads 100% of hydration
    inv->coins = 5;
    inv->map_fragment = 1;
    inv->handgun = 0;
    inv->rifle = 0;
    inv->mechanical_piece = 0;
    inv->armor = 0;
    inv->health_potion = 5;
    inv->energy_potion = 4;
    inv->blue_fragment = 2;
    inv->cursed_map = 1;
}

void FindCoins(Inventory *inv, Player *player, char language)
{
    int max_coins = 18;

    // To get random values
    srand(time(NULL));

    int final_coins = ((rand() % max_coins) + 6) * player->lootMultiplier; // Depending on the player's loot multiplier, the player has will be able to loot more or less than 3 coins (3 is the default max coins); // The coins that the player will get

    inv->coins += final_coins;

    language == 'E'
        ? printf("You just received %d coins for killing your enemy !\nFind someone that can trade them for other objects\n", final_coins)
        : printf("Vous venez de recevoir %d pieces pour avoir tuer votre ennemi !\nTrouvez quelqu un qui pourra vous les echanger contre d autres objets\n", final_coins);
    

}

void showInventory(Inventory *inv, char language, Player *player, int max_health, int max_energy)
{

    char choice[20];

    if (language == 'E')
    {

        printf("\n\nInventory\n1 : %d bottle(s) of water\n2 : %d coin(s)\n3 : %d map fragment(s)\n4 : %d handgun\n5 : %d rifle\n6 : %d mechanical_piece(s)\n7 : %d armor(s)\n8 : %d health potion(s)\n9 : %d energy potion(s)\n10 : %d blue fragment(s)\n11 : %d cursed map", inv->water, inv->coins, inv->map_fragment, inv->handgun, inv->rifle, inv->mechanical_piece, inv->armor, inv->health_potion, inv->energy_potion, inv->blue_fragment, inv->cursed_map);

        printf("\n\n1 : Consume or use an object of your inventory \n2 : Leave inventory\n");
    }
    else
    {
        printf("\n\nInventaire\n1 : %d bouteille(s) d'eau\n2 : %d piece(s)\n3 : %d fragment(s) de la carte\n4 : %d arme de poing\n5 : %d fusil d'assault\n6 : %d piece(s) mechanique(s)\n7 : %d armure(s)\n8 : %d potion(s) de vie\n9 : %d potion(s) d energie\n10 : %d fragment(s) bleu\n11 : %d Carte maudite", inv->water, inv->coins, inv->map_fragment, inv->handgun, inv->rifle, inv->mechanical_piece, inv->armor, inv->health_potion, inv->energy_potion, inv->blue_fragment, inv->cursed_map);

        printf("\n\n1 : Consummer ou utiliser un objet de votre inventaire \n2 : Quitter l'inventaire\n");
    }

    scanf("%s", choice);

    while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0)
    {
        language == 'E'
            ? printf("Please enter a valid number !\n")
            : printf("Veuillez choisir un chiffre valide !\n");
           
 
        scanf("%s", choice);
    }

    if (strcmp(choice, "1") == 0)
        interactInventory(inv, language, player, max_health, max_energy);
}

void interactInventory(Inventory *inv, char language, Player *player, int max_health, int max_energy)
{
    char choice[20] = "0";

    while (strcmp(choice, "13") != 0)
    {
        language == 'E'
            ? printf("\nEnter the number of the object that you want to consome / use\nEnter 12 to show your stats / 13 to leave !\n\n")
            : printf("\nEntrez le chiffre de l'objet que vous souhaitez consommer / utiliser\nEntrez 12 pour voir vos statistiques / 13 pour quitter\n\n");

        scanf("%s", choice);

        if (strcmp(choice, "1") == 0)
        {
            if (inv->water > 0)
            {
                inv->water--;
                player->hydration = 100;
                language == 'E'
                    ? printf("\nYour hydration is now full\n\n")
                    : printf("\nVous etes maitenant hydrater au maximum\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t have any water bottle !\n\n")
                    : printf("\nVous ne disposez pas d'eau !\n\n");
            }
        }
        else if (strcmp(choice, "2") == 0)
        {
            if (inv->coins < 0)
            {
                language == 'E'
                    ? printf("\nFind someone that could trade object for you coins !\n\n")
                    : printf("\nTrouve quelqu'un qui pourrait t Echanger des objets contre ces pieces\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t any coin !\n\n")
                    : printf("\nVous ne possedez pas de piece !\n\n");
            }
        }
        else if (strcmp(choice, "3") == 0)
        {
            language == 'E'
                    ? printf("\nA part of a map that can lead you through the dunes\n\n")
                    : printf("\nPartie d'une carte qui sert a vous guider dans les dunes\n\n");

            char map[] =
                    "--------------------\n" 
                    "| -1;2 | 0;2 | 1;2 |\n" 
                    "--------------------\n" 
                    "| -1;1 | 0;1 | 1;1 |\n" 
                    "--------------------\n" 
                    "| -1;0 | 0;0 | 1;0 |\n" 
                    "--------------------\n"
                    "        | X |       ";

                    

            printf("%s", map);
                language == 'E'
                    ? printf("\n\nHere's what you manage to deciphers\n\n")
                    : printf("\n\nVoici ce que vous reussissez a dechiffrer\n\n");
        }
        else if (strcmp(choice, "4") == 0)
        {
            if (inv->handgun > 0)
            {
                language == 'E'
                    ? printf("\nYou own a handgun, a powerfull object that deals more damage than your poor fists\n\n")
                    : printf("\nVous possedez une arme de poing, un objet qui fait plus de degats que vos pauvres poings\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t have any handgun !\n\n")
                    : printf("\nVous n'avez pas d'arme de poing !\n\n");
            }
            
        }
        else if (strcmp(choice, "5") == 0)
        {
            if (inv->rifle > 0)
            {
                language == 'E'
                    ? printf("\nYou own a rifle, a powerfull object that deals a lot of damages\n\n")
                    : printf("\nVous possedez un fusil, un objet qui fait beaucoup de degats\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t any have rifle !\n\n")
                    : printf("\nVous n'avez pas de fusil !\n\n");
            }
        }
        else if (strcmp(choice, "6") == 0)
        {
            if (inv->mechanical_piece > 0)
            {
                language == 'E'
                    ? printf("\nA piece that can be used to create a buggy\n\n")
                    : printf("\nUne piece qui peut vous servir a creer un buggy\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t have any mechanical piece !\n\n")
                    : printf("\nVous n'avez pas de piece mecanique !\n\n");
            }
        }
        else if (strcmp(choice, "7") == 0)
        {
            if (inv->armor > 0)
            {
                inv->armor--;
                player->armorMultiplier -= 0.2;

                language == 'E'
                    ? printf("\nYou just equipped the armor !\n\n")
                    : printf("\nVous avez equipe votre armure !\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou do not own armors !\n\n")
                    : printf("\nVous n'avez pas d'armure !\n\n");
            }
        }
        else if (strcmp(choice, "8") == 0)
        {
            if (inv->health_potion > 0)
            {
                inv->health_potion--;

                if (player->health + 50 >= max_health)
                {
                    player->health = max_health;

                    language == 'E'
                        ? printf("\nYou are now at the maximum of your HP\n\n")
                        : printf("\nVous etes maintenant au maximum de vos PV\n\n");
                }
                else
                {
                    player->health += 50;

                    language == 'E'
                        ? printf("\nYou just received 50 HP\n\n")
                        : printf("\nVous venez de recuperer 50 PV\n\n");
                }

                
            }
            else
            {
                language == 'E'
                    ? printf("\nYou do not own health potions\n\n")
                    : printf("\nVous ne possedez pas de potions de vie\n\n");
            }

        
        }    
        else if (strcmp(choice, "9") == 0)
        {
            if (inv->energy_potion > 0)
            {

                inv->energy_potion--;

                if (player->energy + 50 >= max_energy)
                {
                    player->energy = max_energy;

                    language == 'E'
                        ? printf("\nYou are now at the maximum of your HP\n\n")
                        : printf("\nVous etes maintenant au maximum de votre energie\n\n");
                }
                else 
                {
                    player->energy += 50;
                
                    language == 'E'
                        ? printf("\nYou just received 50 energy points\n\n")
                        : printf("\nVous venez de gagner 50 points d energie\n\n");
                }

               
               
            }
            else
            {
                language == 'E'
                    ? printf("You do not own energy potion\n\n")
                    : printf("Vous ne possedez pas de potion d energie\n\n");
            }
        }
        else if (strcmp(choice, "10") == 0)
        {
            if (inv->blue_fragment > 0)
            {
                language == 'E'
                    ? printf("\nFragments that are going to help you to save humanity\n\n")
                    : printf("\nFragments qui vous aidera a sauver l humanite\n\n");
            }
            else
            {
                language == 'E'
                    ? printf("\nYou don t any blue fragment !\n\n")
                    : printf("\nVous n'avez pas de fragment bleu !\n\n");
            }
        }
        else if (strcmp(choice, "11") == 0)
        {
            language == 'E'
                    ? printf("\nThis map seems to be not reliable\n\n")
                    : printf("\nCette carte n'a pas l'air fiable...\n\n");

            generateRandomMap();
            
        }
        else if (strcmp(choice, "12") == 0)
        {
            ShowStats(player, language);
        }
        else if (strcmp(choice, "13") == 0)
        {
            printf("\nInventaire quitte\n\n");
        }
        else
        {
            language == 'E'
                ? printf("\n\nPlease enter a correct number !\n\n")
                : printf("\n\nVeuillez entrer un chiffre valide !\n\n");
        }


    }
}



void SetTraderInventory(Inventory *inv)
{

    srand(time(NULL));

    inv->water = (rand() % 5) + 2;
    inv->handgun = 1;
    inv->rifle = 1;
    inv->mechanical_piece = rand() % 4;
    inv->armor = rand() % 2 + 1;
    inv->health_potion = 4;
    inv->energy_potion = 5;
    inv->blue_fragment = rand() % 5;

}

void ShowTraderInventory(Inventory *inv, char language)
{
     language == 'E' 
        ? printf("Inventory :\n1 : %d Water bottle(s), price: 2 coins / bottle\n2 : %d Handgun, price: 15 coins\n3 : %d Rifle(s), price: 25 coins / rifle\n4 : %d Mechanical piece(s), price: 5 coins / piece\n5 : %d Armor, price: 20 coins\n6 : %d Health potion(s), price: 8 coins / potion\n7 : %d Energy potion(s), price: 10 coins / potion\n8 : %d Blue fragment(s), price: 60 coins / fragment\n", inv->water, inv->handgun, inv->rifle, inv->mechanical_piece, inv->armor, inv->health_potion, inv->energy_potion, inv->blue_fragment)
        : printf("Inventaire :\n1 : %d Bouteille(s) d eau, prix : 2 pieces / bouteille\n2 : %d Pistolet, prix : 15 pieces\n3 : %d Fusil(s), prix : 25 pieces / fusil\n4 : %d Piece(s) mecaniques, prix : 5 pieces / piece\n5 : %d Armure, prix : 20 pieces\n6 : %d Potion(s) de soin, prix : 8 pieces / potion\n7 : %d Potion(s) d energie, prix : 10 pieces / potion\n8 : %d Fragment(s) bleus, prix : 60 pieces / fragment\n", inv->water, inv->handgun, inv->rifle, inv->mechanical_piece, inv->armor, inv->health_potion, inv->energy_potion, inv->blue_fragment);

}


void BuyTrader(Inventory *trader, Inventory *player, char language)
{

    char choice[20] = "0"; 

    while (strcmp(choice, "9") != 0)
    {
        ShowTraderInventory(trader, language);

        language == 'E'
            ? printf("9 : Leave\n\nWhat would you like to buy ?\n")
            : printf("9 : Quitter\n\nQue souhaitez vous acheter ?\n");
        
        scanf("%s", choice);


        if (strcmp(choice, "1") == 0)
        {
            if (trader->water > 0 && player->coins > 2) {
                trader->water--;
                player->water++;
                player->coins -= 2;
                language == 'E'
                    ? printf("You bought 1 Water bottle.\n\n")
                    : printf("Vous avez achete 1 Bouteille d eau.\n\n");
            } 
            else 
            {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "2") == 0)
        {
            if (trader->handgun > 0 && player->handgun > 15) {
                trader->handgun--;
                player->handgun++;
                player->coins -= 15;
                language == 'E'
                    ? printf("You bought 1 Handgun.\n\n")
                    : printf("Vous avez achete 1 Pistolet.\n\n");
            } 
            else 
            {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "3") == 0)
        {
            if (trader->rifle > 0 && player->rifle > 25) {
                trader->rifle--;
                player->rifle++;
                player->coins -= 25;
                language == 'E'
                    ? printf("You bought 1 Rifle.\n\n")
                    : printf("Vous avez achete 1 Fusil.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "4") == 0)
        {
            if (trader->mechanical_piece > 0 && player->mechanical_piece > 5) {
                trader->mechanical_piece--;
                player->mechanical_piece++;
                player->coins -= 5;
                language == 'E'
                    ? printf("You bought 1 Mechanical piece.\n\n")
                    : printf("Vous avez achete 1 Piece mecanique.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "5") == 0)
        {
            if (trader->armor > 0 && player->armor > 20) {
                trader->armor--;
                player->armor++;
                player->coins -= 20;
                language == 'E'
                    ? printf("You bought 1 Armor.\n\n")
                    : printf("Vous avez achete 1 Armure.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "6") == 0)
        {
            if (trader->health_potion > 0 && player->health_potion > 8) {
                trader->health_potion--;
                player->health_potion++;
                player->coins -= 8;
                language == 'E'
                    ? printf("You bought 1 Health potion.\n\n")
                    : printf("Vous avez achete 1 Potion de soin.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "7") == 0)
        {
            if (trader->energy_potion > 0 && player->energy_potion > 10) {
                trader->energy_potion--;
                player->energy_potion++;
                player->coins -= 10;
                language == 'E'
                    ? printf("You bought 1 Energy potion.\n\n")
                    : printf("Vous avez achete 1 Potion d energie.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                    : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "8") == 0)
        {
            if (trader->blue_fragment > 0 && player->blue_fragment > 60) {
                trader->blue_fragment--;
                player->blue_fragment++;
                player->coins -= 60;
                language == 'E'
                    ? printf("You bought 1 Blue fragment.\n\n")
                    : printf("Vous avez achete 1 Fragment bleu.\n\n");
            } 
            else {
                language == 'E'
                    ? printf("Sorry, impossible to buy (not enought money or not enough stock).\n\n")
                : printf("Desole, impossible d'acheter (pas assez d'argent ou pas assez de stock).\n\n");
            }
        }
        else if(strcmp(choice, "9") == 0) {break;}
        else
        {   
            language == 'E'
                    ? printf("Sorry, please enter a correct number\n\n")
                    : printf("Desole, veuillez entrer un chiffre correct\n\n");
        }

    }


}




bool ProbaSteal() {return rand() % 3 == 2;}

void StealTrader(Player *player,Inventory *playerinv, Inventory *traderinv, char language, bool *finished)
{

    int steal = 0;
    bool probability = ProbaSteal();

    if (probability)
    {        


        while (steal < 2)
        {

            steal++;

            int random = rand() % 8 + 1;

            switch (random)
            {
                case 1:
                    traderinv->water--;
                    playerinv->water++;
                    language == 'E'
                    ? printf("You succefully stole 1 water bottle.\n")
                    : printf("Vous avez reussi a voler 1 bouteille d eau.\n");
                    break;
                
                case 2:
                    traderinv->handgun--;
                    playerinv->handgun++;
                    language == 'E'
                    ? printf("You succefully stole 1 handgun.\n")
                    : printf("Vous avez reussi a voler une arme de poing.\n");
                    break;

                case 3:
                    traderinv->rifle--;
                    playerinv->rifle++;
                    language == 'E'
                    ? printf("You succefully stole 1 rifle.\n")
                    : printf("Vous avez reussi a voler 1 fusil.\n");
                    break;

                case 4:
                    traderinv->mechanical_piece--;
                    playerinv->mechanical_piece++;
                    language == 'E'
                    ? printf("You succefully stole 1 mechanical piece.\n")
                    : printf("Vous avez reussi a voler 1 piece mecanique.\n");
                    break;

                case 5:
                    traderinv->armor--;
                    playerinv->armor++;
                    language == 'E'
                    ? printf("You succefully stole 1 armor.\n")
                    : printf("Vous avez reussi a voler 1 armure.\n");
                    break;

                case 6:
                    traderinv->health_potion--;
                    playerinv->health_potion++;
                    language == 'E'
                    ? printf("You succefully stole 1 health potion.\n")
                    : printf("Vous avez reussi a voler 1 potion de soin.\n");
                    break;

                case 7:
                    traderinv->energy_potion--;
                    playerinv->energy_potion++;
                    language == 'E'
                    ? printf("You succefully stole 1 energy potion.\n")
                    : printf("Vous avez reussi a voler 1 potion d'energie.\n");
                    break;

                case 8:
                    traderinv->blue_fragment--;
                    playerinv->blue_fragment++;
                    language == 'E'
                    ? printf("You succefully stole 1 blue fragment.\n")
                    : printf("Vous avez reussi a voler 1 fragment bleu.\n");
                    break;
                
            }


        }

    }
    else
    {
        
        language == 'E'
            ? printf("The merchant was able to defend himself, but you lost 40 hit points !")
            : printf("Le marchand a reussi a se defendre, vous avez perdu 40 points de vie !");

        
        player->health -= 40;

        if (player->health <= 0)
            *finished = true;

    }
    
}

void generateRandomMap()
{
    int values[SIZE][SIZE];

    // Générer des valeurs aléatoires pour chaque case
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            values[y][x] = rand() % 10 - 5;
        }
    }

    // Afficher la carte
    printf("---------------------\n");
    for (int y = SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < SIZE; x++) {
            printf("| %2d;%d ", values[y][x], y);
        }
        printf("|\n---------------------\n");
    }
    printf("        | X |       \n");

}

