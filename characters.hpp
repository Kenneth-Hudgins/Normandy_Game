using namespace std;


#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>

class characters {

private:
	//Characters first name
	string first_name;

	//Characters last name
	string last_name;

	//Characters nickname
	string nickname;

	//Characters backstory
	string backstory;
	
	//Distance to pill box
	int to_pill;
	
	//Players fatigue level
	int fatigue;

	//Players health		
	int health;

	//Number of enemy soldiers player has killed
	int kill_count;

	/*Position player is currently in.
	0 = upright, 1 = crawling.*/
	int position;
	
	

public:
	 characters();

	string get_fname();
	string get_lname();
	string get_nickname();
	string get_backstory();

	int get_to_pill();
	int get_fatigue();
	int get_health();
	int get_kill_count();
	int get_position();

	void set_to_pill(int temp);
	void set_fatigue(int temp);
	void set_health(int temp);
	void set_kill_count(int temp);
	void set_position(int temp);

	void set(string fn, string ln, string nn, string bs);
	





};
#endif