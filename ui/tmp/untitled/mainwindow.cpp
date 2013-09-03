#include "mainwindow.h"
#include "ui_mainwindow.h"

// #include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*
    QMessageBox Msgbox;
    Msgbox.setText("sum of numbers are....");
    Msgbox.setIcon( QMessageBox::Warning );
    Msgbox.exec();
    */

    // ui->edtSource->setText(QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.sgml)"), 0, QFileDialog::DontUseNativeDialog ));
    ui->edtSource->setText(QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.sgml)") ));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->edtDestination->setText( QFileDialog::getSaveFileName( this, tr("Save Document"), QDir::currentPath(), tr("Documents (*.sgml)") ));
}
