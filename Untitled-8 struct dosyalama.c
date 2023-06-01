#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ogrenciEkle(); //Fonksiyonların prototipleri deklare edilmektedir.
void dersEkle();
void ogrenciDersKaydi();
void ogrenciDersiListele();
void dersiAlanOgrecileriListele();

struct Ogrenci //Öğrenci yapısı tanımlanmaktadır.
{
    char ad[21];
    char soyad[21];
    int ogrenciNumarasi;
    int dersKodlari[10];
};

struct Ders //Ders yapısı tanımlanmaktadır.
{
    char dersAdi[21];
    int dersKodu;
};

int main()
{
    char secim;
    do
    {
        printf("   =Ogrenci Veri Tabani Sistemi=\n");
        printf("------------------------------------\n");
        printf("(1) - Ogrenci Ekle\n");
        printf("(2) - Ders Ekle\n");
        printf("(3) - Ogrenciyi Derse Kaydet\n");
        printf("(4) - Ogrenci Derslerini Listele\n");
        printf("(5) - Dersi Alan Ogrencileri Listele\n");
        printf("(6) - Cikis\n");
        printf("------------------------------------\n");
        printf("Seciminiz:");
        scanf(" %c",&secim); //Kullanıcıdan seçimi alınmaktadır.
        fflush(stdin); //Klavyeden alınarak tampona (buffer) yüklenmiş girdi tampondan silinmektedir. Başka bir deyişle buffer boşaltılmaktadır.
        switch(secim) //Girilen secime göre ilgili case yapsına girilmekte ve işlemler yapılmaktadır.
        {
            case '1':
                printf("\n-Ogrenci Ekleme-\n");
                printf("----------------\n\n");
                ogrenciEkle();
                printf("\n");
                break;
            case '2':
                printf("\n-Ders Ekleme-\n");
                printf("-------------\n\n");
                dersEkle();
                printf("\n");
                break;
            case '3':
                printf("\n-Ogrenci Ders Kaydi-\n");
                printf("--------------------\n\n");
                ogrenciDersKaydi();
                printf("\n");
                break;
            case '4':
                printf("\n-Ogrenci Derslerini Listele-\n");
                printf("----------------------------\n\n");
                ogrenciDersiListele();
                printf("\n");
                break;
            case '5':
                printf("\n-Dersi Alan Ogrencileri Listele-\n");
                printf("--------------------------------\n\n");
                dersiAlanOgrecileriListele();
                printf("\n");
                break;
            case '6':
                printf("\nOgrenci Veri Tabani Sisteminden Cikmaktasiniz...\n");
                break;
            default:
                printf("\nBoyle Bir Islem Seceneginiz Bulunmamaktadir. Yeniden Secim Yapiniz.\n\n");
                break;
        }
    }
    while(secim!='6'); //Kullanıcının 6 girmesiyle döngü sona ermekte ve programdan çıkılmaktadır.

    return 0; //İşlemlerin (fonksiyonun) başarılı bir şekilde sonuçlandığının gösterilmesi için kullanılmaktadır.
}

