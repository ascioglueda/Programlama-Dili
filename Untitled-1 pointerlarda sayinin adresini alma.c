#include <stdio.h>
#include <stdlib.h>
int main(){

   int sayi;
   int *sayininAdresi;
       printf("bir sayi giriniz:");
         scanf("%d",&sayi);

      sayininAdresi=&sayi;
      printf("%d %x \t %u\t %p",sayininAdresi,sayininAdresi,sayininAdresi,sayininAdresi);
    return 0;
}