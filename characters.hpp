using namespace std;
#include <string>

#ifndef CHARACTERS_H
#define CHARACTERS_H


class characters {

private:
	string first_name;
	string last_name;
	string nickname;
	string backstory;
	
	

public:
	 characters();

	string get_fname();
	string get_lname();
	string get_nickname();
	string get_backstory();

	void set(string fn, string ln, string nn, string bs);
	





};
#endif