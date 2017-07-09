/*************** ESTE ARQUIVO N2AO DEVE SER MODIFICADO ***************/
#include <stdio.h>
#include "ordenacao.h"

void imprime(int n, int v[]) {
	int i;

	for (i=0;i<n;i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	int vet[MAX];
	int i,n;
	char op;
	int resp;

	resp = 0;
	while (resp == 0) {
		scanf ("%c ", &op);
		if (op == 'b' || op == 'q' || op == 's' || op == 'm' || op == 'i' || op == 'S') resp = 1;
		else printf("Resposta invalida.\n");
	}

	resp = 0;
	while (resp == 0) {
		scanf ("%d", &n);
		if (n > 1) resp = 1;
		else printf("Resposta invalida. Para ordenar, precisa-se de pelo menos 2 elementos.\n");
	}

	for (i=0;i<n;i++)
		scanf ("%d", &(vet[i]));

	imprime(n,vet);

  switch(op) {
	case 'b':
		printf("BUBBLE\n");
		bubbleSort(n,vet);
		break;

	case 'q':
		printf("QUICK\n");
		quickSort(0,n-1,vet);
		break;

	case 's':
		printf("SELECTION\n");
		selectionSort(n,vet);
		break;

	case 'm':
		printf("MERGE\n");
		mergeSort(0,n-1,vet);
		break;

	case 'i':
		printf("INSERTION\n");
		insertionSort(n, vet);
		break;
	case 'S':
		printf("SHELL\n");
		shellSort(n, vet);
		break;
	default:
		break;
  }
    imprime(n,vet);

  return 0;
}
