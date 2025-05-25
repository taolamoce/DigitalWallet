#ifndef QUANLI_H
#define QUANLI_H
#include "dangki1.h"
#include <QDialog>
#include <QListWidgetItem>
#include "dangnhap1.h"
namespace Ui {
class Quanli;
}
class Dangnhap1;
class Quanli : public QDialog
{
    Q_OBJECT

public:
    explicit Quanli(QWidget *parent = nullptr);
    ~Quanli();
private slots:
    void onFileSelected(QListWidgetItem *item);
    void onSaveClicked();

    void on_pushButton_2_clicked();

    void on_pushButtonHash_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Quanli *ui;
    QString folderPath;
    QString currentFilePath;
    void loadUserFileList();
    Dangnhap1 *dangnhap1;
};

#endif // QUANLI_H
