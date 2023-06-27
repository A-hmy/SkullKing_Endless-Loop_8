#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "player.h"
extern QVector<Card*> CardsOfPlayerClient;
extern QVector <Player*> Players;
extern QVector<Card*>_cards;
extern Player* player ;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
