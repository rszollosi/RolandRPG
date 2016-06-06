#include "Combat.h"


Combat::Combat(Player* player, Npc* opponent)
{
	system("cls");
	while(true)
	{
		if (opponent->GetHp() <= 0) {
			player->RefressPlayer();
			return;
		}
		if (player->GetHp() <= 0)
			return;
		cout << player->StatusBar() + "\n\n";
		cout << opponent->StatusBar() + "\n\n\n";
		cout << "1 to attack, 2 to deffend, 3 to use heal potion and 0 to exit combat!\n";
		string input;
		int decision;
		cin >> input;
		if (all_of(input.begin(), input.end(), ::isdigit))
		{
			decision = atoi(input.c_str());
			switch (decision)
			{
			case 0:
				return;
			case 1:
				srand(time(nullptr));
				if (rand() % 2 == 0)
					opponent->SetStance(Deffending);

				player->Attack(opponent);

				if (opponent->GetHp() <= 0)
				{
					player->RefressPlayer();
					return;
				}
				opponent->Attack(player);
				break;
			case 2:
				player->SetStance(Deffending);
				opponent->Attack(player);
				break;
			case 3:
				player->UseHealthPotion();
				break;
			default:
				cout << "\nI can't do that!";
			}
		}
		else
			cout << "\nI can't do that!";
		system("pause");
		system("cls");
	}
}
