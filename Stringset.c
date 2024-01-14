#include "Stringset.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void freeCharArray(char* charArray)
{
    if (charArray != NULL)
    {
        free(charArray);
        charArray = NULL;  
    }
}
void Init(Stringset* stringset, int length)
{
    stringset->capacity = length;
    stringset->numberOfElements = 0;
    
    stringset->charList = (char**)malloc(length * sizeof(char*));
    for(int i = 0; i<length;i++)
    {
        stringset->charList[i] = (char*)malloc(sizeof(char) * MAX_CHAR_LENGTH); //lehet hogy itt a sizeofban a char-t szoroznom kellene, mert igy csak charokat teszek bele?
    }
}

RemoveMapping Contains(char* string, Stringset* stringset){
    RemoveMapping removeMapping;
    removeMapping.foundValue = -1;
    removeMapping.indexOfRemoval = -1;

    int i = -1;
    int cont = -1;
    int n = stringset->numberOfElements;
    while(i < n && cont !=0)
    {
        i++;
        cont = strcmp(string, stringset->charList[i]);
    }
    if(cont == 0){
        removeMapping.foundValue = 0;
        removeMapping.indexOfRemoval = i;
    }

    return removeMapping;
}
int Insert(char* string, Stringset* stringset)
{
    if(stringset->capacity <= stringset->numberOfElements){
        return 1;
    }

    if(Contains(string, stringset).foundValue == 0){
        return 1;
    }

    stringset->numberOfElements++;
    int indexToPaste = stringset->numberOfElements-1;

    strcpy(stringset->charList[indexToPaste], string);

    return 0;
}
int Remove(char* string, Stringset* stringset)
{
    RemoveMapping removeMapping;
    removeMapping = Contains(string, stringset);
    if(removeMapping.foundValue == 0)
    {
        if(removeMapping.indexOfRemoval == stringset->capacity - 1)
        {
            // item in the last position, removal is enough
            memset(stringset->charList[removeMapping.indexOfRemoval], '\0', MAX_CHAR_LENGTH);
        }else
        {
            int lastPosition = stringset->numberOfElements - 1;
            memset(stringset->charList[removeMapping.indexOfRemoval], '\0', MAX_CHAR_LENGTH);
            
            strcpy(stringset->charList[removeMapping.indexOfRemoval], stringset->charList[lastPosition]);

            memset(stringset->charList[lastPosition], '\0', MAX_CHAR_LENGTH);
            stringset->numberOfElements--;
        }

        return 0;
    }

    return 1;
}

void Destroy(Stringset* stringset)
{
    for(int i = 0; i < stringset->capacity; i++)
    {
        free(stringset->charList[i]);
    }
    stringset->capacity = 0;
    stringset->numberOfElements = 0;

}

void DisplayStateDetailed(Stringset* stringset)
{
    printf("********************\n");
    printf("Capacity: %d \n", stringset->capacity);
    printf("Number of elements: %d \n", stringset->numberOfElements);
    for(int i = 0; i<stringset->numberOfElements; i++)
    {
        printf("element %d: %s \n", i, stringset->charList[i]);
    }
    printf("********************\n");
}
int main()
{
    Stringset stringset;

    char alma[MAX_CHAR_LENGTH] = "alma";
    char korte[MAX_CHAR_LENGTH] = "korte";
    char szilva[MAX_CHAR_LENGTH] = "szilva";
    char banan[MAX_CHAR_LENGTH] = "banan";
    Init(&stringset, 4);
    Insert(alma,&stringset);
    Insert(korte,&stringset);
    Insert(szilva,&stringset);
    Insert(banan,&stringset);
    DisplayStateDetailed(&stringset);
    
    Remove(korte, &stringset);
    DisplayStateDetailed(&stringset);
    
    Destroy(&stringset);
    DisplayStateDetailed(&stringset);
    return 0;
}
