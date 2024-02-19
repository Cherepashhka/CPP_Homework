#pragma once

class Building
{
public:
	Building(int _maxage, int _initialcost);
	~Building() = default;
	int GetCost();
	void ToAge(int years);
	void Destroy();
private:
	static int NextID;
	int maxage, initialcost, id;
};