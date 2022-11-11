#ifndef SUPERPAINTMW_H
#define SUPERPAINTMW_H

#include <QMainWindow>

namespace Ui {
class SuperPaintMW;
}

class SuperPaintMW : public QMainWindow
{
    Q_OBJECT

public:
    explicit SuperPaintMW(QWidget *parent = 0);
    ~SuperPaintMW();

private:
    Ui::SuperPaintMW *ui;
};

#endif // SUPERPAINTMW_H
