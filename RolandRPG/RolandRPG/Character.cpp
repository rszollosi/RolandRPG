
#include "Character.h"
#include <ctime>

using namespace std;

Character::Character()
{
	characterStance = Neutral;
}

Character::~Character()
{
	cout << "\n\nargh... It was a pleasure to fight with you! argh...\n";
}

string Character::GetName() const
{
	return Name;
}


int Character::GetHp() const
{
	return Hp;
}

int Character::GetMaxHp() const
{
	return MaxHp;
}

void Character::Attack(Character* enemy)
{
	SetStance(Attacking);
	enemy->GetDamaged(AttackPower);
	if (enemy->GetHp() <= 0)
		delete enemy;
}


void Character::GetDamaged(int attackPower)
{
	switch (characterStance)
	{
	case Neutral:
		Hp = Hp - attackPower;
		cout << "\n" << Name << " got " << attackPower << " amount of damage!\n";
		break;
	case Deffending:
		Hp = Hp - attackPower / 2;
		cout << "\n" << Name << " blocked the half of " << attackPower << " damage!\n";
		SetStance(Neutral);
		break;
	case Attacking:
		Hp = Hp - attackPower * 1.5;
		cout << "\n" << Name << " was to agressive and got " << attackPower * 1.5 << " amount of damage!\n";
		SetStance(Neutral);
	}
}

int Character::GetLevel() const
{	
	return Level;
}

string Character::StatusBar()
{
	return "";
}

list<Item> Character::GetLoot() const
{
	return {};
}

CharacterStance Character::GetStance() const
{
	return characterStance;
}

void Character::SetStance(CharacterStance stance)
{
	characterStance = stance;
}
