#include <iostream>
using namespace std;

class Weapon
{
public:
	virtual float GetDamage() = 0;
	virtual string GetName() = 0;
};

class Sword : public Weapon
{
	virtual float GetDamage() override { return 100; }
	virtual string GetName() override { return "Sword"; }
};

class Bow : public Weapon
{
	virtual float GetDamage() override { return 150; }
	virtual string GetName() override { return "Bow"; }
};

class Staff : public Weapon
{
	virtual float GetDamage() override { return 90; }
	virtual string GetName() override { return "Staff"; }
};

class Gun : public Weapon
{
	virtual float GetDamage() override { return 55; }
	virtual string GetName() override { return "Gun"; }
};

class Character
{
public:
	void SetWeapon(unique_ptr<Weapon>& ptr)
	{
		myWeapon = move(ptr);
	}
	void GetWeapon() const
	{
		cout << "\nWeapon name: " << myWeapon->GetName() << endl;
		cout << "Damage: " << myWeapon->GetDamage() << "\n" << endl;
	}
private:
	unique_ptr<Weapon> myWeapon;
};

int main()
{
	unique_ptr<Character> mainCharacter = make_unique<Character>();
	unique_ptr<Weapon> weap;
	int choice;
	while (true)
	{
		cout << "Enter type of weapon:\n1. Sword\n2. Bow\n3. Staff\n4. Gun\n\n5. Quit program\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			weap = make_unique<Sword>();
			break;
		case 2:
			weap = make_unique<Bow>();
			break;
		case 3:
			weap = make_unique<Staff>();
			break;
		case 4:
			weap = make_unique<Gun>();
			break;
		case 5:
			cout << "\nQuitting the program!" << endl;
			break;
		default:
			weap = make_unique<Sword>();
			break;
		}
		if (choice == 5) 
		{
			break;
		}
		mainCharacter->SetWeapon(weap);
		mainCharacter->GetWeapon();
	}
}