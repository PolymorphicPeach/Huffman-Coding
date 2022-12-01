#pragma once

#include "TennisTeam.h"

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

class TennisTourney{
private:
	int numPlayers;

	std::vector <int> playerPool;
	TennisTeam* alpha;
	TennisTeam* beta;
	TennisTeam* gamma;

	void selectionPhase(int round1Sequence, int round2Sequence, int round3Sequence);

	// Selection Sequences: All 3 must be used in selectionPhase, but the order does not matter
	void sequence1_ABG();
	void sequence2_BGA();
	void sequence3_GAB();

	// Gameplay
	void alphaVsBeta();
	void betaVsGamma();
	void gammaVsAlpha();

	// These are the specific scenarios asked about
	bool alphaBeatsBeta;
	bool betaBeatsGamma;
	bool gammaBeatsAlpha;

	void displayOutcome();



public:
	TennisTourney(int numPlayers = 9, bool uniqueRank = true);
	~TennisTourney();
	void startTourney();

	void displayEveryCombo();
	void resetTourney();


};

