#include "Circle.h"

int Circle::getNumPieces(int numCuts){
	if(numCuts <= 0){
		return 1;
	}

	return 0.5 * numCuts * numCuts + 0.5 * numCuts + 1;
}

int Circle::getNumPiecesRecursive(int numCuts){
	// Just like the other method, 1 piece for 0 cuts is the base case.
	if(numCuts <= 0){
		return 1;
	}

	return getNumPiecesRecursive(numCuts - 1) + numCuts;
}
