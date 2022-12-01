#pragma once


#include <iostream>
#include <string>

#include "Circle.h"
#include "TennisTourney.h"
#include "HuffmanTree.h"


class Project6Menu{
private:
	HuffmanTree* hufftree;
	TennisTourney* tourney;
	Circle* circle;

	int getPosInt();
	void huffmanTreeMenu();
	void viewTourney();
	void cutCircle();


public:
	void mainMenu();

};

