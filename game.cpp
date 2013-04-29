#include <iostream>
#include <QtGui/QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "board.h"
#include "mainmenu.h"

using namespace std;

int main (int argc, char *argv[]) {
 
   QApplication a(argc, argv);
   /*MainWindow mw;
   mw.addPushButtons();
   mw.addBottomButtons();
   mw.addMoveButtons();
   mw.addTextBoxes();*/
   MainMenu mm;
   mm.contButton();
   
   return a.exec();
}
