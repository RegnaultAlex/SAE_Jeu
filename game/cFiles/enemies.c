#include "../header/enemies.h"


void SetDefaultNpcStats(char enemytype, Npc *enemy)
{

    if (enemytype == 'B') // Bandits
    {
        enemy->health = 80;
        enemy->damage = (rand() % 6) + 10;
    }
    else if (enemytype == 'G') // Golem
    {
        enemy->health = 170;
        enemy->damage = (rand() % 6) + 25;
    }
    else if (enemytype == 'S') // Sandworm
    {
        enemy->health = 120;
        enemy->damage = (rand() % 6) + 20;
    }
    else if (enemytype == 'A') // Guardian
    {
        enemy->health = 120;
        enemy->damage = (rand() % 6) + 20;
    }
    else // Beetle
    {
        enemy->health = 95;
        enemy->damage = (rand() % 6) + 10;
    }


}


char getBestWeapon(Inventory *inv)
{
    if (inv->rifle == 1)
        return 'R'; // Rifle
    else if (inv->handgun == 1)
        return 'H'; // HandGun
    else 
        return 'D'; // Default
}


void Fight(Player *player, Inventory *playerInv, Npc *enemy, char language, bool *isFinished, int max_health, int max_energy)
{

    int choice, damage, counter = 0;
    char bestWeapon = getBestWeapon(playerInv);

    while (player->health > 0 && enemy->health > 0)
    {

        if (counter % 3 == 0)
        {
            choice = 0;

            while (choice != 1)
            {
                language == 'E'
                ? printf("\n1 : Attack your enemy\n2 : Display your stats\n3 : Display inventory\n\n")
                : printf("\n1 : Attaquer l ennemi\n2 : Afficher vos statistiques\n3 : Afficher l inventaire\n\n");

                scanf("%d", &choice);


                while (choice != 1 && choice != 2 && choice != 3)
                {

                    language == 'E'
                        ? printf("Please choose a correct number !\n\n")
                        : printf("Veuillez choisir un chiffre correct !\n\n");

                    scanf("%d", &choice);

                }
                

                switch (choice)
                {
                    case 1:
                        // Player hits the enemy
                        if (bestWeapon == 'R')
                        {
                            damage = (rand() % 6) + 30 * player->attackMultiplier;
                            enemy->health -= damage ;
                        }
                        else if (bestWeapon == 'H')
                        {
                            damage = (rand() % 6) + 20 * player->attackMultiplier;
                            enemy->health -= damage ;
                        }
                        else 
                        {
                            damage = (rand() % 6) + 8 * player->attackMultiplier;
                            enemy->health -= damage ;
                        }
                        
                        language == 'E'
                            ? printf("You have inflicted %d damages to your enemy\n\n", damage)
                            : printf("Vous avez inflige %d de degats a votre ennemi\n\n", damage);

                        if (enemy->health > 0)
                        {
                            int damage = (enemy->damage + rand() % 5) * player->armorMultiplier;
                            player->health -= damage;
                            
                            language == 'E'
                                ? printf("Your enemy inflicted you %d damages\n\n", damage)
                                : printf("Votre ennemi vous a inflige %d degats\n\n", damage);
                        }
                        break;
                    
                    case 2:

                        ShowStats(player, language);
                        break;

                    case 3:

                        showInventory(playerInv, language, player, max_health, max_energy);
                        break;
                }
            }

            
        }
        else 
        {
            
            if (bestWeapon == 'R')
            {
                damage = (rand() % 6) + 30 * player->attackMultiplier;
                enemy->health -= damage ;
            }
            else if (bestWeapon == 'H')
            {
                damage = (rand() % 6) + 20 * player->attackMultiplier;
                enemy->health -= damage ;
            }
            else 
            {
                damage = (rand() % 6) + 8 * player->attackMultiplier;
                enemy->health -= damage ;
            }
            
            language == 'E'
                ? printf("You have inflicted %d damages to your enemy\n\n", damage)
                : printf("Vous avez inflige %d de degats a votre ennemi\n\n", damage);

            if (enemy->health > 0)
            {
                int damage = (enemy->damage + rand() % 5) * player->armorMultiplier;
                player->health -= damage;
                
                language == 'E'
                    ? printf("Your enemy inflicted you %d damages\n\n", damage)
                    : printf("Votre ennemi vous a inflige %d degats\n\n", damage);
            }
          


        }
        
        counter++;


    }


    if (!isPlayerDead(player) && (rand() % 3 == 2))
    {
        playerInv->blue_fragment++;
        language == 'E'
            ? printf("You just received a blue fragment !\n\n")
            : printf("Vous venez de recevoir un fragment bleu !\n\n");
    }

    if (!isPlayerDead(player))
        FindCoins(playerInv, player, language);

    if (isPlayerDead(player))
    {
        *isFinished = true;
        language == 'E'
            ? printf("You re dead !\n")
            : printf("Vous venez de succomber!\n");
    }
        
    
    


}

bool isPlayerDead(Player *player) {return player->health <= 0;}
