#ifndef CARDDIALOG_H
#define CARDDIALOG_H

#include <QDialog>
#include <QList>

namespace Ui {
class CardDialog;
}

class CardDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CardDialog(QWidget *parent = nullptr);
    ~CardDialog();
    void setPersonData(const QList<QString> &data);

signals:
    void printRequested();
    void cancelRequested();

private slots:
    void onPrintButtonClicked();
    void onCancelButtonClicked();

private:
    Ui::CardDialog *ui;
    void loadImage(const QString &type);
};

#endif // CARDDIALOG_H
