#include<stdio.h>
#include<stdlib.h>
 
typedef struct list {
    int sayi;
    struct list *sonraki;
} liste;
liste *ilk = NULL, *son = NULL, *yeni, *silGecici, *gecici;
 
void menu();
void ekle();
void sil(int );
void listele();
void arama(int );
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
    yeni->sayi = veri;
    yeni->sonraki = NULL;
 
    if (ilk == NULL) { //İlk düğümde eleman olup olmadığını kontrol et.
        ilk = yeni;
        son = ilk;
    } else { //İlk düğümde eleman varsa bu işlemleri yap.
        son->sonraki = yeni;
        son = son->sonraki;
    }
}
 
void sil(int veri) {
    int kontrol = 0;
    if (ilk->sayi == veri) {
        silGecici = ilk;
        ilk = ilk->sonraki;
        free(silGecici);
        kontrol = 1;
    } else {
        gecici = ilk;
        while (gecici->sonraki != NULL) { //gecici değişken ile liste üzerinde dolaşım sağlanır.
 
 
            if (gecici->sonraki->sayi == veri) {
                kontrol = 1;
                silGecici = gecici->sonraki; //Silinecek düğüm sil adında değişkene atılır.
 
                if (silGecici == son) //Silinecek düğüm son düğüm ise "son" un kaybolmaması için bir geriye atanır.
                    son = gecici;
                gecici->sonraki = silGecici->sonraki; //Liste kaybolmasın diye aradaki bağ düzenlenir.
                free(silGecici); //Sil düğümü bellekten silinir.
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
        printf("%d\n", gecici->sayi);
        gecici = gecici->sonraki;
 
    }
}
 
void arama(int aranan) {
    int kontrol = 0;
    gecici = ilk;
 
 
    while (gecici != NULL) {
        if (aranan == gecici->sayi) {
            kontrol = 1;
        }
        gecici = gecici->sonraki;
    }
 
    if (kontrol == 1)
        printf("\n%d Sayisi Bulunmustur..\n", aranan);
    else
        printf("\nAranan Sayi Bulunamamistir...\n");
}
 
void menu() {
    int secim, sayi;
 
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
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            ekle(sayi);
            printf("%d sayisi listeye eklendi\n",sayi);
            bekle();
            break;
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
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            arama(sayi);
            bekle();
            break;
        case 4:
            ekranTemizle();
            if (ilk == NULL) {
                printf("Liste Bostur. Lutfen eleman ekledikten sonra silme yapiniz..\n");
                bekle();
                break;
            }
            printf("Sayi Giriniz: ");
            scanf("%d", &sayi);
            sil(sayi);
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
    //klavyeden okuma atlamasinin onune gecmek icin 2 kere yazildi
    temp = getchar();
    temp = getchar();
    ekranTemizle();
 
}