#include <iostream>
#include <QLabel>
#include <QPushButton>
#include "mainmenu.h"

using namespace std;

MainMenu::MainMenu() {
   window = new QWidget();
   scene = new QGraphicsScene();
   view = new QGraphicsView( scene );
   view->setFixedSize(402, 402);
   
   QLabel* myImage = new QLabel();
   QImage image("images/00911-Stone-Wall-Backdrop.jpg");
   myImage->setPixmap(QPixmap::fromImage(image));
   scene->addWidget(myImage);
   
   mainLayout = new QVBoxLayout();
   mainLayout->addWidget(view);
   window->setLayout(mainLayout);
   window->show();
}

MainMenu::~MainMenu() {
   delete scene;
   delete view;
}

void MainMenu::enterName() {

}

void MainMenu::contButton() {
   QPushButton *contButton = new QPushButton("Continue");
   mainLayout->addWidget(contButton);
}
