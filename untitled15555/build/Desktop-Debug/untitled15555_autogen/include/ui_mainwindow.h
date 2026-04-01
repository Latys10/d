/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *subjectEdit;
    QLabel *label;
    QLineEdit *teacherEdit;
    QLineEdit *classroomEdit;
    QLineEdit *scheduleNumberEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *lectureRadio;
    QRadioButton *practiceRadio;
    QLabel *label_6;
    QCheckBox *controlCheck;
    QCheckBox *attendanceCheck;
    QCheckBox *cancelCheck;
    QPushButton *resetButton;
    QPushButton *saveButton;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(331, 360);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        subjectEdit = new QLineEdit(centralwidget);
        subjectEdit->setObjectName("subjectEdit");
        subjectEdit->setGeometry(QRect(110, 30, 113, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 71, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        teacherEdit = new QLineEdit(centralwidget);
        teacherEdit->setObjectName("teacherEdit");
        teacherEdit->setGeometry(QRect(150, 60, 131, 21));
        classroomEdit = new QLineEdit(centralwidget);
        classroomEdit->setObjectName("classroomEdit");
        classroomEdit->setGeometry(QRect(130, 90, 41, 21));
        scheduleNumberEdit = new QLineEdit(centralwidget);
        scheduleNumberEdit->setObjectName("scheduleNumberEdit");
        scheduleNumberEdit->setGeometry(QRect(200, 120, 51, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 60, 111, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 90, 91, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 120, 161, 21));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 150, 51, 21));
        label_5->setFont(font);
        lectureRadio = new QRadioButton(centralwidget);
        lectureRadio->setObjectName("lectureRadio");
        lectureRadio->setGeometry(QRect(70, 150, 89, 21));
        practiceRadio = new QRadioButton(centralwidget);
        practiceRadio->setObjectName("practiceRadio");
        practiceRadio->setGeometry(QRect(170, 150, 81, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 180, 101, 21));
        label_6->setFont(font);
        controlCheck = new QCheckBox(centralwidget);
        controlCheck->setObjectName("controlCheck");
        controlCheck->setGeometry(QRect(120, 180, 111, 21));
        attendanceCheck = new QCheckBox(centralwidget);
        attendanceCheck->setObjectName("attendanceCheck");
        attendanceCheck->setGeometry(QRect(120, 210, 151, 20));
        cancelCheck = new QCheckBox(centralwidget);
        cancelCheck->setObjectName("cancelCheck");
        cancelCheck->setGeometry(QRect(120, 240, 71, 20));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(30, 270, 101, 31));
        resetButton->setStyleSheet(QString::fromUtf8("background-color: red; color: white;"));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(180, 270, 111, 31));
        saveButton->setStyleSheet(QString::fromUtf8("background-color: green; color: white;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 331, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\262 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277", nullptr));
        lectureRadio->setText(QCoreApplication::translate("MainWindow", "\320\233\320\265\320\272\321\206\320\270\321\217", nullptr));
        practiceRadio->setText(QCoreApplication::translate("MainWindow", "	\320\237\321\200\320\260\320\272\321\202\320\270\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265", nullptr));
        controlCheck->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\260\321\217", nullptr));
        attendanceCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \320\277\320\276\321\201\320\265\321\211\320\265\320\275\320\270\320\271", nullptr));
        cancelCheck->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
