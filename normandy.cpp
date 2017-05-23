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


	cout << "\n\n\n";
	cout << "                                                         888         " << endl;
	cout << "                                                         888         " << endl;
	cout << "                                                         888         " << endl;
	cout << "88888b.  .d88b. 888d88888888b.d88b.  8888b. 88888b.  .d88888888  888 " << endl;
	cout << "888 '88bd88''88b888P'  888 '888 '88b    '88b888 '88bd88' 888888  888 " << endl;
	cout << "888  888888  888888    888  888  888.d888888888  888888  888888  888 " << endl;
	cout << "888  888Y88..88P888    888  888  888888  888888  888Y88b 888Y88b 888 " << endl;
	cout << "888  888 'Y88P' 888    888  888  888'Y888888888  888 'Y88888 'Y88888 " << endl;
	cout << "                                                                 888 " << endl;
	cout << "                                                            Y8b d88P " << endl;
	cout << "                                                             'Y88P'  " << endl;



}