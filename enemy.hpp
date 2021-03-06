using namespace std;

#ifndef ENEMY_H
#define ENEMY_H
#include <string>


/*Will have manually code in uphill battle 
what weapons they have, as well as random 
hit generator modules*/


class enemy{

private:
	
	string name;

	/*num_e is the number of enemies for a particular enemy position,
	instead of creating multiple enemies with the same location to 
	add difficulty this is much simpler, single enemy can have 
	multiple num_e's which increases health and therefore difficulty 
	for the player*/
	int num_e;
	//Location based on 200 meters to pill
	int location;
	//"Weapons range" at which the enemy can hurt player	
	int range;
	//health = 2 times number_e
	int health;
	

public:

	//Constructor
	enemy();

	//Getters
	string get_name();
	int get_num_e();
	int get_location();
	int get_range();
	int get_health();


	//Setters
	void set_name(string temp);
	void set_num_e(int temp);
	void set_location(int temp);
	void set_range(int temp);
	void set_health(int temp);
	void set(string nme, int ne, int loc, int rng);



};
#endif