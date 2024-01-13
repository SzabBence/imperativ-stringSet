#include "Stringset.h"
#include<stdio.h>
#include<string.h>

void Init(Stringset* stringset, int length)
{
    stringset->capacity = length;
    stringset->numberOfElements = 0;
    
    stringset->charList = (char**)malloc(length * sizeof(char*));
    for(int i = 0; i<length;i++){
        stringset->charList[i] = (char*)malloc(sizeof(char)); //lehet hogy itt a sizeofban a char-t szoroznom kellene, mert igy csak charokat teszek bele?
    }
}

int Contains(char* string, Stringset* stringset){
    int i = 0;
    int cont = 0;
    int n = stringset->numberOfElements;
    while(i < n && cont !=0)
    {
        cont = strcmp(string, stringset->charList[i]);

        i++;
    }

    return cont;
}
int Insert(char* string, Stringset* stringset)
{
    if(stringset->capacity =< stringset->numberOfElements){
        return 1;
    }

    if(Contains(string, stringset) == 0){
        return 1;
    }
    int indexToPaste = stringset->numberOfElements - 1;

    strcpy(stringset->charList[indexToPaste], string);

    return 0;
}
int main()
{
    Stringset stringset;

    return 0;
}
