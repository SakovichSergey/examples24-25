#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>


typedef struct Elem
{
    int data;
    struct Elem* nextPtr;
}List; //Псевдоним для елемента структуры
int* createRndMas(int* mas, size_t length);
void rawListProcess(int* mas, size_t length);
void functionsListProcess(int* mas, size_t length);
int main()
{
    printf("Массив случайных чисел!\n");
    int *mas = NULL;
    mas = createRndMas(mas,10);
    for(size_t i=10;i>0;i--)
    {
        printf("%d\t",mas[i-1]);
    }
    printf("\n");
    rawListProcess(mas,10);
    functionsListProcess(mas,10);
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
void rawListProcess(int* mas, size_t length)
{
    List *head = (List*)malloc(sizeof(List)); //Голова односвязного списка;
    head->data = mas[0];
    head->nextPtr = NULL;
    for(size_t i=1;i<length;i++)
    {
        List *newElem = (List*)malloc(sizeof(List));
        newElem->data = mas[i];
        newElem->nextPtr = head;
        head = newElem;
    }
    do
    {
        printf("%d\t", head->data);
        List *tmpElem = head;
        head = head->nextPtr;
        free(tmpElem);
    }while(head);
    printf("\n");
    free(head);
}
void addValueInList(List **tmp, int number, size_t count);
void printList(List **tmp);
void deleteList(List **tmp);
void functionsListProcess(int* mas, size_t length)
{
    List **head = (List**)malloc(sizeof(List*));
    for(size_t i=0;i<length;i++)
        {
            addValueInList(head,mas[i],i);
        }
    printList(head);
    deleteList(head);
    free(head);
}
void addValueInList(List **tmp, int number, size_t count)
{
    List *newElem = (List*)malloc(sizeof(List));
    newElem->data = number;
    if (count ==0)
        {
            newElem->nextPtr = NULL;
        }
    else
        {
            newElem->nextPtr = (*tmp);
        }
    (*tmp) = newElem;
}
void printList(List **tmp)
{
    if(tmp!=NULL)
    {
        do
            {
                printf("%d\t", (*(*tmp)).data);
                if((*tmp)!=NULL)
                {
                (*tmp) = (*tmp)->nextPtr;
                }
        }while((*tmp)!=NULL);
        printf("\n");
    }
}
void deleteList(List **tmp)
{
    if((*tmp)!=NULL)
    {
        do
        {
            List *tmpElem = (*tmp);
            (*tmp) = (*tmp)->nextPtr;
            free(tmpElem);
        }while((*tmp));
    }
}
