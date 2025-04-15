#include "../header/getLanguage.h"


void getLanguage(char finalPath[])
{
    char choice[3];

    printf("Choisir la langue (fr) / Select language (en) :\n");
    scanf("%s", choice);

    // Set the characters of the string choice to lowercase caracters
    for (int i = 0; choice[i] != '\0'; i++)
    {
        choice[i] = tolower(choice[i]);
    }

    while (strcmp(choice, "en") != 0 && strcmp(choice, "fr") != 0)
    {
        printf("Cette langue n'est pas disponible, veuillez choisir le francais en saisissant FR ou anglais en saisissant EN\n\
The language is not available, please choose French by writing FR or English by writing EN\n\n");
        scanf("%s", choice);

        // Set the characters of the string choice to lowercase caracters
        for (int i = 0; choice[i] != '\0'; i++)
        {
            choice[i] = tolower(choice[i]);
        }
    }

    // if the language choosen is english then we add English to the path, otherwise we add French
    strcmp(choice, "en") == 0 ? strcat(finalPath, "English") : strcat(finalPath, "French");
}

void setLanguage(char defaultPath[], char *language)
{
    strcmp(defaultPath, "../text/ig-text/English") == 0
        ? (*language = 'E')
        : (*language = 'F');
}