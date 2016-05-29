#ifndef OFFENSIVEITEM_H
#define OFFENSIVEITEM_H
#include "Item.h"

class OffensiveItem : public Item
{
public:
	OffensiveItem(int id, std::string name, int itemLvl);

	int Attack;
};

#endif