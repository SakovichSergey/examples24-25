#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>


struct Elem
{
    int data;
    struct Elem* nextPtr;
}List;
int* createRndMas(int* mas, size_t length);

int main()
{
    printf("Random massiv!\n");
    int *mas = NULL;
    mas = createRndMas(mas,10);
    for(size_t i=0;i<10;i++)
    {
        printf("%d\t",mas[i]);
    }
    printf("\n");
    return 0;
}
int* createRndMas(int* mas, size_t length)
{
    mas = (int*)calloc(sizeof(int),length);
    srand(time(NULL));
    for(size_t i=0;i<length;i++)
    {
        mas[i]=rand()%99+1;//1..99
    }
    return mas;
}
