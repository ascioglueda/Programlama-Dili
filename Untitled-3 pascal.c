#include <stdio.h>
int main() {
   int satirlar,orta = 1, bosluk, i, j;
   printf("Satir sayisini girin: ");
   scanf("%d", &satirlar);
   for (i = 0; i < satirlar; i++) {
      for (bosluk= 1; bosluk<=satirlar - i; bosluk++)
         printf("  ");
      for (j = 0; j <= i; j++) {
         if (j == 0 || i == 0)
            orta = 1;
         else
            orta = orta * (i - j + 1) / j;
         printf("%4d", orta);
      }
      printf("\n");
   }
   return 0;
}