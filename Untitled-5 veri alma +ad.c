#include<stdio.h>
#include<stdlib.h>
 
typedef struct list {
    int Tc[11];
    char Ad[30];
    char soyad[30];
    char meslek[50];
    struct list *sonraki;
} liste;
liste *ilk = NULL, *son = NULL, *yeni, *silGecici, *gecici;
int i,j; 
void menu();
void ekle();
void sil(int,char );
void listele();
void arama(int,char );
void ekranTemizle();
void bekle();
 
int main() {
    while (1) {
        menu();
    }
    return 0;
}
 
void ekle(int veri) {
 
    yeni = (liste *) malloc(sizeof (liste));
    yeni->Tc[11] = veri;
    yeni->sonraki = NULL;
 
    if (ilk == NULL) { 
        ilk = yeni;
        son = ilk;
    } else { 
        son->sonraki = yeni;
        son = son->sonraki;
    }
void sil(int veri) {
    int kontrol = 0;
    if (ilk->Tc[11] == veri) {
        silGecici = ilk;
        ilk = ilk->sonraki;
        free(silGecici);
        kontrol = 1;
    } else {
        gecici = ilk;
        while (gecici->sonraki != NULL) { 
 
 
            if (gecici->sonraki->Tc[11] == veri) {
                kontrol = 1;
                silGecici = gecici->sonraki; 
                if (silGecici == son) 
                    son = gecici;
                gecici->sonraki = silGecici->sonraki; 
                free(silGecici); 
                break;
            }
            gecici = gecici->sonraki;
        }
    }
    if (kontrol == 0)
        printf("Silmek Istediginiz Eleman Listede Yoktur...\n");
    else
        printf("%d sayisi listeden silinmiştir...\n", veri);
}
 void listele() {
    gecici = ilk;
    while (gecici != NULL) {
        printf("%d\n", gecici->Tc[11]);
        gecici = gecici->sonraki;
    }
}
 void arama(int aranan) {
    int kontrol = 0;
    gecici = ilk;
    while (gecici != NULL) {
        if (aranan == gecici->Tc[11]) {
            kontrol = 1;
        }
        gecici = gecici->sonraki;
    }
   if (kontrol == 1)
        printf("\n%d  tc Bulunmustur..\n", aranan);
    else
        printf("\nAranan tc Bulunamamistir...\n");
}
void menu() {
    int secim, Tc[11];
    printf("1-Ekleme\n");
    printf("2-Listeleme\n");
    printf("3-Arama\n");
    printf("4-Silme\n");
    printf("5-Cikis\n");
    printf("Lutfen Secim Yapiniz --> ");
    scanf("%d", &secim);
 
    switch (secim) {
        case 1:
            ekranTemizle();
            for(i=0;i<11;i++){
                for(j=0;j<11;j++){
                   printf("Tc Giriniz: ");
            scanf("%d", &Tc[11]);
            printf("adinizi Giriniz: ");
            scanf("%d",& Ad[30]);
            printf("soyadinizi Giriniz: ");
            scanf("%d",& soyad[30]);
            printf("mesleginizi Giriniz: ");
            scanf("%d",& meslek[30]);
            ekle(Tc[11]);
            ekle(Ad[30]);
            ekle(soyad[30]);
            ekle(meslek[30]);
            printf("%d Tc niz  adiniz soyadiniz mesleginiz listeye eklendi\n",Tc[11],Ad[30],soyad[30],meslek[30]);
            bekle();
            break; 
                }
            }
        case 2:
            ekranTemizle();
            if (ilk == NULL) {
                printf("Liste Bostur. Lutfen eleman ekledikten sonra listeleme yapiniz..\n");
                bekle();
                break;
            }
            listele();
            bekle();
            break;
        case 3:
            ekranTemizle();
            if (ilk == NULL) {
                printf("Liste Bostur. Lutfen eleman ekledikten sonra arama yapiniz..\n");
                bekle();
                break;
            }
            printf("Tc Giriniz: ");
            scanf("%d", &Tc[11]);
            arama(Tc[11]);
            printf("Adinizi Giriniz: ");
            scanf("%d", &Ad[30]);
            arama(Ad[30]);,
            printf("Soyadinizi Giriniz: ");
            scanf("%d", &);
            arama(soyad[30]);
            printf("mesleginizi Giriniz: ");
            scanf("%d", &meslek[30]);
            arama(meslek[30]);
            bekle();
            break;
        case 4:
            ekranTemizle();
            if (ilk == NULL) {
                printf("Liste Bostur. Lutfen eleman ekledikten sonra silme yapiniz..\n");
                bekle();
                break;
            }
            printf("Tc[11] Giriniz: ");
            scanf("%d", &Tc[11]);
            sil(Tc[11]);
            printf("Adinizi Giriniz: ");
            scanf("%d", &);
            arama(Ad[30]);
            printf("Soyadinizi Giriniz: ");
            scanf("%d", &soyad[30]);
            arama(soyad[30]);
            printf("mesleginizi Giriniz: ");
            scanf("%d", &meslek[30]);
            arama(meslek[30]);
            bekle();
            break;
        case 5:
            ekranTemizle();
            printf("Program Bitti!\n");
            exit(0);
            break;
        default:
            ekranTemizle();
            printf("Hatali Secim\n");
            bekle();
    }
}
void ekranTemizle() {
 system("cls");
 }
void bekle() {
    char temp;
    printf("Devam etmek icin Enter'a basiniz!\n");
    temp = getchar();
    temp = getchar();
    ekranTemizle();
}