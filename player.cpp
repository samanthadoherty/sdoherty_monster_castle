#include "player.h"

using namespace std;

/** Default constructor */
Player::Player() {}

/** Constructor to initialize a player object at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Player::Player(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  
}

/** Defines which image to use for the player and displays it
*   @returns player image
*/
string Player::display() {
  return "images/realplayer.png";
}

/** @returns true if the object being looked at is a player object */
bool Player::isPlayer() {
  return true;
}

/** @returns false if the object being looked at is a player object, as that means it is not a space */
bool Player::isSpace() {
  return false;
}

/** Determines whether the player can move right a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns y + 1 != dim, because if this evaluates to true, then the player can move right since the 
*   space to its right is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*/
bool Player::canMoveRight(vector<vector<GamePiece*> > *board) {
  if (board->at(x)[y+1]->isMonster()) {
     return y + 1 != dim;
  }
  else
     return y + 1 != dim;
}

/** Determines whether the player can move left a space
*   @param vector<vector<GamePiece*> > *board, a board which is a vector of vectors of GamePiece*
*   @returns y + 1 != dim, because if this evaluates to true, then the player can move left since the 
*   space to its left is free and not off the edge of the board
*   If this evaluates to false, this means the space is out of the scope of the board
*/
bool Player::canMoveLeft(vector<vector<GamePiece*> > *board){
  if (board->at(x)[y-1]->isMonster()) {
     return y != 0;
  }
  else
     return y != 0;
}
