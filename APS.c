#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define TAM 20000

int vet1[TAM];
int vet2[TAM];

void preencheVetor();
void mostraVetor();
void copiaVetor();
void bolha();
void selecaoDireta();
void quickSort(int esq, int dir);
void contagem(int contC, int contT);

void preencheVetor(){
	int i, j;
	for(i = 0; i < TAM; i++){
		vet1[i] = rand() % TAM;
		for(j = 0; j < i; j++){
			if(vet1[j] == vet1[i]){
				i--;
				break;
			}
		}
	}
}

void copiaVetor(){
	int i;
	for(i = 0; i < TAM; i++){
		vet2[i] = vet1[i];
	}
}

void mostraVetor(){
	int i;
	for(i = 0; i < TAM; i++){
		printf("%d ", vet2[i]);
	}
	printf("\n");
}

void bolha(){
	int i, j, aux, cont, inicio, final, tmili;
	
	cont = 0;
	inicio = GetTickCount();
	for(j=0;j<TAM;j++){
		cont=0;
		for(i=0;i<TAM-1;i++){
			if(vet2[i]>vet2[i+1]){
				aux=vet2[i];
				vet2[i]=vet2[i+1];
				vet2[i+1]=aux;
				cont++;
			}
		}
		if(cont==0){
			break;
		}
	}
	final = GetTickCount();
	tmili = final - inicio;
	printf("#BOLHA#");
	printf("\nBolha levou: %d, milisegundos para rodar", tmili);
}

void selecaoDireta(){
	int aux, maior, imaior, i, j, inicio, final, tmili;

	inicio = GetTickCount();
	for(j = TAM-1; j > 0; j--){
		maior = vet2[0];
		imaior = 0;
		for(i = 1; i <= j; i++){
			if(vet2[i] > maior){
				maior = vet2[i];
				imaior = i;
			}
		}
		aux = vet2[j];
		vet2[j] = maior;
		vet2[imaior] = aux;
	}
	final = GetTickCount();
	tmili = final - inicio;
	printf("\n\n#SELECAO DIRETA#");
	printf("\nSelecao direta levou: %d, milisegundos para rodar", tmili);
}

void quickSort(int esq, int dir){
	int i, j, pivo, aux, inicio, final, tmili;
	i = esq;
	j = dir;

	pivo = vet2[(i+j)/2];
	inicio = GetTickCount();
	while(i < j){
		while(vet2[i] < pivo){
			i++;
		}
		while(vet2[j] > pivo){
			j--;
		}
		if(i <= j){
			aux = vet2[i];
			vet2[i] = vet2[j];
			vet2[j] = aux;
			i++;
			j--;
		}
	}
	if(esq < j){
		quickSort(esq, j);
	}
	if(dir < i){
		quickSort(dir, i);
	}
	final = GetTickCount();
	tmili = final - inicio;
}

main(){
	srand(time(NULL));

	preencheVetor();
	copiaVetor();
	bolha();
	copiaVetor();
	selecaoDireta();
	copiaVetor();
	quickSort(0, TAM-1);
}
