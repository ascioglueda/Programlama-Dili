#include <stdio.h>
 
main()
{
    int satir;
    int sutun;
    int toplam = 0;
    printf("Satir sayisini giriniz: ");
    scanf("%d",&satir);
    printf("Sutun sayisini giriniz: ");
    scanf("%d",&sutun);
    
    int dizi[satir][sutun];
    
    for(int i = 0; i < satir; i++)
    {
        for(int j = 0; j < sutun; j++)
        {
            printf("[%d][%d] = ",i,j);
            scanf("%d",&dizi[i][j]);
        }
    }
    printf("\n\n");
    
    for(int i = 0; i < satir; i++)
    {
        for(int j = 0; j < sutun; j++)
        {
            toplam += dizi[i][j];
            printf("%d\t",dizi[i][j]);
        }
        printf("Toplam = %d",toplam);
        toplam = 0;
        printf("\n");
    }
    return 0;
}