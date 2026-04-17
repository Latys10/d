#include "carddialog.h"
#include "ui_carddialog.h"
#include <QPixmap>
#include <QRandomGenerator>
#include <QFile>
#include <QDebug>

CardDialog::CardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardDialog)
{
    ui->setupUi(this);
    connect(ui->printButton, &QPushButton::clicked, this, &CardDialog::onPrintButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &CardDialog::onCancelButtonClicked);
    setWindowTitle("Карточка персонажа");
}

CardDialog::~CardDialog()
{
    delete ui;
}

void CardDialog::setPersonData(const QList<QString> &data)
{
    if (data.size() < 8) return;
    QString type = data[0];
    QString name = data[1];
    QString health = data[4];
    QString armorStr = QString("Броня: Шлем %1, Кираса %2, Сапоги %3")
                           .arg(data[5]).arg(data[6]).arg(data[7]);

    QString infoHtml;
    if (type == "MagP") {
        QString element = data[2];
        QString mana = data[3];
        infoHtml = QString(
                       "<b>Имя:</b> %1<br>"
                       "<b>Тип:</b> Маг<br>"
                       "<b>Стихия:</b> %2<br>"
                       "<b>Мана:</b> %3<br>"
                       "<b>Здоровье:</b> <span style='color:green;'>%4</span><br>"
                       "<b>%5</b>"
                       ).arg(name, element, mana, health, armorStr);
    } else {
        QString rarity = data[2];
        QString damage = data[3];
        infoHtml = QString(
                       "<b>Имя:</b> %1<br>"
                       "<b>Тип:</b> Враг<br>"
                       "<b>Редкость:</b> %2<br>"
                       "<b>Урон:</b> %3<br>"
                       "<b>Здоровье:</b> <span style='color:red;'>%4</span><br>"
                       "<b>%5</b>"
                       ).arg(name, rarity, damage, health, armorStr);
    }
    ui->infoLabel->setText(infoHtml);
    loadImage(type);
}
void CardDialog::loadImage(const QString &type)
{
    QString selectedFile;
    if (type == "MagP") {
        selectedFile = ":/images/mag.png";
    } else {
        QStringList candidates = {
            ":/images/enemy.png",
            ":/images/enemy2.png",
            ":/images/enemy3.png"
        };
        int index = QRandomGenerator::global()->bounded(candidates.size());
        selectedFile = candidates[index];
    }

    QPixmap pix(selectedFile);
    if (!pix.isNull()) {
        QPixmap scaled = pix.scaled(ui->imageLabel->size(),
                                    Qt::KeepAspectRatio,
                                    Qt::SmoothTransformation);
        ui->imageLabel->setPixmap(scaled);
    } else {
        ui->imageLabel->setText("Ошибка: картинка не найдена в ресурсах");
    }
}
void CardDialog::onPrintButtonClicked()
{
    emit printRequested();
}

void CardDialog::onCancelButtonClicked()
{
    emit cancelRequested();
}
