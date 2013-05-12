#include "monster.h"

using namespace std;

/** Default constructor */
Monster::Monster() {}

/** Constructor to initialize a monster object at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Monster::Monster(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  isMovingRight = true;
}

/** Defines which image to use for the monster and displays it
*   @returns monster image
*/
string Monster::display() {
  return "images/finalmonster.png";
}

/** @returns true if the object being looked at is a monster object */
bool Monster::isMonster() {
  return true;
}

/** @returns false if the object being looked at is a monster object, as that means it is not a space */
bool Monster::isSpace() {
  return false;
}

/** Determines whether the monster can move right a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns y + 1 != dim, because if this evaluates to true, then the monster can move right since the 
*   space to its right is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*   Also changes isMovingRight to false if y + 1 = dim because then the monster will have reached the edge
*   and needs to begin moving back left
*/
bool Monster::canMoveRight(vector<vector<GamePiece*> > *board) {
  if (y + 1 == dim) {
    isMovingRight = false;
  }
  return y + 1 != dim && isMovingRight && (board->at(x)[y+1]->isSpace() || 
     board->at(x)[y+1]->isPlayer() || board->at(x)[y+1]->isCandy() || board->at(x)[y+1]->isDynamite()
     || board->at(x)[y+1]->isGold());
}

/** Determines whether the monster can move left a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns y == 0, because if this evaluates to true, then the monster can move left since the 
*   space to its left is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*   Also changes isMovingLeft to false if y == 0 because then the monster will have reached the edge
*   and needs to begin moving back right
*/
bool Monster::canMoveLeft(vector<vector<GamePiece*> > *board) {
  if (y == 0) {
    isMovingRight = true;
  }
  return y != 0 && !isMovingRight && (board->at(x)[y-1]->isSpace() || 
     board->at(x)[y-1]->isPlayer() || board->at(x)[y-1]->isCandy() || board->at(x)[y-1]->isDynamite()
     || board->at(x)[y-1]->isGold());
}
