#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//---- BUBBLE SORT ALGORITMASI ----(kabarcık sıralama)//
void bubble(int array[],int size) //fonksiyonu tanımlıyoruz
{
    int i,j,temp;
    for(i=1;i<size;i++)
    {
        for(j=0;j<size-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }   
        }       
    }
   
   
    for(i=0;i<size;i++)
        printf("%d ",array[i]);
}


//---- SELECTION SORT ALGORITMASI ----(Seçmeli)//
void selection(int array[],int size)//fonksiyonu tanımlıyoruz
{
{
    int i,j,temp,min;
   
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size;j++)
        {       
            if(array[j]<array[min])
                min=j;
        }   
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }
   
    for(i=0;i<size;i++)
        printf("%d ",array[i]);   
}

//---- INSERTION SORT ALGORITMASI ----(Eklemeli)//
void insertion(int array[],int size)//fonksiyonu tanımlıyoruz
{
{
   
    int i,j,temp;
   
    for(i=0;i<size;i++)
    {
        for(j=0;j<i+1;j++)
        {
            if(array[j]>array[i])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }       
    }
   
    for(i=0;i<size;i++)
        printf("%d ",array[i]);   
}



int main(int argc, char *argv[]) {
    int dizi[]={9,4,6,2,8,1}; //dizideki sayıları tanımlıyoruz.
   
    bubble(dizi,6);//kabarcık sıralama
    puts("");
    selection(dizi,6);//seçme
    puts("");
    insertion(dizi,6);//ekleme
    getch();
    return 0;
}
