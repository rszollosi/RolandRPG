#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <algorithm>
#include "Inventory.h"
#include "Npc.h"

class Player : public Character
{
protected:
	int Xp;
	void GainXp(int gainedXp);
	Inventory* PlayersInventory;
	int healthPotions;
	
public:
	Player(string name);
	Player(string name, int hp);
	~Player() override;
		
	void OpenInvetory();
	void Attack(Character* enemy) override;

	int GetMaxHp() const override;

	int GetXp();
	int GetNextLevelXp() const;
	string GetXpStatus();

	string StatusBar() override;

	void PickUpItem(Item* item);

	void UseHealthPotion();

	void RefressPlayer();

	void LevelUp();

	void CheckLoot(list<Item> loot);
};

#endif

