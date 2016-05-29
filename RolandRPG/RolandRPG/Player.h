#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
protected:
	//inventory

public:
	Player(string name);
	~Player();

	void showInvetory(); //Returns with inventory
};

#endif

