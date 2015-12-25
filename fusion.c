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
		for (int i=0;i<taille;i++) {
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
	for (int i =0;i<taille;i++) {
		printf("%d ",tab[i]);
	}
	printf("\n");
}

void main() {
	printf("Tapez la taille du tableau que vous souhaitez ?\n");
	int n = 0;
	scanf("%d",&n);
	int *tab = malloc(n*sizeof(int));
	int indiceMax = n-1;
	for (int i=0;i<n;i++) {
		tab[i] = 100*rand();	
	}
	afficher(tab,n);
	trier(tab,n);
	printf("\n");
	afficher(tab,n);
	free(tab);
}