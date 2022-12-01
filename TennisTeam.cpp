#include "TennisTeam.h"

using std::cout; using std::endl;

TennisTeam::TennisTeam(){

}

void TennisTeam::selectPlayer(std::vector<int>& pool){
	players.push_back(pool[pool.size() - 1]);
	pool.pop_back();
	std::sort(std::begin(players), std::end(players));
}

void TennisTeam::displayTeam(){
	cout << "{ ";
	for(size_t i{0}; i < players.size(); ++i){
		if(i > 0){
			cout << ", ";
		}
		cout << players[i];
	}
	cout << " }";

}

int TennisTeam::getPlayer(int playerIndex){
	return players[playerIndex];
}
