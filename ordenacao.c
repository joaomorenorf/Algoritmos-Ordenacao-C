/*************** VOCE DEVE IMPLEMENTAR AS FUNCOES AQUI ***************/
/*
 * Esqueleto para sua implementacao dos algoritmos de ordenacao
 *
 */

 ///////////////	IMPLEMENTEI O SHELLSORT TAMBÉM, TESTA ELE, FICOU LEGAL
 //////////////		void shellSort(int n, int v[]);
/*					código para a main
					case 'S':
					printf("SHELL\n");
					shellSort(n, vet);
					break;
*/

#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"


int partition(int c, int f, int v[]) {
	return 0;
}

void quickSort(int c, int f, int v[]) {
	if (c < f) {
		int aux, pivoV; //Valor
	    pivoV = v[c];
	    int ii, pivoE;  //Endereço
	    pivoE = c;
	    for (ii = c + 1 ; ii <= f ; ii++) {
	        if      (v[ii] <  pivoV) {
	            pivoE++;
	            aux = v[ii];
	            v[ii] = v[pivoE];
	            v[pivoE] = aux;
	        }
	    }
	    aux = v[pivoE];
	    v[pivoE] = v[c];
	    v[c] = aux;
		quickSort(c, pivoE-1, v);
		quickSort(pivoE+1, f, v);
	}
}

void bubbleSort(int n, int v[]) {
	int ii, jj, aux;
	for (ii = 0 ; ii < n ; ii++) {
		for (jj = 1 ; jj < n ; jj++) {
			if (v[jj-1] > v[jj]) {
				aux = v[jj-1];
				v[jj-1] = v[jj];
				v[jj] = aux;
			}
		}
	}
}

void selectionSort(int n, int v[]) {
	int ii, jj, aux, men;
	for (ii = 0 ; ii < n - 1 ; ii++) {
		aux = ii;
		for (jj = ii + 1; jj < n ; jj++) {
			if (v[aux] > v[jj])
				aux = jj;
		}
		men = v[aux];
		v[aux] = v[ii];
		v[ii] = men;
	}
}

void merge(int c, int m, int f, int v[]) {
	int ii = c, jj = m + 1, kk = 0, aux[f - c + 1];
	while (ii <= m && jj <= f) {
		if (v[ii] <= v[jj]) {
			aux[kk] = v[ii];
			ii++; kk++;
		}
		else {
			aux[kk] = v[jj];
			jj++; kk++;
		}
	}
	while (ii <= m) {
		aux[kk] = v[ii];
		ii++; kk++;
	}
	while (jj <= f) {
		aux[kk] = v[jj];
		jj++; kk++;
	}
	kk = 0;
	for (ii = c ; ii <= f ; ii++) {
		v[ii] = aux[kk];
		kk++;
	}
}


void mergeSort(int c, int f, int v[]) {
	if (c < f) {
		int m = (c + f)/2;
		mergeSort(  c  , m, v);
		mergeSort(m + 1, f, v);
		merge(c, m, f, v);
	}
}

void shellSort(int n, int v[]) { //BONUS
	int ant, pos;
	int aux = 1;
	while (aux < n) aux = 3*aux +1; //Série de Knut
	int esp = (aux - 1) / 3;

	while (esp > 0) {
		for (pos = esp; pos < n; pos++) {
			aux = v[pos];
			ant = pos - esp;
			while ((ant >= 0) && (aux < v[ant])) {
				v[ant+esp] = v[ant];
				ant = ant - esp;
			}
			v[ant+esp] = aux;
		}
		esp = (esp -1)/3; //Série de Knut
	}
}

void insertionSort(int n, int v[]) {
	int ii, jj, aux, e;
	for (ii = 1; ii < n; ii++) {
		aux = v[ii];
		e = 1;
		jj = ii - 1;
		while (jj >= 0 && e) {
			if (v[jj] > aux) {
				v[jj+1] = v[jj];
				jj--;
			}
			else e = 0;
		}
		v[jj + 1] = aux;
	}
}
