#include "weapons.hpp"

using namespace std;

//Constructor
weapons::weapons(void){
	name = " ";
	ammo_capacity = 0;
	damage = 0;
}



//Getters
 	string weapons::get_name(){
 		return name;
 	}

 	int weapons::get_ammo_capacity(){
 		return ammo_capacity;
 	}

 	int weapons::get_damage(){
 		return damage;
 	}



 //Setters
 	void weapons::set_name(string temp){
 		name = temp;
 	}

 	void weapons::set_ammo_capacity(int temp){
 		ammo_capacity = temp;
 	}

 	void weapons::set_damage(int temp){
 		damage = temp;
 	}

 //Auto sets the weapons created in main
 	void weapons::set(string n, int ac, int d){
 		name = n;
 		ammo_capacity = ac;
 		damage = d;
 	}