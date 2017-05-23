#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "characters.hpp"

using namespace std;

void intro(int &d);

//Will need to have random number generator inside the function
int random_player();


int main(){

/*
Experimenting with use of an array of classes

characters soldier[2];

soldier[1].set("John", "Doe", "Johny", "Backwoods of carolina");
cout << soldier[1].get_fname() << endl;


soldier[0].set("Brock", "Doe", "Johny", "Backwoods of carolina");
cout << soldier[0].get_fname() << endl;

*/

characters soldier[2];

int char_designator;

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



random_player();


intro(char_designator);


	return 0;
}





//#####################################################
//################## FUNCTIONS BELOW ##################
//#####################################################





//#################################################
//################## INTRO FUNCTION ###############
//#################################################

void intro(int &d){


	cout << "\n\n\n";
	cout << "                                                         888         " << endl;
	cout << "                                                         888         " << endl;
	cout << "                                                         888         " << endl;
	cout << "     88888b.  .d88b. 888d88888888b.d88b.  8888b. 88888b.  .d88888888  888 " << endl;
	cout << "     888 '88bd88''88b888P'  888 '888 '88b    '88b888 '88bd88' 888888  888 " << endl;
	cout << "     888  888888  888888    888  888  888.d888888888  888888  888888  888 " << endl;
	cout << "     888  888Y88..88P888    888  888  888888  888888  888Y88b 888Y88b 888 " << endl;
	cout << "     888  888 'Y88P' 888    888  888  888'Y888888888  888 'Y88888 'Y88888 " << endl;
	cout << "                                                                      888 " << endl;
	cout << "                                                                 Y8b d88P " << endl;
	cout << "                                                                  'Y88P'  " << endl;


		srand(time(NULL));
		d =(rand()% (2-0+1))+0;

/*
The above ascii art was taken from: 
http://normandy.ascii.uk/ 
Had to change all of the " to '.
*/


}



//######################################################
//################## CHARACTERS FUNCTION ###############
//######################################################


int random_player(){

	srand(time(NULL)); 
int random =(rand()% (14-7+1))+7;

characters soldier[3];

string bs00 = "Your name is John Hamstaff. Born and raised in Austin, Texas; you’re a laid-back\ncity man through and through. Life was okay back home in the city, but when your\nnumber came up in the draftyou didn’t care all that much. There wasn’t much\nholding you down in Austin since most of the local guys had been drafted over\nthe last few months. You knew your number would come up eventually. You not\nparticularly upset about it.\n\n";
soldier[0].set("John", "Hamstaff", "Hammy", bs00);
cout << "Hello?" << endl;
cout << soldier[0].get_backstory() << endl;


soldier[1].set("Samuel", "Suthers", "Sue", "Backwoods of carolina");
//cout << soldier[0].get_fname() << endl;

soldier[2].set("Ramirez", "Vargas", "Vargo", "Backwoods of carolina");
//cout << soldier[0].get_fname() << endl;


}