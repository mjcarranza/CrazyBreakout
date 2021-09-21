/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamewindow
{
public:
    QFrame *background;
    QLabel *label;
    QLabel *score;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName(QString::fromUtf8("gamewindow"));
        gamewindow->resize(868, 538);
        gamewindow->setStyleSheet(QString::fromUtf8(""));
        background = new QFrame(gamewindow);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 871, 541));
        background->setStyleSheet(QString::fromUtf8("background-image: url(:/images/fondo-pared-ladrillo-azul_53876-94010.jpg);"));
        background->setFrameShape(QFrame::StyledPanel);
        background->setFrameShadow(QFrame::Raised);
        label = new QLabel(background);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(650, 10, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tlwg Typo")});
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        score = new QLabel(background);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(740, 10, 111, 31));
        score->setFont(font);
        label_2 = new QLabel(background);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 101, 31));
        label_2->setFont(font);
        label_3 = new QLabel(background);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(130, 10, 191, 31));
        label_3->setFont(font);

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QWidget *gamewindow)
    {
        gamewindow->setWindowTitle(QCoreApplication::translate("gamewindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#8ae234;\">SCORE:</span></p></body></html>", nullptr));
        score->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#8ae234;\">0000000</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#8ae234;\">PLAYER:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:18pt; color:#8ae234;\">PLAYER</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
