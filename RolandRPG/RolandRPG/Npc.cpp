#include "Npc.h"

Npc::Npc(string name, int lvl)
{
	Name = name;
	Level = lvl >= MaxLevel ? MaxLevel : lvl;
	Hp = 50 + (Level - 1) * 20;
	AttackPower = 5 + (Level - 1) * 2;
}

Npc::Npc(string name, int lvl, int hp, int attack) : Character()
{
	Name = name;
	Level = lvl >= MaxLevel ? MaxLevel : lvl;
	Hp = hp;
	MaxHp = Hp;
	AttackPower = attack;
}

list<Item> Npc::GetLoot() const
{
	auto drop = new list<Item>();

	int counter;

	for (counter = 1; counter < Level; counter++)
		drop->push_back(*new Item(Level, Potion));

	srand(time(nullptr));
	drop->push_back(*new Item(Level, rand()%2 == 0 ? Deffensive : Offensive));

	return *drop;
}

string Npc::StatusBar()
{
	return "Its a(n) " + Name + " Level: " + to_string(Level)+ " Hp : " + to_string(MaxHp) + "/" + to_string(Hp) + +"   Attack power: " + to_string(AttackPower);
}
