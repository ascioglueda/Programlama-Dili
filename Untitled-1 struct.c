#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct kitap{
	char kitapadi[50];
	char yazar[50];
	int kitap_id;	
}kitap;

int main()
{
	kitap roman1;
	memcpy(roman1.kitapadi,"�al�ku�u",50);
	memcpy(roman1.yazar,"�mer seyfettin",50);
	roman1.kitap_id=100;
	printf("Kitap ad�: %s\n", roman1.kitapadi);
	printf("Yazar: %s\n", roman1.yazar);
	printf("Kitap id: %d\n", roman1.kitap_id);
	return 0;
}

