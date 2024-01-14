#ifndef STRINGSET_H
#define STRINGSET_H

#define MAX_CHAR_LENGTH 50

typedef struct
{
    char **charList;
    int numberOfElements;
    int capacity;

} Stringset;

typedef struct RemoveMappingResult
{
    int indexOfRemoval;
    int foundValue;
} RemoveMappingResult ;

void Init(Stringset* stringset, int length);

int Insert(char* string, Stringset* stringset);
RemoveMappingResult Contains(char* string, Stringset* stringset);
int Remove(char* string, Stringset* stringset);

void Destroy(Stringset* stringset);

#endif