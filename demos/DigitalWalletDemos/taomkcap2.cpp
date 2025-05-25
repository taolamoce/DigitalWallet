#include "taomkcap2.h"
#include "ui_taomkcap2.h"
#include "menu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
QString usernamemk2;
void setusernamemk2(const QString &username){
    usernamemk2 = username;
}
QString getusernamemk2(){
    return usernamemk2;
}


Taomkcap2::Taomkcap2(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Taomkcap2)
{
    ui->setupUi(this);
    this->setWindowTitle("Create Password");
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

Taomkcap2::~Taomkcap2()
{
    delete ui;
}

void Taomkcap2::on_pushButton_clicked()
{
    QString box1 = ui->lineEdit->text();
    QString box2 = ui->lineEdit_2->text();
    QString box3 = ui->lineEdit_3->text();
    QString box4 = ui->lineEdit_4->text();
    QString box5 = ui->lineEdit_5->text();
    QString box6 = ui->lineEdit_6->text();

    QString mkcap2 = box1 + box2 + box3 + box4 + box5 + box6;
    QString username = getusernamemk2();
    QString basePath = QCoreApplication::applicationDirPath();
    QString userFoder = basePath + "/User_Member";
    QDir dir(userFoder);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QString path = QCoreApplication::applicationDirPath() + "/User_Member/" + username + "_mkcap2.txt";
    QFile file(path);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << mkcap2;
        QMessageBox::information(this,"Create level 2 Password","Created level 2 password successfully");
        file.close();
        accept();
    }
                                // tạo mật khẩu 2 .txt vô trong phần /User_Member
}

