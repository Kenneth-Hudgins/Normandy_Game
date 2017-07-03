#include "enemy.hpp"

using namespace std;

//Constructor
enemy::enemy(void){
	name = " ";
	num_e = 0;
	location = 0;	
	range = 0;
	//health = 2 times number_e
	health = num_e * 2;
	
}


//Getters
	string enemy::get_name(){
		return name;
	}

	int enemy::get_num_e(){
		return num_e;
	}

	int enemy::get_location(){
		return location;
	}

	int enemy::get_range(){
			return range;
	}

	int enemy::get_health(){
		return health;
	}





//Setters
	void enemy::set_name(string temp){
		name = temp;
	}

	void enemy::set_num_e(int temp){
		num_e = temp;
		health = num_e*2;
	}

	void enemy::set_location(int temp){
		location = temp;
	}

	void enemy::set_range(int temp){
		range = temp;
	}

	/*void enemy::set_health(int temp){
		health = temp;
	}*/

	void enemy::set(string nme, int ne, int loc, int rng){
		name = nme;
		num_e = ne;
		location = loc;
		range = rng;
		health = num_e*2;
	}