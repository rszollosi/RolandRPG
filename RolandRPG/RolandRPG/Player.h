#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
public:
	Player(string name);
	Player(string name, int hp);
	~Player();

	Inventory* PlayersInventory;
	void OpenInvetory();
};

#endif

