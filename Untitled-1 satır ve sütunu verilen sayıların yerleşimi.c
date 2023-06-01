#include <stdio.h>
int main (){

int matris[2][3]={1,2,3,4,5,6};
int i,j;
 for(i=0;i<2;i++){//satır
     for (j=0;j<3;j++){//sütun
         printf("%d\t",matris[i][j]);
     }
     printf("\n");
 }

    return 0;
}