#include <stdio.h>
#include <locale.h>
#include <string.h>
  struct OGRENCI {
    char isim[15];
    int numara;
    char bolum[15];
}kisi[10],yedek[10],silinecek[10];

void kayit_ekle();
void ara_bul();
void listele();
void bul_degistir();
void kayit_sil();
char menu();
int sayac;

main(){
    char secim;
    do{
        secim=menu();
        switch(secim)
        {
           case '1':kayit_ekle();break;
           case '2':listele();break;//menuden gelen veri 2 ise listeleme fonksiyonu çağırılıyor
           case '3':ara_bul();break;//menuden gelen veri 3 ise arabul fonksiyonu çağırılıyor
           case '4':bul_degistir();break;//menuden gelen veri 4 ise buldegistir fonksiyonu çağırılıyor
         //  case '5':kayit_sil();break;//menuden gelen veri 5 ise kayıt silfonksiyonu çağırılıyor

        }
    }while(secim<='4' && secim>='1');//karşılaştırma menuden gelen verilerin 1 ile 5 arasında ise

    }//ana fonksiyon sonu
char menu(){//menu fonksiyonu
    char tus;//tus adında char tipinde değişken tanımlanıyor
    printf("1-kayit ekle\n2-listele\n3-arabul\n4-buldegistir\n");//manu seçenekleri ekrana yazdırılıyor
    tus=getch();//kullanıcının girdiği tuş algılanıyor
    return tus;//menu fonksiyonunun çağırıldığı yere kullanıcının girdiği tuş döndürülüyor
}//menu fonksiyonu sonu
void kayit_ekle(){//kayıt ekleme fonksiyonu
    char tus2;//tus2 adında char tipinde değişken tanımlanıyor
    FILE *dosya;//file tipinde bir dosya adında bir pointer tanımlanıyor
    dosya=fopen("a.txt","w");//dosya önceki verilerin üstüne yazmak için açılıyor

    do{
        printf("%d.kişi adi giriniz",sayac+1);//kullanıcıdan isim isteniyor
        scanf("%s",kisi[sayac].isim);//kullanıcını girdiği veri struct yapısına aktarılıyor
        fflush(stdin);//veri değişkene aktarıldıktan sonra gerekli alan boşaltılıyor
        printf("%d.kişinin bölüm giriniz",sayac+1);//kullanıcıdan bölüm isteniyor
        scanf("%s",kisi[sayac].bolum);//kullanıcını girdiği veri struct yapısına aktarılıyor
        fflush(stdin);//veri değişkene aktarıldıktan sonra gerekli alan boşaltılıyor
        printf("%d.kişi numarayi giriniz",sayac+1);//kullanıcıdan final isteniyor
        scanf("%d",&kisi[sayac].numara);//kullanıcını girdiği veri struct yapısına aktarılıyor
        fflush(stdin);//veri değişkene aktarıldıktan sonra gerekli alan boşaltılıyor
        printf("yeni kayit için e basin ve menüye dönmek için herhangi bir tusa basin");//veriler girildikten sonra kullanıcıdan yeni veri girmek istermisiniz diye soruluyor
        tus2=getch();//kullanıcının girdiği karakter tus2 değişkenine aktarılıyor

        fprintf(dosya,"%s\t%s\t%d\t%d\n",kisi[sayac].isim,kisi[sayac].bolum,kisi[sayac].numara);//veriler dosyaya yazılıyor
        sayac++;//whileiçin sayac 1 arttırılıyor
    }while(tus2=='e' || tus2=='E');//eğer kullanıcı devam etmek isterse tekrar dön
    fclose(dosya);//dosya kapatılıyor
}//kayıt ekleme fonksiyonusonu
void listele(){//listele fonksiyonu
    FILE *dosya;//file tipinde bir dosya adında bir pointer tanımlanıyor
    dosya=fopen("a.txt","r");//dosya önceki verileri okumak için açılıyor
    int a=0,i;//değişkenler tanımlanıyor
    while(!feof(dosya)){//dosya sonuna kadar dön
        fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].numara);//veriler dosyadan okunuyor
        a++;      //while için a arttırılıyor
    }//dosya sonuna kadar dön sonu
    for(i=0;i<(a-1);i++)//yedek yapısının sonuna kadar dönülüyor
        printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].numara);//okunan veriler ekrana yazılıyor
    fclose(dosya);//dosya kapatılıyor
}//listele fonksiyonu sonu
void ara_bul(){//arabul fonksiyonu
    char kelime[150];//kelima adında char tipinde bir değişken tanımlanıyor
    printf("Aranacak Kelimeyi girin");//kullanıcıdan aranacak veri isteniyor
    scanf("%s",&kelime);//girilen veri kelime değişkenine aktarılıyor
    FILE *dosya;//file tipinde bir dosya adında bir pointer tanımlanıyor
    dosya=fopen("a.txt","r");//dosya önceki verileri okumak için açılıyor
    int a=0,i;//değişkenler tanımlanıyor döngüler için
    while(!feof(dosya)){//dosya sonuna kadar dön
        fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].numara);//dosyadan veriler okunup yedek yapısına aktarılıyor
        a++;     //while için a 1 arttırılıyor
    }//dosya sonuna kadar dön sonu
    for(i=0;i<(a-1);i++){//yedek yapısının sonuna kadar dönülüyor
        if(strcmp(kelime,yedek[i].isim)==0)
        {//eğer aranan kelime yedek yapısının ismine eşit ise aşağıdakileri yap
            printf("%d\t%s\t%s\t%d\t%d\n",i+1,yedek[i].isim,yedek[i].bolum,yedek[i].numara);//veriler ekrana yadırılıyor
        }//eğer aranan kelime yedek yapısının ismine eşit ise aşağıdakileri yap sonu
    }//yedek yapısının sonuna kadar dönülüyorsonu
    fclose(dosya);//dosya kapatılıyor
}//arabul fonksiyonu sonu
void bul_degistir(){//bul değişrtir fonksiyonu
    char kelime[150];
    printf("Degisecek Kisiyi girin");//degisecek kisi kulanıcıdan alınıyor
    scanf("%s",&kelime);//kullanıcının girdiği veri kelime değişkenine atanıyor
    FILE *dosya;//file tipinde bir dosya pointerı tanımlanıyor
    dosya=fopen("a.txt","r");//a.txt dosyası sadece okunmak için yazılıyor
    int a=0,i;//kullanılacak değişkenler tanımlanıyor
    while(!feof(dosya)){//dosya sonuna kadar dönülüyor başlangıç
        fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].numara);//dosyadan alınan veriler yedek yapısına aktarılıyor
        a++;     //yedek değişkenini her seferinde farklı gelmesi için a her seferinde arttırılıyor
    }//dosya sonuna kadar dönülüyor sonu
    for(i=0;i<(a-1);i++){//yedek yapısına alınan verilerin işleme sokulması
        if(strcmp(kelime,yedek[i].isim)==0)//eğer değişecek kelime yedek yapısının ismine eşit ise aşağıdakileri yap
        {
            printf("%dninci kişinin adini giriniz",i+1);//kullanıcıdan yeni isim isteniyor
            scanf("%s",yedek[i].isim);//isim yedek yapısının değişecek kısmına atanıyor
            fflush(stdin);//değişkene aktarıldıktan sonra o kısım boşaltılıyor
            printf("%dninci kişinin bölümünü giriniz",i+1);//kullanıcıdan yeni bölüm isteniyor
            scanf("%s",yedek[i].bolum);//bölüm yedek yapısının değişecek kısmına atanıyor
            fflush(stdin);//değişkene aktarıldıktan sonra o kısım boşaltılıyor
            printf("%dninci kişinin numarasini giriniz",i+1);//kullanıcıdan yeni final isteniyor
            scanf("%d",&yedek[i].numara);//final yedek yapısının değişecek kısmına atanıyor
            fflush(stdin);//değişkene aktarıldıktan sonra o kısım boşaltılıyor

        }
    }//yedek yapısına alınan verilerin işleme sokulması sonu
    fclose(dosya);//dosya sadece okunmak için açılan dosya kapatılıyor

