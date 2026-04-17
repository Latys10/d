#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "magp.h"
#include "vragp.h"
#include "carddialog.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Заголовки колонок уже заданы в .ui, дополнительный код не нужен
}

MainWindow::~MainWindow()
{
    clearCharacters();
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Выберите файл", "", "*.txt");
    if (!path.isEmpty()) loadFromFile(path);
}

void MainWindow::loadFromFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        return;
    }

    clearCharacters();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        // Парсим броню <a/b/c>
        int armorStart = line.indexOf('<');
        int armorEnd = line.indexOf('>');
        Armor armor(0,0,0);
        if (armorStart != -1 && armorEnd != -1) {
            QString armorStr = line.mid(armorStart+1, armorEnd-armorStart-1);
            QStringList parts = armorStr.split('/');
            if (parts.size() == 3) {
                armor.helmet = parts[0].toInt();
                armor.chestplate = parts[1].toInt();
                armor.boots = parts[2].toInt();
            }
            line.remove(armorStart, armorEnd - armorStart + 1);
        }

        QStringList tokens = line.split(' ', Qt::SkipEmptyParts);
        if (tokens.size() < 5) continue;

        int code = tokens[0].toInt();
        QString name = tokens[1];
        QString third = tokens[2];
        int fourth = tokens[3].toInt();
        int health = tokens[4].toInt();

        if (code == 1) { // VragP: редкость, урон
            characters.append(new VragP(name, third, fourth, health, armor));
        } else if (code == 2) { // MagP: стихия, мана
            characters.append(new MagP(name, third, fourth, health, armor));
        }
    }
    file.close();
    displayCharactersInTable();
}

void MainWindow::displayCharactersInTable()
{
    ui->tableWidget->setRowCount(characters.size());
    for (int i = 0; i < characters.size(); ++i) {
        QList<QString> data = characters[i]->craft();
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(data[1])); // имя
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(data[0])); // тип
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(data[2])); // хар-ка1
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(data[3])); // хар-ка2
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(data[4])); // здоровье
        QString armorStr = QString("%1/%2/%3").arg(data[5]).arg(data[6]).arg(data[7]);
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(armorStr));
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::clearCharacters()
{
    qDeleteAll(characters);
    characters.clear();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int)
{
    if (row < 0 || row >= characters.size()) return;
    CardDialog dialog(this);
    dialog.setPersonData(characters[row]->craft());

    // При нажатии "Печать" – удаляем персонажа, обновляем таблицу и закрываем диалог
    connect(&dialog, &CardDialog::printRequested, [this, row, &dialog]() {
        delete characters[row];
        characters.removeAt(row);
        displayCharactersInTable();
        dialog.close();   // закрываем карточку
    });

    // При нажатии "Отмена" – просто закрываем диалог
    connect(&dialog, &CardDialog::cancelRequested, [&dialog]() {
        dialog.close();
    });

    dialog.exec(); // модальное окно
}
