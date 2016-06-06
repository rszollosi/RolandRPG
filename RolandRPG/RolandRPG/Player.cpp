#include "Player.h"


using namespace std;

int fibonacci(int n);

void Player::GainXp(int gainedXp)
{
	while (gainedXp > 0 && Level < MaxLevel)
	{
		int remainingXp = GetNextLevelXp() - Xp;
		if (remainingXp <= gainedXp)
		{
			Xp = 0;
			Level++;
			cout << "\nI feel myself stronger! I reached level: " + to_string(Level);
			LevelUp();
			RefressPlayer();
			gainedXp = gainedXp -remainingXp;
		}
		else
		{
			Xp = Xp + gainedXp;
			gainedXp = 0;
		}
	}
}

Player::Player(string name)
{
	Name = name;
	Hp = 100;
	MaxHp = Hp;
	Level = 1;
	AttackPower = 10;
	Xp = 0;
	healthPotions = 4;
	
	cout << "\n\nWelcome! " << "I am " << Name << ". I am your new character!\n";
	PlayersInventory = new Inventory();
}

Player::Player(string name, int hp): Xp(0), PlayersInventory(new Inventory()), healthPotions(0)
{
	Name = name;
	Hp = hp;
	cout << "\n\nWelcome! " << "I am " << Name << ". Nice to meet you again!\n";
}

Player::~Player()
{
	system("cls");
	cout << "Argh.. It was a pleasure to play with you...\n\n";
	system("pause");
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
			{
				Hp = GetMaxHp();
				return;
			}
			if (0 < decision && decision <= PlayersInventory->GetItemCount() )
			{
				PlayersInventory->SelectItem(decision);
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
	SetStance(Attacking);
	if (enemy->GetHp() <= 0 )
	{
		cout << "\nI can't found any enemy!";
		return;
	}

	enemy->GetDamaged(AttackPower + PlayersInventory->GetWeaponAttack());
	if (enemy->GetHp() <= 0)
	{
		int gainedXp = fibonacci(enemy->GetLevel()) * 50;
		cout << "\nI killed " << enemy->GetName() << " and gained " << gainedXp << " Xp";
		auto gainedLoot =enemy->GetLoot();
		delete enemy;

		GainXp(gainedXp);
		CheckLoot(gainedLoot);
	}
}

int Player::GetMaxHp() const
{
	return MaxHp + PlayersInventory->GetArmorDeffense();
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
	return "Player " + Name + " Hp : " + to_string(GetMaxHp()) + "/" + to_string(Hp) + "   " + GetXpStatus() + "   Attack power: " + to_string(AttackPower + PlayersInventory->GetWeaponAttack()) + "   Deffense: " + to_string(PlayersInventory->GetArmorDeffense()) + "   Health potions: " + to_string(healthPotions);
}

void Player::PickUpItem(Item* item)
{
	if (item->ItemType == Potion)
	{
		healthPotions++;
		return;
	}
	PlayersInventory->PickUpItem(*item);
}

void Player::UseHealthPotion()
{
	if (healthPotions == 0)
	{
		cout << "\nI don't have any potion!\n";
		return;
	}

	int restoredHp = GetMaxHp()*0.1;

	Hp = Hp + restoredHp;

	cout << "\nI used a helath potion and it restored " + to_string(restoredHp) + " amount of health point!\n";
	
	if (Hp > MaxHp)
		Hp = MaxHp;

	healthPotions--;
}

void Player::RefressPlayer()
{
	Hp = GetMaxHp();
}

void Player::LevelUp()
{
	string input;
	while (true) {
		cout << "\nChose one: 1 more Hp, 2 more attack\n";
		cin >> input;
		if (input == "1")
		{
			MaxHp = MaxHp + 10;
			return;
		}
		if (input == "2")
		{
			AttackPower = AttackPower + 1;
			return;
		}
		cout << "I can't do that!";
	}
}

void Player::CheckLoot(list<Item> loot)
{
	cout << "\nI gained some loot";
	auto healthPotionCount = 0;
	Item* gainedItem = nullptr;
	for (auto it = loot.begin(); it != loot.end(); ++it)
	{
		if (it->ItemType == Potion) {
			healthPotionCount++;
			healthPotions++;
		}
		else
		{
			gainedItem = &*it;
		}
	}
	if (gainedItem != nullptr)
		cout << "\nI found " + to_string(healthPotionCount) + " health potion and a(n) " + gainedItem->Name;
	else
	{
		cout << "\nI found " + to_string(healthPotionCount) + " health potion";
		system("pause");
		return;
	}
	cout << "\nWould you like to keep it?";
	string input;
	while (true) {
		cout << "\nChose one: 1 keep it, 2 dropp it\n";
		cin >> input;
		if (input == "1")
		{
			PlayersInventory->PickUpItem(*gainedItem);
			return;
		}
		if (input == "2")
		{
			cout << "\nI dropped the item\n";
			return;
		}

		cout << "\nI can't do that";
		system("pause");
	}
}

int Player::GetNextLevelXp() const
{
	return fibonacci(Level) * 100;
}

int fibonacci(int n)
{
	return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}
