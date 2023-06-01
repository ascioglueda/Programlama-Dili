#include<stdio.h>

int main(){
	int boyut;
    int sil, silindi=0;
    int dizi[][] = {};
    int i,j;
    int diziTc[11];
    char diziAd[30];
    char diziSoyad[30];
    char diziMeslek[40];
    
    //dizinin boyutunu bulalım
    /*int boyut = sizeof(dizi) / sizeof(dizi[0]);*/
    
    //diziyi ekrana yazdırıyoruz
    for(int i=0 ; i<boyut ; i++)
    	printf("%d ",dizi[i]);
    
    printf("\nSilinecek sayiyi giriniz : ");
    scanf("%d", &sil);
    
    //silme işlemi
    for(int i=0; i<boyut; i++)
    {
        if(dizi[i] == sil)
        {
            for(int j=i; j<(boyut - 1); j++)
                dizi[j] = dizi[j+1];
            silindi = 1;
            i--;
            boyut--;
        }
    }
    if(silindi == 0)
        printf("Eleman listede bulunamadi.");
    else
        printf("Eleman listeden silindi");
        
        
    //diziyi ekrana yazdırıyoruz
    printf("\nDizinin son hali : ");
    
    for(int i=0 ; i<boyut ; i++)
    	printf("%d ",dizi[i]);
        
    
}