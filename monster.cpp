#include "monster.h"

using namespace std;

Monster::Monster() {}

Monster::Monster(int xLoc, int yLoc, Board* board) 
  : GamePiece(xLoc, yLoc, board) {
  isMovingRight = true;
}

string Monster::display() {
  return "images/monster1.png";
}

bool Monster::isMonster() {
  return true;
}

bool Monster::isSpace() {
  return false;
}

bool Monster::canMoveRight(vector<vector<GamePiece*> > *board) {
  if (y + 1 == dim) {
    isMovingRight = false;
  }
  return y + 1 != dim && isMovingRight && board->at(x)[y+1]->isSpace();
}

bool Monster::canMoveLeft(vector<vector<GamePiece*> > *board) {
  if (y == 0) {
    isMovingRight = true;
  }
  return y != 0 && !isMovingRight && board->at(x)[y-1]->isSpace();
}

bool Monster::canMoveDiagonalRight(vector<vector<GamePiece*> > *board) {
  cout << board->at(x)[y]->display() << endl;
  return false;
}

bool Monster::canMoveDiagonalLeft(vector<vector<GamePiece*> > *board) {
  cout << board->at(x)[y]->display() << endl;
  return false;
}
