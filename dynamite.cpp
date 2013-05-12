#include "dynamite.h"

using namespace std;

/** Default constructor */
Dynamite::Dynamite() {}

/** Constructor to initialize a dynamite object at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Dynamite::Dynamite(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

/** Defines which image to use for the dynamite and displays it
*   @returns dynamite image
*/
string Dynamite::display() {
  return "images/realdynamite.png";
}

/** @returns true if the object being looked at is a dynamite object */
bool Dynamite::isDynamite() {
  return true;
}

/** Determines whether the dynamite can move down a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns x + 1 != dim, because if this evaluates to true, then the dynamite can move down since the 
*   space below it is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*/
bool Dynamite::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  if (!pieceBelow->isMonster() && !pieceBelow->isBullet()) {
     return x + 1 != dim;
  }
  else
     return false;
}
