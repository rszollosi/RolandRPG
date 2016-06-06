#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <algorithm>
#include "Npc.h"
#include "Player.h"
#include "Combat.h"

using namespace std;

class Game
{
	Player* CurrentPlayer;
	void GameMenu() const;
	static void DisplayMenuOptions();

public:
	Game();
	Game(deque<string> loadedState);
	~Game();
	string static load();
	void save() const;
};

#endif
