#include <stdio.h>
#include <stdlib.h>
#define TAM  10
 
void Carregar();
void MostrarLista();
void MostrarQuantidadePares();
void MostrarQuantidadeImpares();

 int lista[TAM];
 int qtVetor = 0;

 
main(){

Carregar();

MostrarLista();

MostrarQuantidadePares();

MostrarQuantidadeImpares();

printf("\n");

 system("PAUSE");
}

void MostrarLista(){

 int x;
 for(x = 0; x < TAM; x++){
       if(x==qtVetor){
        break;
       }
       printf("\n%d", lista[x]);
 }
      
}

void Carregar(){
int i = -1;
  printf("Digite um numero para adicionar a fila.\n");      
  printf("Digite 0 (zero) para mostrar o resultado\n");
  
 do{
  i++;
  scanf("%d", &lista[i]);
  if(lista[i]==0){
            break;
            }   
            qtVetor++;      
 }while(i!=TAM-1);      
           
 }
 
 
 void MostrarQuantidadePares(){

 printf("\n Quantidade de pares: ");
 int x;
 int q = 0;
 for(x = 0; x < TAM; x++){
    if(x==qtVetor){
        break;
    }
       if(lista[x]%2==0){
         q++;
       }
 }
      printf("%d", q);      
}

 void MostrarQuantidadeImpares(){

 printf("\n Quantidade de impares: ");
 int x;
 int q = 0;
 for(x = 0; x < TAM; x++){
        if(x==qtVetor){
         break;
       }
       if(lista[x]%2!=0){
         q++;
       }
 }
      printf("%d", q);
}
