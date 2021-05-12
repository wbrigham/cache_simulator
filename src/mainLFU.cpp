#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "../inc/LFUCache.h"

bool is_number(std::string s)
{
	for (unsigned int i = 0; i < s.length(); i++) {
		if (isdigit(s[i]) == false) {
			return false;
		}
	}
	return true;
}

void readFile(std::ifstream& in_file)
{
	std::string input;
	std::string cmd;
	long unsigned int hex;
	int key;
	int counter = 0;
	LFUCache cache(10000);
	while (in_file >> input) {
		if (input.length() == 1 && !is_number(input)) {
			cmd = input;
		}
		if (is_number(input)) {
			key = stoi(input);
		}
		if (input.length() > 1 && !is_number(input)) {
			hex = std::stoul(input, nullptr, 16);
		}
		counter++;
		if (counter % 3 == 0) {
			if (cmd.compare("W") == 0) {
				cache.write(key, hex);
			}
			else {
				cache.read(key, hex);
			}
		}
	}

	std::cout << "Hits: " << cache.getHits() << std::endl;
	std::cout << "Misses: " << cache.getMisses() << std::endl;
}

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Incorrect number of inputs." << std::endl;
		exit(-1);
	}

	std::ifstream read_in(argv[1]);

	if (!read_in) {
		std::cerr << argv[1] << " file does not exist!" << std::endl;
		exit(-1);
	}
	readFile(read_in);
	read_in.close();
	return 0; 
}
