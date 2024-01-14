#include "Stringset.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void Init(Stringset* stringset, int length)
{
    stringset->capacity = length;
    stringset->numberOfElements = 0;
    
    stringset->charList = (char**)malloc(length * sizeof(char*));
}

RemoveMappingResult Contains(char* string, Stringset* stringset){
    RemoveMappingResult removeMapping;
    removeMapping.foundValue = -1;
    removeMapping.indexOfRemoval = -1;

    int i = -1;
    int cont = -1;
    int n = stringset->numberOfElements;
    while(i < n -1 && cont !=0 )
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
        printf("Item '%s' cannot be placed, as capacity(%d) reached.", string, stringset->capacity);
        return 1;
    }

    if(Contains(string, stringset).foundValue == 0){
        printf("Item '%s' is already a member of the set.\n", string);
        return 1;
    }

    stringset->numberOfElements++;
    int indexToPaste = stringset->numberOfElements-1;
    
    stringset->charList[indexToPaste] = (char*)malloc(sizeof(char) * MAX_CHAR_LENGTH); 
    strcpy(stringset->charList[indexToPaste], string);

    return 0;
}
int Remove(char* string, Stringset* stringset)
{
    RemoveMappingResult removeMapping;
    removeMapping = Contains(string, stringset);
    if(removeMapping.foundValue == 0)
    {
        if(removeMapping.indexOfRemoval == stringset->capacity - 1)
        {
            // item in the last position, removal is enough
            memset(stringset->charList[removeMapping.indexOfRemoval], '\0', MAX_CHAR_LENGTH);
            free(stringset->charList[stringset->capacity - 1]);
        }else
        {
            int lastPosition = stringset->numberOfElements - 1;
            memset(stringset->charList[removeMapping.indexOfRemoval], '\0', MAX_CHAR_LENGTH); //drop item 
            
            strcpy(stringset->charList[removeMapping.indexOfRemoval], stringset->charList[lastPosition]); // copy last item to new free position

            memset(stringset->charList[lastPosition], '\0', MAX_CHAR_LENGTH); // empty last position
            free(stringset->charList[lastPosition]);
            
        }
        stringset->numberOfElements--;
        return 0;
    }else{
        printf("Item '%s' not found, therefore cannot remove.\n", string);
    }

    return 1;
}

void Destroy(Stringset* stringset)
{
    for(int i = 0; i < stringset->numberOfElements; i++)
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
    int cap = 5;

    char alma[MAX_CHAR_LENGTH] = "alma";
    char korte[MAX_CHAR_LENGTH] = "korte";
    char szilva[MAX_CHAR_LENGTH] = "szilva";
    char meggy[MAX_CHAR_LENGTH] = "meggy";
    char cseresznye[MAX_CHAR_LENGTH] = "cseresznye";
    char szolo[MAX_CHAR_LENGTH] = "szolo";
    char banan[MAX_CHAR_LENGTH] = "banan";

    Init(&stringset, cap);
    
    Insert(alma,&stringset);
    Insert(korte,&stringset);
    Insert(szilva, &stringset);
    Insert(meggy, &stringset);
    Insert(cseresznye, &stringset);
    DisplayStateDetailed(&stringset);

    Remove(szilva, &stringset);
    DisplayStateDetailed(&stringset);

    Insert(szolo, &stringset);
    DisplayStateDetailed(&stringset);

    Remove(szolo, &stringset);
    DisplayStateDetailed(&stringset);

    Insert(banan, &stringset);
    DisplayStateDetailed(&stringset);

    Destroy(&stringset);
    return 0;
}
