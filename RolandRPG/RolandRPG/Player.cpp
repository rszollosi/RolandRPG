#include "Player.h"


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

Inventory* Player::OpenInvetory() const
{
	return PlayersInventory;
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
	return "Hp : " + to_string(Hp) + "   " + GetXpStatus() + "   Attack power: " + to_string(AttackPower + PlayersInventory->GetWeaponAttack()) + "   Deffense: " + to_string(PlayersInventory->GetArmorDeffense());
}

int Player::GetNextLevelXp()
{
	return factorial(Level) * 100;
}

int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
