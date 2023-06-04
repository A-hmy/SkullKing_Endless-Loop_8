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

private:
    Ui::Sign *ui;
};

#endif // SIGN_H
