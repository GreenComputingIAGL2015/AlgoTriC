#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * Recupere le plus grand element d'un tableau
 * @param tab Le tableau
 * @parm taille La taille du tableau
 */
int getMaxValue(int tab[], int taille) {
	
	int highest = tab[0];
	int index = 1;
	
	for (; index < taille; index ++) {
        if (tab[index] > highest) {
            highest = tab[index];
        }
    }
	
	return highest;
}

/**
 * Affichage des elements d'un tableau en chaine de caracteres
 * @param tab Le tableau
 * @parm taille La taille du tableau
 */
void afficher(int * tab, int taille) {
    int i;
     
	for (i =0; i < taille; i++) {
		printf("%d, ", tab[i]);
	}
}

/**
 * Trie le tableau en utilisant le tri par comptage
 * @param tab Le tableau
 * @parm taille La taille du tableau
 */
void trier(int tab[], int tailleTableau, int borneSuperieure) {
     
    // Initialisation du tableau de comptage a 0
    int * tabComptage = malloc((borneSuperieure + 1) * sizeof(int));
    int i;
	for (i=0; i <= borneSuperieure; i++) {
		tabComptage[i] = 0;
	}
	
	// Creation du tableau de comptage
	for(i=0; i<tailleTableau; i++) {
		tabComptage[tab[i]]++;
	}
	
	// Creation du tableau trie
	int j;
	int x = 0;
	
	for(i = 0; i <= borneSuperieure; i++) {
		for  (j = 0; j < tabComptage[i]; j++) {
			tab[x++] = i;
		}
	}
}

int main() {
	
	// set tab size
    printf("Tapez la taille du tableau que vous souhaitez : ");
	int tabNbElements = 0;
	scanf("%d", &tabNbElements);

	// define tab
	int * tab = malloc(tabNbElements * sizeof(int));

    // initialize with random number rage : 1 - 100
	int i;
    srand (time(NULL));
    int rangeMin = 1;
    int rangeMax = tabNbElements;
	
	for (i=0; i < tabNbElements; i++) {
		tab[i] = rangeMax + rand() / (RAND_MAX / (rangeMin - rangeMax + 1) + 1);
	}
	
	// print tab
	printf("Nb elements : %d\n", tabNbElements);
	printf("Borne superieure : %d\n", getMaxValue(tab, tabNbElements));
	printf("Tableau avant tri : [");
	afficher(tab, tabNbElements);
	printf("]\n");
	
	// sort the table
	int highest = getMaxValue(tab, tabNbElements);
	trier(tab, tabNbElements, highest);
	
	// print sorted table
	printf("Tableau avant tri : [");
	afficher(tab, tabNbElements);
	printf("]+++++++++++++++++\n");
	
	free(tab);
	system("pause");
}
