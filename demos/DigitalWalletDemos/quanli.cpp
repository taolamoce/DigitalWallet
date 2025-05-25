#include "quanli.h"
#include "ui_quanli.h"
#include <QDir>
#include <QFile>
#include <QFileInfoList>
#include <QTextStream>
#include <QMessageBox>
#include "dangki1.h"
Quanli::Quanli(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::Quanli)
{
    ui->setupUi(this);
    this->setWindowTitle("Manager");
    this->setWindowFlags(Qt::Window);
    folderPath = QCoreApplication::applicationDirPath() + "/User/";// đường dẫn đến thư mục chứa file txt

    loadUserFileList();

    connect(ui->listWidgetFiles, &QListWidget::itemClicked, this, &Quanli::onFileSelected);
    connect(ui->pushButtonSave, &QPushButton::clicked, this, &Quanli::onSaveClicked);
    ui->textEditNewUser->hide();
    ui->textEditHash->hide();
}

Quanli::~Quanli()
{
    delete ui;
}
void Quanli::loadUserFileList() {
    QDir dir(folderPath);
    QStringList filters;
    filters << "*.txt";

    QFileInfoList files = dir.entryInfoList(filters, QDir::Files);
    for (const QFileInfo &fileInfo : files) {
        ui->listWidgetFiles->addItem(fileInfo.fileName());
    }
}
                                // load file tránh crash
void Quanli::onFileSelected(QListWidgetItem *item) {
    ui->textEditContent->show();
    ui->textEditNewUser->hide();
    ui->textEditHash->hide();
    QString fileName = item->text();
    currentFilePath = folderPath + "/" + fileName;

    QFile file(currentFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        ui->textEditContent->setPlainText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, "Lỗi", "Không thể mở file.");
    }
}
                                // chọn file cần xem
void Quanli::onSaveClicked() {

    if (currentFilePath.isEmpty()) {
        QMessageBox::information(this, "Thông báo", "Chưa chọn file để lưu.");
        return;
    }

    QFile file(currentFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEditContent->toPlainText();
        file.close();
        QMessageBox::information(this, "Thành công", "Đã lưu nội dung.");
    } else {
        QMessageBox::warning(this, "Lỗi", "Không thể lưu file.");
    }
}
                                // lưu file
void Quanli::on_pushButton_2_clicked()
{
    ui->textEditContent->hide();
    ui->textEditHash->hide();
    ui->textEditNewUser->show();
    QString content = ui->textEditNewUser->toPlainText().trimmed();

    if (content.isEmpty()) {
        return;
    }

    QStringList lines = content.split('\n');

    QString username = lines.at(1);

    if (username.isEmpty()) {
        return;
    }

    QString fileName = username;
    fileName += ".txt";

    QString filePath = QCoreApplication::applicationDirPath() + "/User/" + "/" + fileName;

    QFile file(filePath);
    if (file.exists()) {
        QMessageBox::warning(this, "Tồn tại", "Người dùng đã tồn tại.");
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << content;
        file.close();

        ui->listWidgetFiles->addItem(fileName);
        QMessageBox::information(this, "Thành công", "Đã thêm người dùng.");
        ui->textEditNewUser->clear();
    } else {
        QMessageBox::warning(this, "Lỗi", "Không thể tạo file.");
    }
}
                                // tạo file user khi có hỗ trợ

void Quanli::on_pushButtonHash_clicked()
{
    ui->textEditContent->hide();
    ui->textEditNewUser->hide();
    ui->textEditHash->show();
    QString password = ui->textEditHash->toPlainText();
    if (password == "") return;
    QString hash_password = hashPassword(password);
    ui->textEditHash->setText(hash_password);
}
            // quản lí có thể tùy ý băm mật khảu


void Quanli::on_pushButton_4_clicked()
{
    hide();
    dangnhap1 = new Dangnhap1(this);
    dangnhap1->show();
}

