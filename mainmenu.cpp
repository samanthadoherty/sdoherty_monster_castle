#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include "mainwindow.h"
#include "mainmenu.h"

using namespace std;

/** Constructor that creates a new window, scene and view
*   Also sets the logo image that the user first seas and the layout of the window
*/
MainMenu::MainMenu() {
   window = new QWidget();
   scene = new QGraphicsScene();
   view = new QGraphicsView( scene );
   view->setFixedSize(440, 366);
   
   QLabel* myImage = new QLabel();
   QImage image("images/monstercastle.png");
   myImage->setPixmap(QPixmap::fromImage(image));
   scene->addWidget(myImage);
   
   mainLayout = new QVBoxLayout();
   mainLayout->addWidget(view);
   window->setLayout(mainLayout);
}

/** MainMenu destructor */
MainMenu::~MainMenu() {
}

/** Calls show in order to display the main menu window */
void MainMenu::show() {
   window->show();
}

/** Creates a text box in which the user can enter their name */
void MainMenu::enterName() {
   nameEntry = new QLineEdit();
   mainLayout->addWidget(nameEntry);
   name = nameEntry->text();
}

/** @returns name, the name the user entered */
QString MainMenu::getName() {
   return name;
}

/** Creates the pushbutton that the user pushes to continue on to the next screen */
void MainMenu::contButton() {
   QPushButton *contButton = new QPushButton("Continue");
   mainLayout->addWidget(contButton);
   connect(contButton, SIGNAL(clicked()), this, SLOT(handleCont()));
}

/** This is the slot that determines what happens when user hits continue, which is opens up the main
*    window in a new window and adds the pushbuttons to that window
*/
void MainMenu::handleCont() {
  MainWindow *mw = new MainWindow();
  mw->setFocusPolicy(Qt::StrongFocus);
  mw->addPushButtons();
  mw->addBottomButtons();
  mw->addMoveButtons();
  mw->addTextBoxes(nameEntry->text());
}
