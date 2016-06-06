#include "Item.h"

Item::Item()
{
	Id = 0;
	Name = "";
	ItemLvl = 0;
	ItemType = Potion;
}

void Item::SetPropertiesForDeffensiveItem(int itemLvl)
{
	Id = 1;
	ItemLvl = itemLvl;
	ItemType = Deffensive;
	switch(itemLvl)
	{
	case 1: 
		Name = "Wooden Shiled";
		break;
	case 2:
		Name = "Copper Shiled";
		break;
	case 3:
		Name = "Bronze Shiled";
		break;
	case 4:
		Name = "Iron Shiled";
		break;
	case 5:
		Name = "Steel Shiled";
		break;	
	default:
		Name = "Adamantium Shield";
	}
}

void Item::SetPropertiesForOffensiveItem(int itemLvl)
{
	Id = 1;
	ItemLvl = itemLvl;
	ItemType = Offensive;
	switch (itemLvl)
	{
	case 1:
		Name = "Wooden Sword";
		break;
	case 2:
		Name = "Copper Sword";
		break;
	case 3:
		Name = "Bronze Sword";
		break;
	case 4:
		Name = "Iron Sword";
		break;
	case 5:
		Name = "Steel Sword";
		break;
	default:
		Name = "Adamantium Sword";
	}
}

Item::Item(int itemLvl, Type itemType)
{
	switch(itemType)
	{
	case Potion:
		Id = 0;
		Name = "Potion";
		ItemLvl = 1;
		ItemType = Potion;
		break;
	case Deffensive:
		SetPropertiesForDeffensiveItem(itemLvl);
		break;
	case Offensive:
		SetPropertiesForOffensiveItem(itemLvl);
	}
}

Item::Item(int id, std::string name, int itemLvl, Type itemType)
{
	Id = id;
	Name = name;
	ItemLvl = itemLvl;
	ItemType = itemType;
}

