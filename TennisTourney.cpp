#include "TennisTourney.h"

using std::cout; using std::cin; using std::endl;


void TennisTourney::selectionPhase(int round1Sequence, int round2Sequence, int round3Sequence){
	switch(round1Sequence){
	case 1:
		sequence1_ABG();
		break;

	case 2:
		sequence2_BGA();
		break;

	case 3:
		sequence3_GAB();
		break;

	default:
		cout << "Error: invalid sequence selection." << endl;
	}

	switch(round2Sequence){
	case 1:
		sequence1_ABG();
		break;

	case 2:
		sequence2_BGA();
		break;

	case 3:
		sequence3_GAB();
		break;

	default:
		cout << "Error: invalid sequence selection." << endl;
	}

	switch(round3Sequence){
	case 1:
		sequence1_ABG();
		break;

	case 2:
		sequence2_BGA();
		break;

	case 3:
		sequence3_GAB();
		break;

	default:
		cout << "Error: invalid sequence selection." << endl;
	}
	
}

void TennisTourney::sequence1_ABG(){
	alpha->selectPlayer(playerPool);
	beta->selectPlayer(playerPool);
	gamma->selectPlayer(playerPool);
}

void TennisTourney::sequence2_BGA(){
	beta->selectPlayer(playerPool);
	gamma->selectPlayer(playerPool);
	alpha->selectPlayer(playerPool);
}

void TennisTourney::sequence3_GAB(){
	gamma->selectPlayer(playerPool);
	alpha->selectPlayer(playerPool);
	beta->selectPlayer(playerPool);
}

void TennisTourney::alphaVsBeta(){

	int alphaWins{0};
	int betaWins{0};

	for(int i{0}; i < 3; ++i){
		for(int j{0}; j < 3; ++j){

			if(alpha->getPlayer(i) < beta->getPlayer(j)){
				++alphaWins;
			}
			else{
				++betaWins;
			}
		}
	}

	if(alphaWins > betaWins){
		alphaBeatsBeta = true;
	}
	else{
		alphaBeatsBeta = false;
	}
}

void TennisTourney::betaVsGamma(){
	int betaWins{0};
	int gammaWins{0};

	for(int i{0}; i < 3; ++i){
		for(int j{0}; j < 3; ++j){
			if(beta->getPlayer(i) < gamma->getPlayer(j)){
				++betaWins;
			}
			else{
				++gammaWins;
			}
		}
	}

	if(betaWins > gammaWins){
		betaBeatsGamma = true;
	}
	else{
		betaBeatsGamma = false;
	}

}

void TennisTourney::gammaVsAlpha(){
	int gammaWins{0};
	int alphaWins{0};

	for(int i{0}; i < 3; ++i){
		for(int j{0}; j < 3; ++j){
			if(gamma->getPlayer(i) < alpha->getPlayer(j)){
				++gammaWins;
			}
			else{
				++alphaWins;
			}
		}
	}

	if(gammaWins > alphaWins){
		gammaBeatsAlpha = true;
	}
	else{
		gammaBeatsAlpha = false;
	}
}

void TennisTourney::displayOutcome(){
	cout << "Alpha ";
	alpha->displayTeam();

	cout << ", Beta";
	beta->displayTeam();

	cout << ", Gamma";
	gamma->displayTeam();


	cout << endl << "Alpha beats Beta: ";
	if(alphaBeatsBeta){
		cout << "True";
	}
	else{
		cout << "False";
	}
	cout << endl;

	cout << "Beta beats Gamma: ";
	if(betaBeatsGamma){
		cout << "True";
	}
	else{
		cout << "False";
	}
	cout << endl;

	cout << "Gamma beats Alpha: ";
	if(gammaBeatsAlpha){
		cout << "True";
	}
	else{
		cout << "False";
	}
	cout << endl;
}

TennisTourney::TennisTourney(int numPlayers, bool uniqueRank) : numPlayers(numPlayers), 
					alphaBeatsBeta(false), betaBeatsGamma(false), gammaBeatsAlpha(false)
{
	for(int i{1}; i <= numPlayers; ++i){

		if(uniqueRank){
			playerPool.push_back(i);
		}
		else{
			playerPool.push_back(rand() % 9);
		}
	}

	// Let's rational team captians just use pop_back to get their player
	std::sort(std::begin(playerPool), std::end(playerPool), std::greater<int>());

	alpha = new TennisTeam();
	beta = new TennisTeam();
	gamma = new TennisTeam();
}

TennisTourney::~TennisTourney(){
	delete alpha;
	alpha = nullptr;

	delete beta;
	beta = nullptr;
	
	delete gamma;
	gamma = nullptr;
}

void TennisTourney::startTourney(){
	alphaVsBeta();
	betaVsGamma();
	gammaVsAlpha();

}

void TennisTourney::displayEveryCombo(){

	cout << "==========================================" << endl
		 << "Selection Order: ABG, BGA, GAB" << endl
	     << "------------------------------------------" << endl;
	selectionPhase(1, 2, 3);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();



	cout << "==========================================" << endl
		 << "Selection Order: ABG, GAB, BGA" << endl
		 << "------------------------------------------" << endl;
	selectionPhase(1, 3, 2);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();



	cout << "==========================================" << endl
		 << "Selection Order: BGA, ABG, GAB" << endl
		 << "------------------------------------------" << endl;
	selectionPhase(2, 1, 3);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();



	cout << "==========================================" << endl
		 << "Selection Order: BGA, GAB, ABG" << endl
		 << "------------------------------------------" << endl;
	selectionPhase(2, 3, 1);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();


	cout << "==========================================" << endl
		 << "Selection Order: GAB, ABG, BGA" << endl
		 << "------------------------------------------" << endl;
	selectionPhase(3, 1, 2);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();


	cout << "==========================================" << endl
		 << "Selection Order: GAB, BGA, ABG" << endl
		 << "------------------------------------------" << endl;
	selectionPhase(3, 2, 1);
	startTourney();
	displayOutcome();
	cout << "------------------------------------------" << endl;
	resetTourney();
}

void TennisTourney::resetTourney(){
	delete alpha;
	alpha = nullptr;
	alpha = new TennisTeam();

	delete beta;
	beta = nullptr;
	beta = new TennisTeam();

	delete gamma;
	gamma = nullptr;
	gamma = new TennisTeam();

	playerPool.clear();
	playerPool = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	alphaBeatsBeta = false;
	betaBeatsGamma = false;
	gammaBeatsAlpha = false;
}
