#include "Project6Menu.h"

using std::cout; using std::endl; using std::cin; using std::string;

void Project6Menu::mainMenu(){


	int numCuts{0};

	bool quit{false};


	do{
		cout << "===================================" << endl
			<< "1.) Cutting a Circle" << endl
			<< "2.) Tennis Tournament" << endl
			<< "3.) Huffman Tree" << endl
			<< "4.) Quit" << endl
			<< "-----------------------------------" << endl;

		switch(getPosInt()){
		case 1:
			cout << "Enter a number of cuts" << endl;
			numCuts = getPosInt();
			cout << "Standard method: " << circle->getNumPieces(numCuts) << " pieces" << endl;
			cout << "Recursive method: " << circle->getNumPiecesRecursive(numCuts) << " pieces" << endl;

			break;

		case 2:
			viewTourney();
			break;

		case 3:
			huffmanTreeMenu();
			break;

		case 4:
			quit = true;
			break;

		default:
			cout << "Please choose a valid selection" << endl << endl;
		}
	} while(!quit);
}

int Project6Menu::getPosInt(){
	string userInput;
	bool validInput{true};

	cout << "Selection: ";
	getline(cin, userInput);
	cin.clear();
	cout << endl;

	for(size_t i{0}; i < userInput.size(); ++i){
		if(!isdigit(userInput[i])){
			validInput = false;
		}
	}

	if(validInput){
		return std::stoi(userInput);
	}
	else{
		return -1;
	}
}

void Project6Menu::huffmanTreeMenu(){

	hufftree = new HuffmanTree();

	bool quit{false};

	hufftree->getUserString();
	hufftree->generateTree();
	hufftree->generateBinaryTable();

	do{
		if(!hufftree->getOriginalString().empty()){
			cout << "===================================" << endl
				 << "Your text: " << hufftree->getOriginalString() << endl;
		}

		cout<< "===================================" << endl
			<< "1.) View characters with frequencies" << endl
			<< "2.) View binary codes" << endl
			<< "3.) View savings" << endl
			<< "4.) Go back" << endl
			<< "-----------------------------------" << endl;

		switch(getPosInt()){
		case 1:
			hufftree->displayPairs();
			break;

		case 2:
			hufftree->displayBinaryTable();
			break;

		case 3:
			hufftree->displaySavings();
			break;

		case 4:
			quit = true;
			break;

		default:
			cout << "Please choose a valid selection" << endl << endl;
		}
	} while(!quit);


	delete hufftree;
	hufftree = nullptr;
}

void Project6Menu::viewTourney(){
	tourney = new TennisTourney();
	tourney->displayEveryCombo();

	delete tourney;
	tourney = nullptr;
}

void Project6Menu::cutCircle(){

	circle = new Circle();
	int numCuts{-1};

	bool quit{false};

	do{
		cout << "===================================" << endl
			<< "1.) Use functional method" << endl
			<< "2.) Use recursive method" << endl
			<< "3.) Go back" << endl
			<< "-----------------------------------" << endl;

		switch(getPosInt()){
		case 1:
			cout << "How many cuts?" << endl;
			cout << circle->getNumPieces(getPosInt()) << " pieces created." << endl;

			break;

		case 2:
			cout << "How many cuts?" << endl;
			cout << circle->getNumPiecesRecursive(getPosInt()) << " pieces created." << endl;

			break;

		case 3:
			quit = true;
			break;

		default:
			cout << "Please choose a valid selection" << endl << endl;
		}
	} while(!quit);

	delete circle;
	circle = nullptr;
}


