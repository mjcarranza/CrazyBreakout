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
    QLabel *paddle;
    QLabel *ball;
    QLabel *label;
    QLabel *score;

    void setupUi(QWidget *gamewindow)
    {
        if (gamewindow->objectName().isEmpty())
            gamewindow->setObjectName(QString::fromUtf8("gamewindow"));
        gamewindow->resize(639, 450);
        gamewindow->setStyleSheet(QString::fromUtf8(""));
        background = new QFrame(gamewindow);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 641, 451));
        background->setStyleSheet(QString::fromUtf8("background-image: url(:/images/fondo-pared-ladrillo-azul_53876-94010.jpg);"));
        background->setFrameShape(QFrame::StyledPanel);
        background->setFrameShadow(QFrame::Raised);
        paddle = new QLabel(background);
        paddle->setObjectName(QString::fromUtf8("paddle"));
        paddle->setGeometry(QRect(300, 410, 61, 16));
        paddle->setPixmap(QPixmap(QString::fromUtf8(":/images/paddle.png")));
        paddle->setScaledContents(true);
        ball = new QLabel(background);
        ball->setObjectName(QString::fromUtf8("ball"));
        ball->setGeometry(QRect(320, 380, 16, 16));
        ball->setPixmap(QPixmap(QString::fromUtf8(":/images/ball.png")));
        ball->setScaledContents(true);
        label = new QLabel(background);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 10, 91, 31));
        score = new QLabel(background);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(500, 10, 111, 31));

        retranslateUi(gamewindow);

        QMetaObject::connectSlotsByName(gamewindow);
    } // setupUi

    void retranslateUi(QWidget *gamewindow)
    {
        gamewindow->setWindowTitle(QCoreApplication::translate("gamewindow", "Form", nullptr));
        paddle->setText(QString());
        ball->setText(QString());
        label->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#8ae234;\">SCORE:</span></p></body></html>", nullptr));
        score->setText(QCoreApplication::translate("gamewindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#8ae234;\">0000000</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gamewindow: public Ui_gamewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
