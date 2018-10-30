
using namespace std;

#include "dict.h"

word1 *root = NULL;
int count = 0;

word1* newnode()
{
	
    word1 *node = new word1;
    if (node == NULL)
    {
        unload();
        return NULL;
    }
    node->value = false;

    //initializing each pointer to NULL
    for (int i = 0; i < 26; i++)
    {
        node->ch1[i] = NULL;
    }

    return node;
}

void del(word1 *rem)
{
    for (int i = 0; i < 26; i++)
    {
        if (rem->ch1[i] != NULL)
        {
            del(rem->ch1[i]);
        }
    }
    delete rem;
}

bool load_dict()
{
	cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t ********************************************Loading word in Dictionary**********************************************";
    int num;
    word1 *create;
    root = newnode();
    create = root;
    fstream f;
    f.open("read.txt", ios::in);
    if (!f)
    {
        return false;
    }
    while(!f.eof())
    {
        //reading single charcter from file
        char ch;
        f.get(ch);

        if (ch == '-')
        {
          goto abc;
        }

        if (isalpha(ch))
        {
            num = ch - 97;
            if (create->ch1[num] == NULL)
            {
                create->ch1[num] = newnode();
            }
            create = create->ch1[num];
            continue;

        }
        abc:
          int i = 0;
          while (ch != '\n')
          {
            f.get(ch);
            create->meaning[i] = ch;
            i++;
          }

        if (ch == '\n')
        {
            create->value = true;
            create = root;
            //counting number of words
            count++;
        }

    }
    f.close();
	Sleep(500);
   	cout<<"\n         							Total words loaded : "<<count;
    return true;
    return false;
}

void meaning(word1 *get, char *word)
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t           							"<<word<<" - "<<get->meaning;
}

bool exist(char *word)
{
	
    char ch;
    word1* create = root;
    int num;
    //checking words in tries
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        ch = tolower(word[i]);
        if (isalpha(ch))
        {

            num = ch - 97;
        }
        else
        {
            return false;
        }

        if (create->ch1[num] == NULL)
        {
            return false;

        }
        else
        {
            create = create->ch1[num];
        }
    }
    if (create->value == true)
    {
    	meaning(create, word);
	}
    return create->value;
    return false;
}

bool addword()
{
	char ch;
	fstream f;
	f.open("read.txt",ios::app);
	if (!f)
	{
		return false;
	}
	char word[30];
	char meaning[50];
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n           							Enter word : ";
		cin>>word;
		if (exist(word) != false)
		{
			return false;
		}
		cout<<"\n           							Enter meaning : ";
		cin.ignore();
		gets(meaning);
		f<<word;
		f<<"- ";
		f<<meaning;
		f<<"\n";
		cout<<"\n           							Do you want to add another word(Y/N) : ";
		cin>>ch;
	}
	while (ch == 'y' || ch == 'Y');	
	f.close();
	return true;
}

bool unload(void)
{
	cout<<"\n *****************************Dictionary Unloading****************************";
    del(root);
    return true;
    return false;
}

