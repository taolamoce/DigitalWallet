#include "historydialog.h"
#include "ui_historydialog.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include <QFile>
#include <QDir>
HistoryDialog::HistoryDialog(QWidget *parent, const QString &username)
    : QDialog(parent)
{
    setWindowTitle("Transaction History");
    resize(500,400);
    textEdit = new QTextEdit(this);
    textEdit->setReadOnly(true);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(textEdit);

    QString basePath = QCoreApplication::applicationDirPath();
    QString userFoder = basePath + "/User_Member";
    QDir dir(userFoder);
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QString historyPath = QCoreApplication::applicationDirPath() + "/User_Member/" + username + "_history.txt";
    QFile file(historyPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    } else {
        textEdit->setText("No Transaction History");
    }
    // đọc từ file _history.txt và xem lịch sử giao dịch
}
HistoryDialog::~HistoryDialog()
{

}
