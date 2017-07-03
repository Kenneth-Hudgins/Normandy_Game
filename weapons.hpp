using namespace std;

#ifndef WEAPONS_H
#define WEAPONS_H
#include <string>

class weapons {

private:
string name;
int ammo_capacity;
int in_clip;
int location;

public:	

	//Constructor
	weapons();

	//Getters
	string get_name();
	int get_ammo_capacity();
	int get_in_clip();
	int get_location();


	//Setters
	void set_name(string temp);
	void set_ammo_capacity(int temp);
	void set_in_clip(int temp);
	void set_location(int temp);

	void set(string n, int ac, int ic,  int local);


};
#endif