void ogrenciEkle() //Sisteme öğrenci ekleme fonksiyonu.
{
    FILE *ogrenciPtr;
    struct Ogrenci girilenOgrenci,tempOgrenci;
    int karakterSayisi,ogrenciNo;
    int dosyaUzunlugu;
    int indis;

    ogrenciPtr=fopen("ogrenci.bin","ab+"); //Dosya ekleme ve okuma modunda açılmaktadır.
    if(ogrenciPtr==NULL)
    {
        printf("ogrenci.bin Dosyasi Acilamadi...\n");
        exit(0); //Programdan çıkılmaktadır.
    }

    fseek(ogrenciPtr,0,SEEK_END); //ogrenciPtr dosyanın sonuna işaret etmektedir.
    dosyaUzunlugu=ftell(ogrenciPtr); //ftell() fonksiyonu yardımıyla dosyanın boyutu hesaplanmaktadır.

    if(dosyaUzunlugu==0) //Dosyanın boş olması durumunda eklenen ilk öğrenciye öğrenci numarası olarak 1 atanmaktadır.
        ogrenciNo=1;
    else
    {
        rewind(ogrenciPtr); //ogrenciPtr dosyanın başına işaret etmektedir.
        while( !feof(ogrenciPtr) ) //Dosya sonuna gelinmediği müddetçe döngü devam etmektedir.
        {
            fread( &tempOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr ); //Dosyadan ilgili öğrenciye ait bilgiler okunmaktadır.
            ogrenciNo=tempOgrenci.ogrenciNumarasi; //Sistemde kayıtlı olan en son öğrencinin öğrenci numarasi tespit edilmektedir.
        }
        ogrenciNo++; //Sisteme eklenecek bir sonraki öğrenci için öğrenci numarasi oluşturulmaktadır.
    }

    if(ogrenciNo>100)
        printf("Sistemde 100 Ogrenci Kayitlidir. Yeni Ogrenci Ekleyemessiniz!\n");

    else //Sistemde 100'den az öğrenci varsa else yapısına girilmektedir.
    {
        do
        {
            printf("Ogrenci Adini Giriniz:");
            gets(girilenOgrenci.ad);
            fflush(stdin);  //Klavyeden alınarak tampona (buffer) yüklenmiş girdi tampondan silinmektedir. Başka bir deyişle buffer boşaltılmaktadır.
            karakterSayisi=strlen(girilenOgrenci.ad); //Girilen adın karakter sayısı bulunmaktadır.
            if(karakterSayisi>20)
            {
                printf("\nOgrenci Adi 20 Karakterden Fazla Olamaz!\n");
                printf("Lutfen Ogrenci Adini Tekrar Giriniz.\n\n");
            }
        }
        while(karakterSayisi>20); //Girilen adın karakter sayısı 20'den büyük olduğu müddetçe döngü devam etmektedir.

        do
        {
            printf("Ogrenci Soyadini Giriniz:");
            gets(girilenOgrenci.soyad);
            fflush(stdin);  //Klavyeden alınarak tampona (buffer) yüklenmiş girdi tampondan silinmektedir. Başka bir deyişle buffer boşaltılmaktadır.
            karakterSayisi=strlen(girilenOgrenci.soyad); //Girilen soyadın karakter sayısı bulunmaktadır.
            if(karakterSayisi>20)
            {
                printf("\nOgrenci Soyadi 20 Karakterden Fazla Olamaz!\n");
                printf("Lutfen Ogrenci Soyadini Tekrar Giriniz.\n\n");
            }
        }
        while(karakterSayisi>20); //Girilen soyadın karakter sayısı 20'den büyük olduğu müddetçe döngü devam etmektedir.

        rewind(ogrenciPtr);
        girilenOgrenci.ogrenciNumarasi=ogrenciNo; //Eklenen öğrenciye, öğrenci numarası ataması yapılmaktadır.

        for(indis=0;indis<10;indis++)
        {
            girilenOgrenci.dersKodlari[indis]=0; //Eklenen öğrencinin alabileceği 10 dersin koduna 0 atanmaktadır.
        }

        fseek( ogrenciPtr,(ogrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET ); //Öğrencinin öğrenci numarasına göre dosyada bulunacağı sıra tespit edilmektedir.
        fwrite( &girilenOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr ); //Eklenen öğrenci bilgileri dosyaya yazılmaktadır.
        printf("\nOgrenci Sisteme Eklenmistir!\n");
    }

    fclose(ogrenciPtr); //Dosya kapatılmaktadır.
}

void dersEkle() //Sisteme ders ekleme fonksiyonu.
{
    FILE *derslerPtr;
    struct Ders girilenDers,tempDers;
    int karakterSayisi,dersKod;
    int dosyaUzunlugu;

    derslerPtr=fopen("dersler.bin","ab+"); //Dosya ekleme ve okuma modunda açılmaktadır.
    if(derslerPtr==NULL)
    {
        printf("dersler.bin Dosyasi Acilamadi...\n");
        exit(0); //Programdan çıkılmaktadır.
    }

    fseek(derslerPtr,0,SEEK_END); //derslerPtr dosyanın sonuna işaret etmektedir.
    dosyaUzunlugu=ftell(derslerPtr); //ftell() fonksiyonu yardımıyla dosyanın boyutu hesaplanmaktadır.

    if(dosyaUzunlugu==0)
        dersKod=1001; //Dosyanın boş olması durumunda eklenen ilk derse ders kodu olarak 1001 atanmaktadır.
    else
    {
        rewind(derslerPtr); //derslerPtr dosyanın başına işaret etmektedir.
        while( !feof(derslerPtr) ) //Dosya sonuna gelinmediği müddetçe döngü devam etmektedir.
        {
            fread( &tempDers,sizeof(struct Ders),1,derslerPtr ); //Dosyadan ilgili derse ait bilgiler okunmaktadır.
            dersKod=tempDers.dersKodu; //Sistemde kayıtlı olan en son dersin ders kodu tespit edilmektedir.
        }
        dersKod++; //Sisteme eklenecek bir sonraki ders için ders kodu oluşturulmaktadır.
    }

    if(dersKod>1020)
        printf("Sistemde 20 Ders Kayitlidir. Yeni Ders Ekleyemessiniz!\n");
    else //Sistemde 20'den az ders varsa else yapısına girilmektedir.
    {
        do
        {
            printf("Eklenecek Dersin Adini Giriniz:");
            gets(girilenDers.dersAdi);
            fflush(stdin); //Klavyeden alınarak tampona (buffer) yüklenmiş girdi tampondan silinmektedir. Başka bir deyişle buffer boşaltılmaktadır.
            karakterSayisi=strlen(girilenDers.dersAdi); //Girilen ders adının karakter sayısı bulunmaktadır.
            if(karakterSayisi>20)
            {
                printf("\nDers Adi 20 Karakterden Fazla Olamaz!\n");
                printf("Lutfen Ders Adini Tekrar Giriniz.\n\n");
            }
        }
        while(karakterSayisi>20); //Girilen ders adının karakter sayısı 20'den büyük olduğu müddetçe döngü devam etmektedir.

        rewind(derslerPtr);
        girilenDers.dersKodu=dersKod;
        fseek( derslerPtr,(dersKod-1-1000)*sizeof(struct Ders),SEEK_SET ); //Dersin ders koduna göre dosyada bulunacağı sıra tespit edilmektedir.
        fwrite( &girilenDers,sizeof(struct Ders),1,derslerPtr ); //Eklenen ders bilgileri dosyaya yazılmaktadır.
        printf("\nDers Sisteme Eklenmistir!\n");
    }

    fclose(derslerPtr); //Dosya kapatılmaktadır.
}

void ogrenciDersKaydi() //Öğrencinin derse kaydının yapıldığı fonksiyon.
{
    FILE *ogrenciPtr,*derslerPtr;
    struct Ogrenci okunanOgrenci;
    struct Ders okunanDers;
    int girilenOgrenciNo,girilenDersKodu;
    int ogrenciDersSayisi=0,kontrol=0,indis;

    ogrenciPtr=fopen("ogrenci.bin","rb+"); //Dosya okuma ve yazma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(ogrenciPtr==NULL)
    {
        printf("ogrenci.bin Dosyasi Acilamadi...\n");
        exit(0);  //Programdan çıkılmaktadır.
    }

    derslerPtr=fopen("dersler.bin","rb"); //Dosya okuma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(derslerPtr==NULL)
    {
        printf("dersler.bin Dosyasi Acilamadi...\n");
        exit(0);
    }

    do
    {
        printf("Derse Kayit Yapmak Istediginiz Ogrencinin Ogrenci Numarasini Giriniz:");
        scanf("%d",&girilenOgrenciNo);
        fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET );
        fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr );
        if(girilenOgrenciNo!=okunanOgrenci.ogrenciNumarasi)
            printf("\n%d Ogrenci Numarali Ogreci Sistemde Kayitli Degildir!\nLutfen Yeni Bir Ogrenci Numarasi Giriniz.\n\n",girilenOgrenciNo);
        rewind(ogrenciPtr); //ogrenciPtr dosyanın başına işaret etmektedir.
    }
    while(girilenOgrenciNo!=okunanOgrenci.ogrenciNumarasi); //Girilen öğreci numarası, sistemde kayıtlı bir öğrenci numarası olana kadar döngü devam etmektedir.

    fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET ); //Girilen öğrenci numarasına göre ilgili öğrencinin dosyadaki yeri tespit edilmektedir.
    fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr ); //İlgili öğrencinin bilgileri dosyadan okunmaktadır.
    for(indis=0;indis<10;indis++)
    {
        if(okunanOgrenci.dersKodlari[indis]!=0)
            ogrenciDersSayisi++; //Ders kaydı yapılacak olan öğrencinin kayıtlı olduğu ders sayısı tespit edilmektedir.
    }

    if(ogrenciDersSayisi==10)
        printf("\nOgrenciye Tanimli 10 Ders Bulunmaktadir. Ogrenciye Baska Ders Tanimlayamassiniz!\n");
    else //Ders kaydı yapılacak olan öğrencinin kayıtlı olduğu ders sayısı 10 dan az ise else yapsına girilmektedir.
    {
        rewind(ogrenciPtr);
        do
        {
            printf("Ogrenciye Tanimlamak Istediginiz Dersin Kodunu Giriniz:");
            scanf("%d",&girilenDersKodu);
            fseek( derslerPtr,(girilenDersKodu-1-1000)*sizeof(struct Ders),SEEK_SET );
            fread( &okunanDers,sizeof(struct Ders),1,derslerPtr );
            if(girilenDersKodu!=okunanDers.dersKodu)
                printf("\n%d Ders Kodlu Ders Sistemde Kayitli Degildir!\nLutfen Yeni Bir Ders Kodu Giriniz.\n\n",girilenDersKodu);
            rewind(derslerPtr);
        }
        while(girilenDersKodu!=okunanDers.dersKodu); //Girilen ders kodu, sistemde kayıtlı bir ders kodu olana kadar döngü devam etmektedir.

        fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET );
        fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr );

        for(indis=0;indis<10;indis++)
        {
            if(okunanOgrenci.dersKodlari[indis]==0) //İlgili indisde ders kodu tanımlı değilse if yapısına girilmektedir.
            {
                okunanOgrenci.dersKodlari[indis]=okunanDers.dersKodu; //Kullanıcının öğrenciyi kaydetmek istediği dersin kodu dersKodlari dizisine aktarılmaktadır.
                kontrol=1;
                break;
            }
            else
            {
                if(okunanOgrenci.dersKodlari[indis]==okunanDers.dersKodu) //Kullanıcının girdiği ders kodu öğrencinin kayıtlı olduğu dersin kodu ise if yapısına girilmektedir.
                {
                    kontrol=0;
                    break;
                }
            }
        }

        if(kontrol==1)
        {
            rewind(ogrenciPtr);
            fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET );
            fwrite( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr ); //Öğrenci bilgileri gerçekleştirilen ders kaydıyla birlikte dosyaya yazılmaktadır.
            printf("\n%d Numarali Ogrencinin %d Kodlu %s Dersine Kaydi Yapilmistir!\n",okunanOgrenci.ogrenciNumarasi,okunanDers.dersKodu,okunanDers.dersAdi);
        }
        else
            printf("\n%d Numarali Ogrencinin %d Kodlu %s Dersine Kaydi Bulunmaktadir!\n",okunanOgrenci.ogrenciNumarasi,okunanDers.dersKodu,okunanDers.dersAdi);
    }

    fclose(ogrenciPtr); //Dosyalar kapatılmaktadır.
    fclose(derslerPtr);
}

