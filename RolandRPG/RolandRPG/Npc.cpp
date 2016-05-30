#include "Npc.h"

Npc::Npc(string name, int lvl, int hp, int attack) : Character()
{
	Name = name;
	Level = lvl;
	Hp = hp;
	AttackPower = attack;
}

Npc::~Npc()
{
}
