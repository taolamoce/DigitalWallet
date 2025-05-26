#include "help1.h"
#include "ui_help1.h"

Help1::Help1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Help1)
{

    ui->setupUi(this);
    this->setWindowTitle("Help");
}

Help1::~Help1()
{
    delete ui;
}
