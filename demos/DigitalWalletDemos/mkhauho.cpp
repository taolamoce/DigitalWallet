 #include "mkhauho.h"
#include "ui_mkhauho.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
QString usernameho;
void setusernameho(const QString &username) {
    usernameho = username;
}
QString getusernameho() {
    return usernameho;
}
Mkhauho::Mkhauho(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Mkhauho)
{
    ui->setupUi(this);
    this->setWindowTitle("Change Password");
}

Mkhauho::~Mkhauho()
{
    delete ui;
}
void replaceLineInFile4(const QString &filePath, int lineNumber, const QString &newText) {
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
QString hashPassword6(const QString &password) {
    QByteArray hashed = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return hashed.toHex();
}
                                    // hàm băm mật khẩu
void Mkhauho::on_pushButton_clicked()
{
    QString new_password = ui->lineEdit->text();
    QString new_repairpassword = ui->lineEdit_2->text();
    if (new_password != new_repairpassword) {
        return;
    }
    QString username = getusernameho();
    QString path = QCoreApplication::applicationDirPath() + "/User/" + username + ".txt";
    QString new_hashPassword = hashPassword6(new_password);
    replaceLineInFile4(path,2,new_hashPassword);
    QMessageBox::information(this,"Change Password","Password changed successfully");
    accept();
                                // đổi mật khẩu do mật khẩu bỏ trống
}

