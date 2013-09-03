/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btnAbout;
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QLineEdit *edtDestination;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *edtSource;
    QCheckBox *checkBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(498, 142);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(498, 142));
        MainWindow->setMaximumSize(QSize(498, 142));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/rc/1375680555_66937.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        btnAbout = new QPushButton(centralWidget);
        btnAbout->setObjectName(QStringLiteral("btnAbout"));
        btnAbout->setGeometry(QRect(9, 112, 61, 23));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/rc/1375552777_question-frame.png"), QSize(), QIcon::Normal, QIcon::On);
        btnAbout->setIcon(icon1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(9, 10, 481, 95));
        groupBox->setTitle(QStringLiteral("Select Source and Destination File"));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(412, 47, 61, 23));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/rc/1374733068_save_16.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_2->setIcon(icon2);
        edtDestination = new QLineEdit(groupBox);
        edtDestination->setObjectName(QStringLiteral("edtDestination"));
        edtDestination->setGeometry(QRect(89, 47, 321, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(8, 51, 81, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(29, 27, 61, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(412, 22, 61, 23));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/rc/1374732821_folder_open-add.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton->setIcon(icon3);
        edtSource = new QLineEdit(groupBox);
        edtSource->setObjectName(QStringLiteral("edtSource"));
        edtSource->setEnabled(true);
        edtSource->setGeometry(QRect(89, 22, 321, 20));
        edtSource->setCursor(QCursor(Qt::IBeamCursor));
        edtSource->setFocusPolicy(Qt::StrongFocus);
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(90, 70, 111, 18));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(429, 112, 61, 23));
        pushButton_3->setLayoutDirection(Qt::LeftToRight);
        pushButton_3->setIconSize(QSize(16, 16));
        pushButton_3->setDefault(false);
        pushButton_3->setFlat(false);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(366, 112, 61, 23));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/rc/1375505876_tick.png"), QSize(), QIcon::Normal, QIcon::On);
        pushButton_4->setIcon(icon4);
        pushButton_4->setIconSize(QSize(10, 10));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(98, 113, 261, 23));
        progressBar->setMinimum(0);
        progressBar->setValue(50);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(edtSource, pushButton);
        QWidget::setTabOrder(pushButton, edtDestination);
        QWidget::setTabOrder(edtDestination, pushButton_2);
        QWidget::setTabOrder(pushButton_2, checkBox);
        QWidget::setTabOrder(checkBox, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_3);
        QWidget::setTabOrder(pushButton_3, btnAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BelloSGML", 0));
        btnAbout->setText(QApplication::translate("MainWindow", "About", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Save", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Destination file:</p></body></html>", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Source file:</p></body></html>", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Open", 0));
        edtSource->setText(QString());
        checkBox->setText(QApplication::translate("MainWindow", "Replace Source File", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Cancel", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Beautify", 0));
        progressBar->setFormat(QApplication::translate("MainWindow", "%p%", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
