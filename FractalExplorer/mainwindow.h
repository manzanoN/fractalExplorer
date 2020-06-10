#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "plotwindow.h"
#include "about.h"
#include "credits.h"
#include "aboutmandel.h"
#include "meetthedevs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_aboutQtButton_clicked();

    void on_exploreButton_clicked();

    void on_aboutMandelButton_clicked();

    void on_creditsButton_clicked();

    void on_aboutButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    plotWindow *window;
    about *aboutMessage;
    credits *creditsMessage;
    aboutMandel *aboutMandelMessage;
    meetTheDevs *devMessage;


};
#endif // MAINWINDOW_H
