#ifndef TAOMKCAP2_H
#define TAOMKCAP2_H
#include "menu.h"

#include <QDialog>

namespace Ui {
class Taomkcap2;
}
void setusernamemk2(const QString &username);
class Taomkcap2 : public QDialog
{
    Q_OBJECT

public:
    explicit Taomkcap2(QWidget *parent = nullptr);
    ~Taomkcap2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Taomkcap2 *ui;
};

#endif // TAOMKCAP2_H
