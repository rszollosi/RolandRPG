#include "Game.h"

using namespace std;

Game::Game()
{
	system("cls");
	cout << "You started a new game!\n";
	cout << "Please name your character!\n";

	string name;
	cin >> name;

	CurrentPlayer = new Player(name);

}

Game::Game(deque<string> loadedState)
{
	string name;
	string hpAsString;

	name = loadedState.front();
	loadedState.pop_front();
	hpAsString = loadedState.front();
	loadedState.pop_front();
	
	CurrentPlayer = new Player(name, atoi(hpAsString.c_str()));
	
}

Game::~Game()
{
	cout << "Bye!";
	exit(1);
}


string Game::load()
{
	ifstream gameFile;
	string saveString;

	gameFile.open("game.sav");
	
	getline(gameFile, saveString);

	gameFile.close();

	return saveString;
}

void Game::save()
{
	ofstream gameFile;
	string saveString;

	saveString = CurrentPlayer->Name + ";" + to_string(CurrentPlayer->Hp);
	
	gameFile.open("game.sav");

	gameFile << saveString;

	gameFile.close();
}
