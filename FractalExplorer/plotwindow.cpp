#include "plotwindow.h"
#include "ui_plotwindow.h"


plotWindow::plotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::plotWindow)
{
    ui->setupUi(this);

    // Set Validator for Text Fields
    QDoubleValidator *dValidator = new QDoubleValidator(-5000.0,5000.0,10,nullptr);
    ui->XminField->setValidator(dValidator);
    ui->XmaxField->setValidator(dValidator);
    ui->YminField->setValidator(dValidator);
    ui->YmaxField->setValidator(dValidator);

    // Initialize parameters
    mandel::setMaxIterations(30);
    QString fieldVal;
        fieldVal = ui->XminField->text();
            Xmin = fieldVal.toDouble();
        fieldVal = ui->XmaxField->text();
            Xmax = fieldVal.toDouble();
        fieldVal = ui->YminField->text();
            Ymin = fieldVal.toDouble();
        fieldVal = ui->YmaxField->text();
            Ymax = fieldVal.toDouble();
        QColor color(0,0,0);
        color.setHsv(53,100,100);

        welcome = new QMessageBox(this);
        QString messageBody = "Welcome to Fractal Explorer!\n\n";
            messageBody+= "Use the zoom controls and arrows to start exploring the Mandelbrot Set.";
            messageBody+= " The deeper you go, the more work the computer does to render it!";
            messageBody+= "\n\nTip: Try adjusting the render iterations in the settings menu to improve performance.";

       QMessageBox::about(this,"Welcome!",messageBody);

}

plotWindow::~plotWindow()
{
    delete ui;
}

void plotWindow::paintEvent(QPaintEvent *pEvent)
{

    //Need to loop between points within the window range
   int windowWidth = ui->window->width();
   int  windowHeight = ui->window->height();
    double deltaX = std::abs(plotWindow::Xmax - plotWindow::Xmin)/windowWidth;
    double deltaY = std::abs(plotWindow::Ymax - plotWindow::Ymin)/windowHeight;
    double mandelVal;
    std::complex<double> point(0.0,0.0);
    QPainter painter(this);


    for (int x = 0; x<windowWidth; ++x) {
        for (int y = 0; y<windowHeight; ++y) {
            point = std::complex<double>(plotWindow::Xmin + x*deltaX,plotWindow::Ymax -y*deltaY);
            color.setHsv(plotWindow::color.hue(),plotWindow::color.saturation(),mandel::colorValue(point)); // Change third value to brightness from MandelVal
            painter.setPen(QPen(color));
            painter.drawPoint(x,y);
        }
    }
}

void plotWindow::on_ZoomInButton_clicked()
{
    double zoomAmt = 2;
    double centerX = (plotWindow::Xmin+plotWindow::Xmax)/2;
    double centerY = (plotWindow::Ymin+plotWindow::Ymax)/2;

    plotWindow::Xmin = centerX - 0.5*(plotWindow::Xmax-plotWindow::Xmin)/zoomAmt;
    ui->XminField->setText(QString::number(plotWindow::Xmin));
    plotWindow::Ymin = centerY - 0.5*(plotWindow::Ymax-plotWindow::Ymin)/zoomAmt;
    ui->YminField->setText(QString::number(plotWindow::Ymin));
    plotWindow::Xmax = centerX + 0.5*(plotWindow::Xmax-plotWindow::Xmin)/zoomAmt;
    ui->XmaxField->setText(QString::number(plotWindow::Xmax));
    plotWindow::Ymax = centerY + 0.5*(plotWindow::Ymax-plotWindow::Ymin)/zoomAmt;
    ui->YmaxField->setText(QString::number(plotWindow::Ymax));
    calculateZoom();
    repaint();

}

void plotWindow::on_ZoomOutButton_clicked()
{
    double zoomAmt = 2;
    double centerX = (plotWindow::Xmin+plotWindow::Xmax)/2;
    double centerY = (plotWindow::Ymin+plotWindow::Ymax)/2;

    plotWindow::Xmin = centerX - 0.5*(plotWindow::Xmax-plotWindow::Xmin)*zoomAmt;
    ui->XminField->setText(QString::number(plotWindow::Xmin));
    plotWindow::Ymin = centerY - 0.5*(plotWindow::Ymax-plotWindow::Ymin)*zoomAmt;
    ui->YminField->setText(QString::number(plotWindow::Ymin));
    plotWindow::Xmax = centerX + 0.5*(plotWindow::Xmax-plotWindow::Xmin)*zoomAmt;
    ui->XmaxField->setText(QString::number(plotWindow::Xmax));
    plotWindow::Ymax = centerY + 0.5*(plotWindow::Ymax-plotWindow::Ymin)*zoomAmt;
    ui->YmaxField->setText(QString::number(plotWindow::Ymax));
    calculateZoom();
    repaint();


}

