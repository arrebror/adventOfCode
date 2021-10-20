#include <iostream>
#include <cstdlib> 
#include <string>
#include <fstream>
#include <sstream>


int star1() {

	std::ifstream file("input1.txt");
	std::string	  word;
	int not_valid = { 0 };
	int tot = { 0 };


	for (std::string line; std::getline(file, line, '\n'); ) {
	    std::istringstream iss(line);
		std::string new_line = ' ' + line + ' ';
		while (iss >> word)
		{

			std::size_t found = new_line.find(' ' + word + ' ');
			int repeated = new_line.find(' ' + word + ' ', found + 1);
			
			if (repeated > 0) {
				not_valid += 1;
				break;
			}
		}
		tot += 1;
	}

return  - not_valid;
}


int star2() {

	std::ifstream file("input.txt");
	std::string	  char_;
	std::string	  word;
	int repeated_letter = { 0 };
	int not_valid = { 0 };
	int tot = { 0 };


	for (std::string line; std::getline(file, line, '\n'); ) {
		std::istringstream iss(line);
		std::string new_line = ' ' + line + ' ';
		while (iss >> word)
		{ 
		std::istringstream iss(word);

		while (iss >> char_) {

			std::size_t found = word.find(char_);
			int repeated = word.find(char_, found + 1);

			if (repeated > 0) {
				repeated_letter += 1;
				break;
			}
		}
		std::cout << " nr of rep letters " << repeated_letter << "\n";
		std::cout << " word " << repeated_letter << "\n";
		if (repeated_letter >= word.length()) {
			std::cout << " not valid " << "\n";
			std::cout << " nr of rep letters " << repeated_letter << "\n";
			not_valid += 1;
			repeated_letter = 0;
			break;
			}


			}
		tot += 1;
	}

	return  tot-not_valid;
}


int main() {
		// int star_1_ans = star1();
		// std::cout << " answer " << star_1_ans << "\n";

		int star_2_ans = star2();

		std::cout << " answer " << star_2_ans << "\n";


		return EXIT_SUCCESS;
	}
