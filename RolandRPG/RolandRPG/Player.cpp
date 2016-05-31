#include "Player.h"
#include <string>
#include <algorithm>

using namespace std;

int factorial(int n);

void Player::GainXp(int gainedXp)
{
	while (gainedXp > 0)
	{
		int remainingXp = GetNextLevelXp() - Xp;
		if (remainingXp <= gainedXp)
		{
			Xp = Xp + remainingXp;
			Level++;
			cout << "\nI feel myself stronger!";
			// call level up
			gainedXp = gainedXp -remainingXp;
		}
		else
		{
			Xp = Xp + gainedXp;
		}
	}
}

Player::Player(string name)
{
	Name = name;
	Hp = 100;
	Level = 1;
	AttackPower = 10;
	Xp = 0;
	
	cout << "\n\nWelcome! " << "I am " << Name << ". I am your new character!\n";
	PlayersInventory = new Inventory();
}

Player::Player(string name, int hp): Xp(0), PlayersInventory(nullptr)
{
	Name = name;
	Hp = hp;
	cout << "\n\nWelcome! " << "I am " << Name << ". Nice to meet you again!\n";
}

Player::~Player()
{
}

void Player::OpenInvetory()
{
	while (true)
	{
		system("cls");
		PlayersInventory->ShowInventory();

		cout << "\n\nType the number of the item that you want to use or press 0 to exit!\n";

		string input;
		cin >> input;
		if (std::all_of(input.begin(), input.end(), ::isdigit))
		{
			int decision = atoi(input.c_str());
			if (decision == 0)
				return;
			if (decision <= PlayersInventory->GetItemCount())
			{
				Item* item;
				item = PlayersInventory->GetItem(decision);
				item->ItemType == Deffensive ? PlayersInventory->EquipArmor(*item) : PlayersInventory->EquipWeapon(*item);
			}
			else
				cout << "\nI can't do that!\n";
		}
		else
			cout << "\nI can't do that!\n";

		system("pause");
	}
}

void Player::Attack(Character* enemy)
{
	if (enemy->GetHp() <= 0 )
	{
		cout << "\nI can't found any enemy!";
		return;
	}

	enemy->GetDamaged(AttackPower + PlayersInventory->GetWeaponAttack());
	if (enemy->GetHp() <= 0)
	{
		int gainedXp = factorial(enemy->GetLevel()) * 20;
		GainXp(Xp + gainedXp);
		cout << "\nI killed " << enemy->GetName() << " and gained " << gainedXp << " Xp";
		delete enemy;
	}

}

int Player::GetXp()
{
	return Xp;
}

string Player::GetXpStatus()
{
	return "Level: " + to_string(Level) + "  " + to_string(GetXp()) + "/" + to_string(GetNextLevelXp()) + " Xp";
}

string Player::StatusBar()
{
	return "Player " + Name + " Hp : " + to_string(Hp) + "   " + GetXpStatus() + "   Attack power: " + to_string(AttackPower + PlayersInventory->GetWeaponAttack()) + "   Deffense: " + to_string(PlayersInventory->GetArmorDeffense());
}

void Player::PickUpItem(Item* item)
{
	PlayersInventory->PickUpItem(*item);
}

int Player::GetNextLevelXp()
{
	return factorial(Level) * 100;
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
