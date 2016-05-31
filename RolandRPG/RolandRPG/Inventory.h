#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <list>
#include "Item.h"
#include "OffensiveItem.h"
#include "DeffensiveItem.h"

using namespace std;

class Inventory
{
protected:
	list<Item> Items;
	OffensiveItem* Weapon;
	DeffensiveItem* Armor;
public:
	Inventory();
	Inventory(list<Item> loadedItems, DeffensiveItem* actualArmor, OffensiveItem* actualWeapon);
	
	int EquipWeapon(Item weapon);
	int EquipArmor(Item armor);

	void DropItem(Item item);

	void PickUpItem(Item item);

	string GetCapacity() const;

	int GetItemCount() const;

	string GetCurrentSize() const;

	void ShowInventory();

	Item* GetItem(int index);

	int GetWeaponAttack();

	int GetArmorDeffense();
};

#endif