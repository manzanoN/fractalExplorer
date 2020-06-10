#include "aboutmandel.h"
#include "ui_aboutmandel.h"

aboutMandel::aboutMandel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutMandel)
{
    ui->setupUi(this);
}

aboutMandel::~aboutMandel()
{
    delete ui;
}

void aboutMandel::on_pushButton_clicked()
{
    this->close();
}
