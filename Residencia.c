#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TAM 3

//variaveis globais e metodos genericos
int in,chave,pesq,posicao;
void linha();
void imprimir();
void cadastrar();

// residencia (respectivamente, uma leitura de consumo)  
struct Residencia {
       char rua[25];
       int numCasa;
       int numMedidor;
       float medidaConsumo;
       } residencias[TAM];

//Metodos de ordenação

//Seleção e troca
void selectSort(int menorParaMaior);

//Inserção
void insertionSortMenorParaMaior();
void insertionSortMaiorParaMenor();

//Distribuição
void mergeSort(struct Residencia* vec, int vecSize, int menorParaMaior);
void mergeMenorParaMaior(struct Residencia* vec, int vecSize);
void mergeMaiorParaMenor(struct Residencia* vec, int vecSize);

//Intercalação
void mergesortIntercalacao(int p, int r, struct Residencia* v, int menorParaMaior);
void intercalaMaiorParaMenor(int p, int q, int r, struct Residencia* v);
void intercalaMenorParaMaior(int p, int q, int r, struct Residencia* v);

//------------------------------------------------------------------------------
main(){
    
  int escolha = 0;
  
  while(escolha!=11){
  	
  	printf("Opcoes\n");
  	printf("	> Cadastro\n");
  	printf("		> 1 - Para cadastrar residencias\n");
  	
  	printf("	> Ordenar lista\n");
  	printf("		> 2 - Por selecao e troca (Do menor para o maior):\n");
  	printf("		> 3 - Por selecao e troca (Do maior para o menor):\n");
  	
  	printf("		> 4 - Por distribuicao (Do menor para o maior):\n");
  	printf("		> 5 - Por distribuicao (Do menor para o maior):\n");
  	
  	printf("		> 6 - Por insercao (Do menor para o maior):\n");
  	printf("		> 7 - Por insercao (Do menor para o maior):\n");
  	
  	printf("		> 8 - Por intercalacao (Do menor para o maior):\n");
  	printf("		> 9 - Por intercalacao (Do menor para o maior):\n");
  	
  	printf("	> 10 - Mostrar lista\n");
  	printf("	> 11 - Sair\n");
  	
  	scanf("%i", &escolha);
  	
  	switch(escolha){
  		case 1 :
  			cadastrar();
  			break;
  		case 2 : 
  			selectSort(1);
  			printf("A lista foi ordenada.\n");
  			break;
  		case 3 :
  			selectSort(0);
  			printf("A lista foi ordenada.\n");
  			break;
		case 4 :
  			mergeSort(residencias, TAM, 1);
  			printf("A lista foi ordenada.\n");
  			break;
  		case 5 :
  			mergeSort(residencias, TAM, 0);
  			printf("A lista foi ordenada.\n");
  			break;
  		case 6 :
  			insertionSortMenorParaMaior();
  			printf("A lista foi ordenada.\n");
  			break;
  		case 7 :
			insertionSortMaiorParaMenor();
  			printf("A lista foi ordenada.\n");
  			break;
  		case 8 :
  			mergesortIntercalacao(0, TAM, residencias, 1);
  			printf("A lista foi ordenada.\n");
  			break;
  		case 9 :
  			mergesortIntercalacao(0, TAM, residencias, 0);
  			printf("A lista foi ordenada.\n");
  			break;
  		case 10 :
  			imprimir();
  			break;
  		case 11 : 
  			printf("Saindo!\n");
  			break;
  		default:
  			printf("Opção invalida! Escolha novamente.\n");
	  }
  }
  
  linha();
  system("PAUSE");
}

void cadastrar(){
	
	   int i = 0;
       int x = 0;
       getchar();
       
  for(i=0; i<TAM; i++){

           printf("Digite o nome da rua da casa %i: \n", i+1);
           gets(residencias[i].rua);
           linha();
           printf("\nDigite o numero da casa:\n");
           scanf("%d", &residencias[i].numCasa);
           linha();
           
           printf("\nMedidor:\n");
           scanf("%i", &residencias[i].numMedidor);
           linha();
           
           printf("\nMedida consumo:\n");
           scanf("%f", &residencias[i].medidaConsumo);
           linha();
		   getchar();
     }
     
}

void imprimir(){
	linha();
	  for(in=0;in<TAM;in++){
    
    	printf("Residencia %i: \n", in+1);
		printf("Nome da rua: %s", residencias[in].rua);
		printf("\n");
		printf("Numero da casa: %i", residencias[in].numCasa);
		printf("\n");
		printf("Num Medidor: %d", residencias[in].numMedidor);
		printf("\n");
		printf("Medida Consumo: %f", residencias[in].medidaConsumo);
		printf("\n");
	
	}
	linha();
}
    
void linha(){
	int i = 0;
	for(i=1;i<=40;i++){
		printf("-");
	}
	printf("\n");
}

