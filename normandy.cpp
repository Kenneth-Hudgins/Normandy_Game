/*
Creator: Kenneth William Hudgins

	Date Started: May 21st, 2017

	Date Completed: August 5th, 2017

	Purpose: Console application oriented text game based around a soldier 
	         storiming the beeches of Normandy durring world war 2 with the
	         mission of destroying a german pillbox.


	NOTES: Developing this game tuaght me many lessons, the most important of which is 
	       the need to plan ahead. Development would not have taken anywhere near as 
	       long as it did had I taken the initial time to plan out exactly what I 
	       wanted to happen and build good test cases. Instead there was no plan and I
	       wasted what could have otherwise been a very valuable summer of self 
	       education.

	       Where I to build this over again there are many things I would do
	       differently. But over the course of its construction I have gained a much 
	       better understanding of classes, structures, design, user input and 
	       pointers. 


	NOTE 2: There are large comments above each function, those where so I could 
            skip large amounts of code when looking for something on my editor's 
            minimap.
*/


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

//Chooses random character player based from list
characters random_player();

//Creates the list of in game weapons
void weapons_list(weapons list[]);

//Main game mission, actual gameplay found here
char up_hill_battle(characters *your_player, weapons list[]);

//Moves player forward by 5
void move_forward(int &distance_traveled, characters *your_player, bool &player_turn, bool &done);

//Sets fatigue = 0
void rest_here_awhile(characters *your_player, bool &player_turn);

//Lets player change their position
void change_position_menu(characters *your_player);

//Restores player health if they have medkits
void use_medkit(characters *your_player);

//Switches primary and secondary weapons
void switch_weapons(weapons &primary_w, weapons &secondary_w, bool &player_turn);

//Sets up enemy specifics
void set_enemy(enemy e_list[], int num_enemies);

//Shows position to player, not used to operate on data
string show_position(characters *your_player);

//Determines if enemy fire misses player or not
bool e_hit_or_miss(characters *your_player);

//Determines if player fire misses player or not
bool p_hit_or_miss(characters *your_player);

//Calculates damage done by enemy
int damage_calc();

//Displays player death outro and terminates program
void killed();

//Enemy attacks player
void enemy_fire_on_player(characters *your_player, bool &player_turn, int distance_traveled, enemy e_list[], int num_enemies, bool &done);

//Shows status report to player
void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill, int distance_traveled);

//Displays survey report to player
void survey_forward_area(cover *cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies, int distance_to_pill, int distance_traveled);

//Switchtes primary weapon with weapon on the ground
void pick_up_weapon(weapons list[], int distance_traveled, weapons &primary_w, weapons &secondary_w, bool &player_turn);

//Makes player covered if they are in the same location as a covered spot
void make_covered(int distance_traveled, characters *your_player, cover *cover_spots, int num_covers);

//Player attacks enemy
void player_fire_on_enemy(int distance_traveled, characters *your_player, weapons &primary_w, weapons &secondary_w,  enemy e_list[], int num_enemies, bool &player_turn);

//Tells player if they need to rest
void check_fatigue(characters *your_player);

//Displays tutorial tips
void tips();

/*This should have all of the needed variables passed by their correct values*/
void choices(char &choice, characters *your_player, cover *cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies, int distance_to_pill, int &distance_traveled, weapons &primary_w, weapons &secondary_w, bool &player_turn, bool &done);

//Validates main menu input for up_hill_battle function
void validation(char &choice);

//Ending used if player killed all enemies
void pillbox_a();

//Displays info about creator, what hes doing, how awesome he is, etc.
void about_creator();

//Ending used if Player didnt kill all enemies, pill box soldiers survived
void pillbox_b();

//Ending used if Player didnt kill all enemies, pill box soldiers did not survive
void pillbox_c();



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

	char ending = ' ';

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

	/*^(much later) Does not need to return array if its passed by referance, 
	which arrays are already passed by referance. Im an idiot.*/


	//**************
	/*Passes list to weapons_list
	so it can be initialized*/
	weapons list[6];	//This should have a variable for size
	weapons_list(list);



	/*The below if statement serves the purpose of both calling
	the up_hill_battle function and determining which ending to 
	use based on wether up_hill_battle returned true or false:

	pillbox_a function if player killed all enemies or
	pillbox_b if player didnt kill all enemies.
	*/
	ending = up_hill_battle(your_player, list);

		/*
		a = all enemies killed
		b = pill box soldiers not dead
		c = pillbox soldiers are dead but other enemies are still alive
		*/

	switch(ending){
		case 'a': pillbox_a();
		break;

		case 'b': pillbox_b();
		break;

		case 'c': pillbox_c();
		break;


	
	}
		
	


return 0;
}

//################################################***********************
//################## END MAIN ####################***********************
//################################################***********************







//################################################################
//################## CHECK FATIGUE FUNCTION ######################
//################################################################
void check_fatigue(characters *your_player){

	if(your_player->get_fatigue() == 3){
		cout << "\n\n\n\n\n\n";
		cout << "     ###################" << endl;
		cout << "     # Your exhausted. #" << endl;
		cout << "     ###################" << endl;
		cin.get();
	}


		if(your_player->get_fatigue() > 3){
		cout << "\n\n\n\n\n\n";
		cout << "         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "         !#############################################!" << endl;
		cout << "         !#           YOU DIED OF EXHAUSTION          #!" << endl;
		cout << "         !#############################################!" << endl;
		cout << "         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n" << endl;
		
		cin.get();

		exit(0);
		}
}







