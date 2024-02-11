#include <iostream>
using namespace std;

int main() {
	string name;
	int healthpoints, classid;
	enum AllClasses
	{
		Mage = 1,
		Warrior = 2
	};
	AllClasses playerclass;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your health points: ";
	cin >> healthpoints;
	cout << "Enter your class (1 - Mage, 2 - Warrior): ";
	cin >> classid;
	switch (classid) 
	{
	      case 1: 
	      {
			  playerclass = Mage;
		      break;
	      }
	      case 2: 
	      {
			  playerclass = Warrior;
		      break;
	      }
	      default: 
	      {
		      cout << "Not following the rules, huh? You'll be a warrior then!" << endl;
			  playerclass = Warrior;
		      break;
	      }
	}
	while (healthpoints > 0)
	{
		cout << endl;
		cout << name << ", your health is " << healthpoints << endl;
		int damage;
		cout << "Enter damage from enemy: ";
		cin >> damage;
        if (playerclass == Mage && damage % 2 == 0) 
		{
			healthpoints -= damage * 2;
		}
		else if (playerclass == Warrior)
		{
		    if (damage % 2 == 1) 
			{
				healthpoints -= damage * 3;
			}
		}
		else 
		{
			healthpoints -= damage;
		}
	}
	cout << endl;
	cout << "Your hero died!" << endl;
}