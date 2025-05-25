#include "tradeotp.h"
#include "ui_tradeotp.h"
#include "qpixmap.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include "../../src/SmtpMime"
#include "../demo_vars.h"
#include <QRandomGenerator>
#include <QTimer>
#include "giaodich.h"
QDateTime g_otpGeneratedTimex;
Tradeotp::Tradeotp(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Tradeotp)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter OTP");
    this->setWindowFlags(Qt::Window);
    QPixmap pixmap(":/picture/raw.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaledPixmap);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) ui->lineEdit_2->setFocus();
    });

    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) ui->lineEdit_3->setFocus();
    });

    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) ui->lineEdit_4->setFocus();
    });
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) {
            ui->pushButton->setFocus();
        }
    });

    resendTimer = new QTimer(this);
    countdown = 60; // hoặc bao nhiêu giây bạn muốn

    connect(resendTimer, &QTimer::timeout, this, [=]() {
        countdown--;
        ui->pushButton_2->setText(QString("Gửi lại OTP (%1)").arg(countdown));
        if (countdown <= 0) {
            resendTimer->stop();
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_2->setText("Gửi lại OTP");
        }
    });
}
Tradeotp::~Tradeotp()
{
    delete ui;
}

static QString savedOTP;

QString g_currentOTPx="0";
static QString g_currentUsernamex;
static QString g_currentemailx;
void setUsernamex(const QString &username) {
    g_currentUsernamex = username;
}
void setemailx(const QString &email) {
    g_currentemailx = email;
}
void generateNewOTPx(const QString &newotp) {
    setOTP(newotp);
    g_otpGeneratedTimex = QDateTime::currentDateTime();
}
QString getOTPx() {
    return g_currentOTPx;
}
QString getUsernamex() {
    return g_currentUsernamex;
}
QString getemailx() {
    return g_currentemailx;
}
void Tradeotp::on_pushButton_clicked()
{
    QString OLD_OTP = getOTP();
    QDateTime now = QDateTime::currentDateTime();
    int timeoutSeconds = 300;
    if (g_otpGeneratedTimex.secsTo(now) > timeoutSeconds) {
        QMessageBox::warning(this, "OTP Expired", "Mã OTP đã hết hạn. Vui lòng yêu cầu mã mới.");
        return;
    }
    QString box1 = ui->lineEdit->text();
    QString box2 = ui->lineEdit_2->text();
    QString box3 = ui->lineEdit_3->text();
    QString box4 = ui->lineEdit_4->text();
    QString GMAIL_OTP = box1 + box2 + box3 + box4;
    if (OLD_OTP == GMAIL_OTP) {
        QMessageBox::information(this,"OTP","OTP is correct!");
        accept();
        hide();
    } else {
        QMessageBox::warning(this,"OTP","OTP is incorrect!");
    }
}

QString generateOTPx(int length = 4) {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    QString otp;

    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        otp.append(possibleCharacters.at(index));
    }

    return otp;
}
void Tradeotp::on_pushButton_2_clicked()
{
    countdown = 60;
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_2->setText(QString("Gửi lại OTP (%1)").arg(countdown));
    resendTimer->start(1000);


    QString new_OTP = generateOTPx();

    // Credit : SmtpClient-for-Qt
    QString RECIPIENT_NAME = getUsernamex();
    QString RECIPIENT_EMAIL = getemailx();
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

    generateNewOTPx(new_OTP);



}
