#include <stdio.h>
#include <stdlib.h>

main(){
       int aux;
       int i, j, x;

       int valor[10] = {23, 14, 3, 17, 19 ,28, 40, 1, 2};
       for(i=0;i<10; i++){
         for(j=i+1; j<10; j++){
             if(valor[i]>valor[j]){
                 aux=valor[i];
                 valor[i]=valor[j];
                 valor[j]=aux;
             }
         }
       }
       
       for(x = 0; x < 10; x++){
             printf("\n%d", valor[x]);
       }
       printf("\n");
       system("PAUSE");
}