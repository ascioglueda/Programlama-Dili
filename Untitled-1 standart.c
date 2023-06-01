#include <conio.h>
#include <math.h> //Kütüphanelerimizi giriyoruz.
 
float hesapla(float sayi[]);
 
int main() //Ana fonksiyonumuzu açtık.
{
int i;
float sayi[10]; //Dışarıdan 10 sayı gireceğimiz için böyle yazdık.Siz bu değeri değiştirebilirsiniz.
printf("10 tane sayi giriniz : ");
for(i=0; i < 10; i++){ //For döngüsüyle sayılarımızın tek seferde toplu girişini yapıyoruz.
scanf("%f", &sayi[i]);}
printf("\nStandart Sapma = %.6f", hesapla(sayi)); //Burada ise standart sapma hesabını yapmak için ana fonksiyonumuzu yardımcı hesapla fonksiyonuna gönderiyoruz.
getch ();
return 0;
}
 
float hesapla(float sayi[]) //Yardımcı hesaplama fonksiyonumuzu açıyoruz.
{
float toplam = 0.0, orta, standartsapma = 0.0;
int i;
for(i=0; i<10; i++)
{
toplam = toplam + sayi[i];
}
orta = toplam/10;
for(i=0; i<10; i++){
standartsapma = standartsapma + pow(sayi[i] - orta, 2);} //Bu kısımda hesabını yapıyoruz üstteki linkte paylaştığımız yazıya giderek standart sapma nasıl hesaplanır tam şekilde öğrenebilirsiniz.
return sqrt(standartsapma/10); //Burada fonksiyonumuz standartsapma bölü 10'un karekökü şeklinde geri dönüyor.Ardından hesaplama işlemi bitince tekrar ana fonksiyonumuza dönüş yapacak.
}
//sqrt karekök alma komutu