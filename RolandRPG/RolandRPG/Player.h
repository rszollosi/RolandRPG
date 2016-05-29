#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
protected:
	//inventory

public:
	Player(string name);
	Player(string name, int hp);
	~Player();

	void showInvetory(); //Returns with inventory
};

#endif

