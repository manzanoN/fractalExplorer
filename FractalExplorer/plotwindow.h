#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDoubleValidator>
#include <QGraphicsView>
#include "settingsdialog.h"
#include <QColorDialog>
#include <QGridLayout>
#include <QImage>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include "Mandel.h"

namespace Ui {
class plotWindow;
}

class plotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit plotWindow(QWidget *parent = nullptr);
    ~plotWindow();
    void updateVars();

private:
    Ui::plotWindow *ui;
    double Xmin;
    double Xmax;
    double Ymin;
    double Ymax;
    int WindowWidth;
    int WindowHeight;
    QColor color = (0,0,0);
    QImage screenshot;
    QPainter *painter;
    QPen *pen;
    QGraphicsView *graphic;
    QPixmap *imgmap;
    QGraphicsScene *scene;
    int imgWidth = 800;
    int imgHeight = 800;
    int imgIterations = 80;
    SettingsDialog *settings;
    QMessageBox *welcome;
    double ZoomLevel = 1.0;

    void calculateZoom();

protected:
    void paintEvent(QPaintEvent *pEvent);
signals:
    void pushCurrentSettings(const int& imgWidth,const int& imgHeight, const int& imgIterations, const int&renderIterations);
private slots:
//    void on_Refresh_clicked();
    void on_ZoomInButton_clicked();
    void on_ZoomOutButton_clicked();
    void on_reset_clicked();
    void on_ColorButton_clicked();
    void on_configButton_clicked();
    void on_settingsDataChanged(const int& imgiterations, const int& imgWidth, const int& imgHeight, const int& renderIterations);
    void on_XminField_returnPressed();
    void on_XmaxField_returnPressed();
    void on_YminField_returnPressed();
    void on_YmaxField_returnPressed();
    void on_upButton_clicked();
    void on_rightButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_exportButton_clicked();
};

#endif // PLOTWINDOW_H
