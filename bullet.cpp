#include "bullet.h"

using namespace std;

/** Default constructor */
Bullet::Bullet() {}

/** Constructor to initialize a bullet at a certain location on the given board
*   Uses inherited GamePiece constructor
*   @param int xLoc, the new x coordinates
*   @param int yLoc, the new y coordinates
*   @param Board* board, the current board
*/
Bullet::Bullet(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

/** Defines which image to use for the bullet and displays it
*   @returns bullet image
*/
string Bullet::display() {
  return "images/realbullet.png";
}

/** @returns true if the object being looked at is a bullet */
bool Bullet::isBullet() {
  return true;
}

/** @returns false if the object being looked at is a bullet, as that means it is not a space */
bool Bullet::isSpace() {
  return false;
}
