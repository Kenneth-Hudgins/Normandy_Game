
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <ctime>
#include <string>
#include <cstdlib>
#include "characters.hpp"
#include "weapons.hpp"

using namespace std;

void display();

void intro(characters *d);

void story_segment01();

void check_continue();

characters random_player();

void weapons_list(weapons list[]);

void up_hill_battle(characters *your_player, weapons list[]);






//To be finished.....
void validation(char choice);

void choices(char choice);

void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill);

void move_forward();

void find_cover();

void fire_on_enemy();

void change_position_menu(characters *your_player);

void survey_forward_area();

void use_medkit();

void switch_weapons(weapons &primary_w, weapons &secondary_w);

void rest_here_awhile();

string show_position(characters *your_player);



//Not lucky = 0, lucky event 1 = 1,
//lucky event 2 = 2, etc, return 
//specific int to be checked in
//loop or by other function to
//enact event instance
int  feeling_lucky();




//################################################*************************
//################################################*************************
//################################################*************************
//################################################**************************************************
//################################################**************************************************
//################## BEGIN MAIN ##################**************************************************
//################################################**************************************************
//################################################**************************************************
//################################################*************************
//################################################*************************
//################################################*************************
int main(){






	/*
	Thought about how I could just have
	the pointer accept the address but after
	about an hour of messing with it I stopped
	because it was beyond me and the below 
	already works
	*/
	characters player = random_player();
	characters *your_player = &player;
//***************************************************



	/*DOES NOT WORK????????????
	supposed to return an array from 
	weapons_list so we can pass it to 
	up_hill_battle like I did with 
	the characters variable above it*/
	//**************
	/*Passes list to weapons_list
	so it can be initialized*/
	weapons list[6];
	weapons_list(list);

	//cout << list[0].get_name() << endl;
	//cout << list[1].get_name() << endl;
	//cout << list[2].get_name() << endl;




	//Players starts making
	//their way to the pill
	//box
	/*Passes your_player and list to the 
	up_hill_battle function */
	up_hill_battle(your_player, list);

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



								/*
								The above ascii art was taken from: 
								http://normandy.ascii.uk/ 
								Had to change all of the " to '.
								*/

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
string bs00 = "Your name is John Hamstaff. Born and raised in Austin, Texas; you’re a laid-back\ncity man through and through. Life was okay back home in the city, but when your\nnumber came up in the draft you didn’t care all that much. There wasn’t much\nholding you down in Austin since most of the local guys had been drafted over\nthe last few months. You knew the war would call upon you eventually. Your not\nparticularly upset about it.\n";

//Character 2 backstory
string bs01 = "Your name is Samuel Suthers. You were once a pastor of the St Marks United\nMethodist Church in Murfreesboro, Tennesse. Though never one to join the \nservice on your own you knew perfectly well that the lord had finally\ncalled apon you to serve in his army the moment you opened your door to\nsee the face of the local recruiter. Your a god fearing man, and if it\nwas his will that led to your draft number being called then so be it.\n";

//Character 3 backstory
string bs02 = "Your name is Ramirez Vargas. Your grandparents immigrated to the United States\n30 years ago after your parents died of a freak accident when a train managed\nto somehow jump the tracks on a hill next to their house and then plowed into\nit, killing both of them while you were away at the nursery. The fact the the\ntrain just so happen to be manufactured by the same company that now makes\nweapons for the nazis probably had a little to do with your enlistment.\n";


soldier[0].set("John", "Hamstaff", "Hammy", bs00);

soldier[1].set("Samuel", "Suthers", "Preacher", bs01);

soldier[2].set("Ramirez", "Vargas", "Vargo", bs02);


return soldier[random_num];
}




//###################################################
//################## WEAPONS FUNCTION ###############
//###################################################
void weapons_list(weapons list[]){

/*Enemies when hit are either 0 dead, 1 no longer able to fight,
2 wounded, or 3 the shot missed*/

	//Will also need a function to determin if enemy was hit
	//and if so which of the above to render the enemy
	//Must also take into consideration how far away player 
	//is from nearest enemy

	

	//Pistol, starting secondary weapon
	list[0].set("Sauer 38H Pistol", 8, 8); 

	//Other weapon that can be found by chance
	list[1].set("Nagant M1895 Revolver", 7, 7); 

	//Other weapon that can be found by chance
	list[2].set("StG 45 Storm Rifle", 30, 30); 

	//Other weapon that can be found by chance
	list[3].set("Browning Automatic Rifle", 20, 20); 

	//Starting primary weapon
	list[4].set("M1941 Johnson Rifle", 10, 10); 

	//Other weapon that can be found by chance
	list[5].set("Ithaca 37 Pump-Action Shotgun", 5, 5);

}













