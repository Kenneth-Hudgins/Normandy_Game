
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <ctime>
#include <string>
#include <cstdlib>
#include "characters.hpp"
#include "weapons.hpp"
#include "enemy.hpp"

using namespace std;


//+++++++++++++++++++++++++++++++++
//+++++++++COVER STRUCTURE+++++++++
//+++++++++++++++++++++++++++++++++
//No range variable, will test it against 2 meters
struct cover{
	string name;
	int location;
};



//Main menu
void display();

void populate_cover(cover * cover_spots);

//Displays intro
void intro(characters *d);

//Starts the first story segment
void story_segment01();

//Player either continues through program
//or terminates the program
void check_continue();

//Choses random character player based from list
characters random_player();

//Creates the list of in game weapons
void weapons_list(weapons list[]);

//First mission
void up_hill_battle(characters *your_player, weapons list[]);

//Moves player forward by 5
void move_forward(int &distance_traveled, characters *your_player);

//Sets fatigue = 0
void rest_here_awhile(characters *your_player);

//Lets player change their position
void change_position_menu(characters *your_player);

//Restores player health if they have medkits
void use_medkit(characters *your_player);

//Switches primary and secondary weapons
void switch_weapons(weapons &primary_w, weapons &secondary_w);

//Sets up enemy specifics
void set_enemy(enemy e_list[], int num_enemies);

//Shows position to player, not used to operate on data
string show_position(characters *your_player);

//Determines if enemy fire misses player or not
bool e_hit_or_miss(characters *your_player);

//Determines if player fire misses player or not
bool p_hit_or_miss();

//Calculates damage done by enemy
int damage_calc();

//Displays player death outro and terminates program
void killed();

//Enemy attacks player
void enemy_fire_on_player(characters *your_player, bool player_turn, int distance_traveled, enemy e_list[], int num_enemies);

//Shows status report to player
void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill, int distance_traveled);

//Displays survey report to player
void survey_forward_area(cover *cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies, int distance_to_pill, int distance_traveled);

//Switchtes primary weapon with weapon on the ground
void pick_up_weapon(weapons list[], int distance_traveled, weapons &primary_w, weapons &secondary_w);

//Makes player covered if they are in the same location as a covered spot
void make_covered(int distance_traveled, characters *your_player, cover *cover_spots, int num_covers);








//To be finished.....
void validation(char choice);

void choices(char choice);

/*Will need its own random hit/miss generator, as 
well as consideration for how this affect enemy health*/
void player_fire_on_enemy();






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
	weapons list[6];	//This should have a variable for size
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








//#########################################################
//################## STATUS FUNCTION ######################
//#########################################################
void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill, int distance_traveled){


	cout <<"\n\n\n\n\n" << endl; 	
	cout << "     ###############################################################" << endl;
	cout << "     ##----------------------STATUS REPORT------------------------##" << endl;
	cout << "     ##----------------------The " << setfill('-') << setw(15) << left <<your_player->get_nickname() << "------------------##" <<  setfill(' ') << endl;
	cout << "     ###############################################################" << endl;
	cout << "     ###                                                         ###" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  HEALTH:      " <<setw(3) << left << your_player->get_health() << "                   FATIGUE:      " << setw(1) << left << your_player->get_fatigue() << "       ##" << endl;
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
	cout << "     ##  DISTANCE TO GERMAN PILL BOX:     " << setw(3) << right << distance_to_pill - distance_traveled << " METERS              ##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ###                                                         ###" << endl;
	cout << "     ###############################################################" << endl;
	cout << "     ###############################################################\n" << endl;

}








