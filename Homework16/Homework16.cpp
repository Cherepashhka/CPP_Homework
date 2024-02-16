#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct PlayerInfo 
{
	vector <string> playernames;
	vector <float> playerpowers;
};
map <string, PlayerInfo> Clans;

int GetPlayerCount (const string& ClanName);
int ClanFight(const string& FirstClanName, const string& SecondClanName);

int main() 
{
	int forfirstfunc, forsecondfunc;
	string clanname, playername, cname1, cname2;
	float playerpower;
	while (true) 
	{
	    cout << "Enter clan name (if clan already exists, new player will be added to this clan): ";
	    cin >> clanname;
	    cout << "Enter player name: ";
	    cin >> playername;
	    cout << "Enter player's power: ";
	    cin >> playerpower;
	    if (Clans.find(clanname) == Clans.end()) 
	    {
		    Clans.insert({ clanname, PlayerInfo() });
	    }
	    Clans[clanname].playernames.push_back(playername);
	    Clans[clanname].playerpowers.push_back(playerpower);
	    cout << "Want to continue creating players and clans? (1 - yes, other numbers - no) ";
	    cin >> playerpower;
		if (playerpower == 1) 
		{
			cout << endl;
		}
		else 
		{
			break;
		}
	}
	cout << endl << "Enter clan name for player count: ";
	cin >> clanname;
	forfirstfunc = GetPlayerCount(clanname);
	cout << clanname << " - " << forfirstfunc << " players" << endl << endl;
	cout << "Enter name of first clan that will fight: ";
	cin >> cname1;
	cout << "Enter name of second clan that will fight: ";
	cin >> cname2;
	forsecondfunc = ClanFight(cname1, cname2);
	cout << forsecondfunc << endl;
}

int GetPlayerCount(const string& ClanName) 
{
	return Clans[ClanName].playernames.size();
};

int ClanFight(const string& FirstClanName, const string& SecondClanName) 
{
	float finpower1 = 0, finpower2 = 0;
	for (float a : Clans[FirstClanName].playerpowers) 
	{
		finpower1 += a;
	}
	for (float a : Clans[SecondClanName].playerpowers) 
	{
		finpower2 += a;
	}
	if (finpower1 > finpower2) 
	{
		return 1;
	}
	else if (finpower2 > finpower1)
	{
		return -1;
	}
	else 
	{
		return 0;
	}
};