//If this doesnt work then #include <iostream> here

//#include <string>
#include "characters.hpp"

using namespace std;


//Constructor
 characters::characters(void) {
	 first_name = " ";
	 last_name = " ";
	 nickname = " ";
	 backstory = " ";
	 fatigue = 0;		
	 health = 10;
	 kill_count = 0;
	 position = 0;
	 medkit = 4;

}


//Getters
 	string characters::get_fname(){
 		return first_name;
 	}

	string characters::get_lname(){
		return last_name;
	}


	string characters::get_nickname(){
		return nickname;
	}
	

	string characters::get_backstory(){
		return backstory;
	}

	
	int characters::get_fatigue(){
		return fatigue;
	}
	int characters::get_health(){
		return health;
	}

	int characters::get_kill_count(){
		return kill_count;
	}

	int characters::get_position(){
		return position;
	}


	int characters::get_medkit(){
		return medkit;
	}


//Setters
	void characters::set_fatigue(int temp){
		fatigue = temp;
	}
	void characters::set_health(int temp){
		health = temp;
	}

	void characters::set_kill_count(int temp){
	kill_count = temp;	
	}

	void characters::set_position(int temp){
		position = temp;
	}

	void characters::set_medkit(int temp){
		//Will have to pay special attention to this
		//adding and subtracting from it
		medkit = temp;
	}


//Auto sets the characters created in main
	void characters::set(string fn, string ln, string nn, string bs){
		 first_name = fn;
		 last_name = ln;
		 nickname = nn;
		 backstory = bs;

		}
 
