#ifndef STRINGSET_H
#define STRINGSET_H

typedef struct
{
    char **charList;
    int numberOfElements;
    int capacity;

} Stringset;

void Init(Stringset* stringset, int length);

int Insert(char* string, Stringset* stringset);
int Contains(char* string, Stringset* stringset);
int Remove(char* string, Stringset* stringset);

void Destroy(Stringset* stringset);

#endif