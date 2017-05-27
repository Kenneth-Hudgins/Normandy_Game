
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "characters.hpp"

using namespace std;

void intro(characters *d);

void story_segment01(characters *d);

characters random_player();


//################################################*************************
//################## BEGIN MAIN ##################*************************
//################################################*************************
int main(){

/*
Thought about how I could just have
the pointer accept the address but after
a few minuets of messing with it I stopped
because the below already works
 */
characters player = random_player();
characters *ptr = &player;

//While loop control
bool done = false;
//Players menu choice
char choice;
//Players miles traveled
int miles_to_pill = 0;
//Players thirst level
int thirst = 0;
//Camels tiredness level
int ammo = 0;
//Amount of drinks left in canteen
int canteen = 3;

//Players health
int health = 100;




random_player();

intro(ptr);

story_segment01(ptr);

	return 0;

}


//################################################***********************
//################## END MAIN ####################***********************
//################################################***********************




//#################################################
//################## INTRO FUNCTION ###############
//#################################################
void intro(characters *d){

//Choice variable only used for this function
char choice = ' ';



	cout << "\n\n\n";
	cout << "                                                              888         " << endl;
	cout << "                                                              888         " << endl;
	cout << "                                                              888         " << endl;
	cout << "     88888b.  .d88b. 888d88888888b.d88b.  8888b. 88888b.  .d88888888  888 " << endl;
	cout << "     888 '88bd88''88b888P'  888 '888 '88b    '88b888 '88bd88' 888888  888 " << endl;
	cout << "     888  888888  888888    888  888  888.d888888888  888888  888888  888 " << endl;
	cout << "     888  888Y88..88P888    888  888  888888  888888  888Y88b 888Y88b 888 " << endl;
	cout << "     888  888 'Y88P' 888    888  888  888'Y888888888  888 'Y88888 'Y88888 " << endl;
	cout << "                                                                      888 " << endl;
	cout << "                                                                 Y8b d88P " << endl;
	cout << "                                                                  'Y88P' \n\n\n " << endl;

//Pause 
cin.get();





									//This can be put in a function,
									//and a few of them might be needed.
									//Input validation
									do{

									cout << "Continue? \n Y / N:" << endl;
									cin >> choice;

									}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
									if (choice == 'n' || choice == 'N'){
										cout << "Program Terminated." << endl;
										exit(0);
									}


//Displays the characters backstory so they have a sense of who
//they are playing as.
		cout << "\n####################################" << endl;
		cout << "#         PLAYER CHARACTER         #" << endl;
		cout << "####################################\n" << endl;
		cout << d->get_backstory() << endl;
		cout << "####################################" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################\n\n\n" << endl;
		
		//Pause
		cin.get();




								//This can be put in a function,
								//and a few of them might be needed.
								 choice = ' ';
								 do{
								cout << "Continue? \n Y / N:" << endl;
								cin >> choice;

								}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
								if (choice == 'n' || choice == 'N'){
									cout << "Program Terminated." << endl;
									exit(0);
								}


/*
The above ascii art was taken from: 
http://normandy.ascii.uk/ 
Had to change all of the " to '.
*/
}



//######################################################
//################## CHARACTERS FUNCTION ###############
//######################################################
characters random_player(){

//Random number generator from 0-2
srand(time(NULL));
		int random_num =(rand()% (2-0+1))+0;

characters soldier[3];


//Sorry for the below strings, couldnt figure out 
//how to make word wrap work without compile time errors

//Character 1 backstory
string bs00 = "Your name is John Hamstaff. Born and raised in Austin, Texas; you’re a laid-back\ncity man through and through. Life was okay back home in the city, but when your\nnumber came up in the draft you didn’t care all that much. There wasn’t much\nholding you down in Austin since most of the local guys had been drafted over\nthe last few months. You knew the war would call upon you eventually. You not\nparticularly upset about it.\n";

//Character 2 backstory
string bs01 = "Your name is Samuel Suthers. You were once a pastor of the St Marks United\nMethodist Church in Murfreesboro, Tennesse. Though never one to join the \nservice on your own you knew perfectly well that the lord had finally\ncalled apon you to serve in his army the moment you opened your door to\nsee the face of the local recruiter. Your a god fearing man, and if it\nwas his will that led to your draft number being called then so be it.\n";

//Character 3 backstory
string bs02 = "Your name is Ramirez Vargas. Your grandparents immigrated to the United States\n30 years ago after your parents died of a freak accident when a train managed\nto somehow jump the tracks on a hill next to their house and then plowed into\nit, killing both of them while you were away at the nursery. The fact the the\ntrain just so happen to be manufactured by the same company that now makes\nweapons for the nazis probably had a little to do with your enlistment.\n";


soldier[0].set("John", "Hamstaff", "Hammy", bs00);

soldier[1].set("Samuel", "Suthers", "Preacher", bs01);

soldier[2].set("Ramirez", "Vargas", "Vargo", bs02);


return soldier[random_num];
}




//############################################################
//################## STORY SEGMENT 01 FUNCTION ###############
//############################################################
void story_segment01(characters *d){
		cout << "###############################################" << endl;
		cout << "#            THE BEACH                        #" << endl;
		cout << "###############################################\n" << endl;
		cout << "-You were lucky to be in the third wave." << endl;
		cin.get();
		cout << "-The first and second wave never had a chance," << endl;
		cout << "not since the bloody germans had correctly" << endl;
		cout << "guessed our landing area in the few hours they" << endl;
		cout << "had since spotting our ships hours ago via" << endl;
		cout << "scout plane." << endl;
		cin.get();
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		




		cout << "####################################" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################\n\n\n" << endl;


}