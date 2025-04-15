#include "../header/readFile.h"


void readFile(char filename[])
// Read a whole file
{

    // Open the file
    FILE *in_file = fopen(filename, "r");

    // Read the file size
    struct stat sb;
    stat(filename, &sb);

    // Allocation of the character array
    char *file_contents = malloc(sb.st_size);

    // Display line by line
    printf("\n");
    while (fscanf(in_file, "%[^\n] ", file_contents) != EOF)
    {
        printf("%s\n", file_contents);
    }

    // Fermeture du fichier
    fclose(in_file);
}


void readLines(char filename[], int firstLine, int lastLine)
// Read a file from a given line to another
{

    int current_line = 0;

    // Open the file
    FILE *in_file = fopen(filename, "r");

    char file_contents[500];

    // Display line by line
    printf("\n");
    while (fgets(file_contents, sizeof(file_contents), in_file) && current_line <= lastLine)
    {
        current_line++;
        if (current_line >= firstLine && current_line <= lastLine)
        {
            printf("%s", file_contents);
        }
    }

    // Fermeture du fichier
    fclose(in_file);
}