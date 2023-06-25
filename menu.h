#ifndef MENU_H
#define MENU_H

#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_Changeinformation_2_clicked();

    void on_Logout_2_clicked();

    void on_Start_2_clicked();

    void on_History_2_clicked();

private:
    Ui::Menu *ui;
};

#endif // MENU_H
