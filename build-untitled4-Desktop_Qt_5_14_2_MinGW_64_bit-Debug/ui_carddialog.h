/********************************************************************************
** Form generated from reading UI file 'carddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDDIALOG_H
#define UI_CARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CardDialog
{
public:
    QLabel *imageLabel;
    QLabel *nameLabel;
    QLabel *typeLabel;
    QLabel *spec1Label;
    QLabel *spec2Label;
    QLabel *healthLabel;
    QLabel *armorLabel;
    QPushButton *cancelButton;
    QPushButton *printButton;

    void setupUi(QDialog *CardDialog)
    {
        if (CardDialog->objectName().isEmpty())
            CardDialog->setObjectName(QString::fromUtf8("CardDialog"));
        CardDialog->resize(353, 468);
        imageLabel = new QLabel(CardDialog);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(70, 130, 200, 200));
        imageLabel->setMinimumSize(QSize(200, 200));
        imageLabel->setMaximumSize(QSize(200, 200));
        imageLabel->setTextFormat(Qt::RichText);
        imageLabel->setScaledContents(true);
        nameLabel = new QLabel(CardDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(140, 10, 61, 21));
        nameLabel->setTextFormat(Qt::RichText);
        typeLabel = new QLabel(CardDialog);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));
        typeLabel->setGeometry(QRect(100, 30, 61, 16));
        typeLabel->setTextFormat(Qt::RichText);
        spec1Label = new QLabel(CardDialog);
        spec1Label->setObjectName(QString::fromUtf8("spec1Label"));
        spec1Label->setGeometry(QRect(190, 30, 81, 16));
        spec1Label->setTextFormat(Qt::RichText);
        spec2Label = new QLabel(CardDialog);
        spec2Label->setObjectName(QString::fromUtf8("spec2Label"));
        spec2Label->setGeometry(QRect(100, 50, 61, 16));
        spec2Label->setTextFormat(Qt::RichText);
        healthLabel = new QLabel(CardDialog);
        healthLabel->setObjectName(QString::fromUtf8("healthLabel"));
        healthLabel->setGeometry(QRect(190, 50, 81, 16));
        healthLabel->setTextFormat(Qt::RichText);
        armorLabel = new QLabel(CardDialog);
        armorLabel->setObjectName(QString::fromUtf8("armorLabel"));
        armorLabel->setGeometry(QRect(140, 70, 61, 21));
        armorLabel->setTextFormat(Qt::RichText);
        cancelButton = new QPushButton(CardDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(230, 420, 111, 41));
        cancelButton->setStyleSheet(QString::fromUtf8("background-color: red;\n"
""));
        printButton = new QPushButton(CardDialog);
        printButton->setObjectName(QString::fromUtf8("printButton"));
        printButton->setGeometry(QRect(10, 420, 111, 41));
        printButton->setStyleSheet(QString::fromUtf8("background-color: blue;"));

        retranslateUi(CardDialog);

        QMetaObject::connectSlotsByName(CardDialog);
    } // setupUi

    void retranslateUi(QDialog *CardDialog)
    {
        CardDialog->setWindowTitle(QCoreApplication::translate("CardDialog", "Dialog", nullptr));
        imageLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        nameLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        typeLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        spec1Label->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        spec2Label->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        healthLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        armorLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        cancelButton->setText(QCoreApplication::translate("CardDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        printButton->setText(QCoreApplication::translate("CardDialog", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardDialog: public Ui_CardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDDIALOG_H
