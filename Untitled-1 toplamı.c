#include <stdio.h>
int main (){
   
   int sayilar[]={10,20,30,40,50,60,70};
   int i;
   int toplam=0;
      
      for(i=0;i<7;i++){
          toplam=toplam+sayilar[i];
          
      }
      printf("Toplam:%d",toplam);

    return 0;
}