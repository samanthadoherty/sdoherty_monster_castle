#include "bullet.h"

using namespace std;

Bullet::Bullet() {}

Bullet::Bullet(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  
}

string Bullet::display() {
  return "B";
}

bool Bullet::isBullet() {
  return true;
}

bool Bullet::isSpace() {
  return false;
}
