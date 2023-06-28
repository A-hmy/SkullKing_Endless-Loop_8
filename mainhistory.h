#ifndef MAINHISTORY_H
#define MAINHISTORY_H

#include <QMainWindow>
namespace Ui {
class MainHistory;
}

class MainHistory : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainHistory(QWidget *parent = nullptr);
    ~MainHistory();

private:
    Ui::MainHistory *ui;
};

#endif // MAINHISTORY_H
