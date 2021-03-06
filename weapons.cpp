#include "weapons.hpp"

using namespace std;

//Constructor
weapons::weapons(void){
	name = " ";
	ammo_capacity = 0;
	in_clip = 0;
	location = 0;
}



//Getters
 	string weapons::get_name(){
 		return name;
 	}

 	int weapons::get_in_clip(){
 		return in_clip;
 	}

 	int weapons::get_ammo_capacity(){
 		return ammo_capacity;
 	}

 	int weapons::get_location(){
 		return location;
 	}



 //Setters
 	void weapons::set_name(string temp){
 		name = temp;
 	}

 	void weapons::set_in_clip(int temp){
 		in_clip = temp;
 	}

 	void weapons::set_ammo_capacity(int temp){
 		ammo_capacity = temp;
 	}

 	void weapons::set_location(int temp){
 		location = temp;
 	}



 //Auto sets the weapons created in main
 	void weapons::set(string n, int ac, int ic, int local){
 		name = n;
 		ammo_capacity = ac;
 		in_clip = ic;
 		location = local;
 	}