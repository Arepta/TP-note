#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct processus
{
    int tps;
    char nom[50];
    int id;
}proc;

proc ajout_activite(proc tab_proc[], int nbProc)
{
    proc ajout_proc;
    printf("Quel est le nom du processus\n");
    scanf("%s", tab_proc[nbProc-1].nom);
    printf("Combien de temps ce processus doit il rester actif ? \n");
    scanf("%d", &tab_proc[nbProc-1].tps);
    tab_proc[nbProc].id = rand();
    return tab_proc[nbProc];
}

int step(proc tab_proc[], int nbProc)
{

    if (nbProc == 0)
    {
        printf("La file de processus est vide.\n");
    }
    else
    {
        for (int i = 0; i < nbProc; i++)
        {
            printf("[%s|%d|%d]\n", tab_proc[i].nom, tab_proc[i].id, tab_proc[i].tps);
            sleep(tab_proc[i].tps);
        }

    }
    return 0;
}


int main(int argc, char const *argv[])
{
    proc tab_proc[50];
    srand(time(NULL));
    int a = 1;
    int nbProc = 0;
    while (a == 1)
    {

    printf("Voulez vous ajouter une activite ? \n 1 = oui, 2 = non.\n");
    scanf("%d", &a);
    if (a == 1){
        nbProc++;
        ajout_activite(tab_proc, nbProc);
    }
    }
    step(tab_proc, nbProc);
    return 0;
}