//################################################################
//################## SHOW POSITION FUNCTION ######################
//################################################################
string show_position(characters *your_player){

/*Position player is currently in.
	0 = upright, 1 = crawling, 2 = behind cover*/

	/*This function is to be used only 
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
//################## CHANGE POSITION FUNCTION #####################
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
	cout << "     ###                                        ###" << endl;
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
	cout << "     ###                                        ###" << endl;
	cout << "     ##############################################" << endl;
	cout << "     ##############################################\n" << endl;
	
	do{
	cout << "POSITION CHOICE: ";
	cin >> pos_choice;
	cout << "\n";


	//Validates that input is not of type char and is 0,1, or 2
	while(isalpha(pos_choice) || ((pos_choice != '0') && (pos_choice != '1') && (pos_choice != '2') )){

		cout << "\nINVALID SELECTION, PLEASE ENTER EITHER 0, 1, 2." << endl;

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
	 	cin.get();
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





//############################################################
//################## USE MEDKIT FUNCTION #####################
//############################################################
void use_medkit(characters *your_player){

	if(your_player->get_medkit() == 0){

		cout << "  #####################################" << endl;
		cout << "  # You dont have any medkits to use. #" << endl;
		cout << "  #####################################\n" << endl;
		cin.get();

	}

	else{

		int new_medkit = (your_player->get_medkit()) -1;

		your_player->set_medkit(new_medkit);

		cout << "  ##########################" << endl;
		cout << "  # Health fully restored. #" << endl;
		cout << "  ##########################\n" << endl;

		your_player->set_health(100);

		cin.get();

	}

}





//################################################################
//################## POPULATE COVER FUNCTION #####################
//################################################################
void populate_cover(cover * cover_spots){

	//Manually set the cover positions
	cover_spots[0].name = "bombed out crater.";
	cover_spots[0].location = 20; 

	cover_spots[1].name = "small dug out trench.";
	cover_spots[1].location = 40;

	cover_spots[2].name = "bombed out crater.";
	cover_spots[2].location = 60;

	cover_spots[3].name = "destroyed tank.";
	cover_spots[3].location = 80;

	cover_spots[4].name = "pile of dead nazis.";
	cover_spots[4].location = 100;

	cover_spots[5].name = "super bombed out crater.";
	cover_spots[5].location = 120;

	cover_spots[6].name = "small dug out trench.";
	cover_spots[6].location = 140;

	cover_spots[7].name = "small boulder.";
	cover_spots[7].location = 160; 

	cover_spots[8].name = "grand fortress of solitude.";
	cover_spots[8].location = 180; 



}







//#####################################################################
//################## SURVEY FORWARD AREA FUNCTION #####################
//#####################################################################
void survey_forward_area(cover * cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies){


//Obviously this needs heavy consideration

//cover_spots[0].name = "o00000000000000000o";
//cout << cover_spots[0].name << endl;
}






//###########################################################
//################## SET ENEMY FUNCTION #####################
//###########################################################
void set_enemy(enemy e_list[], int size){

//Setting up enemy specifics
	e_list[0].set_name("machine gunners.");
	e_list[0].set_num_e(2);
	e_list[0].set_location(70); 
	e_list[0].set_range(20);

	e_list[1].set_name("machine gunners.");
	e_list[1].set_num_e(2);
	e_list[1].set_location(110); 
	e_list[1].set_range(20);

	/*Will need something to tell player that there are snipers ahead
	maybe when pllayer tries to return fire could display message 
	saying because they are too far away they might miss along
	with generator that makes them miss more the farther away they
	are*/
	e_list[2].set_name("snipers.");
	e_list[2].set_num_e(3);
	e_list[2].set_location(160);
	e_list[2].set_range(30);

	e_list[3].set_name("pill box soldiers.");
	e_list[3].set_num_e(4);
	e_list[3].set_location(195);
	e_list[3].set_range(20);
}







