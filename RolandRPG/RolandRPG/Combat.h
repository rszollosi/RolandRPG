#ifndef  COMBAT_H
#define COMBAT_H

#include <string>
#include <algorithm>
#include "Player.h"
#include "Npc.h"

class Combat
{
public:
	Combat(Player* player, Npc* opponent);
};

#endif
