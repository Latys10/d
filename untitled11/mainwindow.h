#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QButtonGroup>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onResetClicked();
    void onSaveClicked();

private:
    // Поля ввода
    QLineEdit *subjectEdit;
    QLineEdit *teacherEdit;
    QLineEdit *classroomEdit;
    QLineEdit *scheduleNumberEdit;

    // Тип
    QRadioButton *lectureRadio;
    QRadioButton *practiceRadio;
    QButtonGroup *typeGroup;

    // Ожидания
    QCheckBox *controlCheck;
    QCheckBox *attendanceCheck;
    QCheckBox *cancelCheck;

    // Кнопки
    QPushButton *resetButton;
    QPushButton *saveButton;
};

#endif // MAINWINDOW_H
