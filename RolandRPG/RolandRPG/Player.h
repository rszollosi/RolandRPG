#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Inventory.h"

class Player : public Character
{
protected:
	int Xp;
	void GainXp(int gainedXp);
	Inventory* PlayersInventory;

public:
	Player(string name);
	Player(string name, int hp);
	~Player();

	
	Inventory* OpenInvetory() const;
	void Attack(Character* enemy) override;

	int GetXp();
	int GetNextLevelXp();
	string GetXpStatus();

	string StatusBar();
};

#endif

