#ifndef GAMEPIECE_H
#define GAMEPIECE_H
#include <QTimer>
#include <QLabel>
#include <iostream>

using namespace std;
class GamePiece : public QLabel {
public:
   GamePiece();
   GamePiece(int xLoc, int yLoc);
   ~GamePiece();
   void scrollBoard();
   virtual string display();

protected:
   QTimer timer;
   int x;
   int y;
};

#endif
