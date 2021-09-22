/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *logoLabel;
    QLabel *nicknameLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *nicknameLineEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *playBtn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(838, 436);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 16, 30);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        logoLabel = new QLabel(centralwidget);
        logoLabel->setObjectName(QString::fromUtf8("logoLabel"));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/GameLogo.png")));
        logoLabel->setScaledContents(true);

        verticalLayout->addWidget(logoLabel);

        nicknameLabel = new QLabel(centralwidget);
        nicknameLabel->setObjectName(QString::fromUtf8("nicknameLabel"));
        QFont font;
        font.setFamilies({QString::fromUtf8("URW Bookman")});
        font.setBold(true);
        font.setItalic(true);
        nicknameLabel->setFont(font);

        verticalLayout->addWidget(nicknameLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        nicknameLineEdit = new QLineEdit(centralwidget);
        nicknameLineEdit->setObjectName(QString::fromUtf8("nicknameLineEdit"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tlwg Typo")});
        font1.setBold(true);
        nicknameLineEdit->setFont(font1);
        nicknameLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(nicknameLineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        playBtn = new QPushButton(centralwidget);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Bookman")});
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setUnderline(false);
        playBtn->setFont(font2);
        playBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(138, 226, 52);\n"
"font: 63 italic 11pt \"URW Bookman\";"));

        horizontalLayout->addWidget(playBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logoLabel->setText(QString());
        nicknameLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; color:#8ae234;\">PLAYER`S NICKNAME</span></p></body></html>", nullptr));
        playBtn->setText(QCoreApplication::translate("MainWindow", "PLAY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
