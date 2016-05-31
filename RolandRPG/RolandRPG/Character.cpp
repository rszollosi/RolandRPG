
#include "Character.h"
#include <ctime>

using namespace std;

Character::Character()
{
}

Character::~Character()
{
	cout << "\nargh... It was a pleasure to fight with you! argh...";
}

string Character::GetName()
{
	return Name;
}


int Character::GetHp()
{
	return Hp;
}

void Character::Attack(Character* enemy)
{
	enemy->GetDamaged(AttackPower);
	if (enemy->GetHp() <= 0)
		delete enemy;
}


void Character::GetDamaged(int attackPower)
{
	int blocking;
	srand(time(nullptr));
	blocking = rand() % 2;

	if (blocking == 0)
	{
		Hp = Hp - attackPower;
		cout << "\n" << Name <<" got " << attackPower << " amount of damage!";
	}
	else
	{
		Hp = Hp - attackPower / 2;
		cout << "\n" << Name << " blocked the half of " << attackPower << " damage!";
	}
}

int Character::GetLevel()
{	
	return Level;
}

string Character::StatusBar()
{
	return "";
}
