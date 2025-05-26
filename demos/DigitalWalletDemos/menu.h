#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "dangnhap1.h"
#include "giaodich.h"
#include "doimk.h"
#include "help1.h"
#include "historydialog.h"
#include "taomkcap2.h"
#include "nhapmkcap2.h"
#include "mkhauho.h"
namespace Ui {
class Menu;
}
class Help1;
class Doimk;
class Dangnhap1;
class Giaodich;
class Taomkcap2;
class Nhapmk2;
class Mkhauho;
void setmkho (const bool &check);
void setusername(const QString &username);
void setmk2 (const bool &check);
class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_mat_clicked();

    void on_tk1_clicked();

    void on_pushButton_4_clicked();


    void on_tk1_4_clicked();

    void on_pushButton_6_clicked();

    void on_tk1_3_clicked();

    void on_tk1_2_clicked();

private:
    Ui::Menu *ui;
    Dangnhap1 *dangnhap1;
    Giaodich *giaodich;
    Doimk *doimk;
    Help1 *help1;
    Taomkcap2 *taomkcap2;
    Nhapmk2 *nhapmk2;
    Mkhauho *mkhauho;
};

#endif // MENU_H
