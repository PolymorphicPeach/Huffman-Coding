#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class TennisTeam{
private:
	std::vector <int> players;

public:
	TennisTeam();

	void selectPlayer(std::vector<int>& pool);

	void displayTeam();
	int getPlayer(int playerIndex);

};

