#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
FILE *dosya,*yedek; // foknsiyonlarda dosya islemleri yapılacağından global tanımladım
struct ogrenci{
 char ad[10];
 int no, Not;
 };
struct ogrenci kisi;
void kayitGirisi(void); 
void kayitListele(void);
void kayitSilme(void);

void kayitArama(void);
void kayitDegistirme(void);
int main(){
do{ 
system("cls");
printf("\t\tMENU \n1- Kayit Girisi\n2- Kayit Listeleme \n3- Kayit Silme \n4- Kayit Arama \n5- Degistirme \n6- Cikis \n\nLutfen islemi seciniz:");
switch(getch()){
 case '1':{ // Kayit Girişi
 system("cls");
 kayitGirisi();
  break;
 }
 case '2':{ // Kayit Listeleme
 system("cls");
 kayitListele();
  break;
 }
 case '3':{ // Kayit Silme
 system("cls");
 kayitSilme();
  break;
 }
 case '4':{ // Kayit Arama
 system("cls");
 kayitArama();
  break;
 }
 case '5':{ // Degistirme
 system("cls");
 kayitDegistirme();
  break;
 }
 case '6':{ // Cikis
    return 0;
  break;
 }
 default:{
  printf("Hatali Giris");
 }
}
}while(1);
 getch();
 return 0;
}

void kayitGirisi(void){
 int i=0;
 dosya=fopen("sinif.txt","a+"); // w ile yazdırma islemi yapıyoruz.
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nOgrenci bilgilerini girin: ");
 do{ // Önce bellege yazdırıyoruz.
  i++;
  fflush(stdin);
  printf("%d. Ogrencinin Adi : ",i);
  gets(kisi.ad);
  printf("%d. Ogrencinin Numarasi : ",i);
  scanf("%d",&kisi.no);
  printf("%d. Ogrencinin Notu : ",i);
  scanf("%d",&kisi.Not);
  printf("\n");
  // Sonra dosyaya yazdırıyoruz.
  fprintf(dosya,"%s %d %d\n",kisi.ad,kisi.no,kisi.Not);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(dosya);
 puts("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
}

void kayitListele(void){
 dosya = fopen("sinif.txt","r"); // r ile okuma islemi yapıyoruz.
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);
 }
 while(!feof(dosya)){ // !feof dosyanın sonuna geldiğinde döngüden çıkmak için
  fflush(stdout);
  fscanf(dosya,"%s %d %d\n",kisi.ad,&kisi.no,&kisi.Not); // Önceden dosyaya yazdırdıklarımızı şimdi belleğe yazdırıyoruz
   if(kisi.ad != NULL){ // Yukarıda isim okunabilmiş ise ekrana yazdırmak için
    printf("\n%s %d %d",kisi.ad,kisi.no,kisi.Not);
   }
 }
 fclose(dosya);
 puts("\nBilgiler listelendi devam etmek icin bir tusa basin ...");
 getch();
}

void kayitSilme(void){
 int numara,durum=0;// durum 1 olduğunda kayit silinmis demektir
 printf("\nSilinecek ogrencinin numarasini giriniz : ");
 scanf("%d",&numara);
 dosya = fopen("sinif.txt","r");// sinif dosyasından sadece okuma yapilacak bu yüzden r kullanıyoruz.
 yedek = fopen("yedek.txt","w");// yedek dosyasına yazma islemi yapacağız.
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %d %d\n",kisi.ad,&kisi.no,&kisi.Not); // dosyayı okuyoruz ve degerleri belleğe yazıyoruz
    if(numara != kisi.no){ // Eğer girilen numara dosyada okunan değere eşit değilse if döngüsüne girer.
     fprintf(yedek,"%s %d %d\n",kisi.ad,kisi.no,kisi.Not);
     /* Okunan değer yedek dosyasına yazılır*/
    }
    else durum=1; // Numara okunan değere eşitse , okunan o değer yedek dosyasına yazılmaz böylece o değer silinmiş olur
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){// durum=1 ise okunan değer silinmiş demektir o halde sinif.txt dosyasını sileriz yedek.txt adını sinif.txt olarak değiştiririz
  remove("sinif.txt"); //silmek icin
  rename("yedek.txt","sinif.txt"); // isim değişikliği için
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
 } 
 else{ // durum=1 değilse okunan değer silinmemiştir, daha doğrusu girilen numara dosyada bulunmamaktadır
  remove("yedek.txt"); // yedek dosyasını kullanamadıgımızdan siliyoruz
  printf(" %d numarasinda bir ogrenci bulunamadi devam etmek icin bir tusa basin ...",numara);
 }
 fflush(stdin);
 getch();
}

void kayitArama(void){ // Aslında numara araması yapmak gerekir çünkü iki defa aynı isim girilebilir . Farklı bir örnek olsun diye isim arattırdım.
 char adi[10];
 int durum=0;// durum=0 ise kayit bulunmamaktadirç
 fflush(stdin);
 printf("\nOgrenci adini giriniz: ");
 gets(adi);
 dosya=fopen("sinif.txt","r");// Dosyada bir değişme olmayacak ,okuma olacak bu yüzden r kullanırız.
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){//Dosya sonuna kadar okunur
   fscanf(dosya,"%s %d %d\n",kisi.ad,&kisi.no,&kisi.Not); // Belleğe yazıyoruz
   if(strcmp(kisi.ad,adi) == 0){ // okunan değer girdiğimiz isme eşitse strcmp 0 döndürür
    printf("%s %d %d\n\n Devam etmek icin bir tusa basiniz...",kisi.ad,kisi.no,kisi.Not);
    durum=1;// Aranan isim bulundu.
   }
  }
  fclose(dosya);
  if(durum == 0){ // Aranan değer dosyada yoktur.
   puts("Kayit bulunamadi devam etmek icin bir tusa basiniz...");
  }
 getch();
 
}

void kayitDegistirme(void){
 int numara,durum=0;//durum =0 ise değiştirme işlemi gerçekleşmemiştir.
 printf("\nBilgilerini degistireceginiz ogrencinin numarasini giriniz: ");
 scanf("%d",&numara);
 dosya = fopen("sinif.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %d %d\n",kisi.ad,&kisi.no,&kisi.Not); //Dosyadaki değeri belleğe yazıyoruz.
  if(numara != kisi.no){
   fprintf(yedek,"%s %d %d\n",kisi.ad,kisi.no,kisi.Not);//dosyadan okunup belleğe yazılan değerler yedeğe yazılır.
  }
  else{//Değerler değiştirilir.
   fflush(stdin);
   printf("Ogrencinin Adi : ");
      gets(kisi.ad);
      printf("Ogrencinin Numarasi : ");
      scanf("%d",&kisi.no);
      printf("Ogrencinin Notu : ");
      scanf("%d",&kisi.Not);
      printf("\n");
      fprintf(yedek,"%s %d %d",kisi.ad,kisi.no,kisi.Not); //verileri yedek dosyasına yazdır
      durum=1; // değişme yapıldı.
  }
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){ //değişme islemi yapilirsa
  remove("sinif.txt");
  rename("yedek.txt","sinif.txt");
  puts("Ogrenci bilgileri degistirildi devam etmek icin bir tusa basin...");
 }
 else{
  remove("yedek.txt");
  puts("Ilgili ogenci bulunamadi devam etmek icin bir tusa basin...");
 }
 fflush(stdin);
 getch();
}
