#include <iostream>
#include "candy.h"

using namespace std;
//
Candy::Candy() {}

Candy::Candy(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
  isMovingRight = true;
}

string Candy::display() {
  return "images/candy1.png";
}

bool Candy::isCandy() {
  return true;
}

bool Candy::isSpace() {
  return false;
}


bool Candy::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  return x + 1 != dim && !pieceBelow->isMonster();
}

bool Candy::canMoveDiagonalRight(vector<vector<GamePiece*> > *board) {
 if (y + 1 == dim - 1) {
    isMovingRight = false;
  }
  return y + 1 != dim - 1 && isMovingRight;
}

bool Candy::canMoveDiagonalLeft(vector<vector<GamePiece*> > *board) {
  if (y == 1) {
    isMovingRight = true;
  }
  return y != 1 && !isMovingRight;
}
