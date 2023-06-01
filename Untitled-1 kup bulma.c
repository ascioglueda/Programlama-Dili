//klavyeden girilen sayinin küpünü alan kod
#include <stdio.h>
int main(){
int i,sayi,kup;
  
  
  printf("Bir sayi giriniz:");
  scanf("%d",&sayi);
 
  kup=sayi*sayi*sayi;

  printf("Girilen Sayinin Kupu:%d",kup);
     

    return 0;
}