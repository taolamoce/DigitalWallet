#include "dangnhap1.h"
#include "ui_dangnhap1.h"
#include "dangki1.h"
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include "menu.h"
#include "quanli.h"
#include "trogiupnguoidung.h"
// #include "usermanager.h"
// #include "useraccount.h"
Dangnhap1::Dangnhap1(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Dangnhap1)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
    this->setWindowFlags(Qt::Window);
    QPixmap pixmap(":/picture/raw.png");
    QPixmap scaledPixmap = pixmap.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaledPixmap);
}

Dangnhap1::~Dangnhap1()
{
    delete ui;
}

void Dangnhap1::on_pushButton_2_clicked()                   // nút mở cửa sổ đăng kí
{
    hide();
    dangki1 = new Dangki1(this);
    dangki1->show();
}
QString hashPassword2(const QString &password)              // băm mật khẩu
{
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}


void Dangnhap1::on_pushButton_clicked()
{
    QString username = ui->lineEdit_2->text();
    QString password = ui->lineEdit->text();
    if (username == "admin" && password == "123") {       // mở cửa sổ manager
        hide();
        quanli = new Quanli(this);
        quanli->show();
        return;
    }
    QString hash_password = hashPassword2(password);

    if (username.isEmpty()) {
        QMessageBox::warning(this,"Login","Please enter both username and password!");
        return;
    }
    QString path = QCoreApplication::applicationDirPath() + "/User/" + username + ".txt";
    qDebug() << path;
    QFile file(path);
    if (!file.exists()) {
        QMessageBox::warning(this, "Login", "Account does not exist!");
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Login", "Cannot open user file!");
        return;
    }
    QTextStream in(&file);
    QString email = in.readLine();
    QString file_username = in.readLine();
    QString file_password = in.readLine();
    file.close();
                    // lấy tài khoản bằng username.txt và đọc lấy 3 dòng email,username,password
                    // và so sánh với 2 lineEdit nhập vào
    if (file_password == hash_password) {
        QMessageBox::information(this,"Login","Login Successful!");
        setusername(file_username);
        hide();
        menu = new Menu(this);
        menu->show();
                    // hiện cửa sổ menu
    } else {
        QMessageBox::warning(this,"Login","Incorrect Password!");
    }
}



void Dangnhap1::on_pushButton_3_clicked()
{
    hide();
    quenmk1 = new Quenmk1(this);
    quenmk1->show();
}                           // hiện cửa sổ quên mật khẩu


void Dangnhap1::on_pushButton_4_clicked()
{
    trogiupnguoidung = new Trogiupnguoidung(this);
    trogiupnguoidung->show();
}                           // hiện cửa sổ support

