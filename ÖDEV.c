//dışarıdan girilen 15 sayının küçükten büyüğe doğru sıralaması
#include <stdio.h>
int main(){

 int sayilar[15];
 int i,j,gecici;
  
   for(i=0;i<15;i++){
      
     printf(" %d.lutfen sayi giriniz:",i+1);
     scanf("%d",&sayilar[i]);
   
   }
printf("\n Kucukten buyuge dogru siralanma :\n");
	
	for(i=0;i<15;i++)
	{
		for(j=i+1;j<15;j++)
		{
			if(sayilar[j] <sayilar[i]){
				gecici = sayilar[i];
				sayilar[i] =sayilar[j];
				sayilar[j] = gecici;
			}
		}
	}
	for(i=0;i<15;i++)
	{
		printf("%d\n",sayilar[i]);
	}
    return 0;
}