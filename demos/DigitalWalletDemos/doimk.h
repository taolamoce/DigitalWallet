#ifndef DOIMK_H
#define DOIMK_H

#include <QDialog>
#include "menu.h"
namespace Ui {
class Doimk;
}
class Menu;
void setUsername3(const QString &username );
void replaceLineInFile(const QString &filePath, int lineNumber, const QString &newText);
class Doimk : public QDialog
{
    Q_OBJECT

public:
    explicit Doimk(QWidget *parent = nullptr);
    ~Doimk();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Doimk *ui;
    Menu *menu;
};

#endif // DOIMK_H
