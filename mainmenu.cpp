#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include "mainwindow.h"
#include "mainmenu.h"

using namespace std;

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

MainMenu::~MainMenu() {
}

void MainMenu::show() {
   window->show();
}

void MainMenu::enterName() {
   nameEntry = new QLineEdit();
   mainLayout->addWidget(nameEntry);
   name = nameEntry->text();
}

QString MainMenu::getName() {
   return name;
}

void MainMenu::contButton() {
   QPushButton *contButton = new QPushButton("Continue");
   mainLayout->addWidget(contButton);
   connect(contButton, SIGNAL(clicked()), this, SLOT(handleCont()));
}

void MainMenu::handleCont() {
  MainWindow *mw = new MainWindow();
  mw->setFocusPolicy(Qt::StrongFocus);
  mw->addPushButtons();
  mw->addBottomButtons();
  mw->addMoveButtons();
  mw->addTextBoxes(nameEntry->text());
}
