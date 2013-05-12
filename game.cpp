#include <iostream>
#include <QtGui/QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "board.h"
#include "mainmenu.h"

using namespace std;

/** Instantiates a QApplication object as well as a Mainmenu object
*   Calls functions to show buttons and show mainmenu
*   @param int argc, the number of arguments in the command line
*   @param char *argv[], a char array of the arguments
*   @returns a.exec(), which executes the graphical user interface
*/
int main (int argc, char *argv[]) {
 
   QApplication a(argc, argv);

   MainMenu mm;
   mm.enterName();
   mm.contButton();
   mm.show();
   
   return a.exec();
}
