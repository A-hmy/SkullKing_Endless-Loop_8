#ifndef SIGN_H
#define SIGN_H

#include <QWidget>

namespace Ui {
class Sign;
}

class Sign : public QWidget
{
    Q_OBJECT

public:
    explicit Sign(QWidget *parent = nullptr);
    ~Sign();

private slots:
    void on_ForgotPassword_clicked();

    void on_SignUp_clicked();

    void on_Login_clicked();

private:
    Ui::Sign *ui;
};

#endif // SIGN_H
