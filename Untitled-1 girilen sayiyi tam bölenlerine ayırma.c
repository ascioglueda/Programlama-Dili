//klavyeden girilen sayının tam bölenlerine ayırınız
#include <stdio.h>
int main ()
{
    int i,sayi;
    int a,b,c;
   printf("lutfen bir sayi giriniz:");
   scanf("%d",&sayi);

     for(i=1;i<=sayi;i++){
      if(sayi%i==0){
         printf("%d\n",i);
      }

     }
    
    return 0;
}
