#include "HuffmanTree.h"

using std::cout; using std::cin; using std::endl; using std::string; using std::vector; using std::thread;
using std::set;


void HuffmanTree::populateTempStorage(char character){

	int charCount{0};

	for(size_t i{0}; i < originalInput.size(); ++i){
		if(originalInput[i] == character){
			++charCount;
		}
		else if(character == '_' && isspace(originalInput[i])){
			++charCount;
		}
	}

	tempStorage.push_back(std::make_pair(character, charCount));
}

void HuffmanTree::preOrder(HuffmanNode* traversalNode){

	if(!traversalNode){	
		return;
	}

	if(traversalNode->isLeaf()){
		characterHolder.push_back(traversalNode->getCharacter());
		frequencyHolder.push_back(traversalNode->getFrequency());
		binaryHolder.push_back(binaryCreator);
	}

	binaryCreator += "0";
	preOrder(traversalNode->getLeft());
	binaryCreator.erase(binaryCreator.size() - 1, 1);



	binaryCreator += "1";
	preOrder(traversalNode->getRight());
	binaryCreator.erase(binaryCreator.size() - 1, 1);

}

void HuffmanTree::getUserString(){
	string userInput;

	do{
		cout << "Enter something to be encoded: ";
		getline(cin, userInput);
		cin.clear();

	} while(userInput.empty());

	originalInput = userInput;


	set <char> foundChars;
	// First pass, just get the character
	for(size_t i{0}; i < userInput.size(); ++i){

		if(isspace(userInput[i])){
			foundChars.insert('_');
		}
		else{
			foundChars.insert(userInput[i]);
		}
	}

	// Second pass, count
	// Oh no, that'd be like O(n^2) sequentially... can't have that
	vector<thread> threads;

	for(char c : foundChars){
		threads.emplace_back(&HuffmanTree::populateTempStorage, this, c);
	}

	for(auto& th : threads){
		th.join();
	}

	// Using lambda to sort
	std::sort(tempStorage.begin(), tempStorage.end(), [](auto& left, auto& right){
		return left.second < right.second;
		});

}

void HuffmanTree::displayPairs(){
	for(auto& p : tempStorage){
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
}

void HuffmanTree::generateTree(){
	if(originalInput.empty()){
		return;
	}
	if(tempStorage.empty()){
		return;
	}

	// I hope this works lol
	std::priority_queue <HuffmanNode*, vector<HuffmanNode*>, compareNodes> queue;

	// Make each leaf node and put it in queue
	for(size_t i{0}; i < tempStorage.size(); ++i){
		queue.push(new HuffmanNode(tempStorage[i].second, tempStorage[i].first));
	}

	HuffmanNode* leftChildHolder;
	HuffmanNode* rightChildHolder;
	HuffmanNode* sumNode;

	while(queue.size() != 1){

		// Extract the left node
		leftChildHolder = queue.top();
		queue.pop();

		// Extract the right node
		rightChildHolder = queue.top();
		queue.pop();

		// Create the "sum node"
		// Using the default value of '\0' if only a frequency is used in the constructor
		sumNode = new HuffmanNode(leftChildHolder->getFrequency() + rightChildHolder->getFrequency());

		// Connect the left and right children
		sumNode->setLeft(leftChildHolder);
		sumNode->setRight(rightChildHolder);

		// Throw the sumNode with its children back into the queue
		queue.push(sumNode);

		leftChildHolder = nullptr;
		rightChildHolder = nullptr;
		sumNode = nullptr;
	}

	// The only node left is the root/start
	start = queue.top();

	// Just to be consistent
	queue.pop();

}


void HuffmanTree::generateBinaryTable(){
	HuffmanNode* traversalNodeRoot = start;

	preOrder(traversalNodeRoot);

	binaryCreator.clear();
	traversalNodeRoot = nullptr;
}

void HuffmanTree::displayBinaryTable(){
	if(characterHolder.empty() || binaryHolder.empty()){
		return;
	}

	for(size_t i{0}; i < characterHolder.size(); ++i){
		cout << characterHolder[i] << " : " << binaryHolder[i] << endl;
	}

}

void HuffmanTree::displaySavings(){
	if(characterHolder.empty() || binaryHolder.empty() || frequencyHolder.empty()){
		return;
	}

	int encodedBits{0};

	for(size_t i{0}; i < characterHolder.size(); ++i){
		encodedBits += frequencyHolder[i] * binaryHolder[i].size();
	}

	cout << "Original text: " << originalInput.size() * 8 << " bits" << endl
		 << "Encoded text: " << encodedBits << " bits" << endl
		 << "You saved: " << (originalInput.size() * 8) - encodedBits << " bits!" << endl;

}

std::string HuffmanTree::getOriginalString(){
	return originalInput;
}

HuffmanTree::~HuffmanTree(){
	delete start;
}
