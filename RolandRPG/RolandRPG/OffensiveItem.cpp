#include "OffensiveItem.h"
OffensiveItem::OffensiveItem(int id, std::string name, int itemLvl): Item(id, name, itemLvl, Offensive)
{
	srand(time(nullptr));
	Attack = ItemLvl * (rand() % 2 + 1);
}

