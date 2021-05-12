#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(int argc, char** argv)
{
	if (argc != 2) {
		std::cout << "Incorrect number of inputs." << std::endl;
	}

	std::ifstream read_in(argv[1]);

	if (!read_in) {
		std::cerr << argv[1] << " file does not exist!" << std::endl;;
	}
	std::string input;
	std::string hex;
	std::string cmd;
	int counter = 0;
	int write = 1;
	std::vector<std::string> hexStore;
	std::vector<int> indexStore;
	while (read_in >> input) {
		if (input.length() == 1) {
			cmd = input;
		}
		else {
			hex = input;
		}
		counter++;
		if (counter % 2 == 0) {
			if (cmd.compare("W") == 0) {
				std::cout << cmd << " " << hex << " " << write << std::endl;
				hexStore.push_back(hex);
				indexStore.push_back(write);
				write++;
			}
			else {
				bool flag = false;
				for (int i = hexStore.size()-1; i >= 0; i--) {
					if (hexStore.at(i).compare(hex) == 0) {
						std::cout << cmd << " " << hex << " " << indexStore.at(i) << std::endl;
						flag = true;
						break;
					}
				}
				if (!flag) {
					std::cout << cmd << " " << hex << " " << 0 << std::endl;
				}
			}
		}
	}
}
