#include "giaodich.h"
#include "ui_giaodich.h"
#include <QFile>
#include <QMessageBox>
#include <QDateTime>
QString points ;
void setpoint (const QString &point ){
    points = point;
}
QString getpoint () {
    return points;
}
bool check = false;
void setCheck(const bool &Check) {
    check = Check;
}
bool getCheck() {
    return check;
}
QString usernamex ;
void setusernamex (const QString &username ){
    usernamex = username;
}
QString getusernamex () {
    return usernamex;
}
QString emailxx;
void setemailxx (const QString &email ){
    emailxx = email;
}
QString getemailxx () {
    return emailxx;
}
Giaodich::Giaodich(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Giaodich)
{
    ui->setupUi(this);
    this->setWindowTitle("Trade Point");
    this->setWindowFlags(Qt::Window);
    QString pointss= getpoint();
    ui->label_9->setText(pointss);
}

Giaodich::~Giaodich()
{
    delete ui;
}
void replaceLineInFilex(const QString &filePath, int lineNumber, const QString &newText) {
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
void Giaodich::on_pushButton_2_clicked()
{
    hide();
}


void Giaodich::on_pushButton_3_clicked()
{
    check = false;
    QString username_sender = getusernamex();
    QString username_receiver = ui->lineEdit_4->text();
    QString path_receiver = QCoreApplication::applicationDirPath() + "/User_Member/" + username_receiver + ".txt";
    QString path_sender = QCoreApplication::applicationDirPath() + "/User_Member/" + username_sender + ".txt";
    QFile file(path_receiver);
    if (!file.exists()) {
        QMessageBox::warning(this, "Trade", "Recipient account does not exist!");
        return;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    QString email = in.readLine();
    QString file_username = in.readLine();
    QString file_password = in.readLine();
    QString receiver_point = in.readLine();
    file.close();
    QString sender_point = getpoint();
    QString trade_point = ui->lineEdit_5->text();
    int check1 = sender_point.toInt();
    int check2 = trade_point.toInt();
    if (check1 < check2) {
        QMessageBox::information(this,"Trade","Your point is not enough");
        return;
    }


    setUsernamex(file_username);
    setemailx(getemailxx());
    tradeotp = new Tradeotp(this);
    if (tradeotp->exec() == QDialog::Accepted) {
        int point1 = sender_point.toInt();
        int point2 = receiver_point.toInt();
        int chenh = trade_point.toInt();
        point1-=chenh;
        point2+=chenh;
        QString s_point = QString::number(point1);
        QString r_point = QString::number(point2);
        replaceLineInFilex(path_sender,3,s_point);
        replaceLineInFilex(path_receiver,3,r_point);
        QMessageBox::information(this,"Trade","Successful Transaction");
        ui->label_9->setText(s_point);
        QString Loinhac = ui->lineEdit->text();
        ui->lineEdit->clear();
        ui->lineEdit_4->clear();
        ui->lineEdit_5->clear();
                                        // kiểm tra số dư và giao dịch bằng hàm thay dòng

        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        QString history_sender_path = QCoreApplication::applicationDirPath() + "/User/" + username_sender + "_history.txt";
        QFile sender_history(history_sender_path);
        if (sender_history.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&sender_history);
            out << "[" << timestamp << "] Send " << chenh << " points at " << username_receiver << " with reminder" << " -> " << Loinhac << "\n";
            sender_history.close();
        }
                                        // tạo lịch sử người gửi
        QString history_receiver_path = QCoreApplication::applicationDirPath() + "/User/" + username_receiver + "_history.txt";
        QFile receiver_history(history_receiver_path);
        if (receiver_history.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&receiver_history);
            out << "[" << timestamp << "] Receive " << chenh << " points from " << username_sender << " with reminder" << " -> " << Loinhac<< "\n";
            receiver_history.close();
        }
                                        // tạo lịch sử người nhận
        return;
    }

}

