#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name)
{
	Name = name;
	cout << "\n\nWelcome! " << "I am " << Name << ". I am your new character!\n";
}

Player::~Player()
{
}

void Player::showInvetory()
{
}
