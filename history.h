#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>

namespace Ui {
class History;
}

class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();

private:
    Ui::History *ui;
private slots:
    void on_Set1_clicked();

    void on_Set2_clicked();

    void on_Set3_clicked();

    void on_Set4_clicked();

    void on_Set5_clicked();

    void on_Set6_clicked();

    void on_Set7_clicked();

    void on_Set8_clicked();

    void on_Set9_clicked();

    void on_Set10_clicked();

    void on_Set11_clicked();

    void on_Set12_clicked();

    void on_Set13_clicked();

    void on_Set14_clicked();

};

#endif // HISTORY_H
