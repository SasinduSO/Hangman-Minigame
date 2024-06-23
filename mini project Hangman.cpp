#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
/*
	Team Members:
*	IM/2020/065 - Sasindu Obeysekere.
*	IM/2020/077 - Pubudini Jayasekara.
*	IM/2020/094 - Oshadhi Rathnayake.
*	IM/2020/095 - Dilini Tharaka.

*/

//functions

void welcomeScreen();
void runMenu();
void Guess( string stg);
string randword();


int main()
{

	srand(time(NULL));
//	system.("CLS"); //clear the screen 
	
	//Start game
	
	runMenu();
	cout << "\tDo you wish to return to main menu?"<<endl;
	cout << "\t~press y for yes and any key for no..~" ;
	char ch;
	cin >> ch;

	
	if (ch == 'y')  //looping to use program as often as they want
	{
	system("CLS");
	main();
	}
	return 0;
}
	
	
void welcomeScreen()
{
	
	cout<<endl;
	
	cout<< "\t()    ()    ()()     ()    ()    ()))))     ()      ()    ()()     ()    ()"<<endl;
	cout<< "\t()    ()   ()  ()    ()))  ()   ()    ()    ()))  ((()   ()  ()    ()))  ()"<<endl;
	cout<< "\t()(())()  ()(())()   () () ()   ()          () (()) ()  ()(())()   () () ()"<<endl;
	cout<< "\t()    ()  ()    ()   ()  ((()   ()  ((((    ()  ()  ()  ()    ()   ()  ((()"<<endl;
	cout<< "\t()    ()  ()    ()   ()    ()    ()))))     ()      ()  ()    ()   ()    ()"<<endl;
	
		cout<<"\n\n";
	int count = 0;
	cout<<"\t";
	while (count <= 100) {

		cout << "~";
		count++; //increasing count.. count=count+1
	};
	cout << endl;

	//make count 0 to run again

	cout << endl;
	//end of heading and start of menu
	cout << "\t[1] Play Hangman " << endl;
	cout << "\t[2] Display About information" << endl;
	cout << "\t[3] Display creator information" << endl;
	cout << "\t[4] Quit" << endl;


	//end of menu
	cout<<"\t";
	count = 0;
	while (count <= 100) {

		cout << "~";
		count++; //increasing count.. count=count+1
	};
	
}


void runMenu() {
	//creating a heading
	welcomeScreen();

	cout << endl;
	cout << "\twhich option would you like (1-4) : " ;

	int opt; //declaring user option
	cin >> opt;
	
	//validating user input

	if (opt > 0 and opt < 5)
	{
		switch (opt)
		{
		default:cout << "\tYou have selected :" << opt << endl;
			break;
		case 1:
			{
			cout<<endl;
			system("CLS");
			 Guess( randword() );
			 
			}
			break;
		case 2: {
			cout<<endl;
			system("CLS");
			string words;
			ifstream displayrule;
			displayrule.open("public.txt");
			if (displayrule.is_open()) //checking if text file is open
			{
				getline(displayrule, words); //assigning first line of displayrule to words
				while (displayrule)
				{
					cout << words << endl;
					getline(displayrule, words);  //looping until all the lines have been displayed
				}

				displayrule.close(); //closing file
			}
				}
			break;
		case 3:{
				cout<<endl;
				system("CLS");
				cout << "\tCreators of the game"<<endl;
				cout << "--------------------"<<endl;
				cout << "\n\t";
				cout << "\tIM/2020/065 - Sasindu Obeyesekere" <<endl;
				cout << "\tIM/2020/077 - Pubudini Jayasekara" <<endl;
				cout << "\tIM/2020/094 - Oshadhi Rathnayaka" <<endl;
				cout << "\tIM/2020/095 - Dilini Tharaka" <<endl;
				cout << "\n\t";
				cout << "\n\t";

			break;
		}
			
		case 4: {
			cout<<endl;
			system("CLS");
			cout << "\tYOU ARE NOW QUITTING HANGMAN" <<endl;
			break;
		}
	
		}
	}
	else
	{
		cout << "\tinvalid option" << endl;
	}

		//end running programs

}


	
string randword()
{
	string word;
	string wordlist[99];
	ifstream Randword; // reads in variable
	
	string file[3]={"objects.txt","animals.txt","countries.txt"};
	
	int filenum =rand()% 3;
	switch(filenum)
	{
		case 0: 
		{
			cout<<endl;
			cout << "\tHint : This is an Object ;) "<<endl;
			break;
		}
		case 1: 
		{
			cout<<endl;
			cout << "\tHint : This is an Animal ;) " <<endl;
			break;
		}
		case 3: 
		{
			cout<<endl;
			cout << "\tHint : This is a Country ;) "<<endl;
			break;
		}
		
	}
	
	Randword.open(file[filenum].c_str());	//opens list of words file
	
		
		for(int i=0; i<99; i++)
		{
			Randword >> wordlist[i];
		
		}
		
		int RandNum =rand()% 10;
		word = wordlist[RandNum];
		Randword.close();
		return word;
	
 		cout<<"\tHint: no. of words are " <<word.size() <<endl; //printing out * (hidden word)		
}



