// REGNAULT ALEX & DUSSAUTOIS TOM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "./types.h"





#ifndef READFILE
#define READFILE

// Reads an entire file and displays it
void readFile(char filename[]);



#endif

#ifndef READLINES
#define READLINES


// Reads a part of a file depending on a start and a end line
void readLines(char filename[], int firstLine, int lastLine);


#endif