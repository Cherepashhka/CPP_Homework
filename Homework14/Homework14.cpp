#include <iostream>
using namespace std;

void HighestDamageIndexes(int AllDamage[]);
void LowestDamageIndexes(int AllDamage[]);
void HealingIndexes(int AllDamage[]);
void TotalHealDamageCount(int AllDamage[], const string& choice);
bool IsThereZeroDamage(int AllDamage[]);

int main() 
{
	int AllDamage[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter damage number " << i+1 << " (negative damage = heal): ";
		cin >> AllDamage[i];
	}
	cout << endl;
	HighestDamageIndexes(AllDamage);
	cout << endl;
	LowestDamageIndexes(AllDamage);
	cout << endl;
	HealingIndexes(AllDamage);
	cout << endl;
	string choice;
	cout << "What do you want to know? Total heal or damage? (type 'heal' or 'damage') ";
	cin >> choice;
	TotalHealDamageCount(AllDamage, choice);
	cout << endl;
	if (IsThereZeroDamage(AllDamage)) 
	{
		cout << "There is someone, who did nothing to us." << endl;
	}
	else
	{
		cout << "There is no one, who did nothing to us." << endl;
	}

}

void HighestDamageIndexes(int AllDamage[])
{
	int highestdamage = 0;
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] > highestdamage) 
		{
			highestdamage = AllDamage[i];
		}
	}
	cout << "Highest damage: " << highestdamage << endl;
	cout << "Indexes of highest damage: ";
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] == highestdamage) 
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}

void LowestDamageIndexes(int AllDamage[])
{
	int lowestdamage = INT_MAX;
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] < lowestdamage)
		{
			lowestdamage = AllDamage[i];
		}
	}
	cout << "Lowest damage: " << lowestdamage << endl;
	cout << "Indexes of lowest damage: ";
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] == lowestdamage)
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;
}

void HealingIndexes(int AllDamage[])
{
	int healscount = 0;
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] < 0)
		{
			cout << i + 1 << " ";
			healscount++;
		}
	}
	if (healscount == 0)
	{
		cout << "There was no heals!" << endl;
	}
	else
	{
		cout << "- indexes of heals" << endl;
	}
}

void TotalHealDamageCount(int AllDamage[], const string& choice)
{
	if (choice == "heal")
	{
		int totalheal = 0;
		for (int i = 0; i < 10; i++)
		{
			if (AllDamage[i] < 0) 
			{
				totalheal -= AllDamage[i];
			}
		}
		cout << "Total heal: " << totalheal << endl;
	}
	else if (choice == "damage")
	{
		int totaldamage = 0;
		for (int i = 0; i < 10; i++)
		{
			if (AllDamage[i] > 0)
			{
				totaldamage += AllDamage[i];
			}
		}
		cout << "Total damage: " << totaldamage << endl;
	}
	else
	{
		cout << "Next time type or 'heal' or 'damage'!" << endl;
	}
}

bool IsThereZeroDamage(int AllDamage[])
{
	for (int i = 0; i < 10; i++)
	{
		if (AllDamage[i] == 0) 
		{
			return true;
		}
	}
	return false;
}