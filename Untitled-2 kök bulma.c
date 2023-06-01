#include <stdio.h>//standart kütüphanelerimizi ekliyoruz.
#include <conio.h>
int main (void)//ana fonksiyonumuzu başlattık.
{
int a,b,c,d,e,f,g,h,i;//değerlerimizi programa tanıtıyoruz.
printf(" Kok bulma \n");
printf("x karenin katsayisini giriniz...=");//2. dereceden denklemde x kare ifadesinin katsayısını giriyoruz. 
scanf("%d",&a);
printf("x in katsayisini giriniz...=");//2. dereceden denklemde x ifadesinin katsayısını giriyoruz. 
scanf("%d",&b);
printf("sabit sayıyı giriniz...=");//2. dereceden denklemde sabit sayı ifadesinin katsayısını giriyoruz. 
scanf("%d",&c); 
d=b*b-4*a*c;//burada matematiksel işlemler yapılıyor ve delta değeri bulunuyor. 
e=-b-d^1/2;
g=-b+d^1/2;
f=e/2*a;
h=g/2*a;
if(d<0)
{
printf("Delta sifirdan kucuk oldugu icin kok bulanmaz.");//eğer delta değeri sıfırdan küçük çıkarsa kök bulunmaz.
}
else{
printf("x1=%d,x2=%d",f,h);//cevabımız bu şekilde olacaktır.
}
getch();
return(0);
}