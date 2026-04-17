/********************************************************************************
** Form generated from reading UI file 'carddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
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
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_CardDialog
{
public:
    QLabel *imageLabel;
    QSplitter *splitter;
    QLabel *infoLabel;
    QPushButton *printButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *CardDialog)
    {
        if (CardDialog->objectName().isEmpty())
            CardDialog->setObjectName("CardDialog");
        CardDialog->resize(548, 227);
        imageLabel = new QLabel(CardDialog);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(20, 20, 200, 200));
        imageLabel->setMinimumSize(QSize(200, 200));
        imageLabel->setMaximumSize(QSize(200, 200));
        imageLabel->setScaledContents(true);
        splitter = new QSplitter(CardDialog);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(260, 10, 271, 211));
        splitter->setOrientation(Qt::Orientation::Vertical);
        infoLabel = new QLabel(splitter);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setTextFormat(Qt::TextFormat::RichText);
        infoLabel->setWordWrap(true);
        splitter->addWidget(infoLabel);
        printButton = new QPushButton(splitter);
        printButton->setObjectName("printButton");
        printButton->setStyleSheet(QString::fromUtf8("color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));"));
        splitter->addWidget(printButton);
        cancelButton = new QPushButton(splitter);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setStyleSheet(QString::fromUtf8("color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(255, 255, 255, 255), stop:0.373979 rgba(255, 255, 255, 255), stop:0.373991 rgba(33, 30, 255, 255), stop:0.624018 rgba(33, 30, 255, 255), stop:0.624043 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));"));
        splitter->addWidget(cancelButton);

        retranslateUi(CardDialog);

        QMetaObject::connectSlotsByName(CardDialog);
    } // setupUi

    void retranslateUi(QDialog *CardDialog)
    {
        CardDialog->setWindowTitle(QCoreApplication::translate("CardDialog", "Dialog", nullptr));
        imageLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        infoLabel->setText(QCoreApplication::translate("CardDialog", "TextLabel", nullptr));
        printButton->setText(QCoreApplication::translate("CardDialog", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("CardDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardDialog: public Ui_CardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDDIALOG_H