void Guess( string stg)
{
	string word = stg;
	cout<< "\t" ;
	string hiddenword(word.length(), '*') ;
	
	vector <int> Tries(6); //The number of attempts to guess correctly
	char Guess;
	bool CorrectGuess =false;
	char PreviousGuess [7];
	PreviousGuess[0] = '\0';
	for (int i=1; i<6; i++ )
	{
		PreviousGuess[i] = '-';
	}
		PreviousGuess[6] = '\0'; 
	
	while(Tries.size()>=0){
		
		//reset bool
		CorrectGuess = false;
		
		//Dispaly information related to the word for the player
		
		cout<< "\n\tThe word you have is :\n\n";
		cout << "\t"<<hiddenword << endl;
		if (Tries.size()==0)
		{
			cout<<"\t" <<word<<endl;
			break;
		}
		else
		{
		
		cout << "\tYou have "<<Tries.size() <<" guesses left\n";
		
		}
		if(PreviousGuess[0]=='\0')
		{
			cout  << endl;
		}
		else{
			cout << "\tYou have guessed: "<< PreviousGuess <<endl;
		}
		
		//get player guess
		
		cout << "\n\tGuess a letter : ";
		cin>> Guess;
		
		//Check is guess correct?
		
		for (int i= 0; i < hiddenword.length(); i++ )// for the length of the word (using mystery) do the following:
		{
			if (word[i]== Guess)// check does the word (actual) have guess in it
			{
				hiddenword[i]= Guess;
				CorrectGuess = true;
					
			}
		}
		
		if (word == hiddenword)
		{
			cout  << "\n\n\n\tCongratulations! You've got the word correct" << hiddenword<<endl;
			break;	
		}
		
		if (CorrectGuess == false)
		{
			Tries.resize(Tries.size()-1);
			cout<<"\n\n\n\tSorry! " << Guess << " is not part of the word " << endl;
		}
		else 
		{
			cout << "\n\n\n\tCongratulations!" << Guess << "is one of the letters!" << endl;
		}
		
		switch (Tries.size())
		{
		
		case 6:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____ "<< endl;
				cout <<"\t|            }   " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|______" <<endl;	
				cout <<"\t\n\n\n\n\n"<<endl;
				break;
			}
		
		case 5:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____ "<< endl;
				cout <<"\t|            }   " <<endl;
				cout <<"\t|            0   " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|______" <<endl;	
				cout <<"\t\n\n\n\n\n"<<endl;
				if(CorrectGuess==false)
				{
					PreviousGuess[0] = Guess;
				}
				break;	
		}
		
		case 4:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____ "<< endl;
				cout <<"\t|            }   " <<endl;
				cout <<"\t|            0   " <<endl;
				cout <<"\t|            |   " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|______" <<endl;
				cout <<"\t\n\n\n\n\n"<<endl;
				if(CorrectGuess==false)
				{
					PreviousGuess[1] = Guess;
				}	
				break;	
		}
		
		case 3:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____ "<< endl;
				cout <<"\t|            }   " <<endl;
				cout <<"\t|            0   " <<endl;
				cout <<"\t|            |   " <<endl;
				cout <<"\t|          / |   " <<endl;
				cout <<"\t|         /  |   " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|                " <<endl;
				cout <<"\t|______" <<endl;	
				cout <<"\t\n\n\n\n\n"<<endl;
				if(CorrectGuess==false)
				{
					PreviousGuess[2] = Guess;
				}
				break;	
			}
		
		case 2:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____  "<< endl;
				cout <<"\t|            }    " <<endl;
				cout <<"\t|            0    " <<endl;
				cout <<"\t|            |    " <<endl;
				cout <<"\t|          / | \\ " <<endl;
				cout <<"\t|         /  |  \\" <<endl;
				cout <<"\t|                 " <<endl;
				cout <<"\t|                 " <<endl;
				cout <<"\t|                 " <<endl;
				cout <<"\t|______ " <<endl;	
				cout <<"\t\n\n\n\n\n"<<endl;
				if(CorrectGuess==false)
				{
					PreviousGuess[3] = Guess;
				}
				break;	
		}
		
		case 1:
		{
			cout<<endl;
			system("CLS");
			cout << "\t_____   "<< endl;
			cout <<"\t|            }     " <<endl;
			cout <<"\t|            0     " <<endl;
			cout <<"\t|            |     " <<endl;
			cout <<"\t|          / | \\  " <<endl;
			cout <<"\t|         /  |  \\ " <<endl;
			cout <<"\t|           /      " <<endl;
			cout <<"\t|          /       " <<endl;
			cout <<"\t|                  " <<endl;
			cout <<"\t|_____  _" <<endl;	
			cout <<"\t\n\n\n\n\n"<<endl;
			if(CorrectGuess==false)
			{
				PreviousGuess[4] = Guess;
			}
			break;	
		}
		
		case 0:
			{
				cout<<endl;
				system("CLS");
				cout << "\t_____   "<< endl;
				cout <<"\t|            }     " <<endl;
				cout <<"\t|            0     " <<endl;
				cout <<"\t|            |     " <<endl;
				cout <<"\t|          / | \\  " <<endl;
				cout <<"\t|         /  |  \\ " <<endl;
				cout <<"\t|           / \\   " <<endl;
				cout <<"\t|          /   \\  " <<endl;
				cout <<"\t|                  " <<endl;
				cout <<"\t|______  " <<endl;	
				cout <<"\t\n\n\n\n\n"<<endl;
				cout <<"\n\t\t\tGAME OVER!!!" << endl;
				
				break;	
			}
		default:
				cout << "\t\tIf you are seeing this line, then there is an error.";
				
		}	
	
	} 
}

