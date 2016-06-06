#include "Inventory.h"

using namespace std;

Inventory::Inventory(): Weapon(nullptr), Armor(nullptr)
{
	Items = *new list<Item>();
}

Inventory::Inventory(list<Item> loadedItems, DeffensiveItem* actualArmor, OffensiveItem* actualWeapon)
{
	Items = loadedItems;
	Armor = actualArmor;
	Weapon = actualWeapon;
}

void Inventory::PickUpItem(Item item)
{
	if (Items.size())
		if(Items.size()>=5)
	{
		cout << "\nI can't carry any more items!";

		//Add possibiliti to drop an item
		return;
	}

	Items.push_back(item);
}

void Inventory::DropItem(Item item)
{
	Items.remove(item);
	cout << "\nI dropped " << item.Name;
}

int Inventory::EquipArmor(Item armor)
{
	if (armor.ItemType != Deffensive)
	{
		cout << "ERROR!";
		return 0;
	}
	Armor = new DeffensiveItem(armor.Id, armor.Name, armor.ItemLvl);
	Items.remove(armor);
	return Armor->Deffense;
}

int Inventory::EquipWeapon(Item weapon)
{
	if (weapon.ItemType != Offensive)
	{
		cout << "ERROR!";
		return 0;
	}
	Weapon = new OffensiveItem(weapon.Id, weapon.Name, weapon.ItemLvl);
	Items.remove(weapon);
	return Weapon->Attack;
}

int Inventory::GetItemCount() const
{
	return Items.size();
}

string Inventory::GetCapacity() const
{
	return "Inventory: " + to_string(Items.size()) + " / 5";
}

string Inventory::GetCurrentSize() const
{
	return "There is currently " + to_string(Items.size()) + " item in my inventory!";
}

void Inventory::ShowInventory()
{
	system("cls");
	cout << "----------------------------" << "\n  I N V E N T O R Y" << "\n----------------------------";
	auto counter = 1;
	if (Weapon != nullptr)
		cout << "\nMy curernt Weapon: Name: " << Weapon->Name << " Item level: " << Weapon->ItemLvl << " Damage: " << Weapon->Attack;
	else
		cout << "\nI don't wear any weapon right now!";
	if (Armor != nullptr)
		cout << "\nMy curernt Armor: Name: " << Armor->Name << " Item level: "  << Armor->ItemLvl << " Deffense: " << Armor->Deffense;
	else
		cout << "\nI don't wear any armor right now!";

	if (Items.size() > 0)
	{
		cout << "\n\nThe list of items in my inventory:";
		for (auto it = Items.begin(); it != Items.end(); ++it)
		{
			cout << "\n" << counter << ". Name: " << it->Name << " Item level: " << it->ItemLvl;
			counter++;
		}
	}
	else
		cout << "\n\nI don't have any item in my inventory!";
}

void Inventory::SelectItem(int index)
{
	cout << "\n\nWhat do you want to so with this item?\n";
	cout << "Type 1 to use, 2 to drop it or 0 to cancel the selection\n";
	Item* item;
	item = GetItem(index);
	while (true)
	{
		string input;
		cin >> input;
		if (input == "0")
			return;
		if (input == "1")
		{
			item->ItemType == Deffensive ? EquipArmor(*item) : EquipWeapon(*item);
			return;
		}
		if (input == "2")
		{
			DropItem(*item);
			return;
		}

		cout << "\nI can't do that!";
	}
}

Item* Inventory::GetItem(int index)
{
	auto counter = 1;
	for (auto it = Items.begin(); it != Items.end(); ++it)
	{
		if (counter == index)
		{
			return &*it;
		}
		counter++;
	}
	return nullptr ;
}

int Inventory::GetWeaponAttack() const
{
	return Weapon == nullptr ? 0 : Weapon->Attack;
}

int Inventory::GetArmorDeffense() const
{
	return Armor == nullptr ? 0 : Armor->Deffense;
}


