#include "quenmk1.h"
#include "ui_quenmk1.h"
#include <QPixmap>
#include "../../src/SmtpMime"
#include "../demo_vars.h"
#include "otp.h"
#include <QMessageBox>
#include <QFile>
#include <QRandomGenerator>
#include "dangnhap1.h"
#include "doimkbangotp.h"
Quenmk1::Quenmk1(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Quenmk1)
{
    ui->setupUi(this);
    this->setWindowTitle("Forgot Password");
    this->setWindowFlags(Qt::Window);
    QPixmap pixmap(":/picture/raw.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaledPixmap);
    ui->label_5->hide();
}

Quenmk1::~Quenmk1()
{
    delete ui;
}
QString generateOTP(int length = 4) {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString otp;

    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        otp.append(possibleCharacters.at(index));
    }

    return otp;
}
void Quenmk1::on_pushButton_clicked()
{
    ui->label_5->show();
    QString username = ui->lineEdit->text();
    if (username.isEmpty()) {
        QMessageBox::warning(this,"Login","Please enter both username!");
        ui->label_5->hide();
        return;
    }
    QString path = QCoreApplication::applicationDirPath() + "/User/" + username + ".txt";
    qDebug() << path;
    QFile file(path);
    if (!file.exists()) {
        QMessageBox::warning(this, "Login", "Account does not exist!");
        ui->label_5->hide();
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Login", "Cannot open user file!");
        ui->label_5->hide();
        return;
    }
    QTextStream in(&file);
    QString email = in.readLine();
    QString file_username = in.readLine();
    file.close();

    QString new_OTP = generateOTP();

                                                            // Credit : SmtpClient-for-Qt
    QString RECIPIENT_NAME = file_username;
    QString RECIPIENT_EMAIL = email;
    // QCoreApplication a(argc, argv);

    MimeMessage message;

    EmailAddress sender(SENDER_EMAIL, SENDER_NAME);
    message.setSender(sender);

    EmailAddress to(RECIPIENT_EMAIL, RECIPIENT_NAME);
    message.addRecipient(to);

    message.setSubject("Digital Wallet send to OTP");

    message.setHeaderEncoding(MimePart::Encoding::QuotedPrintable);


    MimeText text;

    text.setText("Hi\nMy OTP : " + new_OTP);

    message.addPart(&text);


    SmtpClient smtp(SMTP_SERVER, 465, SmtpClient::SslConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected()) {
        qDebug() << "Failed to connect to host!";
        return;
    }

    smtp.login(SENDER_EMAIL, SENDER_PASSWORD);
    if (!smtp.waitForAuthenticated()) {
        qDebug() << "Failed to login!";
        return;
    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent()) {
        qDebug() << "Failed to send mail!";
        return;
    }
    smtp.quit();


                                                        // Credit : SmtpClient-for-Qt

    generateNewOTP(new_OTP);
    setUsername(file_username);
    setemail(email);
    setUsername2(file_username);



    hide();
    otp = new Otp(this);
    otp->show();
}


void Quenmk1::on_pushButton_2_clicked()
{
    hide();
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();

}

