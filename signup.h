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

    void on_email_textChanged(const QString &arg1);

    void on_name_returnPressed();

    void on_username_returnPressed();

    void on_password_returnPressed();

    void on_phonenumber_returnPressed();


private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
