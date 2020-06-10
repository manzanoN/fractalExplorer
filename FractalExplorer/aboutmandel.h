#ifndef ABOUTMANDEL_H
#define ABOUTMANDEL_H

#include <QDialog>

namespace Ui {
class aboutMandel;
}

class aboutMandel : public QDialog
{
    Q_OBJECT

public:
    explicit aboutMandel(QWidget *parent = nullptr);
    ~aboutMandel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::aboutMandel *ui;
};

#endif // ABOUTMANDEL_H
