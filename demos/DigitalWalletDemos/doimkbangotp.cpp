#include "doimkbangotp.h"
#include "ui_doimkbangotp.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "quenmk1.h"
#include <QCryptographicHash>
#include "dangnhap1.h"
#include <QMessageBox>
Doimkbangotp::Doimkbangotp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Doimkbangotp)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Password");
}
void replaceLineInFile(const QString &filePath, int lineNumber, const QString &newText) {
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
QString g_currentUsername2;
void setUsername2(const QString &username) {
    g_currentUsername2 = username;
}
QString getUsername2() {
    return g_currentUsername2;
}
Doimkbangotp::~Doimkbangotp()
{
    delete ui;
}
QString hashPassword3(const QString &password) {
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}
void Doimkbangotp::on_pushButton_clicked()
{
    QString username = getUsername2();
    QString path = QCoreApplication::applicationDirPath() + "/User/" + username + ".txt";
    QString password = ui->lineEdit_2->text();
    QString repair_password = ui->lineEdit_3->text();
    if (password != repair_password) return;
    QString hash_password = hashPassword3(password);
    replaceLineInFile(path,2,hash_password);
    QMessageBox::information(this,"Change Password","Password changed successfully");
    hide();
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();

                                        // thay mật khẩu bằng hàm sau khi nhập đúng otp ở quên mk

}
