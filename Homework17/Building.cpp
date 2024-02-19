#include "Building.h"
#include <iostream>
using namespace std;

int Building::NextID = 1;
Building::Building(int _maxage, int _initialcost)
	: maxage(_maxage), initialcost(_initialcost), id(NextID)
{
	++NextID;
}
int Building::GetCost()
{
	return initialcost;
}
void Building::ToAge(int years)
{
	cout << "Successfully applied!" << endl;
	initialcost -= initialcost * (years * 1.0f / maxage);
	maxage -= years;
	if (initialcost <= 0) 
	{
		initialcost = 0;
		Destroy();
	}
}
void Building::Destroy()
{
	cout << "\n--- The building with ID " << id << " has been destroyed! ---\n---           Try to make another one!         ---\n\n";
}


