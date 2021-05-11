#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "../inc/LRUCache.h"

void readFile(std::ifstream& in_file)
{
	std::string input;
	std::string cmd;
	long unsigned int hex;
	int counter = 0;
	LRUCache cache(10);
	while (in_file >> input) {
		if (input.length() == 1) {
			cmd = input;
		}
		else {
			hex = std::stoul(input, nullptr, 16);
		}
		counter++;
		if (counter % 2 == 0) {
			if (cmd.compare("W") == 0) {
				write(hex);
			}
			else {
				read(hex);
			}
		}
	}
	std::cout << "Hits: " << getHits() << std::endl;
	std::cout << "Misses: " << getMisses() << std::endl;
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