void plotWindow::on_reset_clicked()
{
    plotWindow::Xmin = -2.75;
    plotWindow::Xmax = 0.75;
    plotWindow::Ymin = -3;
    plotWindow::Ymax = 3;
    calculateZoom();
    repaint();
}

void plotWindow::on_ColorButton_clicked()
{
    plotWindow::color = QColorDialog::getColor();
    repaint();
}

void plotWindow::on_exportButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save an image"),QDir::homePath(),tr("Images (*.ppm)")  );
    std::string path = filename.toUtf8().constData();
    mandel::exportImg(plotWindow::Xmin, plotWindow::Xmax, plotWindow::Ymin, plotWindow::Ymax,plotWindow::color, imgWidth, imgHeight, imgIterations, path);

}

void plotWindow::on_configButton_clicked()
{
    settings = new SettingsDialog(this);
    settings->show();
    connect(settings, &SettingsDialog::sendSettingsData, this, &plotWindow::on_settingsDataChanged );
    connect(this, &plotWindow::pushCurrentSettings, settings, &SettingsDialog::receiveCurrentSettings);
    emit pushCurrentSettings(imgWidth,imgHeight,imgIterations,mandel::getMaxIterations());
}

void plotWindow::on_settingsDataChanged(const int& imgiterations, const int& imgWidth, const int& imgHeight, const int& renderIterations) {
    this->imgIterations = imgiterations;
    this->imgWidth = imgWidth;
    this->imgHeight = imgHeight;
    mandel::setMaxIterations(renderIterations);
    }

void plotWindow::on_XminField_returnPressed()
{
    QString fieldVal = ui->XminField->text();
    Xmin = fieldVal.toInt();
    calculateZoom();
    repaint();
}

void plotWindow::on_XmaxField_returnPressed()
{
    QString fieldVal = ui->XmaxField->text();
    Xmax = fieldVal.toInt();
    calculateZoom();
    repaint();
}

void plotWindow::on_YminField_returnPressed()
{
    QString fieldVal = ui->YminField->text();
    Ymin = fieldVal.toInt();
    calculateZoom();
    repaint();
}

void plotWindow::on_YmaxField_returnPressed()
{
    QString fieldVal = ui->YmaxField->text();
    Ymax = fieldVal.toInt();
    calculateZoom();
    repaint();
}

void plotWindow::on_upButton_clicked()
{
    double totalY = std::fabs(Ymax - Ymin);
    double percentShift = 0.3; // Shift Up by 1/3 screen distance
    Ymin += std::fabs(totalY*percentShift);
    Ymax+= std::fabs(totalY*percentShift);

    ui->YminField->setText(QString::number(Ymin));
    ui->YmaxField->setText(QString::number(Ymax));
    repaint();
}

void plotWindow::on_downButton_clicked()
{
    double totalY = std::fabs(Ymax - Ymin);
    double percentShift = 0.3; // Shift down by 1/3 screen distance
    Ymin -= std::fabs(totalY*percentShift);
    Ymax-= std::fabs(totalY*percentShift);

    ui->YminField->setText(QString::number(Ymin));
    ui->YmaxField->setText(QString::number(Ymax));
    repaint();
}

void plotWindow::on_rightButton_clicked()
{
    double totalX = std::fabs(Xmax - Xmin);
    double percentShift = 0.3; // Shift right by 1/3 screen distance
    Xmin += std::fabs(totalX*percentShift);
    Xmax+= std::fabs(totalX*percentShift);

    ui->XminField->setText(QString::number(Xmin));
    ui->XmaxField->setText(QString::number(Xmax));
    repaint();
}

void plotWindow::on_leftButton_clicked()
{
    double totalX = std::fabs(Xmax - Xmin);
    double percentShift = 0.3; // Shift right by 1/3 screen distance
    Xmin -= std::fabs(totalX*percentShift);
    Xmax-= std::fabs(totalX*percentShift);

    ui->XminField->setText(QString::number(Xmin));
    ui->XmaxField->setText(QString::number(Xmax));
    repaint();
}

void plotWindow::calculateZoom() {
    double original_x = fabs(0.75 - (-2.75)); // original X Bounds
    double original_y =  fabs(3 - (-3)); // original Y Bounds

    double curr_XTotal = fabs(plotWindow::Xmax - plotWindow::Xmin);
    double curr_YTotal = fabs(plotWindow::Ymax - plotWindow::Ymin);

    double x_zoom = original_x/curr_XTotal;
    double y_zoom = original_y/curr_YTotal;

    double finalZoom = (x_zoom + y_zoom)/2; // Average between x and Y axes (they are independent - may fix in later versions)

    QString zoom_lvl = QString::number(finalZoom,10,2) +"x";
    ui->zoom_lvl->setText(zoom_lvl);
}
