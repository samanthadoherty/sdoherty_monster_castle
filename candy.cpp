#include <iostream>
#include "candy.h"

using namespace std;

Candy::Candy() {}

Candy::Candy(int xLoc, int yLoc, Board* board)
  : GamePiece(xLoc, yLoc, board) {
}

string Candy::display() {
  return "images/candyfinal.png";
}

bool Candy::isCandy() {
  return true;
}

bool Candy::isSpace() {
  return false;
}


bool Candy::canMoveDown(vector<vector<GamePiece*> > *board) {
  GamePiece* pieceBelow = board->at(x)[y];
  if (!pieceBelow->isMonster() && !pieceBelow->isBullet()) {
     return x + 1 != dim;
  }
  else
     return x + 1 != dim;
}
