#ifndef NHAPMKCAP2_H
#define NHAPMKCAP2_H

#include <QDialog>

namespace Ui {
class Nhapmk2;
}
void setusernamemk22(const QString &username);

class Nhapmk2 : public QDialog
{
    Q_OBJECT

public:
    explicit Nhapmk2( QWidget *parent = nullptr);
    ~Nhapmk2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Nhapmk2 *ui;
};

#endif // NHAPMKCAP2_H
