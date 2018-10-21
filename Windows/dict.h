
#ifndef DICT_H
#define DICT_H

#include <iostream>
using namespace std;

typedef struct _word
{
    struct _word *ch1[26];
    bool value;
    char meaning[20];
}
word1;

bool load_dict();

void meaning(char*);

bool exist(char*);

bool unload(void);

#endif

