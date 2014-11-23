#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void Carregar();
void BuscaSequancial();
void Linha();

int item[TAM];
int i,chave,pesq,posicao;

main()
{
  Linha();
  printf("\n           BUSCA SEQUENCIAL      \n");
  Linha();
  Carregar();
  BuscaSequancial();
  printf("\n");                            
  system("PAUSE");	
  return 0;
}

  void Carregar(){
  for(i=0;i<=9;i++){
  printf("\nDigite o %d%s",(i+1),"o numero -> ");  
  scanf("%i",&item[i]);
  }
}
  void BuscaSequancial(){
  Linha();
  printf("\nDigite o dado a ser localizado : ");
  scanf("%d",&chave);
  for(i=0;i<TAM;i++){
    if(chave==item[i]){
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
     
