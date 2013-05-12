#include "gamepiece.h"

using namespace std;

/** Default constructor */
GamePiece::GamePiece() {}

/** Constructor to initialize a GamePiece object at a certain location 
*   on the given board
*   Also initializes dim to 10 and initializes the given board
*   Uses inherited QLabel constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board_, the current board
*/
GamePiece::GamePiece(int xLoc, int yLoc, Board* board_) : QLabel() {
  x = xLoc;
  y = yLoc;
  board = board_;
  dim = 10;
}

/** Destructor for gamepiece */
GamePiece::~GamePiece() {}

/** Defines which image to use for the game pieces and displays it
*   @returns stone image
*/
string GamePiece::display() {
 return "images/stone.png";
}

/** Sets the boolean isCandy() to false
*   @returns false
*/
bool GamePiece::isCandy() {
  return false;
}

/** Sets the boolean isMonster() to false
*   @returns false
*/
bool GamePiece::isMonster() {
  return false;
}

/** Sets the boolean isGold() to false
*   @returns false
*/
bool GamePiece::isGold() {
  return false;
}

/** @returns true if the object being looked at is a space (aka no object is at the location) */
bool GamePiece::isSpace() {
  return true;
}

/** Sets the boolean isDynamite() to false
*   @returns false
*/
bool GamePiece::isDynamite() {
  return false;
}

/** Sets the boolean isBullet() to false
*   @returns false
*/
bool GamePiece::isBullet() {
  return false;
}

/** Sets the boolean isPlayer() to false
*   @returns false
*/
bool GamePiece::isPlayer() {
  return false;
}

/** @returns x, the x coordinate of the gamepiece */
int GamePiece::getX() {
  return x;
}

/** @returns y, the y coordinate of the gamepiece */
int GamePiece::getY() {
  return y;
}

/** Called to move the gamepiece */
void GamePiece::move() {}

/** Adds 1 to the y coordinate to move the object to the right */
void GamePiece::moveRight() {
  y++;
}

/** Subtracts one from the y coordinate to move the object to the left */
void GamePiece::moveLeft() {
  y--;
}

/** Adds 1 to the x coordinate to move the object down */
void GamePiece::moveDown() {
  x++;
}

/** Subtracts 1 from the x coordinate to move the object up */
void GamePiece::moveUp() {
  x--;
}

/** Determines if gamepiece can move to the right
*   @param vector<vector<GamePiece*> >* board, a vector of vectors of pointers to GamePieces that represent the current board
*   @returns true as a default option for other objects
*/
bool GamePiece::canMoveRight(vector<vector<GamePiece*> >* board) {
  if (board->at(x)[y]->isMonster()) {
    return true;
  }
  else
    return true;
}

/** Determines if gamepiece can move to the left
*   @param vector<vector<GamePiece*> >* board, a vector of vectors of pointers to GamePieces that represent the current board
*   @returns true as a default option for other objects
*/
bool GamePiece::canMoveLeft(vector<vector<GamePiece*> > *board) {
  if (board->at(x)[y]->isMonster()) {
    return true;
  }
  else
    return true;
}

/** Determines if gamepiece can move down
*   @param vector<vector<GamePiece*> >* board, a vector of vectors of pointers to GamePieces that represent the current board
*   @returns true as a default option for other objects
*/
bool GamePiece::canMoveDown(vector<vector<GamePiece*> > *board) {
  if (board->at(x)[y]->isMonster()) {
    return true;
  }
  else
    return true;
}
