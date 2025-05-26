#include "menu.h"
#include "ui_menu.h"
#include <QFile>
#include <QMessageBox>
#include "dangnhap1.h"
#include "giaodich.h"
#include "doimk.h"
#include "historydialog.h"
#include "taomkcap2.h"
#include "nhapmkcap2.h"
#include "mkhauho.h"
bool checkmkho = true;
void setmkho (const bool &check) {
    checkmkho = check;
}
bool getmkho() {
    return checkmkho;
}
bool checkmk2 = true;
void setmk2 (const bool &check){
    checkmk2 = check;
}
bool getmk2 (){
    return checkmk2;
}

QString changeusername ;
void setusername (const QString &username ){
    changeusername = username;
}
QString getusername () {
    return changeusername;
}

Menu::Menu(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->setWindowTitle("Menu");
    this->setWindowFlags(Qt::Window);
    ui->label_21->hide();
    ui->groupBox->hide();
    QString username2 = getusername();
    ui->label_3->setText(username2);

    if (!getmkho()) {
        mkhauho = new Mkhauho(this);
        setusernameho(getusername());

        if (mkhauho->exec() == QDialog::Accepted) {
            checkmkho = true;
        }
    } // mở cửa sổ khi mật khẩu bị bỏ trống

    if (!getmk2()){
        taomkcap2 = new Taomkcap2(this);
        setusernamemk2(getusername());

        if (taomkcap2->exec() == QDialog::Accepted){
            checkmk2 = true;
            return;
        // mở cửa sổ tạo mk cấp 2
        }
    }
}
QString bien = "0";
Menu::~Menu()
{
    delete ui;
}

void Menu::on_mat_clicked()
{
    QString username = getusername();
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
    QString point = in.readLine();
    file.close();
    ui->label_21->setText(point);
    if (bien == "0"){
        ui->label_21->show();
        ui->label_9->hide();
        bien = "1";
    }
    else {
        ui->label_9->show();
        ui->label_21->hide();
        bien = "0";
    }
    // ẩn hiện số point dư
}


void Menu::on_tk1_clicked()
{
    QString username = getusername();
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



    ui->label_10->setText("Username : "+file_username);
    ui->label_11->setText("Email : "+email);
    ui->label_12->setText("Password : *********");
    ui->groupBox->show();
}
                        // tạo cách member khi nhấn vào account


void Menu::on_pushButton_4_clicked()
{

    setusernamemk22(getusername());
    nhapmk2 = new Nhapmk2(this);
    if (nhapmk2->exec() == QDialog::Accepted) {
        QString username = getusername();
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
        QString point = in.readLine();
        file.close();
        setpoint(point);
        setusernamex(file_username);
        setemailxx(email);


        giaodich = new Giaodich(this);
        giaodich->show();
        // mở cửa sổ giao dịch và gửi point,username,email qua cửa sổ
    }
}

void Menu::on_tk1_4_clicked()
{
    hide();
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();
}
                            // thoát cửa sổ đăng nhập


void Menu::on_pushButton_6_clicked()
{
    setusernamemk22(getusername());
    nhapmk2 = new Nhapmk2(this);
    if (nhapmk2->exec() == QDialog::Accepted) {
        QString username = getusername();
        setUsername3(username);
        doimk = new Doimk(this);
        doimk->show();
    }
}                           // show window đổi mật khẩu


void Menu::on_tk1_3_clicked()
{
    help1 = new Help1(this);
    help1->show();
}
        // mở ui phần help và xem

void Menu::on_tk1_2_clicked()
{
    QString username = getusername();
    HistoryDialog *history = new HistoryDialog(this, username);
    history->exec();
}
                // xem lịch sử giao dịch

