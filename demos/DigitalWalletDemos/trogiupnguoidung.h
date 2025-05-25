#ifndef TROGIUPNGUOIDUNG_H
#define TROGIUPNGUOIDUNG_H

#include <QDialog>

namespace Ui {
class Trogiupnguoidung;
}
class Trogiupnguoidung : public QDialog
{
    Q_OBJECT

public:
    explicit Trogiupnguoidung(QWidget *parent = nullptr);
    ~Trogiupnguoidung();

private slots:
    void on_pushButton_3_clicked();
    void hideTextEdit();

private:
    Ui::Trogiupnguoidung *ui;
};

#endif // TROGIUPNGUOIDUNG_H
