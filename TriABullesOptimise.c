#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

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
 * Trie le tableau en utilisant le tri a bulles optimise
 * @param tab Le tableau
 * @parm tabSize La taille du tableau
 */
void trier(int tab[], int tabSize) {

	int echange = TRUE;
	int i = 0;
    
    while ((tabSize > 0) && echange) {
			
		echange = FALSE;
		
		for (i = 0; i < tabSize  - 1; i++) {
			
			if (tab[i] > tab[i+1]) {
				int tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i + 1] = tmp;
				echange = TRUE;
			}
		}
		
		tabSize = tabSize - 1;
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
	printf("Tableau avant tri : [");
	afficher(tab, tabNbElements);
	printf("]\n");
	
	// sort the table
	trier(tab, tabNbElements);
	
	// print sorted table
	printf("Tableau avant tri : [");
	afficher(tab, tabNbElements);
	printf("]\n");
	
	free(tab);
	system("pause");
}
