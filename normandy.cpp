
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "characters.hpp"

using namespace std;

void intro(characters *d);

void story_segment01(characters *d);

void check_continue();

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



//##########################################################
//################## CHECK CONTINUE FUNCTION ###############
//##########################################################
void check_continue(){

	char choice = ' ';

	do{
	cout << "Continue? \n Y / N: ";
	cin >> choice;
	}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
	if (choice == 'n' || choice == 'N'){
	cout << "\n\nProgram Terminated." << endl;
	exit(0);
	}

cout << "\n\n\n";


}



//#################################################
//################## INTRO FUNCTION ###############
//#################################################
void intro(characters *d){

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



check_continue();


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


check_continue();

								

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
		cout << "-You were lucky to be in the third wave; " << endl;
		cout << "everyone else in the higgins boat is deathly" << endl;
		cout << "silent as the pilot starts heading to the beach" << endl;
		cout << "front." << endl;
		cin.get();
		cin.get();
		cout << "30 SECONDS TO BEACH LANDING" << endl;
		cin.get();
		cout << "-The first and second wave never had a chance," << endl;
		cout << "not since the bloody germans had correctly" << endl;
		cout << "guessed our landing area in the few hours they" << endl;
		cout << "had since spotting our ships hours ago via" << endl;
		cout << "scout plane." << endl;
		cin.get();
		cout << "22 SECONDS TO BEACH LANDING" << endl;
		cin.get();
		cout << "-The first two waves were mowed down by heavy" << endl;
		cout << "machine gun fire while artillary decimated the" << endl; 
		cout << "very ships they we were arriving on as they." << endl;
		cout << "ran aground." << endl;
		cin.get();
		cout << "15 SECONDS TO BEACH LANDING" << endl;
		cin.get();
		cout << "-One good thing has come up though, the germans" << endl;
		cout << "seem to have become much more conservative with" << endl;
		cout << "their ammunition these last few hours; like they" << endl;
		cout << "didnt expect to have to defend their positions" << endl;
		cout << "for this long against this many enemy" << endl;
		cout << "combatants." << endl;
		cin.get();
		cout << "7 SECONDS TO BEACH LANDING" << endl;
		cin.get();
		cout << "-Thats good news for you, it means theres a good" << endl;
		cout << "chance you wont be killed outright the moment" << endl;
		cout << "the frontal hull door opens." << endl;
		cin.get();
		cout << "BEACH LANDING IMMINENT" << endl;
		cin.get();
		cout << "-The higgins boat lurches up under you, grinding" << endl;
		cout << "against the shallow ground as it plows forward" << endl;
		cout << "into the sand. You hold onto the side but that" << endl;
		cout << "doesnt stop you from being pushed into the guy" << endl;
		cout << "in front of you by the one behind you." << endl;
		cin.get();
		cout << "-The doors open, your commanding officer is" << endl;
		cout << "screaming GO! Go! Go! and eveyone starts" << endl;
		cout << "running out ducking their heads as if to make" << endl;
		cout << "them selves less of a target for the enemy we" << endl;
		cout << "all know is watching." << endl;
		cin.get();
		cout << "-Your boots hit the sand, you can already hear" << endl;
		cout << "gunfire start spraying the area as you try to" << endl;
		cout << "run for cover." << endl;
		cin.get();
		cout << "-There are bodies everywhere." << endl;
		cin.get();
		cout << "-More gunshots, an explosive goes off 20 feet" << endl;
		cout << "to your left, one of your buddies must have" << endl;
		cout << "stepped on a landmine." << endl;
		cin.get();
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cin.get();
		cout << "" << endl;
		




		cout << "####################################" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################\n\n\n" << endl;


}