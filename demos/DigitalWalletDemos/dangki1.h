#ifndef DANGKI1_H
#define DANGKI1_H
#include "dangnhap1.h"
#include <QDialog>
#include "menu.h"
namespace Ui {
class Dangki1;
}
class Dangnhap1;
QString hashPassword(const QString &password);
class Dangki1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dangki1(QWidget *parent = nullptr);
    ~Dangki1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void hideEmailLabel();

    void hideUsernameLabel();

    void hidePasswordLabel();

    void hideRepairPasswordLabel();

private:
    Ui::Dangki1 *ui;
    Dangnhap1 *dangnhap1;
};

#endif // DANGKI1_H
