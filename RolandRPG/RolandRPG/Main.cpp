
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "Welcome to XY RPG Game!" << "\n-------------------------------------------------------------------------";
	cout << "\nPlease choose from one option, by tipeing the number!";
	cout << "\n\n1. Start Game!" << "\n2. Load Game!" << "\n3. Exit Game!\n\n";
	string input;
	auto inputAsNumber = 0;
	auto goodInput = false;

	while (goodInput == false)
	{
		cin >> input;
		inputAsNumber = atoi(input.c_str());
		if (0 < inputAsNumber && inputAsNumber < 4)
		{
			goodInput = true;
		}
		else
		{
			cout << "\nThere isn't that kind of option!\n\n";
		}
	}

	switch (inputAsNumber)
	{
		case 1: cout << "Start a new game!";
		break;
		case 2: cout << "Load the game!";
		break;
		case 3: {
			cout << "Bye!\n";
			exit(1);
		}
	}
}
