#include "../header/progress.h"


void setVisited(int visited[NB_LOCATION])
{

    for (int i = 0; i < NB_LOCATION; i++)
        visited[i] = 0;

}



void progress(int visited[NB_LOCATION], bool done, char language)
{

    int counter = 0;

    for (int i = 0; i < NB_LOCATION; i++)
    {
        if (visited[i] != 0)
            counter += 10;
    }

    
    if (done)
        counter = 100;

    language == 'E'
        ? printf("\nProgress : %d %% \n", counter)
        : printf("\nProgression : %d %% \n", counter);



}