//#######################################################
//################## TIPS FUNCTION ######################
//#######################################################
void tips(){

	char choice = ' ';


	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "     ########################################################" << endl;
	cout << "     #                     HELPFUL TIPS                     #" << endl;
	cout << "     ########################################################" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     # TIP 1. You will need to press the enter key to move  #" << endl;
	cout << "     # through all of the displays and after choice input   #" << endl;
	cout << "     # inorder to progress through the game.                #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get();cin.get();
	cout << "     # TIP 2. Expand your terminal window, preferably to    #" << endl;
	cout << "     # full screen, so you can best see the displays.       #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get();
	cout << "     # TIP 3. In the menu, use the Survey-Forward-Area      #" << endl;
	cout << "     # option often so you can get an idea of what you      #" << endl;
	cout << "     # can expect from the next 20 meters ahead of you.     #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get(); 
	cout << "     # TIP 4. When you choose the Move-Forward option your  #" << endl;
	cout << "     # player will move 5 meters ahead. The same applies    #" << endl;
	cout << "     # while your player is in a crawling position,         #" << endl;
	cout << "     # however, your ability to hit the enemy when firing   #" << endl;
	cout << "     # from a crawling position will be hampered.           #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl; cin.get(); 
	cout << "     # TIP 5. You can pick up a weapon if you are within 5  #" << endl;
	cout << "     # meters of it. Your primary weapon will be switched   #" << endl;
	cout << "     # in its place.                                        #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get(); 
	cout << "     # TIP 6. If you try to fire at the enemy from behind   #" << endl;
	cout << "     # cover your ability to hit them will be hampered.     #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get();
	cout << "     # TIP 7. If you make it to a location with a place to  #" << endl;
	cout << "     # take cover then you will automaticly move to a       #" << endl;
	cout << "     # covered position.                                    #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get(); 
	cout << "     # TIP 8. If behind cover and wanting to move forward,  #" << endl;
	cout << "     # make extra sure its what you want to do because      #" << endl;
	cout << "     # there is no going back.                              #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get(); 
	cout << "     # TIP 9. The above also applies to enemies. You can    #" << endl;
	cout << "     # move past enemy soldiers without defeating them,     #" << endl;
	cout << "     # but once you do that they can still attack you       #" << endl;
	cout << "     # without you being able to return fire on them.       #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get();  
	cout << "     # TIP 10. Some enemies will see you before you see     #" << endl;
	cout << "     # them.                                                #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     #                                                      #" << endl;cin.get(); 
	cout << "     # TIP 11. Keep track of your health and fatigue        #" << endl;
	cout << "     # levels. Health can be restored by the use of your    #" << endl;
	cout << "     # limited amount of medkits. Fatigue can only be       #" << endl;
	cout << "     # alleviated by resting.                               #" << endl;
	cout << "     #                                                      #" << endl;
	cout << "     ########################################################\n\n" << endl;
	cin.get();

	cout << "\n\n";
	cout << "     ##############################" << endl;
	cout << "     #  1. PLAY-GAME  #  2. QUIT  #" << endl;
	cout << "     ##############################" << endl;

	cout << "     #####################################" << endl;
	cout << "     # Enter you choice of 1 or 2 below. #" << endl;
	cout << "     #####################################" << endl;
	cout << "\n     Choice:";
	cin >> choice;

		while((choice != '1') && (choice != '2')){
			cout << "\n\n";
			cout << "     #####################################" << endl;
			cout << "     # Enter you choice of 1 or 2 below. #" << endl;
			cout << "     #####################################" << endl;

			cin >> choice; 
		}

		if(choice == '2'){
			cout << "\n\n\n";
			cout << "     ######################" << endl;
			cout << "     # PROGRAM TERMINATED #" << endl;
			cout << "     ######################" << endl;
			exit(0);
		}
}







//#########################################################
//################## STATUS FUNCTION ######################
//#########################################################
void status(characters *your_player, weapons primary_w, weapons secondary_w, int distance_to_pill, int distance_traveled){


	cout <<"\n\n\n\n\n\n\n\n\n\n\n" << endl; 	
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
	cout << "     ##  AMMUNITION:             " << setw(2) << right << primary_w.get_in_clip() << "/" << setw(2) << left << primary_w.get_ammo_capacity() << "                            ##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  SECONDARY WEAPON:        " << setw (29) << secondary_w.get_name() << "   ##" << endl;
	cout << "     ##  AMMUNITION:             " << setw(2) << right << secondary_w.get_in_clip() << "/" << setw(2) << left << secondary_w.get_ammo_capacity() << "                            ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	/*cout << "     ##                                                           ##" << endl;
	cout << "     ##  KILL COUNT:         " << setw(2) << right << your_player->get_kill_count() << "                                   ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;*/
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  MEDKITS:     " << your_player->get_medkit() << "            POSITION:     " << setw(13) << left << show_position(your_player) << "    ##" << endl;
	cout << "     ##___________________________________________________________##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ##  DISTANCE TO GERMAN PILL BOX:     " << setw(3) << right << distance_to_pill - distance_traveled << " METERS              ##" << endl;
	cout << "     ##                                                           ##" << endl;
	cout << "     ###                                                         ###" << endl;
	cout << "     ###############################################################" << endl;
	cout << "     ###############################################################\n" << endl;
	cin.get();
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
//################## SWITCH WEAPONS FUNCTION ######################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//#################################################################
void switch_weapons(weapons &primary_w, weapons &secondary_w, bool &player_turn){

player_turn = false;
	

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

	cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "     ######################################" << endl;
	cout << "     # Your primary and secondary weapons #" << endl;
	cout << "     # have been switched.                #" << endl;
	cout << "     ######################################\n\n" << endl;
	cin.get(); 	
	
	

	/*In regards to the occasional extra cin.get's, it gets to me
	that somewhere somehow there is something that the first cin.get
	is catching from the buffer that makes it require a second one to 
	pause the program for the user and that I dont know where it is or 
	how to fix it.*/
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

	cout << "\n\n\n\n\n\n\n\n" << endl;
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

		cout << "\n\n     ###################################################" << endl;
		cout << "     # INVALID SELECTION, PLEASE ENTER EITHER 0, 1, 2. #" << endl;
		cout << "     ###################################################" << endl;

		cout << "POSITION CHOICE: ";
		cin >> pos_choice;	
		cout << "\n";
	};

	/*The below gets the integer version of the pos_choice
	 after validation done above. Resources online say it 
	 works because of how the ascii characters are store 
	 in memory, which I can understand.*/
	 pc = pos_choice - '0';

	 //Checks if user doesnt want to change position
	 //Exits this function if they enetered 2
	 if(pc == 2){

	 	cout << "\n\n\n";
	 	cout << "     ########################################" << endl;
	 	cout << "     # Okay, your position will not change. #" << endl;
	 	cout << "     ########################################" << endl;
	 	cin.get();
	 	cin.get();

		return;
	}


	//Checks to see if user chose to change to the
	//same position they are already in
	//makes them choose something else
	 if(pc == your_player->get_position()){

	 	cout << "\n\n";
	 	cout << "     #####################################" << endl;
	 	cout << "     # You are already in that position. #" << endl;
	 	cout << "     #####################################" << endl;
	 	cin.get();
	 	cin.get();
	 }



	}while(pc == your_player->get_position());

	//Sets player position
	if(pc == 0){
		your_player->set_position(pc);

		cout << "\n\n";
		cout << "     ################################" << endl;
		cout << "     # Changed to upright position. #" << endl;
		cout << "     ################################\n" << endl;
		cin.get();
		cin.get();
	}

	//Sets player position
	if(pc == 1){
		your_player->set_position(pc);

		cout << "\n\n";
		cout << "     #################################" << endl;
		cout << "     # Changed to crawling position. #" << endl;
		cout << "     #################################\n" << endl;
		cin.get();
		cin.get();
	}
}





