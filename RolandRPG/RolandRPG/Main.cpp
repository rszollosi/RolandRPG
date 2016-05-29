
#include <iostream>
#include <string>
#include "Game.h"
#include <stack>
using namespace std;

deque<string> split(const string& str, const string& delim);

int main(){
	cout << "Welcome to XY RPG Game!" << "\n-------------------------------------------------------------------------";
	cout << "\nPlease choose from one option, by tipeing the number!";
	cout << "\n\n1. Start Game!" << "\n2. Load Game!" << "\n3. Exit Game!\n\n";
	string input;
	Game* game;
	string saveString;
	deque<string> loadedGame;

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
		case 1: cout << "Start a new game!\n";
			game = new Game();
		break;
		case 2: cout << "Load the game!\n";
			saveString = Game::load();
			if (saveString != "") {
				loadedGame = split(Game::load(), ";");
				game = new Game(loadedGame);
			}
			else
			{
				cout << "There is no valid save file!\n";
			}
		break;
		case 3: {
			cout << "Bye!\n";
			exit(1);
		}
	}
	system("pause");
}

deque<string> split(const string& str, const string& delim)
{
	deque<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}