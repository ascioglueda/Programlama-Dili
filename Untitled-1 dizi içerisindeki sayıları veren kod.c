#include <stdio.h>
int main(){

int dizi[100];
int i,sayi;

   printf("eleman sayisi: ");
   scanf("%d",&sayi);

       for(i=0;i<sayi;i++)
       {
           printf("dizinin %d. degerini giriniz:",i+1);
           scanf("%d",&dizi[i]);
       }

        printf("\n\n");

      for(i=0;i<sayi;i++)
      {
          printf(" %d\n",dizi[i]);
      }







    return 0;
}