//#####################################################################
//################## SURVEY FORWARD AREA FUNCTION #####################
//#####################################################################
void survey_forward_area(cover *cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies, int distance_to_pill, int distance_traveled){

/*This function needs to be built, perhaps using loop structure to go througheach array
as was done in enemy fire on player function and compare it to the players range, which 
we will set at 20 meters. Need to compare everything to players current location 
and display how far it is from player.*/ 

/*Need do make sure that if player wants to move forward from a covered position they
move to a crawl not an upright position as well as insure player cant move forward
while remaining covered */


/*When players location == cover location it should automaticly put them behind cover,
and if they move forward change cover to crawl*/

cout << "\n\n" << endl;
	cout << "     ####################################################" << endl;
	cout << "     #          SURVEY OF AREA 20 METERS AHEAD          #" << endl;
	cout << "     ####################################################" << endl;
	cout << "     #                                                  #" << endl;
	cout << "     # Current Location: " << setw(3) << left << distance_traveled << "                            #" << endl;
	cout << "     #                                                  #" << endl;
	cout << "     # ENEMIES:                                         #" << endl;

//Variable is used to calculate display no enemies are visable
int no_e = 0;


//Loop going through enemies here
	for(int ix = 0; ix < num_enemies; ix++){

		//Checks for forward enemies
		//Ensures no negative numbers are displayed
		if(e_list[ix].get_location() - distance_traveled > 0){

			//Makes sure enemy is within player range
			if( e_list[ix].get_location() - distance_traveled <= 20 ){
				cout << "     #                                                  #" << endl;
				cout << "     # " << setw(2) << left << e_list[ix].get_location() - distance_traveled << " meters ahead there are " << e_list[ix].get_num_e() << " " << setw(18) << left <<  e_list[ix].get_name() << "   #" << endl;
				cout << "     #                                                  #" << endl;
			}
	}

			//Checks for enemies behind player
			//Ensures no negative numbers are displayed
			 if(distance_traveled - e_list[ix].get_location() > 0){

			 	//Makes sure enemy is within player range
			 	if(distance_traveled - e_list[ix].get_location() <= 20){
			 	cout << "     #                                                  #" << endl;
			 	cout << "     # " << setw(2) << left << distance_traveled - e_list[ix].get_location() << " meters behind there are " << e_list[ix].get_num_e() << " " << setw(18) << left <<  e_list[ix].get_name() << "   #" << endl;
				cout << "     #                                                  #" << endl;

			 	}

			 	
			}

			//If none of the above are present this is incremented up
			//For the purpose of the code below it
			else{no_e++;}
			
	}

		if(no_e == num_enemies){
			cout << "     #         NO VISABLE ENEMIES AHEAD                 #" << endl;
			cout << "     #                                                  #" << endl;
			cout << "     ####################################################" << endl;

		}


		if(no_e < num_enemies){
			cout << "     ####################################################" << endl;
		}







			cout << "     #                                                  #" << endl;
			cout << "     # PLACES TO TAKE COVER:                            #" << endl;

//Loop going through cover spots here
		int no_c = 0;

	for(int ix = 0; ix < num_covers; ix++){

		//Checks for forward cover spots
		//Ensures no negative numbers are displayed
		if(cover_spots[ix].location - distance_traveled > 0){

			//Makes sure cover is within player range
			if( cover_spots[ix].location - distance_traveled <= 20 ){

				cout << "     #                                                  #" << endl;
				cout << "     # " <<setw(2) << left <<  cover_spots[ix].location - distance_traveled << " meters ahead there is a:                      #" << endl;
				cout << "     #                " << setw(27) << left<< cover_spots[ix].name << "       #" << endl;
				cout << "     #                                                  #" << endl;
			}

			//If none of the above are present this is incremented up
			//For the purpose of the code below it
			else{no_c++;}
		}

	}

		if(no_c == num_covers){
			cout << "     #         NO WHERE TO TAKE COVER AHEAD             #" << endl;
			cout << "     #                                                  #" << endl;
			cout << "     ####################################################" << endl;

		}


		if(no_c < num_covers){
			cout << "     ####################################################" << endl;
		}


	cout << "     #                                                  #" << endl;
	cout << "     # NEARBY WEAPONS ON THE GROUND:                    #" << endl;


//Loop going through weapons list

				int no_w = 0;
				int num_weapons = 6;

	for(int ix = 0; ix < num_weapons; ix++){

		//Checks for forward weapons
		//Ensures no negative numbers are displayed
		if(list[ix].get_location() - distance_traveled > 0){

			//Makes sure weapon is within player range
			if( list[ix].get_location() - distance_traveled <= 20 ){

				cout << "     #                                                  #" << endl;
				cout << "     # " <<setw(2) << left <<  list[ix].get_location() - distance_traveled << " meters ahead there is a:                      #" << endl;
				cout << "     #                " << setw(27) << left<< list[ix].get_name() << "       #" << endl;
				cout << "     #         AMMUNITION: " << setw(2) << right << list[ix].get_in_clip() << "          CAPACITY: " << setw(2) << right << list[ix].get_ammo_capacity() << "     #" << endl;
				cout << "     #                                                  #" << endl;
			}

			//If none of the above are present this is incremented up
			//For the purpose of the code below it
			else{no_w++;}
		}

	}

		if(no_w == num_weapons){
			cout << "     #         NO NEARBY WEAPONS                        #" << endl;
			cout << "     #                                                  #" << endl;
			cout << "     ####################################################" << endl;

		}


		if(no_w < num_weapons){
			cout << "     ####################################################" << endl;
		}
}










