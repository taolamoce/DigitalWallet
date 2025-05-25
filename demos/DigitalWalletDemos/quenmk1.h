#ifndef QUENMK1_H
#define QUENMK1_H
#include "otp.h"
#include <QDialog>
#include "dangnhap1.h"
#include "doimkbangotp.h"
namespace Ui {

class Quenmk1;

}
class Dangnhap1;
class Otp;
class Doimkbangotp;
class Quenmk1 : public QDialog
{
    Q_OBJECT

public:
    explicit Quenmk1(QWidget *parent = nullptr);
    ~Quenmk1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Quenmk1 *ui;
    Otp *otp;
    Dangnhap1 *dangnhap1;

};

#endif // QUENMK1_H
