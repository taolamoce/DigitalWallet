#ifndef HISTORYDIALOG_H
#define HISTORYDIALOG_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class HistoryDialog;
}

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(QWidget *parent = nullptr, const QString &username = "");
    ~HistoryDialog();

private:
    QTextEdit *textEdit;
};

#endif // HISTORYDIALOG_H