//################################################################
//################## PICK UP WEAPON FUNCTION #####################
//################################################################
void pick_up_weapon(weapons list[], int distance_traveled, weapons &primary_w, weapons &secondary_w){

//Explained below
int no_w = 0;

char choice = ' ';

//Temp variables used for swapping
string tn;
int ac;
int ic;

	for (int i = 0; i < 6; i++)
	{
		if((list[i].get_location() - distance_traveled == 5) || (list[i].get_location() - distance_traveled == 0)) {
			cout << "\n\n\n";
			cout << "     ######################################################" << endl;
			cout << "     #                                                    #" << endl;
			cout << "     # Do you want to switch your primary weapon with the #" << endl;
			cout << "     #               " << setw(27) << left<< list[i].get_name() << "          #" << endl;
			cout << "     #                                                    #" << endl;
			cout << "     ######################################################" << endl;



			do{
			cout << "\n\nContinue? \n Y / N: ";
			cin >> choice;
			}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
				
				if (choice == 'n' || choice == 'N'){
				return;
				}

				else{


//Sets temp variables = primary weapon
	string tn = primary_w.get_name();
	int ac = primary_w.get_ammo_capacity();
	int ic = primary_w.get_in_clip();

//Sets primary weapon = list[i]
	primary_w.set_name(list[i].get_name());
	primary_w.set_ammo_capacity(list[i].get_ammo_capacity());
	primary_w.set_in_clip(list[i].get_in_clip());

//Sets list[i] = temp variables (primary Weapon)
	list[i].set_name(tn);
	list[i].set_ammo_capacity(ac);
	list[i].set_in_clip(ic);

				}

		}
	//If no weapons are in range this is incrimented up for the
		//purpose of the code below it
		else{no_w++;}
	}

	if(no_w == 6){
		cout << "\n\n\n";
		cout << "     ###############################" << endl;
		cout << "     # No weapons to pickup nearby #" << endl;
		cout << "     ###############################" << endl;
		cin.get();
		cin.get();
	}
}









//######################################################################
//################## MAKE COVERED FUNCTION #############################
//######################################################################
void make_covered(int distance_traveled, characters *your_player, cover *cover_spots, int num_covers){
	
	for(int ix = 0; ix < num_covers; ix++){
		if(distance_traveled - cover_spots[ix].location == 0){
			cout << "\n\n" << endl;
			cout << "     ##################################" << endl;
			cout << "     # You have found cover behind a  #" << endl;
			cout << "     # " << setw(27) << left << cover_spots[ix].name << "    #" << endl;
			cout << "     ##################################\n\n" << endl;

			your_player->set_position(2);

		}
	}
}








