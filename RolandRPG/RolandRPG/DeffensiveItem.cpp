#include "DeffensiveItem.h"

DeffensiveItem::DeffensiveItem(int id, std::string name, int itemLvl) : Item(id, name, itemLvl, Deffensive)
{
	srand(time(nullptr));
	Deffense = ItemLvl*(rand() % 4 + 1);
}


