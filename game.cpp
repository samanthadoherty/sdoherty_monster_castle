#include <iostream>
#include <QtGui/QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "board.h"
#include "mainmenu.h"

using namespace std;

int main (int argc, char *argv[]) {
 
   QApplication a(argc, argv);

   MainMenu mm;
   mm.enterName();
   mm.contButton();
   mm.show();
   
   return a.exec();
}
