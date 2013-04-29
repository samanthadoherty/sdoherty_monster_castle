#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>

class MainMenu : public QWidget {
   Q_OBJECT
   
public:
   MainMenu();
   ~MainMenu();
   void enterName();
   void contButton();
private:
   QWidget *window;
   QGraphicsScene *scene;
   QGraphicsView *view; 
   QVBoxLayout *mainLayout;  
};

#endif
