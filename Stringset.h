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

RemoveMappingResult Contains(char* string, Stringset* stringset);

void Init(Stringset* stringset, int length);
void Destroy(Stringset* stringset);
int Insert(char* string, Stringset* stringset);
int Remove(char* string, Stringset* stringset);

#endif