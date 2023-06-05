#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_ok_clicked();

    void on_cancle_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