// Função de ordenação por seleção e troca
void selectSort(int menorParaMaior){
 int i, j, k, troca;
 struct Residencia temp;
 
 for(i = 0; i < TAM-1; i++){
	  troca = 0;
	  k = i;
	  temp = residencias[i];
	  for(j = i+1; j < TAM; j++){
	  	if(menorParaMaior==1){
			  if(residencias[j].medidaConsumo < temp.medidaConsumo){
			    k = j;
			    temp = residencias[j];
			    troca = 1;
			   }		
		  }else{
				if(residencias[j].medidaConsumo > temp.medidaConsumo){
			    k = j;
			    temp = residencias[j];
			    troca = 1;
			   }  	
		  }
	  }
	  if(troca){
	   residencias[k] = residencias[i];
	   residencias[i] = temp;
	  }
	}
}


void insertionSortMaiorParaMenor() {
   int i, j;
   struct Residencia temp;
      
   for (i = 1; i < TAM; i++){
      temp = residencias[i];
      j = i - 1;
      
      while ((j>=0) && (temp.medidaConsumo > residencias[j].medidaConsumo)) {
      	 residencias[j+1] = residencias[j];
         j--;
      }
      residencias[j+1] = temp;
   }
}

void insertionSortMenorParaMaior() {
   int i, j;
   struct Residencia temp;
      
   for (i = 1; i < TAM; i++){
      temp = residencias[i];
      j = i - 1;
      
      while ((j>=0) && (temp.medidaConsumo < residencias[j].medidaConsumo)) {
      	 residencias[j+1] = residencias[j];
         j--;
      }
      residencias[j+1] = temp;
   }
}


void intercalaMaiorParaMenor(int p, int q, int r, struct Residencia* v) {
	int i, j, k; 
	struct Residencia w[TAM];
	i = p;
	j = q;
	k = 0;
	while (i < q && j < r) {
		if (v[i].medidaConsumo > v[j].medidaConsumo) {
			w[k] = v[i];
			i++;
		} else {
			w[k] = v[j];
			j++;
		}
		k++;
	}
	while (i < q) {
		w[k] = v[i];
		i++;
		k++;
	}
	while (j < r) {
		w[k] = v[j];
		j++;
		k++;
	}
	for (i = p; i < r; i++){
		v[i] = w[i-p];	
	}

}

void intercalaMenorParaMaior(int p, int q, int r, struct Residencia* v) {
	int i, j, k; 
	struct Residencia w[TAM];
	i = p;
	j = q;
	k = 0;
	while (i < q && j < r) {
		if (v[i].medidaConsumo < v[j].medidaConsumo) {
			w[k] = v[i];
			i++;
		} else {
			w[k] = v[j];
			j++;
		}
		k++;
	}
	while (i < q) {
		w[k] = v[i];
		i++;
		k++;
	}
	while (j < r) {
		w[k] = v[j];
		j++;
		k++;
	}
	for (i = p; i < r; i++){
		v[i] = w[i-p];	
	}

}

void mergesortIntercalacao(int p, int r, struct Residencia* v, int menorParaMaior) {
	int q;
	if (p < r - 1) {
		q = (p + r) / 2;
		mergesortIntercalacao(p, q, v, menorParaMaior);
		mergesortIntercalacao(q, r, v, menorParaMaior);
		if(menorParaMaior==1){
			intercalaMenorParaMaior(p, q, r, v);
		}else{
			intercalaMaiorParaMenor(p, q, r, v);
		}
		
	}
}

//distribuição maior para menor
void mergeMaiorParaMenor(struct Residencia* vec, int vecSize) {
  int mid;
  int i, j, k;
  struct Residencia tmp[TAM];
 
  if (&tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i].medidaConsumo >= vec[j].medidaConsumo) {
      tmp[k] = vec[i++];
    }else {
      tmp[k] = vec[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k++] = vec[j++];
    }
  } else {
    while (i < mid) {
      tmp[k++] = vec[i++];
 
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
  }

}

//distribuição menor para maior
void mergeMenorParaMaior(struct Residencia* vec, int vecSize) {
  int mid;
  int i, j, k;
  struct Residencia tmp[TAM];
 
  if (&tmp == NULL) {
    exit(1);
  }
 
  mid = vecSize / 2;
 
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < vecSize) {
    if (vec[i].medidaConsumo <= vec[j].medidaConsumo) {
      tmp[k] = vec[i++];
    }
    else {
      tmp[k] = vec[j++];
    }
    ++k;
  }
 
  if (i == mid) {
    while (j < vecSize) {
      tmp[k++] = vec[j++];
    }
  }
  else {
    while (i < mid) {
      tmp[k++] = vec[i++];
 
    }
  }
 
  for (i = 0; i < vecSize; ++i) {
    vec[i] = tmp[i];
  }
 
}
 
 //distribuição
void mergeSort(struct Residencia* vec, int vecSize, int menorParaMaior) {
  int mid;
 
  if (vecSize > 1) {
    mid = vecSize / 2;
    mergeSort(vec, mid, menorParaMaior);
    mergeSort(vec + mid, vecSize - mid, menorParaMaior);
    if(menorParaMaior==1){
		mergeMenorParaMaior(vec, vecSize);
	}else{
		mergeMaiorParaMenor(vec, vecSize);
	}
    
  }
}
