#include <iostream>
#include <QtGui/QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "graphicswindow.h"
#include "board.h"

using namespace std;

int main (int argc, char *argv[]) {
 
   QApplication a(argc, argv);
   MainWindow mw;
   mw.addPushButtons();
   mw.addBottomButtons();
   
   return a.exec();
}
