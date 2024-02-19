#include <iostream>
#include "Building.h"
using namespace std;

int main() 
{
	while (true) 
	{
		int age, cost, choice;
		cout << "Enter maximum age of your building: ";
		cin >> age;
		cout << "Enter cost of your building: ";
		cin >> cost;
		Building YourBuilding(age, cost);
		while (YourBuilding.GetCost() != 0) 
		{
			cout << "\nWhat you wanna do?\n 1. Get cost of building\n 2. Age the building.\n 3. Create new building\n ";
			cin >> choice;
			if (choice == 1) 
			{
				cout << "Cost of the building at the moment: " << YourBuilding.GetCost() << endl;
			}
			else if (choice == 2) 
			{
				cout << "Enter amount of years: ";
				cin >> age;
				YourBuilding.ToAge(age);
			}
			else if (choice == 3) 
			{
				break;
			}
			else 
			{
				choice == 0;
			}
		}
	}
}