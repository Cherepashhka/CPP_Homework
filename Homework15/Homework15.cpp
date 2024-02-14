#include <iostream>
#include <vector>
using namespace std;

enum Classes
{
	Warrior,
	Gunman,
	Summoner
};
struct PlayerX
{
	int id;
	Classes PlayerClass;
	float meleeatk;
	float rangedatk;
};
int StrongestCharSearch(const vector <PlayerX>& PlayerVect);

int main() 
{
	PlayerX Player;
	int choice, numberofcharacters = 1, finalid;
	float atkvalue;
	vector <PlayerX> PlayerVector;
	while (true) 
	{
		Player.id = numberofcharacters;
		cout << endl;
		cout << "Collecting info for character number " << numberofcharacters << endl;
		while (true) 
		{
			cout << "Pick a class for character: 1 - Warrior, 2 - Gunman, 3 - Summoner" << endl;
			cout << "Enter the number that matches the class: ";
			cin >> choice;
			if (choice < 4 && choice > 0)
			{
				Player.PlayerClass = Classes(choice - 1);
				break;
			}
			else 
			{
				cout << "This number does not match any class!" << endl;
			}
		}
		cout << "Enter the strength of the character's melee attack: ";
		cin >> atkvalue;
		Player.meleeatk = atkvalue;
		cout << "Enter the strength of the character's ranged attack: ";
		cin >> atkvalue;
		Player.rangedatk = atkvalue;
		PlayerVector.push_back(Player);
		while (true) 
		{
			cout << endl << "Do you want to create another character? (1 - yes, 2 - no) ";
			cin >> choice;
			if (choice == 1)
			{
				numberofcharacters++;
				break;
			}
			else if (choice == 2)
			{
				choice = -1;
				break;
			}
			else 
			{
				cout << "Wrong number!" << endl;
			}
		}
		if (choice == -1) 
		{
			break;
		}
	}
	finalid = StrongestCharSearch(PlayerVector);
	cout << endl << "Strongest character ID: " << finalid << endl;
	switch (PlayerVector[finalid - 1].PlayerClass) 
	{
	    case Warrior:
		    cout << "His class: Warrior" << endl;
		    break;
	    case Gunman:
		    cout << "His class: Gunman" << endl;
		    break;
	    case Summoner:
		    cout << "His class: Summoner" << endl;
		    break;
	}
	cout << "His total strength: " << PlayerVector[finalid - 1].meleeatk + PlayerVector[finalid - 1].rangedatk << endl;
}

int StrongestCharSearch(const vector <PlayerX>& PlayerVect) 
{
	int maxpower = INT_MIN, thatid;
	for (int i = 0; i < PlayerVect.size(); i++) 
	{
		if (PlayerVect[i].meleeatk + PlayerVect[i].rangedatk > maxpower) 
		{
			maxpower = PlayerVect[i].meleeatk + PlayerVect[i].rangedatk;
			thatid = i+1;
		}
	}
	return thatid;
};