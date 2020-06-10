#include "meetthedevs.h"
#include "ui_meetthedevs.h"

meetTheDevs::meetTheDevs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meetTheDevs)
{
    ui->setupUi(this);
}

meetTheDevs::~meetTheDevs()
{
    delete ui;
}

void meetTheDevs::on_pushButton_clicked()
{
    this->close();
}
