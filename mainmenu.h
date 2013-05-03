#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include <QVBoxLayout>

class MainMenu : public QWidget {
   Q_OBJECT
   
public:
   MainMenu();
   ~MainMenu();
   void enterName();
   void contButton();
   QString getName();
   void show();
   QString name;
protected:

public slots:
   void handleCont();
private:
   QWidget *window;
   QGraphicsScene *scene;
   QGraphicsView *view; 
   QVBoxLayout *mainLayout;  
   QLineEdit *nameEntry;
};

#endif
