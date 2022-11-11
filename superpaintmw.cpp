#include "superpaintmw.h"
#include "ui_superpaintmw.h"

SuperPaintMW::SuperPaintMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SuperPaintMW)
{
    ui->setupUi(this);
}

SuperPaintMW::~SuperPaintMW()
{
    delete ui;
}
