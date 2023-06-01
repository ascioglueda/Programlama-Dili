#include <stdio.h>
 
int faktoriyel(int);
 

int faktoriyel(int x) {
    if (x <= 1)
        return 1;
    return x * faktoriyel(x - 1);
}
int main() {
    int sayi;
    printf("faktoriyelini hesaplamak istediginiz sayiyi giriniz--->");
    scanf("%d",&sayi);
    int sonuc = faktoriyel(sayi);
    printf("%d! = %d\n", sayi, sonuc);
    return 0;
}
 