//şimdi bu kısımda değiştirilen yedek yapısını a.txtnin üzerine yazarak bul değiştir örneğimizi bitireceğiz
    FILE *dosya2;//file tipinde bir dosya2 pointerı tanımlanıyor
    dosya2=fopen("a.txt","w");//a.txt dosyası önceki veriler silinecek şekilde açılıyor
    int i2;//integer tipinde for döngüsü için i2 değişkeni oluşturuluyor
    for(i2=0;i2<(a-1);i2++){//yine yedek değişkeninin sonuna kadar dönülüyor
        fprintf(dosya2,"%s\t%s\t%d\t%d\n",yedek[i2].isim,yedek[i2].bolum,yedek[i2].numara);
    }//yedek değişkeninin sonuna kadar dönme sonu
    fclose(dosya2);//açılan dosya kapatılıyor
}//bul değiştir fonksiyonu sonu


/*void kayit_sil(){//kayit sil fonksiyonu
    char kelime[150];
    printf("Silinecek Kişiyi girin");//silinecek kişi kulanıcıdan alınıyor
    scanf("%s",&kelime);//kullanıcının girdiği veri kelime değişkenine atanıyor
    FILE *dosya;//file tipinde bir dosya pointerı tanımlanıyor
    dosya=fopen("a.txt","r");//a.txt dosyası sadece okunmak için yazılıyor
    int a=0,i=0,kacinci;//kullanılacak değişkenler tanımlanıyor
    while(!feof(dosya)){//dosya sonuna kadar dönülüyor başlangıç
        fscanf(dosya,"%s%s%d%d",yedek[a].isim,yedek[a].bolum,&yedek[a].numara);//dosyadan alınan veriler yedek yapısına aktarılıyor
        a++;     //yedek değişkenini her seferinde farklı gelmesi için a her seferinde arttırılıyor
    }//dosya sonuna kadar dönülüyor sonu

    for(i=0;i<(a-1);i++){//yedek yapısına alınan verilerin işleme sokulması
        if(strcmp(kelime,yedek[i].isim)==0)//eğer silinmesi gereken kişi adı yedek yapısının ismine eşit ise aşağıdakileri yap
        {       
            kacinci=i;//aranan verinin kaçıncı olduğu bulunuyor
        }//eğer silinmesi gereken kişi adı yedek yapısının ismine eşit ise aşağıdakileri yapsonu

    }//yedek yapısına alınan verilerin işleme sokulması sonu
    for(i=0;i<(kacinci);i++){//verinin bulunduğu yere kadar dön
        strcpy(silinecek[i].isim,yedek[i].isim);
        //kacıncıya kadar olan kısımlar silinen yapısına aktarılıyor
        strcpy(silinecek[i].bolum,yedek[i].bolum);
        //kacıncıya kadar olan kısımlar silinen yapısına aktarılıyor
        silinecek[i].numara=yedek[i].numara;
        //kacıncıya kadar olan kısımlar silinen yapısına aktarılıyor
    }
    //verinin bulunduğu yere kadar dön sonu
    for(i=(kacinci+1);i<=(a-1);i++){//silinen veriden sonrakini silinecek kısmına ata
        strcpy(silinecek[i-1].isim,yedek[i].isim);//kacıncıdan sonra olan kısımlar silinen yapısına aktarılıyor
        strcpy(silinecek[i-1].bolum,yedek[i].bolum);//kacıncıdan sonra  olan kısımlar silinen yapısına aktarılıyor
        silinecek[i-1].numara=yedek[i].numara;//kacıncıdan sonra  olan kısımlar silinen yapısına aktarılıyor
    }//silinen veriden sonrakini silinecek kısmına ata sonu


    fclose(dosya);//dosya sadece okunmak için açılan dosya kapatılıyor

    //şimdi bu kısımda değiştirilen yedek yapısını a.txtnin üzerine yazarak bul değiştir örneğimizi bitireceğiz
    FILE *dosya2;//file tipinde bir dosya2 pointerı tanımlanıyor
    dosya2=fopen("a.txt","w");//a.txt dosyası önceki veriler silinecek şekilde açılıyor
    int i2;//integer tipinde for döngüsü için i2 değişkeni oluşturuluyor
    for(i2=0;i2<(a-1);i2++){//yine silinecek değişkeninin sonuna kadar dönülüyor
        fprintf(dosya2,"%s\t%s\t%d\t%d\n",silinecek[i2].isim,silinecek[i2].bolum,silinecek[i2].numara);
    }//silinecek değişkeninin sonuna kadar dönme sonu 
    fclose(dosya2); //açılan dosya kapatılıyor

}*/ //kayitsil fonksiyonu sonu 