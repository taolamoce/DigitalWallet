#ifndef DANGNHAP1_H
#define DANGNHAP1_H
#include "dangki1.h"
#include "quenmk1.h"
#include "menu.h"
#include <QDialog>
#include "quanli.h"
#include "trogiupnguoidung.h"
namespace Ui {
class Dangnhap1;
}
class Dangki1;
class Quenmk1;
class Menu;
class Quanli;
class Dangnhap1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dangnhap1(QWidget *parent = nullptr);
    ~Dangnhap1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void on_pushButton_clicked();




    void on_pushButton_4_clicked();

private:
    Ui::Dangnhap1 *ui;
    Dangki1 *dangki1;
    Quenmk1 *quenmk1;
    Menu *menu;
    Quanli *quanli;
    Trogiupnguoidung *trogiupnguoidung;
};

#endif // DANGNHAP1_H
