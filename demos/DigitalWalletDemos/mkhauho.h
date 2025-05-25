#ifndef MKHAUHO_H
#define MKHAUHO_H

#include <QDialog>

namespace Ui {
class Mkhauho;
}
void setusernameho(const QString &username);
class Mkhauho : public QDialog
{
    Q_OBJECT

public:
    explicit Mkhauho(QWidget *parent = nullptr);
    ~Mkhauho();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Mkhauho *ui;
};

#endif // MKHAUHO_H
