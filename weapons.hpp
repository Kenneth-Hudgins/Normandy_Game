using namespace std;

#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>

class weapons {

private:
string name;
int ammo_capacity;
int damage;

public:	

	//Constructor
	weapons();

	//Getters
	string get_name();
	int get_ammo_capacity();
	int get_damage();


	//Setters
	void set_name(string temp);
	void set_ammo_capacity(int temp);
	void set_damage(int temp);

	void set(string n, int ac, int d);


};
#endif