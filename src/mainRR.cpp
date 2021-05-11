#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "../inc/RRCache.h"

void readFile(std::ifstream& in_file)
{
	std::string input;
	std::string cmd;
	long unsigned int hex;
	int counter = 0;
	RRCache cache(10);
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
				cache.write(hex);
			}
			else {
				cache.read(hex);
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
