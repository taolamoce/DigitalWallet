#include "trogiupnguoidung.h"
#include "ui_trogiupnguoidung.h"
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include "../../src/SmtpMime"
#include "../demo_vars.h"
Trogiupnguoidung::Trogiupnguoidung(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Trogiupnguoidung)
{
    ui->setupUi(this);
    this->setWindowTitle("Support");
    connect(ui->textEdit, &QTextEdit::textChanged, this, &Trogiupnguoidung::hideTextEdit);
}

Trogiupnguoidung::~Trogiupnguoidung()
{
    delete ui;
}

void Trogiupnguoidung::on_pushButton_3_clicked()
{
    QString noidung = ui->textEdit->toPlainText();
    QString RECIPIENT_NAME = "EmChien";
    QString RECIPIENT_EMAIL = "emchienehe@gmail.com";
    // QCoreApplication a(argc, argv);
    MimeMessage message;

    EmailAddress sender(SENDER_EMAIL, SENDER_NAME);
    message.setSender(sender);

    EmailAddress to(RECIPIENT_EMAIL, RECIPIENT_NAME);
    message.addRecipient(to);

    message.setSubject("Support User");

    message.setHeaderEncoding(MimePart::Encoding::QuotedPrintable);


    MimeText text;

    text.setText("Content : \n" + noidung);

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
    hide();
}
void Trogiupnguoidung::hideTextEdit()
{
    if (!ui->textEdit->toPlainText().isEmpty()) {
        ui->label_3->hide();
    } else {
        ui->label_3->show();
    }
}
