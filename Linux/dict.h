
#ifndef DICT_H
#define DICT_H
// headerfiles used
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

//Defining structure
typedef struct _word
{
    struct _word *ch1[26];
    bool value;
    char meaning[200];
}
word1;

// function to load dictionary
bool load_dict();

//function which will print meaning
void meaning(char*);

// whether word exist or not in the dictionary
bool exist(char*);

// function tp unload dictionary
bool unload(void);

//function to add new word
bool addword();


#endif
