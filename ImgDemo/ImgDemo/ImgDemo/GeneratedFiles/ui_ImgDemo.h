/********************************************************************************
** Form generated from reading UI file 'ImgDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGDEMO_H
#define UI_IMGDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImgDemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgDemoClass)
    {
        if (ImgDemoClass->objectName().isEmpty())
            ImgDemoClass->setObjectName(QString::fromUtf8("ImgDemoClass"));
        ImgDemoClass->resize(600, 400);
        menuBar = new QMenuBar(ImgDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ImgDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImgDemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ImgDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImgDemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImgDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImgDemoClass->setStatusBar(statusBar);

        retranslateUi(ImgDemoClass);

        QMetaObject::connectSlotsByName(ImgDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImgDemoClass)
    {
        ImgDemoClass->setWindowTitle(QCoreApplication::translate("ImgDemoClass", "ImgDemo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImgDemoClass: public Ui_ImgDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGDEMO_H
