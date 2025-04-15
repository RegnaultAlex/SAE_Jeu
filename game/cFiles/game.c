#include "../header/game.h"


void startGame()
{
    // Game
    bool is_finished = false;

    // Handle text files
    char language;
    char defaultPath[50] = "../text/ig-text/";
    char currentpath[50];

    // Player's character
    Player player;

    // Player's inventory
    Inventory inventory;

    // Player's choice
    char choice;

    // Visited Location
    int visited[NB_LOCATIONS];
    setVisited(visited);

    // If first (0;0) is visited, default_visited = 1
    int default_visited = 0;

    // Get player's language
    getLanguage(defaultPath);
    setLanguage(defaultPath, &language);
    strcpy(currentpath, defaultPath);
    
    // Get player's characteristics
    player = SetPlayerCharacts(defaultPath, player);
    SetInventory(&inventory);
    int max_health = player.health + 20;
    int max_energy = 125;

    // Handle player's position
    int position[COORDS];

    // Trader
    Inventory trader;
    SetTraderInventory(&trader);
    

    // Introduction
    language == 'E'
        ? readFile(strcat(currentpath, "/Synopsis-GB.txt"))
        : readFile(strcat(currentpath, "/Synopsis-FR.txt"));
    strcpy(currentpath, defaultPath);


    // Game
    char frenchPath[50];
    char englishPath[50];

    strcpy(frenchPath, defaultPath);
    strcat(frenchPath, "/Game-FR.txt");
    strcpy(englishPath, defaultPath);
    strcat(englishPath, "/Game-GB.txt");

    // 1st scene
    if (language == 'E')
    {
        readLines(strcat(currentpath, "/Game-GB.txt"), 2, 3);
        strcpy(currentpath, defaultPath);
        readLines(strcat(currentpath, "/Game-GB.txt"), 6, 7);
    }
    else
    {
        readLines(strcat(currentpath, "/Game-FR.txt"), 2, 3);
        strcpy(currentpath, defaultPath);
        readLines(strcat(currentpath, "/Game-FR.txt"), 6, 7);
    }
    strcpy(currentpath, defaultPath);

    ShowStats(&player, language);
    
    
    language == 'E'
        ? printf("\nWhat do you want to do ?\n1 : Leave the cabin\n2 : Inventory\n\n")
        : printf("\nQue souhaitez vous faire ?\n1 : Sortir de la cabane\n2 : Inventaire\n\n");
    fflush(stdin);
    choice = getchar();

    while (choice != '1' && choice != '2')
    {
        language == 'E'
            ? printf("\n\nThe number was not valid !\n\nWhat do you want to do ?\n1 : Leave the cabin\n2 : Inventory\n\n")
            : printf("\n\nLe chiffre n est pas valide !\n\nQue souhaitez vous faire ?\n1 : Sortir de la cabane\n2 : Inventaire\n\n");
        fflush(stdin);
        choice = getchar();
    };

    while (choice != '1')
    {
    
        showInventory(&inventory, language, &player, max_health, max_energy);
        language == 'E'
            ? printf("\n\nWhat do you want to do ?\n1 : Leave the cabin\n2 : Inventory\n\n")
            : printf("\n\nQue souhaitez vous faire ?\n1 : Sortir de la cabane\n2 : Inventaire\n\n");
        fflush(stdin);
        choice = getchar();
    }


    // Default position
    position[0] = 0;
    position[1] = 0;


    // While the game is not finished
    while (!is_finished)
    {
        

        if (position[0] == 0 && position[1] == 0) // If current location is (0;0)
        {

            visited[0] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar(); // The user choose what he wants

            
            while (choice != '1' && choice != '2') // If the user select a number different of 1 or 2
            {
                

                language == 'E'
                    ? printf("\n\nThe number is not valid !\n\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\n\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '1' || (choice == '1' && (player.hydration <= 20 || player.energy <= 25)) ) // While the player doesnt want to take a direction or if he wants to take it , if he doesnt have enough energy or water
            {

                if (choice == '2')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);
                }
                else if (choice == '1' && (player.hydration <= 20 || player.energy <= 25))
                {

                    HydrationEnergy(&player,language);
                    
                }

                language == 'E'
                    ? readLines(englishPath, 13, 15)
                    : readLines(frenchPath, 13, 15);

                fflush(stdin);
                choice = getchar();
                
            }          


            HydrationEnergy(&player,language); // Reduce player's hydration & energy


            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : North\n2 : East\n\n")
                : printf("\n\nQuelle directions souhaitez vous prendre ?\n1 : Nord\n2 : Est\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2') // If the user do not select a correct direction
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }


            

            switch (choice)
            {
                case '1': // If North is choosen
                    position[1] = 1;
                    break;
                case '2': // If East is choosen
                    position[0] = 1;
                    break;
                default :
                    break;
            }

            default_visited = 1;

        }
        else if (position[0] == 0 && position[1] == 1) // If current location is (0;1)
        {

            default_visited = 1;
            visited[1] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            player.health -= 20;

            

            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            if (language == 'E')
            {
                printf("You lost 20 HP\n\n");
                readLines(englishPath, 19, 21);
            }
            else 
            {
                printf("Vous venez de perdre 20 HP\n\n");
                readLines(frenchPath, 19, 21);
            }

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\n\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\n\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '1' || (choice == '1' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }
                else 
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);
                }
                    
                
                language == 'E'
                    ? readLines(englishPath, 19, 21)
                    : readLines(frenchPath, 19, 21);

                fflush(stdin);
                choice = getchar();
            
            }

            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : North\n2 : South\n3 : West\n\n")
                : printf("\n\nQuelle directions souhaitez vous prendre ?\n1 : Nord\n2 : Sud\n3 : Ouest\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            switch (choice)
            {
                case '1': // If North is choosen
                    position[1] = 2;
                    break;
                case '2': // If South is choosen
                    position[1] = 0;
                    break;
                case '3': // If West is choosen
                    position[0] = -1;
                    break;
            }


        }
        else if (position[0] == 0 && position[1] == 2) // If current location is (0;2)
        {
            default_visited = 1;
            visited[2] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



    
            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();
            
            while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");
                
                fflush(stdin);
                choice = getchar();
            }

            while (choice != '3' || (choice == '3' && (player.hydration <= 20 || player.energy <= 25)))
            {
                
                if (choice == '1')
                {
                    BuyTrader(&trader, &inventory, language);
                }
                else if (choice == '2')
                {

                    StealTrader(&player,&inventory, &trader, language, &is_finished);

                    if (is_finished)
                        language == 'E'
                            ? printf("\n\nYou died !\n\n")
                            : printf("\n\nVous avez succombe !\n\n");
                    
                }
                else if (choice == '4')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);

                }
                else if (choice == '3' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }
                
                if (is_finished)
                    break;

                language == 'E'
                    ? readLines(englishPath, 25, 29)
                    : readLines(frenchPath, 25, 29);

                fflush(stdin);
                choice = getchar();


            }

            if (is_finished)
                    break;

            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : South\n2 : East\n\n")
                : printf("\n\nQuelle directions souhaitez vous prendre ?\n1 : Sud\n2 : Est\n\n");

            fflush(stdin);
            choice = getchar();


            while (choice != '1' && choice != '2')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            switch (choice)
            {
            case '1': // If South is choosen
                position[1] = 1;
                break;
            case '2': // If East is choosen
                position[0] = 1;
                break;
            }


        }    
        else if (position[0] == 1 && position[1] == 2) // If current position is (1;2)
        {

            default_visited = 1;
            visited[3] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\n\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\n\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '2' || (choice == '2' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1')
                { 

                    Npc sandWorm;
                    SetDefaultNpcStats('S', &sandWorm);

                    // Fight the sandWorm
                    Fight(&player, &inventory, &sandWorm, language, &is_finished, max_health, max_energy); 

                }
                else if (choice == '3')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);
                }
                else if (choice == '2' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }

                if (is_finished) break;
 
                language == 'E'
                    ? readLines(englishPath, 49, 52)
                    : readLines(frenchPath, 49, 52);

                fflush(stdin);
                choice = getchar();
            }

            if (is_finished) break;
            

            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : West\n\n")
                : printf("\n\nQuelle direction souhaitez vous prendre ?\n1 : Ouest\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            if (choice == 1)
                position[0] = 0;

        }
        else if (position[0] == 1 && position[1] == 1) // If current position is (1;1)
        {

            default_visited = 1;
            visited[4] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '2' || (choice == '2' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1')
                {
                    Npc bandit1;
                    SetDefaultNpcStats('B', &bandit1);

                    Fight(&player, &inventory, &bandit1, language, &is_finished, max_health, max_energy);
                }
                else if (choice == '3')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);

                }
                else if (choice == '2' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }


                if (is_finished)
                    break;


                language == 'E'
                    ? readLines(englishPath, 42, 45)
                    : readLines(frenchPath, 42, 45);

                fflush(stdin);
                choice = getchar();   

            }

            if (is_finished)
                break;

            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            if (choice == '2')
            {
                if (inventory.coins < 10)
                {
                    language == 'E'
                        ? printf("\n\n%s You only have %d coins !\n\nYou must fight them !\n\n", player.name, inventory.coins)
                        : printf("\n\n%s vous n avez que %d pieces !\n\nVous etes oblige de les combattres !\n\n", player.name, inventory.coins);


                    Npc bandit1;
                    SetDefaultNpcStats('B', &bandit1);
                    
                    // Fight
                    Fight(&player, &inventory, &bandit1, language, &is_finished, max_health, max_energy);
                    
                    
                }
            }

            if (is_finished)
                break;

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : South\n\n")
                : printf("\n\nQuelle direction souhaitez vous prendre ?\n1 : Sud\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            switch (choice)
            {
            case '1': // If South is choosen
                position[1] = 0;
                break;
            }

            inventory.coins -= 10;

        }

        else if (position[0] == 1 && position[1] == 0) // If current position is (1;0)
        {

            default_visited = 1;
            visited[5] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '2' || (choice == '2' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1')
                {
                    Npc beetle;
                    SetDefaultNpcStats('Z', &beetle);

                    Fight(&player, &inventory, &beetle, language, &is_finished, max_health, max_energy);
                }
                else if (choice == '3')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);

                }
                else if (choice == '2' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }

                if (is_finished)
                    break;

                language == 'E'
                    ? readLines(englishPath, 33, 36)
                    : readLines(frenchPath, 33, 36);

                    fflush(stdin);
                    choice = getchar();

            }

            if (is_finished)
                    break;

            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : West\n2 : North\n\n")
                : printf("\n\nQuelle direction souhaitez vous prendre ?\n1 : Ouest\n2 : Nord\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            switch (choice)
            {
            case '1': // If West is choosen
                position[0] = 0;
                break;
            case '2': // If North is choosen
                position[1] = 1;
                break;
            }

            
        }
        else if (position[0] == -1 && position[1] == 0) // If current position is (-1;0)
        {     

            default_visited = 1;
            visited[6] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '2' || (choice == '2' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1')
                {
                    Npc Guardian;
                    SetDefaultNpcStats('A', &Guardian);

                    Fight(&player, &inventory, &Guardian, language, &is_finished, max_health, max_energy);
                }
                else if (choice == '3')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);            
                }
                else if (choice == '2' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }


                if (is_finished)
                    break;

                language == 'E'
                        ? readLines(englishPath, 56, 59)
                        : readLines(frenchPath, 56, 59);

                fflush(stdin);
                choice = getchar();

            }

            if (is_finished)
                break;


            HydrationEnergy(&player,language); // Reduce player's hydration & energy

            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : North\n\n")
                : printf("\n\nQuelle direction souhaitez vous prendre ?\n1 : Nord\n\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            switch (choice)
            {
            case '1': // If North is choosen
                position[1] = 1;
                break;
            }
        
        }
        else if (position[0] == -1 && position[1] == 1) // If current position is (-1;1)
        {
            
            default_visited = 1;
            visited[7] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            while (choice != '2' || (choice == '2' && (player.hydration <= 20 || player.energy <= 25)))
            {
                if (choice == '1')
                {
                    Npc bandit2;
                    SetDefaultNpcStats('B', &bandit2);

                    Fight(&player, &inventory, &bandit2, language, &is_finished, max_health, max_energy);   
                }
                else if (choice == '3')
                {
                    showInventory(&inventory, language, &player, max_health, max_energy);

                }
                else if (choice == '2' && (player.hydration <= 20 || player.energy <= 25))
                {
                    HydrationEnergy(&player,language);
                }


                if (is_finished) break;


                language == 'E'
                        ? readLines(englishPath, 65, 68)
                        : readLines(frenchPath, 65, 68);

                    fflush(stdin);
                    choice = getchar();

            }



            if (is_finished) break;


            HydrationEnergy(&player,language); // Reduce player's hydration & energy
            
            


            if (choice == '2')
            {
                if (inventory.coins < 10)
                {
                    language == 'E'
                        ? printf("\n\n%s You only have %d coins !\n\nYou must fight them !\n\n", player.name, inventory.coins)
                        : printf("\n\n%s vous n avez que %d pieces !\n\nVous etes oblige de les combattres !\n\n", player.name, inventory.coins);


                    Npc bandit2;
                    SetDefaultNpcStats('B', &bandit2);
                    
                    // Fight
                    Fight(&player, &inventory, &bandit2, language, &is_finished, max_health, max_energy);
                    
                    
                }
            }
            


            if (is_finished)
                break;



            while(player.hydration <= 20 || player.energy <= 25)
            {
                HydrationEnergy(&player,language);
                showInventory(&inventory, language, &player, max_health, max_energy);
            }



            language == 'E' // When the player finally choose to take a direction, we display the multiple directions available
                ? printf("\n\nWhich direction do you want to take ?\n1 : North\n2 : East\n3 : South\n\n")
                : printf("\n\nQuelle direction souhaitez vous prendre ?\n1 : Nord\n2 : Est\n3 : Sud\n\n");

            fflush(stdin);
            choice = getchar();

                
            while (choice != '1' && choice != '2' && choice != '3')
            {
                language == 'E'
                    ? printf("\n\nPlease select a possible direction !\n\n")
                    : printf("\n\nVeuillez selectionner une direction possible !\n\n");

                fflush(stdin);
                choice = getchar();
            }

            inventory.coins -= 10;

            switch (choice)
            {
                case '1': // If North is choosen
                    position[1] = 2;
                    break;
                case '2': // If East is choosen
                    position[0] = 0;
                    break;
                case '3': // If South is choosen
                    position[1] = 0;
                    break;
            }

        }
        else if (position[0] == -1 && position[1] == 2) // If current position is (-1;2)
        {

            default_visited = 1;
            visited[8] = 1;


            language == 'E'
                ? printf("\n\n\n\nCurrent location : (%d;%d)\n", position[0], position[1])
                : printf("\n\n\n\nPosition actuelle : (%d;%d)\n", position[0], position[1]);

            progress(visited, is_finished, language);



            handleLocation(position, default_visited, defaultPath, player.name, language); // Read the correct part
            language == 'E'
                ? printf("4 : Move\n")
                : printf("4 : Se deplacer\n");

            fflush(stdin);
            choice = getchar();

            while (choice != '1' && choice != '2' && choice != '3' && choice != '4')
            {
                language == 'E'
                    ? printf("\n\nThe number is not valid !\nPlease choose a correct number !\n\n")
                    : printf("\n\nLe chiffre n est pas valide !\nVeuillez choisir un chiffre correct !\n\n");

                fflush(stdin);
                choice = getchar();

            }
            while (choice != '3')
            {
                if (choice == '1' && inventory.blue_fragment >= 5)
                {
                    language == 'E'
                        ? printf("\n\nYou have solved the puzzle successfully, so you saved humanity. However, the Golem comes after you and you both die in an epic battle.\n\n")
                        : printf("\n\nVous avez reussi a resoudre l'enigme, vous avez donc sauve l'humanite. Cependant le Golem s'en prends a vous et vous mourrez tous les deux dans un combat epique.\n\n");
                    
                    is_finished = true;
                }
                else if (choice == '1' && inventory.blue_fragment < 5)
                {
                    language == 'E'
                        ? printf("\n\nYou don t have enough clue to solve the puzzle.\n")
                        : printf("\n\nVous n avez pas assez d'indice pour resoudre l'enigme (il vous faudra au moins 5 fragments.\n");

                }
                else if (choice == '2')
                {
                    Npc Golem;
                    SetDefaultNpcStats('G', &Golem);

                    // Fight the Golem
                    Fight(&player, &inventory, &Golem, language, &is_finished, max_health, max_energy);

                    if (!is_finished)
                    {
                        language == 'E'
                            ? printf("\n\nYou defeated the Golem who was mean and who wanted your evil !\nYou become the hero of the village\n\n")
                            : printf("\n\nVous avez vaincu le Golem qui etait mechant et qui voulait votre mal !\nVous devenez le hero du village.\n\n");
                        
                        is_finished = true;
                        progress(visited, is_finished, language);

                    }

                    if (is_finished) break;

                    is_finished = true;

                    language == 'E'
                        ? printf("\nYou died to the Golem !\n")
                        : printf("\nVous venez de succomber !\n");

                }
                else if (choice == '4')
                {
                    language == 'E'
                        ? printf("\n1 : South\n")
                        : printf("\n1 : Sud\n");
                    
                    fflush(stdin);
                    choice = getchar();

                    while (choice != '1')
                    {
                        language == 'E'
                        ? printf("\nPlease enter a correct number\n\n")
                        : printf("\nVeuillez entrer un chiffre correct\n\n");

                        fflush(stdin);
                        choice = getchar();
                    }

                    position[1] = 1;
                }
                
                if (choice == '1') break;

                if (is_finished) break;

                language == 'E'
                    ? readLines(englishPath, 74, 77 )
                    : readLines(frenchPath, 74, 77);

                fflush(stdin);
                choice = getchar();

            }
            

            
            
            if (is_finished) break;

            if (choice == '3')
            {
                language == 'E'
                    ? printf("\n\nYou have decided not to save humanity and therefore you become the king of this world. The bandits are under your control !\n\n")
                    : printf("\n\nVous avez decider de ne pas sauver l'humanite et vous devenez donc le roi de ce monde. Les bandits sont sous votre controle\n\n");
                is_finished = true;
                progress(visited, is_finished, language);
            }
            
            
        }

    }

}

