#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QMessageBox>
#include <qDebug>
#include <QInputDialog>
//#include <mandel.h>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->result->setText("");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::aboutQt(this, "What is Qt software?");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::about(this, "The purpose of this project",
                       "This project uses an algorithm that "
                       "Shawn was able to create in C++ in order to analyze different values "
                       "to see whether or not they fit inside the famous Mandelbrot set. "
                       "Shawn also mentioned that we would be able to see the set in action "
                       "by implementing it on the Qt software.");
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::about(this, "What is a Mandelbrot set?",
                       "Benoit Mandlebrot was able to map out stable, and unstable values by using his "
                       "simple, yet powerful formula. Instead of simply squaring a value, he would also add "
                       "a complex number to it. If we were to square '4', and continue squaring it, it would become "
                       "a very large number; however, what would happen"
                       " if we were to continue squaring a number less than 1? If we were to "
                       "continue squaring '0.9' over, and over again, it "
                       "would eventually become a very small number. Its breakpoint is at the value of '1', "
                       "so essentially it's like a finding the limit as the value approaches the number '1' from either sides. "
                       "By plotting these values we can see how volatile, and amazing the Mandelbrot set really is.");
}

/*void MainWindow::on_pushButton_4_clicked()
{
    double n = QInputDialog::getDouble(this, "title", "Enter a number", 0.0, -2147483647, 2147483647, 3);

    n = n*n;
    ui->result->setText(QString::number(n));

}
*/



void MainWindow::on_pushButton_6_clicked()
{
     QMessageBox::about(this, "Meet the programmers", "Just two future UCR graduates that are full of ambition, and share the common goal of being "
                                                      "successful in life."
                                                      " "
                                                      "");
    //QPixmap pix(":/new/prefix1/dudes");
    //int w = ui->label_pic->width();
    //int h = ui->label_pic->height();
    //ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}
