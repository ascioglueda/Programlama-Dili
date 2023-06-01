#include <stdio.h>
int main (){

    printf("yil giriniz:");
    scanf("%d",&yil);

    if(yil%400==0){
        printf("%d artik yil.",yil);
    }
    else if(yil%100==0){
        printf("%d artik yil degil.",yil);
    }
    else if(yil%4==0){
        printf("%d artik yil.",yil);
    }
    else 
    printf("%d artik yil degil.",yil);
   }


    return 0;
}