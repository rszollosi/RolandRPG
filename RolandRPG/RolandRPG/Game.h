#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
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
	Game(deque<string> loadedState);
	~Game();
	string static load();
	void save();
};

#endif
