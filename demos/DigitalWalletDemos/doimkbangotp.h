#ifndef DOIMKBANGOTP_H
#define DOIMKBANGOTP_H
#include  "quenmk1.h"
#include <QDialog>
#include "dangnhap1.h"
namespace Ui {
class Doimkbangotp;
}
class Dangnhap1;
void setUsername2(const QString &username);
class Doimkbangotp : public QDialog
{
    Q_OBJECT

public:
    explicit Doimkbangotp(QWidget *parent = nullptr);
    ~Doimkbangotp();

private slots:
    void on_pushButton_clicked();
private:
    Ui::Doimkbangotp *ui;
    Dangnhap1 *dangnhap1;
};

#endif // DOIMKBANGOTP_H
