#ifndef DEFFENSIVEITEM_H
#define DEFFENSIVEITEM_H
#include "Item.h"

class DeffensiveItem: public Item
{
public:
	DeffensiveItem(int id, std::string name, int itemLvl);

	int Deffense;
};

#endif