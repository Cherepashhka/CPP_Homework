#include <iostream>
#include <vector>
using namespace std;

class NameChangeTeller 
{
public:
	virtual void NameChange(string* newname) = 0;
};

class NameSender 
{
	virtual void Observe(NameChangeTeller*) = 0;
	virtual void CancelObserve(NameChangeTeller*) = 0;
	virtual void ApplyNewName(string* newname) = 0;
};

class Character : public NameSender
{
public:
    Character(string init_name) 
	{
		char_name = init_name;
	}

	virtual void Observe(NameChangeTeller* observer) override
	{
		Observers.push_back(observer);
	}

	virtual void CancelObserve(NameChangeTeller* observer) override
	{
		Observers.erase(find(Observers.begin(), Observers.end(), observer));
	}

	virtual void ApplyNewName(string* newname) override
	{
		char_name = *newname;
		for (NameChangeTeller* Teller : Observers) 
		{
		    if (Teller) 
			{
				Teller->NameChange(newname);
			}
		}
	}

private:
	string char_name;
	vector <NameChangeTeller*> Observers;
};

class ServerNameChangeLog : public NameChangeTeller 
{
	virtual void NameChange(string* newname) override
	{
		cout << "Server: Name has changed, it's " << *newname << " now." << endl;
	}
};

class ClientNameChangeLog : public NameChangeTeller
{
	virtual void NameChange(string* newname) override
	{
		cout << "Successfully changed name to " << *newname << endl;
	}
};

void ChangeName(Character& m_char, string& cin_name) 
{
	cout << "Enter new name: ";
	cin >> cin_name;
	m_char.ApplyNewName(&cin_name);
}

int main() 
{
	Character mainCharacter("Sam");
	ServerNameChangeLog log1;
	ClientNameChangeLog log2;
	string cin_name;

	mainCharacter.Observe(&log1);
	mainCharacter.Observe(&log2);
	ChangeName(mainCharacter, cin_name);

	mainCharacter.CancelObserve(&log1);
	ChangeName(mainCharacter, cin_name);

	mainCharacter.Observe(&log1);
	mainCharacter.CancelObserve(&log2);
	ChangeName(mainCharacter, cin_name);
}