#ifndef NPC_H
#define NPC_H

#include "Character.h"

using namespace std;

class Npc : public Character
{
public:
	Npc(string name, int lvl, int hp, int attack);
	~Npc();
};

#endif
