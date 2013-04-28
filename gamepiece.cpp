#include "gamepiece.h"

using namespace std;

GamePiece::GamePiece() {}

GamePiece::GamePiece(int xLoc, int yLoc) : QLabel() {
  x = xLoc;
  y = yLoc;
}

GamePiece::~GamePiece() {}

string GamePiece::display() {
 return "s";
}
