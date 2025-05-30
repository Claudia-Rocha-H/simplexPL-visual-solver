/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *lblVar;
    QSpinBox *spinVariables;
    QLabel *lblRes;
    QSpinBox *spinRestricciones;
    QPushButton *btnGenerar;
    QGroupBox *gbObjetivo;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *layoutObjetivo;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *widgetRestricciones;
    QWidget *gridLayoutWidget_2;
    QGridLayout *layoutRestricciones;
    QPushButton *btnCalcular;
    QTextEdit *textEdit;
    QTableWidget *tablaSimplex;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1620, 804);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 10, 541, 751));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        lblVar = new QLabel(verticalLayoutWidget);
        lblVar->setObjectName("lblVar");
        lblVar->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblVar->sizePolicy().hasHeightForWidth());
        lblVar->setSizePolicy(sizePolicy);
        lblVar->setMinimumSize(QSize(10, 0));

        horizontalLayout->addWidget(lblVar);

        spinVariables = new QSpinBox(verticalLayoutWidget);
        spinVariables->setObjectName("spinVariables");
        spinVariables->setMinimum(1);
        spinVariables->setMaximum(10);
        spinVariables->setValue(2);

        horizontalLayout->addWidget(spinVariables);

        lblRes = new QLabel(verticalLayoutWidget);
        lblRes->setObjectName("lblRes");

        horizontalLayout->addWidget(lblRes);

        spinRestricciones = new QSpinBox(verticalLayoutWidget);
        spinRestricciones->setObjectName("spinRestricciones");
        spinRestricciones->setMinimum(1);
        spinRestricciones->setMaximum(10);
        spinRestricciones->setValue(2);

        horizontalLayout->addWidget(spinRestricciones);

        btnGenerar = new QPushButton(verticalLayoutWidget);
        btnGenerar->setObjectName("btnGenerar");

        horizontalLayout->addWidget(btnGenerar);


        verticalLayout_2->addLayout(horizontalLayout);

        gbObjetivo = new QGroupBox(verticalLayoutWidget);
        gbObjetivo->setObjectName("gbObjetivo");
        horizontalLayoutWidget_2 = new QWidget(gbObjetivo);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 40, 61, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_3);

        widget = new QWidget(gbObjetivo);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 30, 451, 271));
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 431, 251));
        layoutObjetivo = new QGridLayout(gridLayoutWidget);
        layoutObjetivo->setObjectName("layoutObjetivo");
        layoutObjetivo->setContentsMargins(0, 0, 0, 0);

        verticalLayout_2->addWidget(gbObjetivo);

        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName("groupBox");
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 602, 181));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widgetRestricciones = new QWidget(verticalLayoutWidget_2);
        widgetRestricciones->setObjectName("widgetRestricciones");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widgetRestricciones->sizePolicy().hasHeightForWidth());
        widgetRestricciones->setSizePolicy(sizePolicy2);
        widgetRestricciones->setMinimumSize(QSize(520, 0));
        gridLayoutWidget_2 = new QWidget(widgetRestricciones);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 511, 181));
        layoutRestricciones = new QGridLayout(gridLayoutWidget_2);
        layoutRestricciones->setObjectName("layoutRestricciones");
        layoutRestricciones->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(widgetRestricciones);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        btnCalcular = new QPushButton(centralwidget);
        btnCalcular->setObjectName("btnCalcular");
        btnCalcular->setGeometry(QRect(610, 10, 271, 51));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(890, 10, 231, 51));
        tablaSimplex = new QTableWidget(centralwidget);
        tablaSimplex->setObjectName("tablaSimplex");
        tablaSimplex->setGeometry(QRect(610, 80, 991, 251));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(610, 340, 991, 421));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1620, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lblVar->setText(QCoreApplication::translate("MainWindow", "Variables", nullptr));
        lblRes->setText(QCoreApplication::translate("MainWindow", "Restricciones", nullptr));
        btnGenerar->setText(QCoreApplication::translate("MainWindow", "Generar", nullptr));
        gbObjetivo->setTitle(QCoreApplication::translate("MainWindow", "Funcion Objetivo", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", " MAX Z =", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Restricciones", nullptr));
        btnCalcular->setText(QCoreApplication::translate("MainWindow", "Calcular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
