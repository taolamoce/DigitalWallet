#include "nhapmkcap2.h"
#include "ui_nhapmkcap2.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
QString usernamemk22;
void setusernamemk22(const QString &username){
    usernamemk22 = username;
}
QString getusernamemk22(){
    return usernamemk22;
}

Nhapmk2::Nhapmk2(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Nhapmk2)
{
    ui->setupUi(this);
    this->setWindowTitle("Enter Password");
    this->setWindowFlags(Qt::Window);
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
            ui->lineEdit_5->setFocus();
        }
    });
    connect(ui->lineEdit_5, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) ui->lineEdit_6->setFocus();
    });

    connect(ui->lineEdit_6, &QLineEdit::textChanged, this, [=](const QString &text) {
        if (text.length() == 1) ui->pushButton->setFocus();
    });


}

Nhapmk2::~Nhapmk2()
{
    delete ui;
}

void Nhapmk2::on_pushButton_clicked()
{
    QString username = getusernamemk22();
    QString path = QCoreApplication::applicationDirPath() + "/User_Member/" + username + "_mkcap2.txt";
    qDebug() << path;
    QFile file(path);
    QString mkcap2;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        mkcap2 = in.readLine();
        file.close();
    } else {
        qDebug() << "Không mở được file tại:" << path;
        return;
    }

    QString box1 = ui->lineEdit->text();
    QString box2 = ui->lineEdit_2->text();
    QString box3 = ui->lineEdit_3->text();
    QString box4 = ui->lineEdit_4->text();
    QString box5 = ui->lineEdit_5->text();
    QString box6 = ui->lineEdit_6->text();

    QString mkcap22 = box1 + box2 + box3 + box4 + box5 + box6;

    if (mkcap2 == mkcap22){
        QMessageBox::information(this,"Enter Password","Password entered successfully");
        accept();
    } else return;
    // mở file chứa mật khẩu cấp 2 đọc và so sánh, accept
}

