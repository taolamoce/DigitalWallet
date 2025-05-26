#ifndef HELP1_H
#define HELP1_H

#include <QDialog>

namespace Ui {
class Help1;
}

class Help1 : public QDialog
{
    Q_OBJECT

public:
    explicit Help1(QWidget *parent = nullptr);
    ~Help1();

private:
    Ui::Help1 *ui;
};

#endif // HELP1_H
