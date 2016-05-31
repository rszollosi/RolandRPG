#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character
{
protected:
	int Hp;
	int AttackPower;
	string Name;
	int Level;

public:
	Character();
	virtual ~Character();

	string GetName();
	int GetHp();
	virtual void Attack(Character* enemy);
	void GetDamaged(int attackPower);
	int GetLevel();
	virtual string StatusBar();
};

#endif
