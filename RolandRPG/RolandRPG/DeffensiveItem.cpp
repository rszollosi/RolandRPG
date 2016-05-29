#include "DeffensiveItem.h"
DeffensiveItem::DeffensiveItem(int id, std::string name, int itemLvl) : Item(id, name, itemLvl, Deffensive)
{
	Deffense = ItemLvl*(rand() % 4 + 1);
}


