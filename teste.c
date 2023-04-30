//por Alice Aquino, 30/04/2023
//atividade de Estrtura de Dados envolvendo o conteúdo de ordenação

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//GERAR O VETOR ALEATÓRIO
int randValor(int linf, int lsup){
        return (linf + (lrand48() % (lsup - linf+1)));
}

//FUNÇÃO BUBBLE SORT
void bublle_sort(int vetor[], int tamanho){
	int aux;
	for(int j = tamanho-1; j >= 1; j--){
		for(int i = 0; i < j; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
    }
}

//FUNÇÃO INSERTION SORT 
void insertion_sort(int vet[], int tam){
    int j, x;
    for(int i = 2; i <= tam; i++){
	    x = vet[i];
	    j = i-1;
	    vet[0] = x; 
	    while (x < vet[j]){
            vet[j+1] = vet[j];
            j--;
        } vet[j+1] = x;
    }
}

//FUNÇÃO SELECTION SORT
void selection_sort(int vet[], int tam){
    int i, j, min, x;
    for (int i = 1; i <= tam-1; i++){
        min = i;
	    for (j = i+1; j <= tam; j++){
            if (vet[j] < vet[min])
	        min = j;
	    } x = vet[min];
	    vet[min] = vet[i];
	    vet[i] = x;
    }
}

//FUNÇÃO INTERCALA E MERGE SORT
void intercala(int p, int q, int r, int v[]){
   int *w;
   w = malloc((r-p) * sizeof (int));
   int i = p, j = q;
   int k = 0;
   while(i < q && j < r){
      if(v[i] <= v[j]) w[k++] = v[i++];
      else w[k++] = v[j++];
   } while(i < q) w[k++] = v[i++];
   while(j < r) w[k++] = v[j++];
   for(i = p; i < r; ++i) v[i] = w[i-p];
   free(w);
}

void merge_sort(int p, int r, int v[]){
    if(p < r-1){
        int q = (p + r)/2;
        merge_sort(p, q, v);
        merge_sort(q, r, v);
        intercala(p, q, r, v);
   }
}

//FUNÇÃO MERGE SORT V2
void merge_sortv2(int p, int r, int v[]){
    if(p < r-1){
        int q = (p + r)/3;
        merge_sort(p, q, v);
        merge_sort(q+1, q+q, v);
        merge_sort(q+q+1, r, v);
        intercala(p, q+1, q+q, v);
        intercala(p, q+q+1, r, v);
   }
}

//FUNÇÃO SEPARA E QUICK SORT
int separa(int v[], int p, int r){
    int c = v[r]; 
    int t, j = p;
    for(int k = p; k < r; ++k){
        if(v[k] <= c) {
            t = v[j], v[j] = v[k], v[k] = t;
            ++j; 
        }
    } t = v[j], v[j] = v[r], v[r] = t;
    return j; 
}

void quicksort(int v[], int p, int r){
    if(p < r){
        int j = separa (v, p, r);
        quicksort(v, p, j-1);
        quicksort(v, j+1, r);
    }
}


//FUNÇÃO PRINCIPAL
int main(){ 
    int n, inf, sup;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);
    printf("Digite o número inferior e superior do vetor: \n");
    scanf("%d %d", &inf, &sup);

    int *vet;
    vet = (int *) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) vet[i] = randValor(inf, sup);

    double time_spent = 0.0;
    clock_t begin = clock();

    //bublle_sort(vet, n);
    //selection_sort(vet, n);
    //insertion_sort(vet, n);
    //merge_sort(0, n, vet);
    //merge_sortv2(0, n, vet);
    quicksort(vet, 0, n);
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;//calcular o tempo de execução
    printf("O tempo de execução é %f segundos\n", time_spent);

    free(vet);

    return 0;
}

//RESULTADOS DOS TESTES DE PERFOMANCE:
//
// ----- BUBBLE SORT -----
//  vetor de 1000 = 0.010828 segundos
//  vetor de 5000 = 0.175148 segundos
//  vetor de 10000 = 0.784129 segundos
//  vetor de 50000 = 20.587136 segundos
//  vetor de 100000 = 82.326096 segundos
//  vetor de 200000 = 330.509216 segundos
//  MÉDIA DE TEMPO = 72.398758833 segundos
//
// ----- SELECTION SORT -----
//  vetor de 1000 = 0.005365 segundos
//  vetor de 5000 = 0.070428 segundos
//  vetor de 10000 = 0.252403 segundos
//  vetor de 50000 = 6.182492 segundos
//  vetor de 100000 = 24.667415 segundos
//  vetor de 200000 = 98.766858 segundos
//  MÉDIA DE TEMPO = 21.6574935 segundos
//
// ----- INSERTION SORT -----
//  vetor de 1000 = 0.005942 segundos
//  vetor de 5000 = 0.072797 segundos
//  vetor de 10000 = 0.281859 segundos
//  vetor de 50000 = 6.943702 segundos
//  vetor de 100000 = 27.670185 segundos
//  vetor de 200000 = 110.862558 segundos
//  MÉDIA DE TEMPO = 24.306173833 segundos
//
// ----- MERGE SORT -----
//  vetor de 1000 = 0.000976 segundos
//  vetor de 5000 = 0.004014 segundos
//  vetor de 10000 = 0.008279 segundos
//  vetor de 50000 = 0.026887 segundos
//  vetor de 100000 = 0.057362 segundos
//  vetor de 200000 = 0.118231 segundos
//  MÉDIA DE TEMPO = 0.035958167 segundos
//
// ----- MERGE SORT V2 -----
//  vetor de 1000 = 0.000892 segundos
//  vetor de 5000 = 0.004674 segundos
//  vetor de 10000 = 0.008837 segundos
//  vetor de 50000 = 0.027136 segundos
//  vetor de 100000 = 0.057583 segundos
//  vetor de 200000 = 0.114966 segundos
//  MÉDIA DE TEMPO = 0.035681333 segundos
//
// ----- QUICK SORT -----
//  vetor de 1000 = 0.000524 segundos
//  vetor de 5000 = 0.003357 segundos
//  vetor de 10000 = 0.005806 segundos
//  vetor de 50000 = 0.019282 segundos
//  vetor de 100000 = 0.038414 segundos
//  vetor de 200000 = 0.079584 segundos
//  MÉDIA DE TEMPO = 0.0244945 segundos
//