//######################################################################
//################## ENEMY FIRE ON PLAYER FUNCTION #####################
//######################################################################
void enemy_fire_on_player(characters *your_player, bool player_turn, int distance_traveled, enemy e_list[], int num_enemies){

//Damage variable
int d;
//Variable will calculate new health if enemy didnt miss
int new_health;

	if((player_turn == false) && (your_player->get_position() != 2)){
		
		//Checks if player is within range of enemy in front or behind them
		for(int ix = 0; ix < num_enemies; ix++){
			
			if(distance_traveled >= (e_list[ix].get_location() - e_list[ix].get_range()) || distance_traveled <= (e_list[ix].get_location() + e_list[ix].get_range())){
				
				if(e_hit_or_miss(your_player) == false){

					d = damage_calc();

					//Calculates the new health and sets player health accordingly
					new_health = your_player->get_health() - d;
					your_player->set_health(new_health);

					//Player will need to survey forward area to see how far out enemies are

					cout << "\n     ###########################################"<< endl;
					cout << "     # You took damage from " << setw(18) << left << e_list[ix].get_name() << " #" << endl;
					cout << "     #                                         #" << endl;
					cout << "     # Your health: " << setw(3) << left << your_player->get_health() << "                        #" << endl;
					cout << "     ###########################################\n\n" << endl;
					cin.get();


						//Calls killed function if players health is <= 0
						if(your_player->get_health() <= 0){
							killed();
						}

				}

				else{
					cout << "\n" << endl;
					cout << "  ##################################" << endl;
					cout << "  # Bullets fly by you just a few  #" << endl;
					cout << "  # inches away.                   #" << endl;
					cout << "  ##################################\n\n" << endl;
					cin.get();

					check_continue();
				}
			}/*End of range check for()*/
			ix++;
		}
	}/*End of player_turn if()*/
}






//########################################################
//################## KILLED FUNCTION #####################
//########################################################
void killed(){
	
	cout << "\n\n\n";
	cout << "         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	cout << "         !################################!" << endl;
	cout << "         !#           YOU DIED           #!" << endl;
	cout << "         !################################!" << endl;
	cout << "         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n" << endl;
	
	cin.get();

	exit(0);
}





//#############################################################
//################## DAMAGE CALC FUNCTION #####################
//#############################################################
int damage_calc(){
	int damage = (rand()% (10 - 3 + 1)) + 4;

	return damage;
}





//###############################################################
//################## P HIT OR MISS FUNCTION #####################
//###############################################################
bool p_hit_or_miss(){
	bool missed = false;

	int rand_hit = (rand()% (15 - 0 + 1)) + 0;

	if(rand_hit <= 3){
		missed = true;
	}
	return missed;
}







//###############################################################
//################## E HIT OR MISS FUNCTION #####################
//###############################################################
bool e_hit_or_miss(characters *your_player){
	bool missed = false;

	int rand_hit = (rand()% (15 - 0 + 1)) + 0;
	
	//If player is upright they have a 1/16 chance of not being hit
	if(your_player->get_position() == 0){
	if(rand_hit = 7){
		missed = true;
	}
}


	//If player is crawling they have a 4/16 chance of not being hit
	if(your_player->get_position() == 0){
	if((rand_hit = 7) || (rand_hit = 6) || (rand_hit = 5) || (rand_hit = 4)){
		missed = true;
	}
}

	return missed;
}





//###################################################################
//################## REST HERE AWHILE FUNCTION ######################
//###################################################################
void rest_here_awhile(characters *your_player){
	your_player->set_fatigue(0);
}





