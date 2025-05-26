#ifndef GIAODICH_H
#define GIAODICH_H


#include <QDialog>
#include "menu.h"
#include "tradeotp.h"

class Menu;
namespace Ui {
class Giaodich;

}
class Tradeotp;
void setpoint (const QString &point );
void setCheck(const bool &Check);
void replaceLineInFilex(const QString &filePath, int lineNumber, const QString &newText);
void setusernamex (const QString &username );
void setemailxx (const QString &email );
class Giaodich : public QDialog
{
    Q_OBJECT

public:
    explicit Giaodich(QWidget *parent = nullptr);
    ~Giaodich();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Giaodich *ui;
    Menu *menu;
    Tradeotp *tradeotp;
};

#endif // GIAODICH_H
