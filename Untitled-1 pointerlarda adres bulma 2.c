#include <stdio.h>
#include <stdlib.h>
int main(){

   int sayi;
   int *sayininAdresi;
       printf("bir sayi giriniz:");
         scanf("%d",&sayi);

      sayininAdresi=&sayi;
      printf("%d %x \n",sayininAdresi,sayininAdresi);
      printf("%d %x",sayi,&sayi);
    return 0;
}