//############################################################
//################## STORY SEGMENT 01 FUNCTION ###############
//############################################################
void story_segment01(){

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
		cout << "very ships they we were arriving on as they" << endl;
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
		cout << "screaming GO! GO! GO! and eveyone starts" << endl;
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
		cout << "-But you cant worry about him." << endl;
		cin.get();
		cout << "-The only thing you have time to worry about" << endl;
		cout << "is how your going to keep your self alive and" << endl;
		cout << "do what your here for.\n" << endl;
		cin.get();
		
		cout << "####################################" << endl;
		cout << "#                                  #" << endl;
		cout << "####################################\n\n\n" << endl;
}









//##########################################################
//################## UP HILL BATTLE FUNCTION ###############
//##########################################################
void up_hill_battle(characters *your_player, weapons list[]){


	/*
	Thought about how I could just have
	the pointer accept the address but after
	a few minuets of messing with it I stopped
	because the below already works
	 */

	
	//Initialize primary and
	//secondary weapons
	weapons primary_w;
	weapons secondary_w;

	//Distance to pill box and end
	//of up_hill_battle
	int distance_to_pill = 200;

	//Set primary weapon
	primary_w.set(list[4].get_name(),list[4].get_ammo_capacity(),list[4].get_in_clip());
	//cout << primary_w.get_name() << endl;

	//Set secondary weapon
	secondary_w.set(list[0].get_name(),list[0].get_ammo_capacity(),list[0].get_in_clip());
	//cout << secondary_w.get_name() << endl;

	//Calls intro function and passes it
	intro(your_player);

	//Call story segment 01 function
	//story_segment01();

	//Call display function
	display();

	

	
	status(your_player, primary_w, secondary_w, distance_to_pill);







	//While loop control
	bool done = false;
	//Players menu choice
	char choice;



	//Test
	cout << list[2].get_name() << endl;
	cout << list[0].get_name() << endl;
	cout << list[1].get_name() << endl;
	cout << "\n" << endl;

//Working
//switch_weapons(primary_w, secondary_w);

//Working
//change_position_menu(your_player);




/*Will need to create various enemy positions
based on distance to pill from notebook sketch,
as well as their respective visual ranges, 
weapons range, hit playey and or player 
spotted functions/possible sneak mechanic?*/



	/*
	#

	#

	#

	#

	BUILD MENUE BLAH BLAH HERE

	#

	#

	#

	#
	*/
}





//##########################################################
//################## DISPLAY FUNCTION ######################
//##########################################################
void display(){

//Change position option should have submenu asking to either stand upright, 
//crawl, or find cover

	cout <<"\n\n\n\n\n" << endl; 	
	cout << "     #############################################################" << endl;
	cout << "     ##----------------------ACTIONS MENU-----------------------##" << endl;
	cout << "     #############################################################" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  A.   Status                   B.   Rest-Here           ##" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  C.   Move-Forward             D.   Find-Cover          ##" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  E.   Fire-On-Enemy            F.   Switch-Weapons      ##" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  G.   Survey-Forward-Area      H.   Use-Medkit          ##" << endl;	
	cout << "     ##                                                         ##" << endl;	
	cout << "     ##  I.   Change-Position          J.   Im-Feeling-lucky    ##" << endl;	
	cout << "     ##                                                         ##" << endl;
	cout << "     #############################################################" << endl;
	cout << "     ##---------------------------------------------------------##" << endl;
	cout << "     #############################################################\n\n" << endl;



}






//##########################################################
//################## CHOICES FUNCTION ######################
//##########################################################
void choices(char choice){


	switch(choice){

	case 'a':
	case 'A': /*----------*/ ;
	break;

	case 'b':
	case 'B': /*----------*/ ;
	break;

	case 'c':
	case 'C': /*----------*/ ;
	break;

	case 'd':
	case 'D': /*----------*/ ;
	break;

	case 'e':
	case 'E': /*----------*/ ;
	break;

	case 'f':
	case 'F': /*----------*/ ;
	break;

	case 'g':
	case 'G': /*----------*/ ;
	break;

	case 'h':
	case 'H': /*----------*/ ;
	break;

	case 'i':
	case 'I': /*----------*/ ;
	break;

	case 'j':
	case 'J': /*----------*/ ;
	break;




	}

}









