#include "Game.h"
#include <iostream>
#include <string>
#include "Player.h"

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

Game::~Game()
{
	cout << "Bye!";
	exit(1);
}

void Game::save()
{
	
}
