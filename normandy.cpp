#include <iostream>
#include <ctime>
#include <string>
#include "characters.hpp"

using namespace std;

void intro();

//Will need to have random number generator inside the function
characters random_player();


int main(){

characters soldier[2];

soldier[1].set("John", "Doe", "Johny", "Backwoods of carolina");
cout << soldier[1].get_fname() << endl;


soldier[0].set("Brock", "Doe", "Johny", "Backwoods of carolina");
cout << soldier[0].get_fname() << endl;



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

int health = 100;




intro();


	return 0;
}





//#####################################################
//################## FUNCTIONS BELOW ##################
//#####################################################





//#################################################
//################## INTRO FUNCTION ###############
//#################################################

void intro(){

	cout << " ASCI NORMANDY TEXT ART GOES HERE" << endl;
	cout << "\n\n\n";
}