#ifndef CHANGEINFORMATION_H
#define CHANGEINFORMATION_H

#include <QWidget>

namespace Ui {
class ChangeInformation;
}

class ChangeInformation : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeInformation(QWidget *parent = nullptr);
    ~ChangeInformation();

private slots:
    void on_ok_clicked();

    void on_cancle_clicked();

    void on_name_returnPressed();

    void on_username_returnPressed();

    void on_phonenumber_returnPressed();

    void on_email_returnPressed();

private:
    Ui::ChangeInformation *ui;
};

#endif // CHANGEINFORMATION_H
