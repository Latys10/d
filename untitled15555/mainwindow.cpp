#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lesson.h"
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    typeGroup = new QButtonGroup(this);
    typeGroup->addButton(ui->lectureRadio);
    typeGroup->addButton(ui->practiceRadio);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    ui->resetButton->setStyleSheet("background-color: red; color: white;");
    ui->saveButton->setStyleSheet("background-color: green; color: white;");
    setStyleSheet("background-color: white;");
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResetClicked()
{
    ui->subjectEdit->clear();
    ui->teacherEdit->clear();
    ui->classroomEdit->clear();
    ui->scheduleNumberEdit->clear();
    typeGroup->setExclusive(false);
    ui->lectureRadio->setChecked(false);
    ui->practiceRadio->setChecked(false);
    typeGroup->setExclusive(true);
    ui->controlCheck->setChecked(false);
    ui->attendanceCheck->setChecked(false);
    ui->cancelCheck->setChecked(false);
}

void MainWindow::onSaveClicked()
{
    QString subject = ui->subjectEdit->text().trimmed();
    QString teacher = ui->teacherEdit->text().trimmed();
    QString classroom = ui->classroomEdit->text().trimmed();
    QString scheduleNumber = ui->scheduleNumberEdit->text().trimmed();
    if (subject.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Предмет' не может быть пустым.");
        return;
    }
    if (teacher.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Преподаватель' не может быть пустым.");
        return;
    }
    if (classroom.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Аудитория' не может быть пустым.");
        return;
    }
    if (scheduleNumber.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле 'Номер в расписании' не может быть пустым.");
        return;
    }
    if (!ui->lectureRadio->isChecked() && !ui->practiceRadio->isChecked()) {
        QMessageBox::warning(this, "Ошибка", "Выберите тип пары (Лекция или Практика).");
        return;
    }
    QString type = ui->lectureRadio->isChecked() ? "Лекция" : "Практика";
    QRegularExpression subjectRx("^[А-Я][а-я]*(\\s[А-Я][а-я]*)*$");
    if (!subjectRx.match(subject).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Предмет должен содержать только русские буквы, с заглавной.");
        return;
    }
    QRegularExpression teacherRx("^[А-Я][а-я]*(\\s[А-Я][а-я]*)*$");
    if (!teacherRx.match(teacher).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Преподаватель должен быть");
        return;
    }
    QRegularExpression classroomRx("^(10[1-9]|1[1-3][0-9]|140|20[1-9]|2[1-3][0-9]|240|30[1-9]|3[1-3][0-9]|340|40[1-9]|4[1-3][0-9]|440)(А)?$");
    if (!classroomRx.match(classroom).hasMatch()) {
        QMessageBox::warning(this, "Ошибка",
                             "Аудитория должна быть числом из диапазонов 101-140, 201-240, 301-340, 401-440");
        return;
    }
    QRegularExpression scheduleRx("^[1-8]$");
    if (!scheduleRx.match(scheduleNumber).hasMatch()) {
        QMessageBox::warning(this, "Ошибка", "Номер в расписании должен быть от 1 до 8.");
        return;
    }
    QStringList expectations;
    if (ui->controlCheck->isChecked()) expectations << "Контрольная";
    if (ui->attendanceCheck->isChecked()) expectations << "Проверка посещений";
    if (ui->cancelCheck->isChecked()) expectations << "Отмена";
    QString expectationsStr = expectations.join(", ");
    Lesson lesson(subject, teacher, classroom, scheduleNumber, type, expectationsStr);
    if (lesson.saveToFile("result.txt")) {
        QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные.");
    }
}
