
#include <iostream>
#include <ctime>
#include <string>

#include <cstdlib>
#include "characters.hpp"

using namespace std;

void intro();

//Will need to have random number generator inside the function
characters random_player();



int main(){


characters player = random_player();


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


intro();


	return 0;

}


//#########################################################################

//################## FUNCTIONS BELOW ######################################

//#########################################################################








//#################################################

//################## INTRO FUNCTION ###############

//#################################################
void intro(){





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

srand(time(NULL));

		int random_num =(rand()% (2-0+1))+0;



characters soldier[3];


//Sorry for the below strings, couldnt figure out 
//how to make word wrap work without compile time errors

//Character 1 backstory
string bs00 = "Your name is John Hamstaff. Born and raised in Austin, Texas; you’re a laid-back\ncity man through and through. Life was okay back home in the city, but when your\nnumber came up in the draftyou didn’t care all that much. There wasn’t much\nholding you down in Austin since most of the local guys had been drafted over\nthe last few months. You knew your number would come up eventually. You not\nparticularly upset about it.\n\n";

//Character 2 backstory
string bs01 = "Your name is Samuel Suthers. You were once a pastor of the St Marks United\nMethodist Church in Murfreesboro, Tennesse. Although you are not a violent\nman by any means you knew perfectly well that the lord had finally called\napon you to servein his righteous army. Your a god fearing man, and if it\nwas his will that led to your draft number being called then so be it.\n\n";

//Character 3 backstory
string bs02 = "Your name is Ramirez Vargas. Your grandparents immigrated to the United States\n30 years ago after your parents died of a freak accident when a train managed\nto somehow jump the tracks on a hill next to their house and then plowed into\nit, killing both of them while you were away at the nursery. The fact the the\ntrain just so happen to be manufactured by the same company that now makes\nweapons for the nazis probably had a little to do with your enlistment.\n\n";


soldier[0].set("John", "Hamstaff", "Hammy", bs00);

soldier[1].set("Samuel", "Suthers", "Preacher", bs01);

soldier[2].set("Ramirez", "Vargas", "Vargo", bs02);



return soldier[random_num];
}