//############################################################
//################## USE MEDKIT FUNCTION #####################
//############################################################
void use_medkit(characters *your_player){

	if(your_player->get_health() == 100){
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "     ####################################" << endl;
		cout << "     # Your health is already full, you #" << endl;
		cout << "     # cant use a medkit right now.     #" << endl;
		cout << "     ####################################\n\n" << endl;
		cin.get();
		return;

	}

	if(your_player->get_medkit() == 0){

		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "     #####################################" << endl;
		cout << "     # You dont have any medkits to use. #" << endl;
		cout << "     #####################################\n" << endl;
		cin.get();

	}

	else{

		int new_medkit = (your_player->get_medkit()) -1;

		your_player->set_medkit(new_medkit);

		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "     ##########################" << endl;
		cout << "     # Health fully restored. #" << endl;
		cout << "     ##########################\n" << endl;

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
	e_list[1].set_num_e(3);
	e_list[1].set_location(110); 
	e_list[1].set_range(20);

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

cout << "\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "     ####################################################" << endl;
	cout << "     #          SURVEY OF AREA 20 METERS AHEAD          #" << endl;
	cout << "     ####################################################" << endl;
	cout << "     #                                                  #" << endl;
	cout << "     # Current Location: " << setw(3) << left << distance_traveled << "                            #" << endl;
	cout << "     #                                                  #" << endl;
	cout << "     # ENEMIES:                                         #" << endl;

//Variable is used to calculate display no enemies are visable	
	/*For future reference, the reason this particular variable was giving me
	issues was because I was using it to search for both forward and backward 
	enemies, which is why it was always printing the wrong thing for the 
	enemies loop. Needed to use one for forward and one for backward, though
	now I dont need to account for backward.*/
int no_e = 0;




//Loop going through enemies here
	for(int ix = 0; ix < num_enemies; ix++){

		//Checks for forward enemies
		//Ensures no negative numbers are displayed
		if(e_list[ix].get_location() - distance_traveled >= 0){

			//Makes sure enemy is within player range
			if( (e_list[ix].get_location() - distance_traveled <= 20) && (e_list[ix].get_health() > 0) ){
				cout << "     #                                                  #" << endl;
				cout << "     # " << setw(2) << left << e_list[ix].get_location() - distance_traveled << " meters ahead there are " << e_list[ix].get_num_e() << " " << setw(18) << left <<  e_list[ix].get_name() << "   #" << endl;
				cout << "     #                                                  #" << endl;
			}

			else{no_e++;} 
	}
	else{no_e++;} 

				//Checks for enemies behind player
				//Ensures no negative numbers are displayed
				 if(distance_traveled - e_list[ix].get_location() > 0){

				 	//Ensures only live enemies are displayed
				 	if(e_list[ix].get_health() != 0){

					 	//Makes sure enemy is within player range
					 	if(distance_traveled - e_list[ix].get_location() <= 20){
					 	cout << "     #                                                  #" << endl;
					 	cout << "     # " << setw(2) << left << distance_traveled - e_list[ix].get_location() << " meters behind there are " << setw(2) << left << e_list[ix].get_num_e() << " " << setw(18) << left <<  e_list[ix].get_name() << " #" << endl;
						cout << "     #                                                  #" << endl;
					 	}

				 	}				 	
			 	
			}

			
			
	}

		if(no_e >= num_enemies){
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
				cout << "     #                " << setw(27) << left << cover_spots[ix].name << "       #" << endl;
				cout << "     #                                                  #" << endl;
			}

			//If none of the above are present this is incremented up
			//For the purpose of the code below it
			
			else{no_c++;} //Origional
		}

		else{no_c++;}

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
		if((list[ix].get_location() - distance_traveled) > 0){

			//Makes sure weapon is within player range
			if( (list[ix].get_location() - distance_traveled <= 20) && (list[ix].get_location() - distance_traveled >= 0) ){

				cout << "     #                                                  #" << endl;
				cout << "     # " <<setw(2) << left <<  list[ix].get_location() - distance_traveled << " meters ahead there is a:                      #" << endl;
				cout << "     #              " << setw(29) << left<< list[ix].get_name() << "       #" << endl;
				cout << "     #         AMMUNITION: " << setw(2) << right << list[ix].get_in_clip() << "          CAPACITY: " << setw(2) << right << list[ix].get_ammo_capacity() << "     #" << endl;
				cout << "     #                                                  #" << endl;
			}

			//If none of the above are present this is incremented up
			//For the purpose of the code below it
			else{no_w++;}
		}
		else{no_w++;}
	}

		if(no_w == num_weapons){
			cout << "     #         NO NEARBY WEAPONS                        #" << endl;
			cout << "     #                                                  #" << endl;
			cout << "     ####################################################" << endl;

		}


		if(no_w < num_weapons){
			cout << "     ####################################################" << endl;
		}

		cin.get();
}










//################################################################
//################## PICK UP WEAPON FUNCTION #####################
//################################################################
void pick_up_weapon(weapons list[], int distance_traveled, weapons &primary_w, weapons &secondary_w, bool &player_turn){

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
			cout << "\n\n\n\n\n\n\n\n\n";
			cout << "     #######################################################" << endl;
			cout << "     #                                                     #" << endl;
			cout << "     # Do you want to switch your primary weapon with the  #" << endl;
			cout << "     #            " << setw(29) << left<< list[i].get_name() << "?           #" << endl;
			cout << "     #                                                     #" << endl;
			cout << "     #######################################################" << endl;



			do{
			cout << "\n\nContinue? \n Y / N: ";
			cin >> choice;
			}while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');
				
				if (choice == 'n' || choice == 'N'){
				return;
				}

				else{
					player_turn = false;


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
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "     ###############################" << endl;
		cout << "     # No weapons to pickup nearby #" << endl;
		cout << "     ###############################" << endl;
		cin.get();
	}
}









//######################################################################
//################## MAKE COVERED FUNCTION #############################
//######################################################################
void make_covered(int distance_traveled, characters *your_player, cover *cover_spots, int num_covers){
	
		if(your_player->get_position() == 2){
			return;
		}

	for(int ix = 0; ix < num_covers; ix++){
		if(distance_traveled - cover_spots[ix].location == 0){
			cout << "\n\n\n\n\n\n\n" << endl;
			cout << "     ##################################" << endl;
			cout << "     # You have found cover behind a  #" << endl;
			cout << "     # " << setw(27) << left << cover_spots[ix].name << "    #" << endl;
			cout << "     ##################################\n\n" << endl;
			cin.get();

			your_player->set_position(2);

		}
	}
}








//######################################################################
//################## ENEMY FIRE ON PLAYER FUNCTION #####################
//######################################################################
void enemy_fire_on_player(characters *your_player, bool &player_turn, int distance_traveled, enemy e_list[], int num_enemies, bool &done){

//Damage variable
int d;
//Variable will calculate new health if enemy didnt miss
int new_health;
	
	//This outer if statement could have been done outside of this function
	//Will fix when creating player version of this module
	if((player_turn == false) && (your_player->get_position() != 2)){
		
		//Checks if player is within range of enemy in front or behind them
		for(int ix = 0; ix < num_enemies; ix++){
			
			if((distance_traveled >= (e_list[ix].get_location() - e_list[ix].get_range())) && (distance_traveled <= (e_list[ix].get_location() + e_list[ix].get_range())) && e_list[ix].get_health() >= 1){	
	


				if(e_hit_or_miss(your_player) == false){

					d = damage_calc();

					//Calculates the new health and sets player health accordingly
					new_health = your_player->get_health() - d;
					your_player->set_health(new_health);


								//Calls killed function if players health is <= 0
								if(your_player->get_health() <= 0){
									cout << "\n\n\n\n\n\n\n\n     ###########################################"<< endl;
									cout << "     # You took damage from " << setw(18) << left << e_list[ix].get_name() << " #" << endl;
									cout << "     ###########################################"<< endl;
									cin.get();
									cin.get();

									killed();
								}



					cout << "\n\n\n\n\n\n\n\n     ###########################################"<< endl;
					cout << "     # You took damage from " << setw(18) << left << e_list[ix].get_name() << " #" << endl;
					cout << "     #                                         #" << endl;
					cout << "     # Your health: " << setw(3) << left << your_player->get_health() << "                        #" << endl;
					cout << "     ###########################################\n\n" << endl;
					check_continue();
					}

				else if(e_hit_or_miss(your_player) == true){
					cout << "\n\n\n\n\n" << endl;
					cout << "  ##################################" << endl;
					cout << "  # Bullets fly by you just a few  #" << endl;
					cout << "  # inches away.                   #" << endl;
					cout << "  ##################################\n\n" << endl;
					check_continue();
				}
			}/*End of range check for()*/
			
		}
	}


	//Placement for this could be better
	if(distance_traveled >= 200){
		done = true;
	}

	else{player_turn = true;}
}