//#########################################################
//################## STATUS FUNCTION ######################
//#########################################################
void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill){


	cout <<"\n\n\n\n\n" << endl; 	
	cout << "     ###############################################################" << endl;
	cout << "     ##----------------------STATUS REPORT------------------------##" << endl;
	cout << "     ##----------------------The " << setfill('-') << setw(15) << left <<your_player->get_nickname() << "------------------##" <<  setfill(' ') << endl;
	cout << "     ###############################################################" << endl;
	cout << "     ###                                                         ###" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  HEALTH:      " << your_player->get_health() << "                    FATIGUE:      " << your_player->get_fatigue() << "       ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  PRIMARY WEAPON:          " << setw (29) << primary_w.get_name() << "   ##" << endl;
	cout << "     ##  AMMUNITION:             " << setw(2) << right << primary_w.get_in_clip() << "/" << left << primary_w.get_ammo_capacity() << "                            ##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  SECONDARY WEAPON:        " << setw (29) << secondary_w.get_name() << "   ##" << endl;
	cout << "     ##  AMMUNITION:             " << setw(2) << right << secondary_w.get_in_clip() << "/" << left << secondary_w.get_ammo_capacity() << "                             ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  KILL COUNT:         " << setw(2) << right << your_player->get_kill_count() << "                                   ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  MEDKITS:     " << your_player->get_medkit() << "            POSITION:     " << setw(13) << left << show_position(your_player) << "    ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  DISTANCE TO GERMAN PILL BOX:     " << setw(3) << right << distance_to_pill << " METERS              ##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ###                                                         ###" << endl;
	cout << "     ###############################################################" << endl;
	cout << "     ###############################################################" << endl;




				/*Keep fixing this*/


}








//################################################################
//################## SHOW POSITION FUNCTION ######################
//################################################################
string show_position(characters *your_player){

/*Position player is currently in.
	0 = upright, 1 = crawling, 2 = behind cover*/

	/*THis function is to be used only 
	when displaying the players 
	position to the user, not when 
	operating on the position data*/

	int pos = your_player->get_position();

	switch(pos){

	case 0:
	return "Upright";
	break;

	case 1:
	return "Crawl";
	break;

	case 2:
	return "Covered";
	break;

	}
}








//#################################################################
//################## SWITCH WEAPONS FUNCTION ######################
//#################################################################
void switch_weapons(weapons &primary_w, weapons &secondary_w){

	//Sets temp variables = primary weapon
	string tn = primary_w.get_name();
	int ac = primary_w.get_ammo_capacity();
	int ic = primary_w.get_in_clip();

	//Sets primary weapon = secondary weapon
	primary_w.set_name(secondary_w.get_name());
	primary_w.set_ammo_capacity(secondary_w.get_ammo_capacity());
	primary_w.set_in_clip(secondary_w.get_in_clip());

	//Sets secondary weapon = temp variables(primary weapon)
	secondary_w.set_name(tn);
	secondary_w.set_ammo_capacity(ac);
	secondary_w.set_in_clip(ic);

}





//#################################################################
//################## CHANGE POSITION FUNCTION ######################
//#################################################################
void change_position_menu(characters *your_player){

	/*Position player is currently in.
		0 = upright, 1 = crawling, 2 = behind cover*/

	
	/*While this is more complicated than just looking for a
	char in the first place, I thought it educational to
	learn how to protect against this type of wrong user
	input*/
	
	//Temp character variable used for input verification of 
	//position by user to guard against character inputs
	char pos_choice;

	//Final variable to be used for manipulation
	int pc;

	cout << "\n\n" << endl;
	cout << "     ##############################################" << endl;
	cout << "     ##-----------CHANGE POSITION MENU-----------##" << endl;
	cout << "     ##############################################" << endl;
	cout << "     ##                                          ##" << endl;
	cout << "     ##   CURRENT POSITION: " << setw(13) << left << show_position(your_player) << "        ##" << endl;
	cout << "     ##__________________________________________##" << endl;
	cout << "     ##                                          ##" << endl;
	cout << "     ##   WHAT POSITION DO YOU WANT TO CHANGE    ##" << endl;
	cout << "     ##   TO?                                    ##" << endl;
	cout << "     ##                                          ##" << endl;
	cout << "     ##   0. Upright            1. Crawling      ##" << endl;
	cout << "     ##                                          ##" << endl;
	cout << "     ##   2. DONT CHANGE POSITION                ##" << endl;
	cout << "     ##                                          ##" << endl;
	cout << "     ##############################################\n" << endl;
	
	do{
	cout << "POSITION CHOICE: ";
	cin >> pos_choice;
	cout << "\n";


	//Validates that input is not of type char and is 0,1, or 2
	while(isalpha(pos_choice) || ((pos_choice != '0') && (pos_choice != '1') && (pos_choice != '2'))){

		cout << "\nINVALID SELECTION, PLEASE ENTER EITHER 0, 1, OR 2." << endl;

		cout << "POSITION CHOICE: ";
		cin >> pos_choice;	
		cout << "\n";
	};

	//Gets the integer version of the pos_choice
	//After validation done above
	 pc = pos_choice - '0';

	 //Checks if user doesnt want to change position
	 //Exits this function if they enetered 2
	 if(pc == 2){
		return;
	}


	//Checks to see if user chose to change to the
	//same position they are already in
	//makes them choose something else
	 if(pc == your_player->get_position()){
	 	cout <<"You are already in the " << show_position(your_player) << " position." << endl;
	 }



	}while(pc == your_player->get_position());

	//Sets player position
	if(pc == 0){
		your_player->set_position(pc);
	}

	//Sets player position
	if(pc == 1){
		your_player->set_position(pc);
	}

 


}