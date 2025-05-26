#ifndef HELLO1_H
#define HELLO1_H
#include "dangnhap1.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {
class hello1;
}
QT_END_NAMESPACE

class hello1 : public QMainWindow
{
    Q_OBJECT

public:
     hello1(QWidget *parent = nullptr);
    ~hello1();

 private slots:
     void on_pushButton_clicked();

 private:
    Ui::hello1 *ui;
    Dangnhap1 *dangnhap1;
};

#endif // HELLO1_H
