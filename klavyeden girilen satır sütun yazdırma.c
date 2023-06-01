//klavyeden girilen satır sütun alma
#include <stdio.h>
int main (){
int satir,sutun,i,j,k,n;

  printf("satir sayisini giriniz:");
   scanf("%d",&satir);
  printf("sutun sayisini giriniz:");
   scanf("%d",&sutun);

int matris[satir][sutun];
 for(i=0;i<satir;i++){
     for(j=0;j<sutun;j++){
       printf("\n degeriniz [%d][%d]:",i+1,j+j);
       scanf("%d",&matris[i][j]);
     }
 }
 for(k=0;k<satir;k++){
     for(n=0;n<sutun;n++){
         printf(" %d\t",matris[k][n]);
     }
printf("\n");
 }


    return 0;
}