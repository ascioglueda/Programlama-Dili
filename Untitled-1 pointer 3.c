#include <stdio.h>
#include <stdlib.h>
int main(){
int sayi=12,*sayininAdresi;
float kesirlisayi=5.7,*kesirlisayininAdresi;
double buyukKesirlisayi=7.8,*buyukKesirlisayininAdresi;
char karakter='K',*karakterinAdresi;
   
   printf("%d\n,sayi");
   printf("%f\n,kesirlisayi");
   printf("%lf\n,buyukKesirlisayi");
   printf("%c\n,karakter");

   printf("%d %x\n",*sayininAdresi , sayininAdresi);
   printf("%f %x\n",*kesirlisayininAdresi , kesirlisayininAdresi);
   printf("%lf %x\n",*buyukKesirlisayininAdresi, buyukKesirlisayininAdresi);
   printf("%c %x\n", * karakterinAdresi,karakterinAdresi);
return 0;
}