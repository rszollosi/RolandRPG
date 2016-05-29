#include "Item.h"

Item::Item()
{
	Id = 0;
	Name = "";
	ItemLvl = 0;
}

Item::Item(int id, std::string name, int itemLvl, Type itemType)
{
	Id = id;
	Name = name;
	ItemLvl = itemLvl;
	ItemType = itemType;
}