void ogrenciDersiListele() //Öğrencinin sistemde kayıtlı olduğu tüm derslerin adının ve kodlarının listelendiği fonksiyon.
{
    FILE *ogrenciPtr,*derslerPtr;
    struct Ogrenci okunanOgrenci;
    struct Ders okunanDers;
    int girilenOgrenciNo,alinanDersSaysi=0;
    int indis;

    ogrenciPtr=fopen("ogrenci.bin","rb"); //Dosya okuma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(ogrenciPtr==NULL)
    {
        printf("ogrenci.bin Dosyasi Acilamadi...\n");
        exit(0); //Programdan çıkılmaktadır.
    }

    derslerPtr=fopen("dersler.bin","rb"); //Dosya okuma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(derslerPtr==NULL)
    {
        printf("dersler.bin Dosyasi Acilamadi...\n");
        exit(0);
    }

    do
    {
        printf("Kayitli Derslerini Gormek Istediginiz Ogrencinin Ogrenci Numarasini Giriniz:");
        scanf("%d",&girilenOgrenciNo);
        fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET );
        fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr );
        if(girilenOgrenciNo!=okunanOgrenci.ogrenciNumarasi)
            printf("\n%d Ogrenci Numarali Ogreci Sistemde Kayitli Degildir!\nLutfen Yeni Bir Ogrenci Numarasi Giriniz.\n\n",girilenOgrenciNo);
        rewind(ogrenciPtr);
    }
    while(girilenOgrenciNo!=okunanOgrenci.ogrenciNumarasi); //Girilen öğreci numarası, sistemde kayıtlı bir öğrenci numarası olana kadar döngü devam etmektedir.

    fseek( ogrenciPtr,(girilenOgrenciNo-1)*sizeof(struct Ogrenci),SEEK_SET ); //Girilen öğrenci numarasına göre ilgili öğrencinin dosyadaki yeri tespit edilmektedir.
    fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr ); //İlgili öğrencinin bilgileri dosyadan okunmaktadır.

    printf("\nOgrenci Numarasi  : %d\n",okunanOgrenci.ogrenciNumarasi);
    printf("Ogrenci Adi       : %s\n",okunanOgrenci.ad);
    printf("Ogrenci Soyadi    : %s\n\n",okunanOgrenci.soyad);
    printf("Ogrencinin Aldigi Dersler\n");
    printf("-------------------------\n");

    while(  fread( &okunanDers,sizeof(struct Ders),1,derslerPtr )==1 ) //Dosya sonuna gelinmediği müddetçe döngü devam etmektedir.
    { //Dosyadan okunan ders bilgileri okunanDers'e aktarılmaktadır.
        for(indis=0;indis<10;indis++)
        {
            if(okunanOgrenci.dersKodlari[indis]==okunanDers.dersKodu)
            {
                printf("Dersin Kodu: %d\nDersin Adi : %s\n\n",okunanDers.dersKodu,okunanDers.dersAdi);  //Öğrencinin kayıtlı olduğu dersin kodu ve dersin adı bilgileri ekrana yazdırılmaktadır.
                alinanDersSaysi++; //Öğrencinin sistede kayıtlı olduğu ders sayısı tespit edilmektedir.
            }
        }
    }
    if(alinanDersSaysi==0)
        printf("Ogrenci Hicbir Derse Kayitli Degildir!\n");

    fclose(ogrenciPtr); //Dosyalar kapatılmaktadır.
    fclose(derslerPtr);
}

