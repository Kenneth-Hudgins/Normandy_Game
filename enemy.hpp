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
	int num_e;
	int location;	
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
	void set(string nme, int ne, int loc, int rng, int hlth);



};
#endif