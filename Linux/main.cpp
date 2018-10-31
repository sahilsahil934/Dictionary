
using namespace std;

#include "dict.h"

int main()
{

	// Loading words in the dictionary

    load_dict();
   	cout<<"\n\n\n\n\n \t\t\t\t\t\t***********************************************Loading Complete**************************************";

    char word[30];
    char ch1 = 'y';
    int ch;
	do
	{
	// 	sleep(3);
		system("clear");
		// Main menu
		cout<<"\n\n\n\t\t\t			************************************************Dictionary*****************************************\n";
		cout<<"\n\t\t\t\t           							1. Search Meaning\n";
		cout<<"\n\t\t\t\t          							2. Add word in dictionary\n";
		cout<<"\n\t\t\t\t           							3. Exit\n";
		cout<<"\n\t\t\t\t\t           							Enter choice : ";

		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					system("clear");
					cout<<"\n\n\n\n\n\t\t\t			************************************************Dictionary*****************************************\n";
					cout<<"\n\n\n\n\n\t\t\t           							Enter word : ";
    				cin>>word;
					if (exist(word) == false)
    				{
    		  			cout<<"\n\n\n\n\n\t\t\t\t 			Sorry! Word is not availble in the dictionary!";
    		  			cout<<"\n\t\t\t\t\t\t\t Press any key. And help us by adding this word in the dictionay";
								cin.ignore().get();

    				}
    				else
    				{
    					cout<<"\n\t\t\t\t           							Press any key : ";

    		  			cout<<"\n\t\t\t\t           							word exist";
    				}
    				break;
    			}
    		case 2:
    			{
	    			bool val = addword();
    				if (val == true)
    				{
    					load_dict();
    				}
    				else
    				{
    					cout<<"\n           							Word already exist\n";
							cin.ignore().get();

						}
						break;
					}
    		case 3:
    			{
    				exit(0);
    			}
    		default:
    			cout<<"\n           							Wrong Input";
		}
	}
    while (ch1 == 'y' || ch1 == 'Y');
    unload();
}
