#include "gold.h"

using namespace std;

/** Default constructor */
Gold::Gold() {}

/** Constructor to initialize a gold object at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Gold::Gold(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

/** Defines which image to use for the gold and displays it
*   @returns gold image
*/
string Gold::display() {
  return "images/realgold.png";
}

/** @returns true if the object being looked at is a gold object */
bool Gold::isGold() {
  return true;
}

/** @returns false if the object being looked at is a gold object, as that means it is not a space */
bool Gold::isSpace() {
  return false;
}

/** Determines whether the gold can move down a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns x + 1 != dim, because if this evaluates to true, then the gold can move down since the 
*   space below it is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*/
bool Gold::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  if (!pieceBelow->isMonster() && !pieceBelow->isBullet()) {
     return x + 1 != dim;
  }
  else
     return false;
}
