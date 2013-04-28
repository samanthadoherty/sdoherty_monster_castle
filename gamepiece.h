#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <QTimer>
#include <QLabel>
#include <iostream>

using namespace std;
class Board;
class GamePiece : public QLabel {
public:
   GamePiece();
   GamePiece(int xLoc, int yLoc, Board* board_);
   ~GamePiece();
   void scrollBoard();
   void moveRight();
   void moveLeft();
   int getX();
   int getY();
   virtual string display();
   virtual bool isMonster();
   virtual void move();
   virtual bool canMoveRight(vector<vector<GamePiece*> > *board);
   virtual bool canMoveLeft(vector<vector<GamePiece*> > *board);

protected:
   QTimer timer;
   int x;
   int y;
   int dim;
   Board* board;
};

#endif
