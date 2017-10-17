/********************************************************************************
** Form generated from reading UI file 'rfidApp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RFIDAPP_H
#define UI_RFIDAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rfidAppClass
{
public:
    QAction *actionStart;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionQuit_now;
    QAction *actionScan_for_Tags;
    QAction *actionOn;
    QAction *actionOff;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuConnections;
    QMenu *menuScan;

    void setupUi(QMainWindow *rfidAppClass)
    {
        if (rfidAppClass->objectName().isEmpty())
            rfidAppClass->setObjectName(QStringLiteral("rfidAppClass"));
        rfidAppClass->resize(600, 400);
        actionStart = new QAction(rfidAppClass);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionConnect = new QAction(rfidAppClass);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(rfidAppClass);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionQuit_now = new QAction(rfidAppClass);
        actionQuit_now->setObjectName(QStringLiteral("actionQuit_now"));
        actionScan_for_Tags = new QAction(rfidAppClass);
        actionScan_for_Tags->setObjectName(QStringLiteral("actionScan_for_Tags"));
        actionOn = new QAction(rfidAppClass);
        actionOn->setObjectName(QStringLiteral("actionOn"));
        actionOff = new QAction(rfidAppClass);
        actionOff->setObjectName(QStringLiteral("actionOff"));
        centralWidget = new QWidget(rfidAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        rfidAppClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(rfidAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        rfidAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(rfidAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        rfidAppClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(rfidAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuConnections = new QMenu(menuBar);
        menuConnections->setObjectName(QStringLiteral("menuConnections"));
        menuScan = new QMenu(menuBar);
        menuScan->setObjectName(QStringLiteral("menuScan"));
        rfidAppClass->setMenuBar(menuBar);

        menuBar->addAction(menuConnections->menuAction());
        menuBar->addAction(menuScan->menuAction());
        menuConnections->addAction(actionConnect);
        menuConnections->addAction(actionDisconnect);

        retranslateUi(rfidAppClass);

        QMetaObject::connectSlotsByName(rfidAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *rfidAppClass)
    {
        rfidAppClass->setWindowTitle(QApplication::translate("rfidAppClass", "rfidApp", Q_NULLPTR));
        actionStart->setText(QApplication::translate("rfidAppClass", "Start", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("rfidAppClass", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("rfidAppClass", "Disconnect", Q_NULLPTR));
        actionQuit_now->setText(QApplication::translate("rfidAppClass", "Quit now", Q_NULLPTR));
        actionScan_for_Tags->setText(QApplication::translate("rfidAppClass", "Scan for Tags", Q_NULLPTR));
        actionOn->setText(QApplication::translate("rfidAppClass", "On", Q_NULLPTR));
        actionOff->setText(QApplication::translate("rfidAppClass", "Off", Q_NULLPTR));
        menuConnections->setTitle(QApplication::translate("rfidAppClass", "Connections", Q_NULLPTR));
        menuScan->setTitle(QApplication::translate("rfidAppClass", "Scan", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rfidAppClass: public Ui_rfidAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFIDAPP_H
