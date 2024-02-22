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
	void SetWeapon(Weapon* weapon) 
	{
		myWeapon = weapon;
	}
	Weapon* GetWeapon() const
	{
		return myWeapon;
	}
private:
	Weapon* myWeapon;
};

int main() 
{
	Character MainCharacter;
	Weapon* weap;
	int choice;
	cout << "Enter type of weapon:\n1. Sword\n2. Bow\n3. Staff\n4. Gun\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		weap = new Sword;
		break;
	case 2:
		weap = new Bow;
		break;
	case 3:
		weap = new Staff;
		break;
	case 4:
		weap = new Gun;
		break;
	default:
		weap = new Sword;
		break;
	}
	MainCharacter.SetWeapon(weap);
	cout << "Weapon name: " << MainCharacter.GetWeapon()->GetName() << endl;
	cout << "Damage: " << MainCharacter.GetWeapon()->GetDamage() << endl;
	delete weap;
}