#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QDebug>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    QIntValidator *iValidator = new QIntValidator();
    ui->imgWidthField->setValidator(iValidator);
    ui->imgHeightField->setValidator(iValidator);
    ui->rendIterationsField->setValidator(iValidator);
    ui->expIterationsField->setValidator(iValidator);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_buttonBox_accepted()
{
    // Save Configuration Settings
    QString fieldVal;
    fieldVal = ui->imgWidthField->text();
        imgWidth = fieldVal.toInt();
    fieldVal = ui->imgHeightField->text();
        imgHeight = fieldVal.toInt();
    fieldVal = ui->expIterationsField->text();
        imgIterations = fieldVal.toInt();
    fieldVal = ui->rendIterationsField->text();
        rendIterations = fieldVal.toInt();

        emit sendSettingsData(imgIterations, imgWidth, imgHeight, rendIterations);

}

void SettingsDialog::receiveCurrentSettings(const int& imgWidth,const int& imgHeight, const int& imgIterations, const int&renderIterations) {
    this->imgWidth = imgWidth;
        ui->imgWidthField->setText(QString::number(imgWidth));
    this->imgHeight = imgHeight;
        ui->imgHeightField->setText(QString::number(imgHeight));
    this->rendIterations = renderIterations;
        ui->rendIterationsField->setText(QString::number(renderIterations));
    this->imgIterations = imgIterations;
        ui->expIterationsField->setText(QString::number(imgIterations));
}
