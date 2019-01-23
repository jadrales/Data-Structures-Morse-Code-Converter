#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class HashTable {
private:
	unordered_map<string, string> letters_map;
public:
	//constructor
	HashTable() {}

	//Member Functions
	void add_letter(string letter, string morse) {
		//adds hash table based on given line
		letters_map[letter] = morse;
	};

	// does a lookup and returns the morse version of the letter
	string get_morse_version(string letter) {
		return letters_map[letter];
	};
};
