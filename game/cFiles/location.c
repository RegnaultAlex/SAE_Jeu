#include "../header/location.h"


void handleLocation(int location[COORDS], int visited, char defaultPath[], char name[], char language)
{

    char englishPath[50];
    char frenchPath[50];

    if (language == 'E')
    {
        strcpy(englishPath, defaultPath);
        strcat(englishPath, "/Game-GB.txt");
    }
    else
    {
        strcpy(frenchPath, defaultPath);
        strcat(frenchPath, "/Game-FR.txt");
    }

    
    bool locationVisited = isVisited(visited);



    if (location[0] == 0) // (0 ; y)
    {
        if (location[1] == 0) 
        {

            if (!locationVisited)
            {
                language == 'E'
                    ? readLines(englishPath, 10, 15)
                    : readLines(frenchPath, 10, 15);

                // Add the current location to the visited location in order to not show the text again
                visited = 1;
            }
            else 
            {
                language == 'E'
                    ? readLines(englishPath, 13, 15)
                    : readLines(frenchPath, 13, 15);
            }

        }
        else if (location[1] == 1)
        {
            language == 'E' 
                ? readLines(englishPath, 17, 18)
                : readLines(frenchPath, 17, 18);
        }
        else if (location[1] == 2)
        {
            language == 'E' 
                ? readLines(englishPath, 23, 29)
                : readLines(frenchPath, 23, 29);
        }
    }
    else if (location[0] == 1) // (1 ; y)
    {
        if (location[1] == 0)
        {
            language == 'E' 
                ? readLines(englishPath, 31, 36)
                : readLines(frenchPath, 31, 36);

        }
        else if (location[1] == 1)
        {
            language == 'E' 
                ? readLines(englishPath, 38, 45)
                : readLines(frenchPath, 38, 45);
        }
        else if (location[1] == 2)
        {
            language == 'E' 
                ? readLines(englishPath, 47, 52)
                : readLines(frenchPath, 47, 52);
        }
    }
    else if (location[0] == -1) // (-1 ; y)
    {
        if (location[1] == 0)
        {
            language == 'E' 
                ? readLines(englishPath, 54, 59)
                : readLines(frenchPath, 54, 59);
        }
        else if (location[1] == 1)
        {
            language == 'E' 
                ? readLines(englishPath, 61, 68)
                : readLines(frenchPath, 61, 68);
        }
        else if (location[1] == 2)
        {
            if (language == 'E')
            {
                readLines(englishPath, 70, 71);
                printf("\"Hello %s,", name);
                readLines(englishPath, 72, 76);
            }
            else
            {
                readLines(frenchPath, 70, 71);
                printf("\"Bonjour %s,", name);
                readLines(frenchPath, 72, 76);
            }
        }
    }
}




bool isVisited(int visited) {return visited == 1;}