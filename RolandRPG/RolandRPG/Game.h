#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Npc.h"
#include "Player.h"

using namespace std;

class Game
{

protected:
	//status
	//actors
	Player* CurrentPlayer;

public:
	Game();
	~Game();
	void save();
};

#endif
