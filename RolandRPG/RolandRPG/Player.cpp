#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name)
{
	Name = name;
	Hp = 100;
	cout << "\n\nWelcome! " << "I am " << Name << ". I am your new character!\n";
}

Player::Player(string name, int hp)
{
	Name = name;
	Hp = hp;
	cout << "\n\nWelcome! " << "I am " << Name << ". Nice to meet you again!\n";
}

Player::~Player()
{
}

void Player::showInvetory()
{
}
