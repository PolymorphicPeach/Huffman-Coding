#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(int freq, char ch) : frequency(freq), character(ch){
	if(character == '\0'){
		leaf = false;
	}
	else{
		leaf = true;
	}

	left = nullptr;
	right = nullptr;
}

HuffmanNode::~HuffmanNode(){
	if(left){
		delete left;
	}
	if(right){
		delete right;
	}
}

HuffmanNode* HuffmanNode::getLeft(){
	return left;
}

HuffmanNode* HuffmanNode::getRight(){
	return right;
}

void HuffmanNode::setLeft(HuffmanNode* node){
	left = node;
}

void HuffmanNode::setRight(HuffmanNode* node){
	right = node;
}

char HuffmanNode::getCharacter(){
	return character;
}

int HuffmanNode::getFrequency(){
	return frequency;
}

bool HuffmanNode::isLeaf(){
	return leaf;
}
