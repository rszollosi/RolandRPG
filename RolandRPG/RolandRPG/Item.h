#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <ctime>

enum Type
{
	Deffensive,
	Offensive,
	Potion
};

class Item 
{
public:
	Item();
	void SetPropertiesForDeffensiveItem(int itemLvl);
	void SetPropertiesForOffensiveItem(int itemLvl);
	Item(int itemLvl, Type itemType);
	Item(int id, std::string name, int itemLvl, Type itemType);

	std::string Name;
	int ItemLvl;
	int Id;
	Type ItemType;
};

inline bool operator==(Item& lhs, Item rhs) {
	if (lhs.Name == rhs.Name && lhs.Id == rhs.Id && lhs.ItemLvl == rhs.ItemLvl && lhs.ItemType == rhs.ItemType)
		return true;
	return false;
}
#endif