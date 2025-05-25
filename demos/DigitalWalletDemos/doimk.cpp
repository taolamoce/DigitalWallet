#include "doimk.h"
#include "ui_doimk.h"
#include "menu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCryptographicHash>

QString menu_username;
void setUsername3(const QString &username ){
    menu_username = username;
}
QString getUsername3 () {
    return menu_username;
}
Doimk::Doimk(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doimk)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Password");
}

Doimk::~Doimk()
{
    delete ui;
}
void replaceLineInFile2(const QString &filePath, int lineNumber, const QString &newText) {
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Không thể mở file để đọc";
        return;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        lines.append(in.readLine());
    }
    file.close();

    if (lineNumber < 0 || lineNumber >= lines.size()) {
        qDebug() << "Dòng cần sửa không hợp lệ";
        return;
    }

    lines[lineNumber] = newText;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Không thể mở file để ghi";
        return;
    }

    QTextStream out(&file);
    for (const QString &line : lines) {
        out << line << "\n";
    }

    file.close();
}
                        // hàm thay dòng trong file
QString hashPassword4(const QString &password) {
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}
                        // băm mật khẩu
void Doimk::on_pushButton_clicked()
{
    QString username = getUsername3();
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
    QString password = ui->lineEdit->text();
    QString hashpassword = hashPassword4(password);
    if (hashpassword != file_password) {
        return;
    }
    QString new_password = ui->lineEdit_2->text();
    QString new_repairpassword = ui->lineEdit_3->text();
    if (new_password != new_repairpassword) {
        return;
    }
    QString hashnewpassword = hashPassword4(new_password);
    replaceLineInFile2(path,2,hashnewpassword);
    QMessageBox::information(this,"Change Password","Password changed successfully");
    hide();
                // đổi mật khẩu bằng hàm thay dòng
}


void Doimk::on_pushButton_2_clicked()
{
    hide();
}

