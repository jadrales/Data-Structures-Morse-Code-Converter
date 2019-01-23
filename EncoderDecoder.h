#ifndef ENCODERDECODER_H_
#define ENCODERDECODER_H_
#include <map>
#include <string>


class encoder {
private:
	std::map<char, std::string> alphabet;
	std::string input;
	void create_alphabet();
public:
	encoder();
	std::string encode(std::string input);

	std::string get_input();
	void set_input(std::string in);
};
#endif // !ENCODERDECODER_H_