//########################################################
//################## KILLED FUNCTION #####################
//########################################################
void killed(){
	
	cout << "\n\n\n\n\n\n\n\n\n";
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
bool p_hit_or_miss(characters *your_player){
	bool missed = false;

	int rand_hit = (rand()% (15 - 0 + 1)) + 0;

		if((your_player->get_position() !=2) && (your_player->get_position() !=1)){

			if(rand_hit <= 5){
				missed = true;
			}
		}

	else{
		if(rand_hit <= 8){
		missed = true;
		}
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
	if(rand_hit == 7){
		missed = true;
	}
}



	//If player is crawling they have a 4/16 chance of not being hit
	if(your_player->get_position() == 0){
	if((rand_hit == 7) || (rand_hit == 6) || (rand_hit == 5) || (rand_hit == 4)){
		missed = true;
	}
}

	return missed;
}





//###################################################################
//################## REST HERE AWHILE FUNCTION ######################
//###################################################################
void rest_here_awhile(characters *your_player, bool &player_turn){
	your_player->set_fatigue(0);

	player_turn = false;

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "     ##########################" << endl;
	cout << "     # Your now fully rested. #" << endl;
	cout << "     ##########################" << endl;
	cin.get();


}





//###############################################################
//################## MOVE FORWARD FUNCTION ######################
//###############################################################
void move_forward(int &distance_traveled, characters *your_player, bool &player_turn, bool &done){

	//New fatigue to change players fatigue
	int new_f = your_player->get_fatigue() +1;
		your_player->set_fatigue(new_f);

	if(your_player->get_position() == 2){
		your_player->set_position(0);

		cout << "\n\n\n\n\n\n\n\n";
		cout << "     ############################" << endl;
		cout << "     # You have changed into an #" << endl;
		cout << "     # " << setw(8) << left << show_position(your_player) << "position.        #" << endl;
		cout << "     ############################" << endl;
		cin.get();
	}

 distance_traveled+= 5;

 	cout << "\n\n\n\n\n\n\n\n";
	cout << "     ###############################" << endl;
	cout << "     # You moved forward 5 meters. #" << endl;
	cout << "     ###############################\n\n" << endl;
	cin.get();

	player_turn = false;

	if(distance_traveled == 200){
		done == true;
	}
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
	
	char choice = ' ';

	cout << "\n\n\n\n\n\n\n\n";
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


	cout << "\n\n";
	cout << "     #####################################################################" << endl;
	cout << "     #     1. PLAY-GAME     #     2. QUIT     #     3. ABOUT CREATOR     #" << endl;
	cout << "     #####################################################################" << endl;

	cout << "\n     ################################################" << endl;
	cout << "     # Enter you choice of either 1, 2, or 3 below. #" << endl;
	cout << "     ################################################\n" << endl;
	cout << "     Choice: ";
	cin >> choice;

		while((choice != '1') && (choice != '2') && (choice != '3')){
			cout << "\n\n";
			cout << "         ################################################" << endl;
			cout << "         # Enter you choice of either 1, 2, or 3 below. #" << endl;
			cout << "         ################################################\n" << endl;
			cout << "         Choice: ";
			cin >> choice;
		}

			//If player chose 1 then program will 
			//already continue on
			switch(choice){

				case '2': 
					cout << "\n\n\n";
					cout << "     ######################" << endl;
					cout << "     # PROGRAM TERMINATED #" << endl;
					cout << "     ######################" << endl;
					exit(0);
				break;

				case '3': about_creator();
				break; 
			}

		tips();


		//Displays the characters backstory so they have a sense of who
		//they are playing as.
		cout << "\n\n\n\n\n\n\n\n\n####################################" << endl;
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
//^(much later) figured it out :)

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
	

	//Pistol, starting secondary weapon
	list[0].set("Sauer 38H Pistol", 8, 8, 50); 

	//Other weapon that can be found by chance
	list[1].set("Nagant M1895 Revolver", 7, 7, 20);

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

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n###############################################" << endl;
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
char up_hill_battle(characters *your_player, weapons list[]){

char all_e_killed = 'a';

	int num_enemies = 4;

		//While loop control, is true when distance traveled = 200
		bool done = false;

		//When player turn = true then enemies cant do anything except see player
		bool player_turn = true;

	enemy e_list[num_enemies];

	set_enemy(e_list, num_enemies);

	//Initialize primary and
	//secondary weapons
	weapons primary_w;
	weapons secondary_w;

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

	//Creates and sets cover spots
	populate_cover(cover_spots);

	//Players menu choice
	char choice;


		story_segment01();



				
//Main loop
		while(done == false){

				while(player_turn == true){
					
					display();

					choices(choice, your_player, cover_spots, num_covers, list, e_list, num_enemies, distance_to_pill, distance_traveled, primary_w, secondary_w, player_turn, done);

					check_fatigue(your_player);
					make_covered(distance_traveled, your_player, cover_spots, num_covers);
					
				
				}
				
		enemy_fire_on_player(your_player, player_turn, distance_traveled, e_list, num_enemies, done);
	}
//End main loop




	//Below determins if all enemies were killed or not
		/*
		a = all enemies killed
		b = pill box soldiers not dead
		c = pillbox soldiers are dead but other enemies are still alive
		*/
		for(int ix = 0; ix < num_enemies; ix++){

				//Goes through enemies and checks for life
				if(e_list[ix].get_health() != 0){
					all_e_killed = 'b';

							
							/*At this point we know not all enemies are dead,
							so the onlything we care about now is if the pill
							box soldiers survived or not. If they did, then 
							set all_e_killed = b, if they are dead set it = 
							c
							*/
							if(e_list[3].get_health() != 0){
								return all_e_killed;
							}

						/*If not all enemies are dead but the pillbox soldiers are
						dead then it is set = c*/
						else{ 
							all_e_killed = 'c';
							return all_e_killed;
						}
				}
		}
	

return all_e_killed;
}








//##########################################################
//################## DISPLAY FUNCTION ######################
//##########################################################
void display(){

//Change position option should have submenu asking to either stand upright, 
//crawl, or find cover

	cout <<"\n\n\n\n\n\n\n\n\n\n\n\n" << endl; 	
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
	cout << "     ##  I.   Pick_Up_Weapon                                    ##" << endl;	
	cout << "     ##                                                         ##" << endl;
	cout << "     #############################################################" << endl;
	cout << "     ##---------------------------------------------------------##" << endl;
	cout << "     #############################################################\n\n" << endl;

}







//#######################################################################
//################## PLAYER FIRE ON ENEMY FUNCTION ######################
//#######################################################################
void player_fire_on_enemy(int distance_traveled, characters *your_player, weapons &primary_w, weapons &secondary_w,  enemy e_list[], int num_enemies, bool &player_turn){
	int no_e = 0;

	//Checks if player even has ammo
	if((primary_w.get_in_clip() == 0) && (secondary_w.get_in_clip() == 0)){
		cout << "\n\n\n\n\n\n\n\n\n";
		player_turn = false;
		cout << "     ###########################" << endl;
		cout << "     # Your out of ammunition. #" << endl;
		cout << "     ###########################" << endl;
		cin.get();
		return;
	}

	/*Assuming at least the secondary has ammo but primary doesnt, tells player they need to switch weapons*/
	if(primary_w.get_in_clip() <= 0){
		player_turn = false;
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "     #############################################" << endl;
		cout << "     # Your primary weapon is out of ammunition, #" << endl;
		cout << "     # switch to your secondary.                 #" << endl;
		cout << "     #############################################" << endl;
		cin.get();
		return;
	}

	
	//Variable will calculate new health if player didnt miss
	int new_health;
	int new_in_clip;

	//Checks if player is within range of enemy in front or behind them
		for(int ix = 0; ix < num_enemies; ix++){
			
			//Checks if enemy is within range of player, front only
			if((e_list[ix].get_location() - distance_traveled <= 20) && (e_list[ix].get_location() - distance_traveled >= 0) ){

					if(e_list[ix].get_health() == 0){
					cout << "\n\n\n\n\n\n\n\n\n";
					cout << "     ########################################" << endl;
					cout << "     # The nazis in that position are dead, #" << endl;
					cout << "     # no point in wasting ammunition.      #" << endl;
					cout << "     ########################################" << endl;
					cin.get();
					return;
					}
				
						if(p_hit_or_miss(your_player) == false){


							cout << "\n\n\n\n\n\n\n\n     #############" << endl;
							cout << "     # Firing... #" << endl;
							cout << "     #############" << endl;
							cin.get();

							//Subtracts 1 from primary w ammo
							new_in_clip = primary_w.get_in_clip() -1;
							primary_w.set_in_clip(new_in_clip);
							
							//Subtracts 1 from enemy health
							new_health = e_list[ix].get_health() -1;
							e_list[ix].set_health(new_health);


							cout << "\n\n\n\n\n\n\n\n";
							cout << "     ##################################" << endl; 
							cout << "     # You hit the " << setw(18) << left << e_list[ix].get_name() << " #" << endl;
							cout << "     ##################################\n\n" << endl;
							cin.get();
							player_turn = false;


								if(new_health == 0){
									cout << "\n\n\n\n\n\n\n\n";
									cout << "     ###########################################" << endl;
									cout << "     # You killed everyone in that position of #" << endl;
									cout << "     # " << setw(18) << left << e_list[ix].get_name() << "                      #" << endl;
									cout << "     ###########################################\n\n" << endl;
									cin.get();
								}

						}

				else{

						cout << "\n\n\n\n\n\n\n\n     #############" << endl;
					cout << "     # Firing... #" << endl;
					cout << "     #############" << endl;
					cin.get();

					new_in_clip = primary_w.get_in_clip() -1;
					primary_w.set_in_clip(new_in_clip);

					cout << "\n\n\n\n\n\n\n\n";
					cout << "     #####################################" << endl;
					cout << "     # You missed the " <<setw(18) << left << e_list[ix].get_name() << " #" << endl;
					cout << "     #####################################" << endl;
					cin.get();		
					player_turn = false;			
				}

	}

	else{no_e++;}
}

if(no_e == num_enemies){
	player_turn = false;
	cout << "\n\n\n\n\n";
	cout << "     #####################" << endl;
	cout << "     # Nothing in range. #" << endl;
	cout << "     #####################" << endl;
	cin.get();

}

/*I have this statement in this function a few times more than what seems needed
because occasionaly it doesnt seem to work and I cant pinpoint where is causing
it*/
player_turn = false;
}








//##########################################################
//################## CHOICES FUNCTION ######################
//##########################################################
void choices(char &choice, characters *your_player, cover *cover_spots, int num_covers, weapons list[], enemy e_list[], int num_enemies, int distance_to_pill, int &distance_traveled, weapons &primary_w, weapons &secondary_w, bool &player_turn, bool &done){

	cout << "     ###############################" << endl;
	cout << "     # Enter your selection below: #" << endl;
	cout << "     ###############################" << endl;

	validation(choice);



	switch(choice){

	case 'a':
	case 'A': status(your_player, primary_w, secondary_w, distance_to_pill, distance_traveled);
	break;

	case 'b':
	case 'B': rest_here_awhile(your_player, player_turn);
	break;

	case 'c':
	case 'C': move_forward(distance_traveled, your_player, player_turn, done);
	break;

	case 'd':
	case 'D': change_position_menu(your_player);
	break;

	case 'e':
	case 'E': player_fire_on_enemy(distance_traveled, your_player, primary_w, secondary_w, e_list, num_enemies, player_turn);
	break;

	case 'f':
	case 'F': switch_weapons(primary_w, secondary_w, player_turn);
	break;

	case 'g':
	case 'G': survey_forward_area(cover_spots, num_covers, list, e_list, num_enemies, distance_to_pill, distance_traveled);
	break;

	case 'h':
	case 'H': use_medkit(your_player);
	break;

	case 'i':
	case 'I': pick_up_weapon(list, distance_traveled, primary_w, secondary_w, player_turn);
	break;
	}

}







//#############################################################
//################## VALIDATION FUNCTION ######################
//#############################################################
void validation(char &choice){

	cout << "     Your choice: ";
	cin >> choice;

	while((choice != 'a') && (choice != 'A') && (choice != 'b') && (choice != 'B') && (choice != 'c') && (choice != 'C') && (choice != 'd') && (choice != 'D') && (choice != 'e') && (choice != 'E') && (choice != 'f') && (choice != 'F') && (choice != 'g') && (choice != 'G') && (choice != 'h') && (choice != 'H') && (choice != 'i') && (choice != 'I')){

		cout << "\n\n";
		cout << "     #################################################" << endl;
		cout << "     # INVALID SELECTION: Please enter a menu option #" << endl;
		cout << "     # listed above. Example: A, B, C, etc.          #" << endl;
		cout << "     #################################################\n" << endl;
		cin >> choice;
	}
cin.get();

}








//################################################################
//################## ABOUT CREATOR FUNCTION ######################
//################################################################
void about_creator(){

char choice;

	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "     #########################################################" << endl;
	cout << "     #*******************************************************#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #* This program was created by Kenneth William Hudgins *#" << endl;
	cout << "     #* during the summer of 2017. I am currently 21 and    *#" << endl;
	cout << "     #* half way to getting my programming analyst          *#" << endl;
	cout << "     #* associates degree at the Central Texas College main *#" << endl;
	cout << "     #* campus.                                             *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #*                                                     *#" << endl;cin.get();cin.get();
	cout << "     #* This Normandy game was meant to be my first solo    *#" << endl;
	cout << "     #* (albeit incredibly simple and small) coding project *#" << endl;
	cout << "     #* outside of completeing my C++ class that spring     *#" << endl;
	cout << "     #* semester at CTC.                                    *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #*                                                     *#" << endl;cin.get();
	cout << "     #* As of writing this on 7/28/17, 11:34pm I feel I     *#" << endl;
	cout << "     #* am incredibly behind in regards to what I need to   *#" << endl;
	cout << "     #* know for software development so I spend as much of *#" << endl;
	cout << "     #* my free time as possible learning and going to tech *#" << endl;
	cout << "     #* events in my area while I am not at work or school. *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #*                                                     *#" << endl;cin.get();
	cout << "     #* You can see how my career is progressing at the     *#" << endl;
	cout << "     #* following places:                                   *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #* My Website:             www.kenhudgins.com          *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #* Or my YouTube channel:                              *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #* Kenneth Hudgins                                     *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #* www.youtube.com/channel/UCiTKXwXWYj9mNBR2voSH08A    *#" << endl;
	cout << "     #*                                                     *#" << endl;
	cout << "     #*******************************************************#" << endl;
	cout << "     #########################################################\n\n" << endl;
	cin.get();

	cout << "\n\n";
	cout << "     ##############################" << endl;
	cout << "     #  1. PLAY-GAME  #  2. QUIT  #" << endl;
	cout << "     ##############################" << endl;

	cout << "     #####################################" << endl;
	cout << "     # Enter you choice of 1 or 2 below. #" << endl;
	cout << "     #####################################" << endl;

	cin >> choice;

		while((choice != '1') && (choice != '2')){
			cout << "\n\n";
			cout << "     #####################################" << endl;
			cout << "     # Enter you choice of 1 or 2 below. #" << endl;
			cout << "     #####################################" << endl;

			cin >> choice; 
		}

		if(choice == '2'){
			cout << "\n\n\n";
			cout << "     ######################" << endl;
			cout << "     # PROGRAM TERMINATED #" << endl;
			cout << "     ######################" << endl;
			exit(0);
		}
}







//################################################################
//################## PILLBOX A FUNCTION ##########################
//################################################################
void pillbox_a(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
cout << "     ################################################################" << endl;
cout << "     #                     ENTERING THE PILLBOX                     #" << endl;
cout << "     ################################################################" << endl;
cout << "     #                                                              #" << endl;
cout << "     #                                                              #" << endl;
cout << "     # You keep moving forward, pushing through the heavy sand and  #" << endl;
cout << "     # stepping over lifeless corpses of German soldiers both young #" << endl;
cout << "     # and old.                                                     #" << endl;
cin.get();

cout << "     # The pillbox looms just above you just a few meters ahead, a  #" << endl;
cout << "     # large concrete dome like structure jutting out of the beach  #" << endl;
cout << "     # hillside maybe 10 feet tall; a long 2 feet wide slit running #" << endl;
cout << "     # horizontally at shoulder hight for soldiers to fire their    #" << endl;
cout << "     # weapons through, as well as a small cannon in the middle     #" << endl;
cout << "     # that would seem to beare down on you menacingly if not for   #" << endl;
cout << "     # fact that its inoperable.                                    #" << endl;   
cin.get();                        

cout << "     # You limp around to the back of the structure and find the    #" << endl;
cout << "     # entrance. The inside is dark, the only source of light comes #" << endl;
cout << "     # from the entrance and long opening on the wall. You count 4  #" << endl;
cout << "     # bodies on the floor in various positions, all suffered some  #" << endl;
cout << "     # degree of damage to the upper torso, a few even missing      #" << endl;
cout << "     # their heads. Maybe thats what the bloody mess on the wall    #" << endl;
cout << "     # behind them is.                                              #" << endl;
cin.get();

cout << "     # There is an ammunition room to the left of the bodies. There #" << endl;
cout << "     # are boxes strewn about all over the floor, machine gun and   #" << endl;
cout << "     # rifle ammo mostly, with a few large crates of shells for the #" << endl;
cout << "     # cannon. It looks like they were running low on supplies      #" << endl;
cout << "     # since almost everything is gone. The air is thick with the   #" << endl;
cout << "     # smell of gunpowder and spent brass.                          #" << endl;
cin.get();

cout << "     # While this pillbox may currently be neutralized, you cant    #" << endl;
cout << "     # risk the possibility that the Germans might reclaim this     #" << endl;
cout << "     # position. As you lean on one of the cold concrete walls to   #" << endl;
cout << "     # rest and contemplate how you can permanently disable this    #" << endl;
cout << "     # position, you suddenly have an idea.                         #" << endl;
cin.get();

cout << "     # It takes a few minuets, the sound of gunfire and men yelling #" << endl;
cout << "     # in a foreign language can be heard in the not too far        #" << endl;
cout << "     # distance as you dig through the mostly empty crates to find  #" << endl;
cout << "     # what your looking for, tossing aside useless debris and      #" << endl;
cout << "     # material as you try not to slip on the empty casings that    #" << endl;
cout << "     # litter the floor. Tripping over something stupid and falling #" << endl;
cout << "     # on your ass is the last thing you need at the moment.        #" << endl;
cin.get();

cout << "     # After what seems like half an hour, but was more than likely #" << endl;
cout << "     # 10 minuets or so, you find enough of what your looking for.  #" << endl;
cin.get();

cout << "     # 14 high explosive shells for the cannon and 5 grenades. You  #" << endl;
cout << "     # pocket one of the grenades and align everything else around  #" << endl;
cout << "     # what you think are the structurally weakest points of the    #" << endl;
cout << "     # pillbox interior, namely in the corners and along the front  #" << endl;
cout << "     # under the horizontal firing opening. By no means are you an  #" << endl;
cout << "     # engineer but you think it should easily collapse the         #" << endl;
cout << "     # structure; or, at the very least, turn it into such a burned #" << endl;
cout << "     # out shell of concrete barely held together by its iron       #" << endl;
cout << "     # supports that no krout would ever consider using it in the   #" << endl;
cout << "     # future.                                                      #" << endl;
cin.get();

cout << "     # Walking outside, you turn back and take one last look inside #" << endl;
cout << "     # at the bodies. You feel tired and exhausted; reaching into   #" << endl;
cout << "     # your pocket you fish out the grenade you picked up just a    #" << endl;
cout << "     # few moments ago.                                             #" << endl;
cin.get();

cout << "     # Closing your eyes, you pull the pin while still holding the  #" << endl;
cout << "     # lever.                                                       #" << endl;
cin.get();

cout << "     # Breath in...                                                 #" << endl;
cin.get();

cout << "     # Breath out...                                                #" << endl;
cin.get();

cout << "     # You chuck the primed grenade into the pillbox entrance and   #" << endl;
cout << "     # see it bounce off one of the walls before it rolls out of    #" << endl;
cout << "     # sight into a corner. You turn around and start hauling ass   #" << endl;
cout << "     # up the hill behind the pillbox.                              #" << endl;
cin.get();

cout << "     # 3                                                            #" << endl;
cin.get();

cout << "     # You run and climb up the hill as fast as you can. Its too    #" << endl;
cout << "     # steep for you to make progress fast enough. Almost every     #" << endl;
cout << "     # hand and foot hold gives way to spilling sand or loose dirt. #" << endl;
cin.get();

cout << "     # 2                                                            #" << endl;
cin.get();

cout << "     # Your half way up the hill, about 6, no, 7 meters away from   #" << endl;
cout << "     # the pillbox and scrambling for purchase as you try to get    #" << endl;
cout << "     # higher.                                                      #" << endl;
cin.get();

cout << "     # 1                                                            #" << endl;
cin.get();

cout << "     # You manage to climb another meter and a half up the hill     #" << endl;
cout << "     # before you realize you wont make it far enough away in time. #" << endl;
cin.get();

cout << "     # The explosion shatters the world around you, lifting your    #" << endl;
cout << "     # body up like doll and throwing you just over the top of the  #" << endl;
cout << "     # hill as chunks of rock and concrete fly in every direction.  #" << endl;
cout << "     # A fireball shoots up 100 feet into the air while dozens of   #" << endl;
cout << "     # smaller explosions can be heard when the remaining ordinance #" << endl;
cout << "     # pops off like fire crackers.                                 #" << endl;
cin.get();

cout << "     # Laying on your side where you landed, all you know is pain.  #" << endl;
cout << "     # Your ears are ringing, it hurts to breath, and you can       #" << endl;
cout << "     # barely move.                                                 #" << endl;
cin.get();

cout << "     # As you try to turn over on your back all you focus on is     #" << endl;
cout << "     # trying to breath.                                            #" << endl;
cin.get();

cout << "     # As you stare up at the sky your vision starts to get dark at #" << endl;
cout << "     # the edges.                                                   #" << endl;
cin.get();

cout << "     # You close your eyes, and as you slip into unconsciousness    #" << endl;
cout << "     # you can faintly hear people calling your name from the other #" << endl;
cout << "     # side of the hill. A pleasent breeze blows across your face.  #" << endl;
cout << "     #                                                              #" << endl;
cout << "     ################################################################" << endl;
cin.get();


cout << "\n\n\n\n";
cout << "     ###########################" << endl;
cout << "     #         THE END         #" << endl;
cout << "     ###########################" << endl;
cout << "\n\n\n\n";
cin.get();

exit(0);
}








//################################################################
//################## PILLBOX B FUNCTION ##########################
//################################################################
//Player didnt kill all enemies, pill box soldiers survived
void pillbox_b(){

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
cout << "     ##################################################################" << endl;
cout << "     #                     APROACHING THE PILLBOX                     #" << endl;
cout << "     ##################################################################" << endl;
cout << "     #                                                                #" << endl;
cout << "     # You couldn't kill them all, but your comrades should take care #" << endl;
cout << "     # of the ones you missed soon.                                   #" << endl;
cin.get();

cout << "     # You keep moving forward, pushing through the heavy sand and    #" << endl;
cout << "     # stepping over lifeless corpses of German soldiers both young   #" << endl;
cout << "     # and old. Your tired but the fights not over.                   #" << endl;
cin.get();

cout << "     # The krout's in that damned pillbox where too well defended, no #" << endl;
cout << "     # way for any of your shots to get through. You crouch low and   #" << endl;
cout << "     # slowly move off to the side of the concrete structure, hoping  #" << endl;
cout << "     # to enter from the back without the enemy knowing. They seem to #" << endl;
cout << "     # be focused on your comrades still coming up the beach so you   #" << endl;
cout << "     # figure your chances of making it are pretty good.              #" << endl;
cin.get();

cout << "     # You are about 8 meters off to the right of the pillbox, slowly #" << endl;
cout << "     # making your way around to the back entrance when, naturally,   #" << endl;
cout << "     # one of the Germans walks out the back and stops just a few     #" << endl;
cout << "     # feet out while starting to undo his trousers, presumably to    #" << endl;
cout << "     # take a leak.                                                   #" << endl;
cin.get();

cout << "     # You freeze, your hand on your sidearm, praying he doesn't see  #" << endl;
cout << "     # you.                                                           #" << endl;
cin.get();

cout << "     # He drops his pants, and lets loose a stream of urine. He turns #" << endl;
cout << "     # his head to the left, then to the right.                       #" << endl;
cin.get();

cout << "     # You drop him. He lurches to the side as if someone pushed him, #" << endl;
cout << "     # hitting the ground hard. He doesn't get up. A small wisp of    #" << endl;
cout << "     # smoke escapes the barrel of the pistol clenched tightly in     #" << endl;
cout << "     # your hand.                                                     #" << endl; 
cin.get();

cout << "     # Knowing you have likely already lost the element of surprise,  #" << endl;
cout << "     # you quickly run and kneel down next to the dead krout. He lays #" << endl;
cout << "     # still on the urine soaked ground where he fell. Turning him    #" << endl;
cout << "     # you find exactly what you were hoping for in one of his coat   #" << endl;
cout << "     # pockets. A single fragmentation grenade.                       #" << endl;
cin.get();

cout << "     # Someone inside shouts something German in a questioning tone.  #" << endl;
cout << "     # A name? Probably the name of the former Nazi now dead at your  #" << endl;
cout << "     # feet. The voice wasn't more than a meter or 2 away inside the  #" << endl;
cout << "     # pillbox.                                                       #" << endl;
cin.get();

cout << "     # Hurriedly, you get to your feet and pull the pin from the      #" << endl;
cout << "     # grenade. You throw it has hard as you can into the dark        #" << endl;
cout << "     # entrance; hearing it bounce off a wall and hit the floor.      #" << endl;
cin.get();

cout << "     # 3                                                              #" << endl;
cin.get();

cout << "     # As you turn to run up the hill behind the pill box several of  #" << endl;
cout << "     # the soldiers inside the pillbox start screaming really loud,   #" << endl;
cout << "     # yelling at each other in their foreign tongue, presumably      #" << endl;
cout << "     # about the live frag rolling around at their feet as they       #" << endl;
cout << "     # scrambled to crawl over each other and escape.                 #" << endl;
cin.get();

cout << "     # 2                                                              #" << endl;
cin.get();

cout << "     # You run and climb up the hill as fast as you can. Its too      #" << endl;
cout << "     # steep for you to make progress fast enough. Almost every hand  #" << endl;
cout << "     # and foot hold gives way to spilling sand or loose dirt.        #" << endl;
cin.get();

cout << "     # 1                                                              #" << endl;
cin.get();

cout << "     # You manage to climb another meter and a half up the hill       #" << endl;
cout << "     # before you realize you wont make it far enough away in time.   #" << endl;
cin.get();


cout << "     # The explosion shatters the world around you, lifting your      #" << endl;
cout << "     # body up like doll and throwing you just over the top of the    #" << endl;
cout << "     # hill as chunks of rock and concrete fly in every direction. A  #" << endl;
cout << "     # fireball shoots up 100 feet into the air while dozens of       #" << endl;
cout << "     # smaller explosions can be heard when the remaining ordinance   #" << endl;
cout << "     # pops off like fire crackers.                                   #" << endl;
cin.get();

cout << "     # Laying on your side where you landed, all you know is pain.    #" << endl;
cout << "     # Your ears are ringing, it hurts to breath, and you can barely  #" << endl;
cout << "     # move.                                                          #" << endl;
cin.get();

cout << "     # As you try to turn over on your back all you focus on is       #" << endl;
cout << "     # trying to breath.                                              #" << endl;
cin.get();

cout << "     # As you stare up at the sky your vision starts to get dark at   #" << endl;
cout << "     # the edges.                                                     #" << endl;
cin.get();

cout << "     # You close your eyes, and as you slip into unconsciousness      #" << endl;
cout << "     # you can faintly hear people calling your name from the other   #" << endl;
cout << "     # side of the hill. A pleasent breeze blows across your face.    #" << endl;
cout << "     #                                                                #" << endl;
cout << "     ##################################################################" << endl;
cin.get();


cout << "\n\n\n\n";
cout << "     ###########################" << endl;
cout << "     #         THE END         #" << endl;
cout << "     ###########################" << endl;
cout << "\n\n\n\n";
cin.get();

exit(0);


	
}







//################################################################
//################## PILLBOX C FUNCTION ##########################
//################################################################
//Player didnt kill all enemies, pill box soldiers did not survive
void pillbox_c(){
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
cout << "     ################################################################" << endl;
cout << "     #                     ENTERING THE PILLBOX                     #" << endl;
cout << "     ################################################################" << endl;
cout << "     #                                                              #" << endl;
cout << "     #                                                              #" << endl;
cout << "     # You keep moving forward, pushing through the heavy sand and  #" << endl;
cout << "     # stepping over lifeless corpses of German soldiers both young #" << endl;
cout << "     # and old.                                                     #" << endl;
cin.get();

cout << "     # The pillbox looms just above you just a few meters ahead, a  #" << endl;
cout << "     # large concrete dome like structure jutting out of the beach  #" << endl;
cout << "     # hillside maybe 10 feet tall; a long 2 feet wide slit running #" << endl;
cout << "     # horizontally at shoulder hight for soldiers to fire their    #" << endl;
cout << "     # weapons through, as well as a small cannon in the middle     #" << endl;
cout << "     # that would seem to beare down on you menacingly if not for   #" << endl;
cout << "     # fact that its inoperable.                                    #" << endl;   
cin.get();                        

cout << "     # You limp around to the back of the structure and find the    #" << endl;
cout << "     # entrance. The inside is dark, the only source of light comes #" << endl;
cout << "     # from the entrance and long opening on the wall. You count 4  #" << endl;
cout << "     # bodies on the floor in various positions, all suffered some  #" << endl;
cout << "     # degree of damage to the upper torso, a few even missing      #" << endl;
cout << "     # their heads. Maybe thats what the bloody mess on the wall    #" << endl;
cout << "     # behind them is.                                              #" << endl;
cin.get();

cout << "     # There is an ammunition room to the left of the bodies. There #" << endl;
cout << "     # are boxes strewn about all over the floor, machine gun and   #" << endl;
cout << "     # rifle ammo mostly, with a few large crates of shells for the #" << endl;
cout << "     # cannon. It looks like they were running low on supplies      #" << endl;
cout << "     # since almost everything is gone. The air is thick with the   #" << endl;
cout << "     # smell of gunpowder and spent brass.                          #" << endl;
cin.get();

cout << "     # While this pillbox may currently be neutralized, you cant    #" << endl;
cout << "     # risk the possibility that the Germans might reclaim this     #" << endl;
cout << "     # position. As you lean on one of the cold concrete walls to   #" << endl;
cout << "     # rest and contemplate how you can permanently disable this    #" << endl;
cout << "     # position, you suddenly have an idea.                         #" << endl;
cin.get();

cout << "     # It takes a few minuets, the sound of gunfire and men yelling #" << endl;
cout << "     # in a foreign language can be heard in the not too far        #" << endl;
cout << "     # distance as you dig through the mostly empty crates to find  #" << endl;
cout << "     # what your looking for, tossing aside useless debris and      #" << endl;
cout << "     # material as you try not to slip on the empty casings that    #" << endl;
cout << "     # litter the floor. Tripping over something stupid and falling #" << endl;
cout << "     # on your ass is the last thing you need at the moment.        #" << endl;
cin.get();

cout << "     # After what seems like half an hour, but was more than likely #" << endl;
cout << "     # 10 minuets or so, you find enough of what your looking for.  #" << endl;
cin.get();

cout << "     # 14 high explosive shells for the cannon and 5 grenades. You  #" << endl;
cout << "     # pocket one of the grenades and align everything else around  #" << endl;
cout << "     # what you think are the structurally weakest points of the    #" << endl;
cout << "     # pillbox interior, namely in the corners and along the front  #" << endl;
cout << "     # under the horizontal firing opening. By no means are you an  #" << endl;
cout << "     # engineer but you think it should easily collapse the         #" << endl;
cout << "     # structure; or, at the very least, turn it into such a burned #" << endl;
cout << "     # out shell of concrete barely held together by its iron       #" << endl;
cout << "     # supports that no krout would ever consider using it in the   #" << endl;
cout << "     # future.                                                      #" << endl;
cin.get();

cout << "     # Just as you are about to turn around and walk out a small    #" << endl;
cout << "     # baseball sized object flies through the space on the wall.   #" << endl;
cout << "     # You pull out your rifle and aim through the opening, seeing  #" << endl;
cout << "     # the German soldier sprinting away. You take aim...           #" << endl;
cin.get();

cout << "     # 3                                                            #" << endl;
cin.get();

cout << "     # You are just about to pull the trigger when a bullet catches  #" << endl;
cout << "     # you in your shoulder, throwing you back and onto the floor.   #" << endl;
cout << "     # As you clutch your shoulder in pain you finally notice what   #" << endl;
cout << "     # the German had thrown into the pillbox with you. A grenade.   #" << endl;
cin.get();

cout << "     # 2                                                             #" << endl;
cin.get();

cout << "     # Quickly, you try to reach over and grab it, maybe you can     #" << endl;
cout << "     # still clutch the lever and stop it from going off. You try    #" << endl;
cout << "     # to grab it but its just out of reach. Your fingers just       #" << endl;
cout << "     # barely touch it, but your shoulder is in so much pain you     #" << endl;
cout << "     # cant stretch your arm any further.                            #" << endl;
cin.get();

cout << "     # 1                                                             #" << endl;
cin.get();

cout << "     # You stop trying to reach for the grenade. You take            #" << endl;
cout << "     # consolation in knowing that the blast will ignite the         #" << endl;
cout << "     # ordinance you have placed around the interior and destroy the #" << endl;
cout << "     # pillbox. You see a quick flash of light, and then you are no  #" << endl;
cout << "     # more.                                                         #" << endl;
cin.get();

cout << "\n\n\n\n";
cout << "     ###########################" << endl;
cout << "     #         THE END         #" << endl;
cout << "     ###########################" << endl;
cout << "\n\n\n\n";
cin.get();

exit(0);
}