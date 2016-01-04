#include <stdlib.h>
#include <stdio.h>

int* dupTab(int tab[], int i, int j) {
	int *result = malloc((j-i+1)*sizeof(int));
	int x = 0;
	for (i;i<j;i++) {
		result[x] = tab[i];
		x = x+1;
	}
	return result;
}

int* trier(int tab[], int taille) {
	int indiceMax = taille-1;
	if (taille > 1) {
		int tailleU = (taille/2);
		int tailleV = taille-tailleU;
		int *u = trier(dupTab(tab,0,taille/2),tailleU);
		int *v = trier(dupTab(tab,taille/2,taille),tailleV);
		int a = 0;
		int b = 0;
		int i=0;
		
		for (i=0;i<taille;i++) {
			if ((a < tailleU) && (b >= tailleV || u[a] <= v[b])) {
				tab[i] = u[a];
				a = a+1;
			} else {
				tab[i] = v[b];
				b = b+1;
			}
		}
		free(u);
		free(v);
	}
	return tab;
}

void afficher(int * tab,int taille) {
    int i;
     
	for (i =0;i<taille;i++) {
		printf("%d ",tab[i]);
	}
	printf("\n");
}

int main() {
	printf("Tapez la taille du tableau que vous souhaitez ?\n");
	int tabNbElements = 0;
	scanf("%d", &tabNbElements);
	int *tab = malloc(tabNbElements * sizeof(int));
	int indiceMax = tabNbElements - 1;
	int i;
	
	// initialize with random number rage : 1 - 100
    srand (time(NULL));
    int rangeMin = 1;
    int rangeMax = tabNbElements;
	
	for (i=0; i < tabNbElements; i++) {
		tab[i] = rangeMax + rand() / (RAND_MAX / (rangeMin - rangeMax + 1) + 1);
	}
	
	
	afficher(tab, tabNbElements);
	trier(tab, tabNbElements);
	printf("\n");
	afficher(tab, tabNbElements);
	free(tab);
	
	system("pause");
}
