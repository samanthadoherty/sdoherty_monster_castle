#include "gamepiece.h"

using namespace std;

GamePiece::GamePiece() {}

GamePiece::GamePiece(int xLoc, int yLoc, Board* board_) : QLabel() {
  x = xLoc;
  y = yLoc;
  board = board_;
  dim = 10;
}

GamePiece::~GamePiece() {}

string GamePiece::display() {
 return " ";
}

bool GamePiece::isMonster() {
  return false;
}

int GamePiece::getX() {
  return x;
}

int GamePiece::getY() {
  return y;
}

void GamePiece::move() {}

void GamePiece::moveRight() {
  y++;
}

void GamePiece::moveLeft() {
  y--;
}

bool GamePiece::canMoveRight(vector<vector<GamePiece*> >* board) {
  return true;
}

bool GamePiece::canMoveLeft(vector<vector<GamePiece*> > *board) {
 return true;
}
