#ifndef TRADEOTP_H
#define TRADEOTP_H

#include <QDialog>
#include <QString>
#include "quenmk1.h"
#include <QDateTime>
#include <QTimer>
#include "giaodich.h"
extern QDateTime g_otpGeneratedTime;
namespace Ui {
class Tradeotp;
}
class Giaodich;
void setOTPx(const QString &otp);
void setUsernamex(const QString &username);
void setemailx(const QString &email);
void generateNewOTPx(const QString &newotp);
class Tradeotp : public QDialog
{
    Q_OBJECT
public:
    explicit Tradeotp(QWidget *parent = nullptr);
    ~Tradeotp();
private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::Tradeotp *ui;
    QTimer *resendTimer;
    int countdown;
    Giaodich *giaodich;
};

#endif // TRADEOTP_H
