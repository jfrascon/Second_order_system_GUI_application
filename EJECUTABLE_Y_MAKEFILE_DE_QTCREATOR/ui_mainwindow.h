/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *l_step_amp;
    QCustomPlot *qcplot;
    QVBoxLayout *vl1;
    QSlider *slider_step_amp;
    QLineEdit *le_step_amp;
    QPushButton *b_execute;
    QGridLayout *gl2;
    QLabel *l_p2_r;
    QLabel *l_p1_r;
    QLabel *l_type;
    QLabel *l_p2;
    QLabel *l_p2_i;
    QLabel *l_p1_i;
    QLabel *l_p1;
    QLineEdit *le_p1_r;
    QLineEdit *le_p1_i;
    QLineEdit *le_p2_r;
    QLineEdit *le_p2_i;
    QLineEdit *le_type;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(939, 701);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(3);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        l_step_amp = new QLabel(centralWidget);
        l_step_amp->setObjectName(QString::fromUtf8("l_step_amp"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(l_step_amp->sizePolicy().hasHeightForWidth());
        l_step_amp->setSizePolicy(sizePolicy1);
        l_step_amp->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(l_step_amp, 0, 1, 1, 1);

        qcplot = new QCustomPlot(centralWidget);
        qcplot->setObjectName(QString::fromUtf8("qcplot"));

        gridLayout->addWidget(qcplot, 0, 0, 2, 1);

        vl1 = new QVBoxLayout();
        vl1->setSpacing(6);
        vl1->setObjectName(QString::fromUtf8("vl1"));
        slider_step_amp = new QSlider(centralWidget);
        slider_step_amp->setObjectName(QString::fromUtf8("slider_step_amp"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(slider_step_amp->sizePolicy().hasHeightForWidth());
        slider_step_amp->setSizePolicy(sizePolicy2);
        slider_step_amp->setMinimum(0);
        slider_step_amp->setMaximum(50);
        slider_step_amp->setPageStep(0);
        slider_step_amp->setValue(50);
        slider_step_amp->setSliderPosition(50);
        slider_step_amp->setOrientation(Qt::Vertical);
        slider_step_amp->setTickPosition(QSlider::TicksBelow);

        vl1->addWidget(slider_step_amp);

        le_step_amp = new QLineEdit(centralWidget);
        le_step_amp->setObjectName(QString::fromUtf8("le_step_amp"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(le_step_amp->sizePolicy().hasHeightForWidth());
        le_step_amp->setSizePolicy(sizePolicy3);
        le_step_amp->setAlignment(Qt::AlignCenter);

        vl1->addWidget(le_step_amp);


        gridLayout->addLayout(vl1, 1, 1, 1, 1);

        b_execute = new QPushButton(centralWidget);
        b_execute->setObjectName(QString::fromUtf8("b_execute"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(b_execute->sizePolicy().hasHeightForWidth());
        b_execute->setSizePolicy(sizePolicy4);
        b_execute->setMaximumSize(QSize(100000, 100000));
        b_execute->setFlat(false);

        gridLayout->addWidget(b_execute, 2, 1, 1, 1);

        gl2 = new QGridLayout();
        gl2->setSpacing(6);
        gl2->setObjectName(QString::fromUtf8("gl2"));
        gl2->setHorizontalSpacing(5);
        gl2->setVerticalSpacing(3);
        l_p2_r = new QLabel(centralWidget);
        l_p2_r->setObjectName(QString::fromUtf8("l_p2_r"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(l_p2_r->sizePolicy().hasHeightForWidth());
        l_p2_r->setSizePolicy(sizePolicy5);
        l_p2_r->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        l_p2_r->setFont(font);
        l_p2_r->setStyleSheet(QString::fromUtf8("color: rgb(221, 221, 221);\n"
"color: rgb(195, 195, 195);"));
        l_p2_r->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p2_r, 2, 2, 1, 1);

        l_p1_r = new QLabel(centralWidget);
        l_p1_r->setObjectName(QString::fromUtf8("l_p1_r"));
        sizePolicy5.setHeightForWidth(l_p1_r->sizePolicy().hasHeightForWidth());
        l_p1_r->setSizePolicy(sizePolicy5);
        l_p1_r->setMinimumSize(QSize(0, 20));
        l_p1_r->setFont(font);
        l_p1_r->setStyleSheet(QString::fromUtf8("color: rgb(221, 221, 221);\n"
"color: rgb(195, 195, 195);"));
        l_p1_r->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p1_r, 2, 0, 1, 1);

        l_type = new QLabel(centralWidget);
        l_type->setObjectName(QString::fromUtf8("l_type"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(l_type->sizePolicy().hasHeightForWidth());
        l_type->setSizePolicy(sizePolicy6);
        l_type->setMinimumSize(QSize(0, 20));
        l_type->setFrameShape(QFrame::Box);
        l_type->setFrameShadow(QFrame::Sunken);
        l_type->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_type, 0, 4, 1, 1);

        l_p2 = new QLabel(centralWidget);
        l_p2->setObjectName(QString::fromUtf8("l_p2"));
        sizePolicy6.setHeightForWidth(l_p2->sizePolicy().hasHeightForWidth());
        l_p2->setSizePolicy(sizePolicy6);
        l_p2->setMinimumSize(QSize(0, 20));
        l_p2->setFrameShape(QFrame::Box);
        l_p2->setFrameShadow(QFrame::Sunken);
        l_p2->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p2, 0, 2, 1, 2);

        l_p2_i = new QLabel(centralWidget);
        l_p2_i->setObjectName(QString::fromUtf8("l_p2_i"));
        sizePolicy5.setHeightForWidth(l_p2_i->sizePolicy().hasHeightForWidth());
        l_p2_i->setSizePolicy(sizePolicy5);
        l_p2_i->setMinimumSize(QSize(0, 20));
        l_p2_i->setFont(font);
        l_p2_i->setStyleSheet(QString::fromUtf8("color: rgb(221, 221, 221);\n"
"color: rgb(195, 195, 195);"));
        l_p2_i->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p2_i, 2, 3, 1, 1);

        l_p1_i = new QLabel(centralWidget);
        l_p1_i->setObjectName(QString::fromUtf8("l_p1_i"));
        sizePolicy5.setHeightForWidth(l_p1_i->sizePolicy().hasHeightForWidth());
        l_p1_i->setSizePolicy(sizePolicy5);
        l_p1_i->setMinimumSize(QSize(0, 20));
        l_p1_i->setFont(font);
        l_p1_i->setStyleSheet(QString::fromUtf8("color: rgb(221, 221, 221);\n"
"color: rgb(195, 195, 195);"));
        l_p1_i->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p1_i, 2, 1, 1, 1);

        l_p1 = new QLabel(centralWidget);
        l_p1->setObjectName(QString::fromUtf8("l_p1"));
        sizePolicy6.setHeightForWidth(l_p1->sizePolicy().hasHeightForWidth());
        l_p1->setSizePolicy(sizePolicy6);
        l_p1->setMinimumSize(QSize(0, 20));
        l_p1->setFrameShape(QFrame::Box);
        l_p1->setFrameShadow(QFrame::Sunken);
        l_p1->setAlignment(Qt::AlignCenter);

        gl2->addWidget(l_p1, 0, 0, 1, 2);

        le_p1_r = new QLineEdit(centralWidget);
        le_p1_r->setObjectName(QString::fromUtf8("le_p1_r"));
        sizePolicy6.setHeightForWidth(le_p1_r->sizePolicy().hasHeightForWidth());
        le_p1_r->setSizePolicy(sizePolicy6);
        le_p1_r->setMinimumSize(QSize(0, 30));
        le_p1_r->setAlignment(Qt::AlignCenter);

        gl2->addWidget(le_p1_r, 1, 0, 1, 1);

        le_p1_i = new QLineEdit(centralWidget);
        le_p1_i->setObjectName(QString::fromUtf8("le_p1_i"));
        sizePolicy6.setHeightForWidth(le_p1_i->sizePolicy().hasHeightForWidth());
        le_p1_i->setSizePolicy(sizePolicy6);
        le_p1_i->setMinimumSize(QSize(0, 30));
        le_p1_i->setAlignment(Qt::AlignCenter);

        gl2->addWidget(le_p1_i, 1, 1, 1, 1);

        le_p2_r = new QLineEdit(centralWidget);
        le_p2_r->setObjectName(QString::fromUtf8("le_p2_r"));
        sizePolicy6.setHeightForWidth(le_p2_r->sizePolicy().hasHeightForWidth());
        le_p2_r->setSizePolicy(sizePolicy6);
        le_p2_r->setMinimumSize(QSize(0, 30));
        le_p2_r->setAlignment(Qt::AlignCenter);

        gl2->addWidget(le_p2_r, 1, 2, 1, 1);

        le_p2_i = new QLineEdit(centralWidget);
        le_p2_i->setObjectName(QString::fromUtf8("le_p2_i"));
        sizePolicy6.setHeightForWidth(le_p2_i->sizePolicy().hasHeightForWidth());
        le_p2_i->setSizePolicy(sizePolicy6);
        le_p2_i->setMinimumSize(QSize(0, 30));
        le_p2_i->setAlignment(Qt::AlignCenter);

        gl2->addWidget(le_p2_i, 1, 3, 1, 1);

        le_type = new QLineEdit(centralWidget);
        le_type->setObjectName(QString::fromUtf8("le_type"));
        sizePolicy6.setHeightForWidth(le_type->sizePolicy().hasHeightForWidth());
        le_type->setSizePolicy(sizePolicy6);
        le_type->setMinimumSize(QSize(0, 30));
        le_type->setAlignment(Qt::AlignCenter);

        gl2->addWidget(le_type, 1, 4, 1, 1);


        gridLayout->addLayout(gl2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 939, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        l_step_amp->setText(QApplication::translate("MainWindow", "Step amplitude", 0, QApplication::UnicodeUTF8));
        b_execute->setText(QApplication::translate("MainWindow", "Execute", 0, QApplication::UnicodeUTF8));
        l_p2_r->setText(QApplication::translate("MainWindow", "Real", 0, QApplication::UnicodeUTF8));
        l_p1_r->setText(QApplication::translate("MainWindow", "Real", 0, QApplication::UnicodeUTF8));
        l_type->setText(QApplication::translate("MainWindow", "System type", 0, QApplication::UnicodeUTF8));
        l_p2->setText(QApplication::translate("MainWindow", "Pole 2", 0, QApplication::UnicodeUTF8));
        l_p2_i->setText(QApplication::translate("MainWindow", "Imaginary", 0, QApplication::UnicodeUTF8));
        l_p1_i->setText(QApplication::translate("MainWindow", "Imaginary", 0, QApplication::UnicodeUTF8));
        l_p1->setText(QApplication::translate("MainWindow", "Pole 1", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
