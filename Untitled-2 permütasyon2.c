#include<stdio.h>
#include<conio.h>
float faktoriyel(int);
float faktoriyel (int k)
{
int i,f=1;
for(i=2 ;i<=k ; i++)
f = f*i;
return(f);
}
int main()
{
int n,r;
float per;
printf("n degerini giriniz : ");
scanf("%d",&n);
printf("r degerini giriniz : ");
scanf("%d",&r);
per = faktoriyel(n)/ faktoriyel(n-r);
printf("Permutasyon sonucu : %f ",per );
getch();
return 0;
}