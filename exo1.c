#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define TAILLE_MAX 1000

typedef struct BNB
{
    int id;
    int accommodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    int distance;
    int alea;

}BNB;
int main(int argc, char* argv[]){

    BNB* tab_BNB;
    FILE *fichier = NULL;
    char ligne[TAILLE_MAX] = "";
    char *temp;
    int nbLignes, nbgens, nbminn, nbmaxn;
    float nbchbs, nblits, nbsdb;
    srand(time(NULL));

    fichier = fopen ("airbnb_donnees_propre.csv", "r");

    if(fichier == NULL){
        printf("Impossible d'ouvrir le fichier airbnb_donnees_propre.csv");
        return 1;
    }

    fgets(ligne, TAILLE_MAX, fichier); //On souhaite commencer la lecture à la ligne 2

    tab_BNB = malloc(sizeof(BNB)); //On prépare le tableau

    nbLignes = 0; // Nombre de lignes et index dans tab_BNB
    int nbAllocated = 1; // Nombres de lignes allouées
    while (fgets(ligne, TAILLE_MAX, fichier))
    {
        if(nbAllocated < (nbLignes+1)){ // Si on s'apprète a overflow
            tab_BNB = realloc(tab_BNB, sizeof(BNB)*(nbAllocated*2));
            nbAllocated *= 2;
            //On doubles l'espace nécéssaire en mémoire au lieu de faire +1 pour passer d'un nombre d'opération n à log2(n)
        }

        // printf("%s", ligne);
        temp = strtok(ligne, ",");
        tab_BNB[nbLignes].id = atoi(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].accommodates = atoi(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].bedrooms = atof(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].bathrooms = atof(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].beds = atof(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].price = atof(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].minimum_nights = atoi(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].maximum_nights = atoi(temp);
        temp = strtok(NULL, ",");
        tab_BNB[nbLignes].number_of_reviews = atoi(temp);
        temp = strtok(NULL, ",");
        nbLignes++; //Une nouvelle ligne a été lue
    }

    if(nbLignes != nbAllocated){ // On libère l'espace mémoire inutilisé
        tab_BNB = realloc(tab_BNB, sizeof(BNB)*(nbLignes));
    }
    int cas,h;
    printf("Avec quelles criteres souhaitez vous comparer ?\n");
    printf("Si vous souhaitez comparer avec un critere, tapez 1.\n");
    printf("Si vous souhaitez comparer avec deux criteres, tapez 2\n");
    printf("Si vous souhaitez comparer avec trois criteres, tapez 3\n");
    printf("Si vous souhaitez comparer avec tous les criteres possibles, tapez 4\n");
    scanf("%d", &cas);
    switch(cas)
    {
        case 1:
        printf("Si vous souhaitez comparer avec le nombre de personnes que peut acceuillir le logement, tapez 1\n");
        printf("Si vous souhaitez comparer avec le nombre de chambre, tapez 2\n");
        printf("Si vous souhaitez comparer avec le nombre de lits, tapez 3\n");
        scanf("%d", &h);
            switch(h)
            {
            case 1:
                printf("Quel est le nombre de personnes pouvant etre acceuillis par votre logement?\n");
                scanf("%d", &nbgens);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrt(pow(tab_BNB[i].accommodates - nbgens, 2));
                }
                break;
            case 2:
                printf("Quel est le nombre de chambres dans votre logement ?\n");
                scanf("%f", &nbchbs);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].bedrooms - nbchbs, 2));
                }
                break;
            case 3:
                printf("Quel est le nombre de lits dans votre logement ?\n");
                scanf("%f", &nblits);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].beds - nblits, 2));
                }
                break;
            }
        break;
        case 2:
            printf("Si vous souhaitez comparer avec le nombre de gens et le nombre de chambres, tapez 1\n");
            printf("Si vous souhaitez comparer avec le nombre de gens et de le nombre de lits, tapez 2\n");
            printf("Si vous souhaitez comparer avec le nombre de chambres et le nombre de lits, tapez 3\n");
            scanf("%d", &h);
            switch(h){
                case 1:
                printf("Quel est le nombre de personne pouvant etre acceuilli par votre logement?\n");
                scanf("%d", &nbgens);
                printf("Quel est le nombre de chambres dans votre logement ?\n");
                scanf("%f", &nbchbs);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].accommodates - nbgens, 2) + pow(tab_BNB[i].bedrooms - nbchbs, 2));
                }
                break;
                case 2:
                printf("Quel est le nombre de personne pouvant etre acceuilli par votre logement?\n");
                scanf("%d", &nbgens);
                printf("Quel est le nombre de lits dans votre logement ?\n");
                scanf("%f", &nblits);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].beds - nblits, 2) + pow(tab_BNB[i].accommodates - nbgens, 2));
                }
                break;
                case 3:
                printf("Quel est le nombre de lits dans votre logement ?\n");
                scanf("%f", &nblits);
                printf("Quel est le nombre de chambres dans votre logement ?\n");
                scanf("%f", &nbchbs);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].beds - nblits, 2) + pow(tab_BNB[i].bedrooms - nbchbs, 2));
                }
                break;
            }
        break;
        case 3:
                printf("Quel est le nombre de personne pouvant etre acceuilli par votre logement?\n");
                scanf("%d", &nbgens);
                printf("Quel est le nombre de chambres dans votre logement ?\n");
                scanf("%f", &nbchbs);
                printf("Quel est le nombre de lits dans votre logement ?\n");
                scanf("%f", &nblits);
                for (int i = 0; i < (nbLignes); i++){
                        tab_BNB[i].alea = rand(); //variable aleatoire a tous les logements
                        tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].beds - nblits, 2) + pow(tab_BNB[i].bedrooms - nbchbs, 2) + pow(tab_BNB[i].accommodates - nbgens, 2));
                }
                break;
        case 4:
            printf("Quel est le nombre de personne pouvant etre acceuilli par votre logement?\n");
            scanf("%d", &nbgens);
            printf("Quel est le nombre de chambres dans votre logement ?\n");
            scanf("%f", &nbchbs);
            printf("Quel est le nombre de lits dans votre logement ?\n");
            scanf("%f", &nblits);
            printf("Quel est le nombre de salle de bain dans votre logement ?\n");
            scanf("%f", &nbsdb);
            printf("Quel est le nombre minimum de nuits ?\n");
            scanf("%d", &nbminn);
            printf("Quel est le nombre maximum de nuits ?\n");
            scanf("%d", &nbmaxn);
            for (int i = 0; i < (nbLignes); i++)
            {
                tab_BNB[i].alea = rand();//on attribue a chaque logement une valeur aleatoire et sa distance par rapport au logement x
                tab_BNB[i].distance = sqrtf(pow(tab_BNB[i].accommodates - nbgens, 2) + pow(tab_BNB[i].bedrooms - nbchbs, 2) + pow(tab_BNB[i].bathrooms - nbsdb, 2) + pow(tab_BNB[i].beds - nblits, 2) + pow(tab_BNB[i].minimum_nights - nbminn, 2) + pow(tab_BNB[i].maximum_nights - nbmaxn, 2));
            }
        break;
    }
    int i,j,c;
    float x;
    for(i=0;i<nbLignes-1;i++) // on effectue une double boucle pour trier selon la variable aleatoire
        for(j=i+1;j<nbLignes;j++)
            if ( tab_BNB[i].alea > tab_BNB[j].alea ) {
                c = tab_BNB[i].alea;
                tab_BNB[i].alea = tab_BNB[j].alea;
                tab_BNB[j].alea = c;
                c = tab_BNB[i].accommodates;
                tab_BNB[i].accommodates = tab_BNB[j].accommodates;
                tab_BNB[j].accommodates = c;
                c = tab_BNB[i].distance;
                tab_BNB[i].distance = tab_BNB[j].distance;
                tab_BNB[j].distance = c;
                c = tab_BNB[i].id;
                tab_BNB[i].id = tab_BNB[j].id;
                tab_BNB[j].id = c;
                c = tab_BNB[i].maximum_nights;
                tab_BNB[i].maximum_nights = tab_BNB[j].maximum_nights;
                tab_BNB[j].maximum_nights = c;
                c = tab_BNB[i].minimum_nights;
                tab_BNB[i].minimum_nights = tab_BNB[j].minimum_nights;
                tab_BNB[j].minimum_nights = c;
                c = tab_BNB[i].number_of_reviews;
                tab_BNB[i].number_of_reviews = tab_BNB[j].number_of_reviews;
                tab_BNB[j].number_of_reviews = c;
                x = tab_BNB[i].bathrooms;
                tab_BNB[i].bathrooms = tab_BNB[j].bathrooms;
                tab_BNB[j].bathrooms = x;
                x = tab_BNB[i].bedrooms;
                tab_BNB[i].bedrooms = tab_BNB[j].bedrooms;
                tab_BNB[j].bedrooms = x;
                x = tab_BNB[i].beds;
                tab_BNB[i].beds = tab_BNB[j].beds;
                tab_BNB[j].beds = x;
                x = tab_BNB[i].price;
                tab_BNB[i].price = tab_BNB[j].price;
                tab_BNB[j].price = x;
        }
    /*for (int i = 0; i < (nbLignes -1); i++){
    printf("[%d;%d;%d;%f;%f;%f;%d;%d;%d;%f;%d]\n", tab_BNB[i].alea, tab_BNB[i].id, tab_BNB[i].accommodates, tab_BNB[i].bedrooms, tab_BNB[i].bathrooms, tab_BNB[i].beds, tab_BNB[i].minimum_nights, tab_BNB[i].maximum_nights, tab_BNB[i].number_of_reviews, tab_BNB[i].price, tab_BNB[i].distance);
    }*/
    for(i=0;i<nbLignes-1;i++) //on trie cette fois en se basant sur la distance
        for(j=i+1;j<nbLignes;j++)
            if ( tab_BNB[i].distance > tab_BNB[j].distance ) {
                c = tab_BNB[i].alea;
                tab_BNB[i].alea = tab_BNB[j].alea;
                tab_BNB[j].alea = c;
                c = tab_BNB[i].accommodates;
                tab_BNB[i].accommodates = tab_BNB[j].accommodates;
                tab_BNB[j].accommodates = c;
                c = tab_BNB[i].distance;
                tab_BNB[i].distance = tab_BNB[j].distance;
                tab_BNB[j].distance = c;
                c = tab_BNB[i].id;
                tab_BNB[i].id = tab_BNB[j].id;
                tab_BNB[j].id = c;
                c = tab_BNB[i].maximum_nights;
                tab_BNB[i].maximum_nights = tab_BNB[j].maximum_nights;
                tab_BNB[j].maximum_nights = c;
                c = tab_BNB[i].minimum_nights;
                tab_BNB[i].minimum_nights = tab_BNB[j].minimum_nights;
                tab_BNB[j].minimum_nights = c;
                c = tab_BNB[i].number_of_reviews;
                tab_BNB[i].number_of_reviews = tab_BNB[j].number_of_reviews;
                tab_BNB[j].number_of_reviews = c;
                x = tab_BNB[i].bathrooms;
                tab_BNB[i].bathrooms = tab_BNB[j].bathrooms;
                tab_BNB[j].bathrooms = x;
                x = tab_BNB[i].bedrooms;
                tab_BNB[i].bedrooms = tab_BNB[j].bedrooms;
                tab_BNB[j].bedrooms = x;
                x = tab_BNB[i].beds;
                tab_BNB[i].beds = tab_BNB[j].beds;
                tab_BNB[j].beds = x;
                x = tab_BNB[i].price;
                tab_BNB[i].price = tab_BNB[j].price;
                tab_BNB[j].price = x;
        }
    /*for (int i = 0; i < (nbLignes -1); i++){
    printf("[%d;%d;%d;%f;%f;%f;%d;%d;%d;%f;%d]\n", tab_BNB[i].distance, tab_BNB[i].id, tab_BNB[i].accommodates, tab_BNB[i].bedrooms, tab_BNB[i].bathrooms, tab_BNB[i].beds, tab_BNB[i].minimum_nights, tab_BNB[i].maximum_nights, tab_BNB[i].number_of_reviews, tab_BNB[i].price, tab_BNB[i].alea);
    }*/
        int k;
        float moy = 0;
        printf("Avec combien de logement souhaitez vous comparer ?\n");
        scanf("%d", &k);
        for(i=0;i<k-1;i++){
                moy = moy + tab_BNB[i].price;}
                moy = moy / k;
                printf("Le prix predit est de %f euros", moy);
    free(tab_BNB);
    fclose(fichier);
    return 0;
}
