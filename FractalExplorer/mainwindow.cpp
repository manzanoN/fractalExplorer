#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_aboutQtButton_clicked()
{
    QMessageBox::aboutQt(this, "What is Qt software?");
}

void MainWindow::on_exploreButton_clicked()
{
    window = new plotWindow(this);
    window->show();
}

void MainWindow::on_aboutMandelButton_clicked()
{
    aboutMandelMessage = new aboutMandel(this);
    aboutMandelMessage->show();
}

void MainWindow::on_creditsButton_clicked()
{
    creditsMessage = new credits(this);
    creditsMessage->show();
}

void MainWindow::on_aboutButton_clicked()
{
    aboutMessage = new about(this);
    aboutMessage->show();
}

void MainWindow::on_pushButton_clicked()
{
    devMessage = new meetTheDevs(this);
    devMessage->show();
}
