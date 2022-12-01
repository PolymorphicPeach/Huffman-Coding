#pragma once

#include <string>

class HuffmanNode{
private:
	char character;
	bool leaf;
	int frequency;
	HuffmanNode* left;
	HuffmanNode* right;


public:
	// Null character as default
	HuffmanNode(int freq, char ch = '\0');
	~HuffmanNode();

	HuffmanNode* getLeft();
	HuffmanNode* getRight();
	void setLeft(HuffmanNode* node);
	void setRight(HuffmanNode* node);

	char getCharacter();
	int getFrequency();
	bool isLeaf();

};

