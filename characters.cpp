#include <iostream>
#include <string>
#include "characters.hpp"

using namespace std;



 characters::characters(void) {
	 first_name = " ";
	 last_name = " ";
	 nickname = " ";
	 backstory = " ";
}

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

	void characters::set(string fn, string ln, string nn, string bs){
	 first_name = fn;
	 last_name = ln;
	 nickname = nn;
	 backstory = bs;
	}
 