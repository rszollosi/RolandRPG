#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <list>
#include "Item.h"

using namespace std;

enum CharacterStance
{
	Attacking,
	Deffending,
	Neutral
};

const int MaxLevel = 5;

class Character
{
protected:
	int Hp;
	int MaxHp;
	int AttackPower;
	string Name;
	int Level;
	CharacterStance characterStance;

public:
	Character();
	virtual ~Character();

	string GetName() const;
	int GetHp() const;
	virtual int GetMaxHp() const;
	virtual void Attack(Character* enemy);
	void GetDamaged(int attackPower);
	int GetLevel() const;
	virtual string StatusBar();
	virtual list<Item> GetLoot() const;

	CharacterStance GetStance() const;
	void SetStance(CharacterStance stance);
};

#endif
