#include "dangki1.h"
#include "ui_dangki1.h"
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QPixmap>
#include <QCryptographicHash>
#include <QRandomGenerator>
#include "menu.h"
// #include "useraccount.h"
Dangki1::Dangki1(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Dangki1)
{
    ui->setupUi(this);
    this->setWindowTitle("Register");
    this->setWindowFlags(Qt::Window);
    QPixmap pixmap2(":/picture/raw.png");
    QPixmap scaled2 = pixmap2.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(scaled2);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dangki1::hideEmailLabel);
    connect(ui->lineEdit_2, &QLineEdit::textChanged, this, &Dangki1::hideUsernameLabel);
    connect(ui->lineEdit_3, &QLineEdit::textChanged, this, &Dangki1::hidePasswordLabel);
    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &Dangki1::hideRepairPasswordLabel);
}

Dangki1::~Dangki1()
{
    delete ui;
}

QString generateRandomPassword(int length = 8) {
    const QString chars = "abcdefghijklmnopqrstuvwxyz"
                          "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                          "0123456789"
                          "!@#$%^&*()_+-=[]{}|;:,.<>?";

    QString password;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(chars.length());
        password.append(chars.at(index));
    }
    return password;
}
                            // random mật khẩu khi người dùng không nhập vào


void Dangki1::on_pushButton_2_clicked()
{
    hide();
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();
}
                            // hiện cửa sổ đăng nhập

QString hashPassword(const QString &password) {
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}
                            // băm mật khẩu
void Dangki1::on_pushButton_clicked()
{   QString point = "0";
    QString email = ui->lineEdit->text();
    QString username = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QString repair_password = ui->lineEdit_4->text();
    QString hashpassword = hashPassword(password);
    QString repair_hashpassword = hashPassword(repair_password);
    if (email.isEmpty() || username.isEmpty() ) {
        QMessageBox::warning(this,"Register","Please enter username and email");
        return;
    }
    if (password == "") {
        setmkho(false);
    }
    if (hashpassword != repair_hashpassword) {
        QMessageBox::warning(this,"Register","Passwords do not match!");
        return;
    }
    // UserAccount newUser(username, password, email);
    QString basePath = QCoreApplication::applicationDirPath();
    QString userFoder = basePath + "/User";
    QDir dir(userFoder);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QString userFoderBackup = basePath + "/Backup";
    QDir dir2(userFoderBackup);
    if (!dir2.exists()) {
        dir2.mkpath(".");
    }
    QString filePath = userFoder + "/" + username + ".txt";
    QString filePathBackup = userFoderBackup + "/" + username + ".txt";
    QFile file(filePath);
    if (file.exists()) {
        QMessageBox::warning(this,"Register","Username already exists!");
        return;
    }
    // lấy username thêm .txt và tạo foder /User và ghi 4 dòng và đưa file vào /User
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out<<email<<"\n"<<username<<"\n"<<hashpassword<<"\n"<<point;
        file.close();
        QFile filebackup(filePathBackup);
        if (filebackup.open(QIODevice::WriteOnly | QIODevice::Text)) {
            out<<email<<"\n"<<username<<"\n"<<hashpassword<<"\n"<<point;
        }
                // tạo backup và thêm username.txt vào
        QMessageBox::information(this,"Register","Registration Successful!");
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
        setmk2(false);
    } else {
        QMessageBox::critical(this, "Register", "Failed to save user data!");
        return;
    }
}
void Dangki1::hideEmailLabel()
{
    if (!ui->lineEdit->text().isEmpty()) {
        ui->label_5->hide();
    } else {
        ui->label_5->show();
    }
}

void Dangki1::hideUsernameLabel()
{
    if (!ui->lineEdit_2->text().isEmpty()) {
        ui->label_6->hide();
    } else {
        ui->label_6->show();
    }
}

void Dangki1::hidePasswordLabel()
{
    if (!ui->lineEdit_3->text().isEmpty()) {
        ui->label_7->hide();
    } else {
        ui->label_7->show();
    }
}

void Dangki1::hideRepairPasswordLabel()
{
    if (!ui->lineEdit_4->text().isEmpty()) {
        ui->label_8->hide();
    } else {
        ui->label_8->show();
    }
}

