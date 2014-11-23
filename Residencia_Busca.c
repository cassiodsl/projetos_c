#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TAM 2

int in,chave,pesq,posicao;
int RandomInteger(int low, int high);
void BuscaSequencial();
void Linha();

// Algoritmo 2 - Definição de uma struct que representa uma 
// residencia (respectivamente, uma leitura de consumo)  
struct Residencia {     
       char rua[25];     
       int numCasa;     
       int numMedidor;     
       float medidaConsumo; 
       } vetResidencias[TAM]; 

main(){
       int i = 0;
       int x = 0;
  for(i=0; i<TAM; i++){
           
           printf("\nDigite o numero da casa:\n");
           scanf("%d", &vetResidencias[i].numCasa);
           Linha();
           
           printf("Digite o nome da rua da casa %i: \n", i+1);
           gets(vetResidencias[i].rua);
           Linha();
           
           
           printf("\nMedidor:\n");
           scanf("%i", &vetResidencias[i].numMedidor);
           Linha();
           
           printf("\nMedida consumo:\n");
           scanf("%d", &vetResidencias[i].medidaConsumo);
           Linha();
     }
  
  
  BuscaSequencial();
                           
  system("PAUSE");	
  return 0;
}

// Algoritmo 1 - Gerador de números inteiros aleatórios 
// A função RandomInteger devolve um inteiro  
// aleatório entre low e high inclusive, 
// ou seja, no intervalo fechado low..high.  
int RandomInteger (int low, int high) {     
    int k;     
    double d;     
    d = (double) rand () / ((double) RAND_MAX + 1);     
    k = d * (high - low + 1);     
    return low + k; 
    } 
    
    void Linha(){
         int i = 0;
         for(i=1;i<=40;i++){
          printf("-");
          }
          printf("\n");
}
  void BuscaSequencial(){
  Linha();
  printf("\nDigite o numero ser localizado : ");
  int num = 0;
  scanf("%d", &num);
  for(in=0;in<TAM;in++){
    if(vetResidencias[in].numCasa==num){
       printf("Nome da rua: %s", vetResidencias[in].rua);
       printf("\n");
       printf("Numero da casa: %d", in+1, vetResidencias[in].numCasa);
       printf("\n");
       printf("Num Medidor: %d", vetResidencias[in].numMedidor);
       printf("\n");
       printf("Medida Consumo: %d", vetResidencias[in].medidaConsumo);
       printf("\n");
    } 
}   
}
