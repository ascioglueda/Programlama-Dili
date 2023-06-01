// 3 basamaklı birbirinden farklı kaç sayı vardır
#include <stdio.h>
int main(){

   int sayac=0;
   int i,a,b,c;

  for(i=100;i<=999;i++){
     a=i/100;
     b=(i/10)%10;
     c=i%10;
     if(a!=b && a!=c && b!=c)
     {
         sayac++;
     }
  }
   printf("%d",sayac);

    return 0;
}