void dersiAlanOgrecileriListele() //Derse kayıtlı olan tüm öğrencilerin adının, soyadının ve öğrenci numarasının listelendiği fonksiyon.
{
    FILE *ogrenciPtr,*derslerPtr;
    struct Ogrenci okunanOgrenci;
    struct Ders okunanDers;
    int girilenDersKodu,dersiAlanOgrenciSayisi=0;
    int indis;

    ogrenciPtr=fopen("ogrenci.bin","rb"); //Dosya okuma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(ogrenciPtr==NULL)
    {
        printf("ogrenci.bin Dosyasi Acilamadi...\n");
        exit(0); //Programdan çıkılmaktadır.
    }

    derslerPtr=fopen("dersler.bin","rb"); //Dosya okuma modunda açılmaktadır. İmleç dosyanın başında bulunmaktadır.
    if(derslerPtr==NULL)
    {
        printf("dersler.bin Dosyasi Acilamadi...\n");
        exit(0);
    }

    do
    {
        printf("Derse Kaydi Olan Ogrecileri Gormek Icin Dersin Kodunu Giriniz:");
        scanf("%d",&girilenDersKodu);
        fseek( derslerPtr,(girilenDersKodu-1-1000)*sizeof(struct Ders),SEEK_SET );
        fread( &okunanDers,sizeof(struct Ders),1,derslerPtr );
        if(girilenDersKodu!=okunanDers.dersKodu)
            printf("\n%d Ders Kodlu Ders Sistemde Kayitli Degildir!\nLutfen Yeni Bir Ders Kodu Giriniz.\n\n",girilenDersKodu);
        rewind(derslerPtr);
    }
    while(girilenDersKodu!=okunanDers.dersKodu); //Girilen ders kodu, sistemde kayıtlı bir ders kodu olana kadar döngü devam etmektedir.

    fseek( derslerPtr,(girilenDersKodu-1-1000)*sizeof(struct Ders),SEEK_SET ); //Girilen ders koduna göre ilgili dersin dosyadaki yeri tespit edilmektedir.
    fread( &okunanDers,sizeof(struct Ders),1,derslerPtr ); //İlgili dersin bilgileri dosyadan okunmaktadır.

    printf("\nDersin Kodu    : %d\n",okunanDers.dersKodu);
    printf("Dersin Adi     : %s\n\n",okunanDers.dersAdi);

    printf("Dersi Alan Ogreciler\n");
    printf("--------------------\n");

    while(  fread( &okunanOgrenci,sizeof(struct Ogrenci),1,ogrenciPtr )==1 ) //Dosya sonuna gelinmediği müddetçe döngü devam etmektedir.
    { //Dosyadan okunan öğrenci bilgileri okunanOgrenci'ye aktarılmaktadır.
        for(indis=0;indis<10;indis++)
        {
            if( okunanOgrenci.dersKodlari[indis]==okunanDers.dersKodu )
            {
                printf("Ogrenci Numarasi  : %d\n",okunanOgrenci.ogrenciNumarasi); //İlgili derse kayıtlı olan öğrencilerin öğrenci numrası, ad ve soyad bilgileri ekrana yazdırılmaktadır.
                printf("Ogrenci Adi       : %s\n",okunanOgrenci.ad);
                printf("Ogrenci Soyadi    : %s\n\n",okunanOgrenci.soyad);
                dersiAlanOgrenciSayisi++; //Derse sistemde kayıtlı olan öğrenci sayısı tespit edilmektedir.
                break;
            }
        }
    }
    if(dersiAlanOgrenciSayisi==0)
        printf("Bu Derse Hicbir Ogrenci Kayitli Degildir!\n");

    fclose(ogrenciPtr); //Dosyalar kapatılmaktadır.
    fclose(derslerPtr);
}