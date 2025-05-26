#include "hello1.h"
#include "./ui_hello1.h"
#include <QPixmap>
hello1::hello1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::hello1)
{
    ui->setupUi(this);
    this->setWindowTitle("Hello");
    QPixmap pixmap(":/picture/raw.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaledPixmap);
}

hello1::~hello1()
{
    delete ui;
}

void hello1::on_pushButton_clicked()
{
    hide();                                         // mở cửa sổ đăng nhập
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();
}

