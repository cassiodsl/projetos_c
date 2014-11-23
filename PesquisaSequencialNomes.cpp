#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define TAM 10



void Carregar();
void BuscaSequencial();
void Linha();

char item[TAM][20];
int i,pesq,posicao;
char chave[1][20];

main()
{
  Linha();
  printf("\n           BUSCA SEQUENCIAL      \n");
  Linha();
  Carregar();
  BuscaSequencial();
  printf("\n");                            
  system("PAUSE");	
  return 0;
}

  void Carregar(){
  for(i=0;i<=9;i++){
  printf("\nDigite o %d%s",(i+1),"o nome -> ");  
  gets(item[i]);
  }
}
  void BuscaSequencial(){
  Linha();
  printf("\nDigite o dado a ser localizado : ");
  gets(chave[0]);
  for(i=0;i<TAM;i++){
    if(strcmp(chave[0], item[i])== 0){
    printf("\necontrado");
       pesq=1;
       posicao=i;}
    }    
       if(pesq==1){              
       printf("\nAchado o dado na posicao : %d %s",posicao+1," do vetor de dados\n");  
       }
       else{
       printf("\nNao achou o dado no vetor\n");    
       }  
     Linha();                     
}    
     
void Linha(){
     for(i=1;i<=40;i++){
       printf("-");
       }
   }
     
