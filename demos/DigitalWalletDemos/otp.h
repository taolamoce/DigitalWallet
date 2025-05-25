#ifndef OTP_H
#define OTP_H

#include <QDialog>
#include <QString>
#include "quenmk1.h"
#include <QDateTime>
#include <QTimer>
#include "doimkbangotp.h"
extern QDateTime g_otpGeneratedTime;
namespace Ui {
class Otp;
}
class Doimkbangotp;
void setOTP(const QString &otp);
void setUsername(const QString &username);
void setemail(const QString &email);
QString getOTP();
void generateNewOTP(const QString &newotp);
class Otp : public QDialog
{
    Q_OBJECT
public:
    explicit Otp(QWidget *parent = nullptr);
    ~Otp();
private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

private:
    Ui::Otp *ui;
    QTimer *resendTimer;
    int countdown;
    Doimkbangotp *doimkbangotp;
};

#endif // OTP_H
