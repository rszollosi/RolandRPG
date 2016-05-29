#include "OffensiveItem.h"
OffensiveItem::OffensiveItem(int id, std::string name, int itemLvl): Item(id, name, itemLvl, Offensive)
{
	Attack = ItemLvl * (rand() % 2 + 1);
}