//###############################################################
//################## MOVE FORWARD FUNCTION ######################
//###############################################################
void move_forward(int &distance_traveled, characters *your_player){

	if(your_player->get_position() == 2){
		your_player->set_position(0);

		cout << "\n\n";
		cout << "     ############################" << endl;
		cout << "     # You have changed into an #" << endl;
		cout << "     # " << setw(8) << left << show_position(your_player) << "position.        #" << endl;
		cout << "     ############################" << endl;
	}

 distance_traveled+= 5;

 	cout << "\n\n";
	cout << "     ###############################" << endl;
	cout << "     # You moved forward 5 meters. #" << endl;
	cout << "     ###############################\n\n" << endl;
}






//##########################################################
//################## CHECK CONTINUE FUNCTION ###############
//##########################################################
void check_continue(){

	char choice = ' ';

	do{
	cout << "\n\nContinue? \n Y / N: ";
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
	list[0].set("Sauer 38H Pistol", 8, 8, 50);  

	//Other weapon that can be found by chance
	list[1].set("Nagant M1895 Revolver", 7, 7, 20 ); 

	//Other weapon that can be found by chance
	list[2].set("StG 45 Storm Rifle", 30, 30, 160); 

	//Other weapon that can be found by chance
	list[3].set("Browning Automatic Rifle", 20, 20, 80); 

	//Starting primary weapon
	list[4].set("M1941 Johnson Rifle", 10, 10, 100); 

	//Other weapon that can be found by chance
	list[5].set("Ithaca 37 Pump-Action Shotgun", 5, 5, 130);

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

	int num_enemies = 4;
	enemy e_list[num_enemies];

	set_enemy(e_list, num_enemies);


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

	//Random weapons, need to modify class to add location
	//DOnt need this, have the weapons list passed from main-----weapons random_w[4];


	//There is a covered position every 20 meters
	//excluding the last 20
	/*If for whatever reason this doesnt work make it a const*/ 
	int num_covers = 9;
	cover cover_spots[num_covers];

	//Distance to pill box and end
	//of up_hill_battle
	int distance_to_pill = 200;
	int distance_traveled = 0;

	//Set primary weapon
	primary_w.set(list[4].get_name(),list[4].get_ammo_capacity(),list[4].get_in_clip(), 0);
	//cout << primary_w.get_name() << endl;

	//Set secondary weapon
	secondary_w.set(list[0].get_name(),list[0].get_ammo_capacity(),list[0].get_in_clip(), 0);
	//cout << secondary_w.get_name() << endl;

	//Calls intro function and passes it
	intro(your_player);

	//Call story segment 01 function
	//story_segment01();

	//Call display function
	display();


	your_player->set_position(2);
	move_forward(distance_traveled, your_player);

	
	//Works
	status(your_player, primary_w, secondary_w, distance_to_pill, distance_traveled);







	//While loop control
	bool done = false;

	//When player turn = true then enemies cant do anything except see player
	bool player_turn = true;

	//Players menu choice
	char choice;



	//Works
	//cout << list[2].get_name() << endl;
	//cout << list[0].get_name() << endl;
	//cout << list[1].get_name() << endl;
	//cout << "\n" << endl;

//Working
//---------------------switch_weapons(primary_w, secondary_w);

//Working
//---------------------change_position_menu(your_player);

//Works
//---------------------use_medkit(your_player);

//Works
populate_cover(cover_spots);

//Works
//---------------------e_hit_or_miss(your_player);





survey_forward_area(cover_spots, num_covers, list, e_list, num_enemies, distance_to_pill, distance_traveled);


 pick_up_weapon(list, distance_traveled,primary_w, secondary_w);






		/*Build cover structures*/


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
	cout << "     ##  C.   Move-Forward             D.   Change-Position     ##" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  E.   Fire-On-Enemy            F.   Switch-Weapons      ##" << endl;
	cout << "     ##                                                         ##" << endl;
	cout << "     ##  G.   Survey-Forward-Area      H.   Use-Medkit          ##" << endl;	
	cout << "     ##                                                         ##" << endl;	
	cout << "     ##  I.   Im-Feeling-lucky                                  ##" << endl;	
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


	}

}
