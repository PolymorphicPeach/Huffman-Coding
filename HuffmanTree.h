#pragma once

#include "HuffmanNode.h"

#include <iostream>
#include <vector>
#include <utility>
#include <thread>
#include <set>
#include <algorithm>
#include <queue>


class HuffmanTree{
private:
	HuffmanNode* start;
	
	std::string originalInput;

	std::vector<std::pair<char, int>> tempStorage;
	void populateTempStorage(char character);

	void preOrder(HuffmanNode* traversalNode);

	struct compareNodes{
		bool operator()(HuffmanNode* node1, HuffmanNode* node2){
			return (node1->getFrequency() > node2->getFrequency());
		}
	};

	std::string binaryCreator;
	std::vector <std::string> binaryHolder;
	std::vector <char> characterHolder;
	std::vector <int> frequencyHolder;

public:
	void getUserString();
	void displayPairs();
	void generateTree();
	void generateBinaryTable();
	void displayBinaryTable();
	void displaySavings();
	std::string getOriginalString();
	~HuffmanTree();

};

