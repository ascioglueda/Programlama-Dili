#include <stdio.h>
#include <time.h>
int main()
{
	int dizi[5][5];
    int i,j;
	srand(time(NULL));
	printf("\n Dizi Matrisi \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			dizi[i][j]=rand()%100 + 1;
			printf("  %d\t\t", dizi[i][j]);
		}
		printf("\n");
	}
    int satir, sutun;
 for(satir=0; satir<5; satir++)
 {
  for(sutun=0; sutun<5; sutun++)
 {
   printf(" %d\t\t ",dizi[satir][sutun]);
  }
  printf("\n"); 
 }
	return 0;
}
