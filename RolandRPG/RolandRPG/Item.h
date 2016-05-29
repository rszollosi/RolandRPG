#ifndef ITEM_H
#define ITEM_H
#include <string>

enum Type
{
	Deffensive,
	Offensive
};

class Item 
{
public:
	Item();
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