#include "Game.h"

using namespace std;

void Game::GameMenu() const
{
	int decision;
	Combat* combat;
	while (CurrentPlayer->GetHp() >0 )
	{
		system("cls");
		cout << CurrentPlayer->StatusBar() + "\n\n";
		DisplayMenuOptions();
		string input;
		cin >> input;
		if (all_of(input.begin(), input.end(), ::isdigit))
		{
			decision = atoi(input.c_str());
			Npc* enemy = new Npc("Troll", 5, 20, 5);
			switch (decision)
			{
			case 0: return;
			case 1: cout << "You asked me to engage something!\n";
				combat = new Combat(CurrentPlayer, enemy);
				break;
			case 2: cout << "\nI will run away!\n";
				break;
			case 3: cout << "\nI will heal myself!\n";
				break;
			case 4: cout << "\nI will turn left!\n";
				break;
			case 6: cout << "\nI will turn right!\n";
				break;
			case 7: cout << "\nGame is saved!\n";
				break;
			case 8: cout << "\nI will go straight on!\n";
				break;
			case 9: CurrentPlayer->OpenInvetory();
				system("cls");
				break;
			default: cout << "\nI can't do that!";
			}
			system("pause");
		}
	}

}

void Game::DisplayMenuOptions()
{
	cout << "What do you want me to do?\n";
	cout << "Type 1 to engage an enemy,\n" 
		<< " 2 to run away,\n" 
		<< " 3 to heal,\n"
		<< " 4 to turn left,\n"
		<< " 6 to turn right,\n"
		<< " 7 to sav the game,\n"
		<< " 8 to go straight,\n"
		<< " 9 to open the inventory\n"
		<< " or 0 to exit the game!\n\n";
}

Game::Game()
{
	system("cls");
	cout << "You started a new game!\n";
	cout << "Please name your character!\n";

	string name;
	cin >> name;

	CurrentPlayer = new Player(name);

	system("pause");

	GameMenu();

}

Game::Game(deque<string> loadedState)
{
	string name;
	string hpAsString;

	name = loadedState.front();
	loadedState.pop_front();
	hpAsString = loadedState.front();
	loadedState.pop_front();
	
	CurrentPlayer = new Player(name, atoi(hpAsString.c_str()));
}

Game::~Game()
{
	cout << "Bye!";
	exit(1);
}


string Game::load()
{
	ifstream gameFile;
	string saveString;

	gameFile.open("game.sav");
	
	getline(gameFile, saveString);

	gameFile.close();

	return saveString;
}

void Game::save() const
{
	ofstream gameFile;
	string saveString;

	saveString = CurrentPlayer->GetName() + ";"
		+ to_string(CurrentPlayer->GetHp());
	
	gameFile.open("game.sav");

	gameFile << saveString;

	gameFile.close();
}
