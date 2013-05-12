#include <iostream>
#include "candy.h"

using namespace std;

/** Default constructor */
Candy::Candy() {}

/** Constructor to initialize a candy object at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Candy::Candy(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
}

/** Defines which image to use for the candy and displays it
*   @returns candy image
*/
string Candy::display() {
  return "images/candyfinal.png";
}

/** @returns true if the object being looked at is a candy object */
bool Candy::isCandy() {
  return true;
}

/** @returns false if the object being looked at is a candy object, as that means it is not a space */
bool Candy::isSpace() {
  return false;
}

/** Determines whether the candy can move down a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns x + 1 != dim, because if this evaluates to true, then the candy can move down since the 
*   space below it is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*/
bool Candy::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  if (!pieceBelow->isMonster() && !pieceBelow->isBullet()) {
     return x + 1 != dim;
  }
  else
     return x + 1 != dim;
}
