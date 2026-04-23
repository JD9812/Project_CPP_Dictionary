#include "dictionary.h"

using namespace JD;

int main(){

	int choice = 1;
	std::string word = "";
	std::string fileName{};

	while (choice != 0) {

		std::cout.width(30);
		std::cout << "Welcome to Dictionary\n";
		std::cout << "Configuration:\n";
		std::cout << "Which dictionary would you like to use?\n";
		std::cout << "1. Small English \n";
		std::cout << "2. Large English \n";
		std::cout << "0. Exit\n";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			fileName = "english_small.csv";
			break;
		case 2:
			fileName = "english_large.csv";
			break;
		case 0:
			break;
		default:
			std::cout << "Invalid choice, using small dictionary.\n";
			fileName = "english_small.csv";
			break;
		}

		if (choice != 0)
		{
			std::cout << "Verbose? 1.Yes 0.No\n";
			std::cin >> Dictionary::m_verbose;
			std::cout << "All Definitions? 1.Yes 0.No\n";
			std::cin >> Dictionary::m_show_all;

			Dictionary dict(fileName.c_str());

			std::cin.ignore(1000, '\n');
			std::cout << "\nType a word to search for its definition, leave empty to go back.\n";
			std::getline(std::cin, word);
			//std::cout << word;

			while (word != "")
			{
				dict.searchWord(word.c_str());
				std::cout << "\nType a word to search for its definition, leave empty to quit.\n";
				std::getline(std::cin, word);
			}
		}

	}

	std::cout << "Goodbye!\n";

	return 0;
}