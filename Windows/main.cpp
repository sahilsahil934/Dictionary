#include <iostream>
#include <stdlib.h>

using namespace std;

#include "dict.h"

int main()
{


    load_dict();

    char word[30];
    char ch;
	do
	{
		system("cls");
    	cout<<"\n Enter word : ";
    	cin>>word;

    	if (exist(word) == false)
    	{
    	  cout<<"\n Sorry! Word is not availble in the dictionary!";
    	}

    	else
    	{
    	  cout<<"\n word exist";
    	}
    	
    	
    	cout<<"\n Do you want to search more words : ";
    	cin>>ch;
	}
    while (ch == 'y' || ch == 'Y');
    
    unload();
}

