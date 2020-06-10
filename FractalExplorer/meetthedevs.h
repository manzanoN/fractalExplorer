#ifndef MEETTHEDEVS_H
#define MEETTHEDEVS_H

#include <QDialog>

namespace Ui {
class meetTheDevs;
}

class meetTheDevs : public QDialog
{
    Q_OBJECT

public:
    explicit meetTheDevs(QWidget *parent = nullptr);
    ~meetTheDevs();

private slots:
    void on_pushButton_clicked();

private:
    Ui::meetTheDevs *ui;
};

#endif // MEETTHEDEVS_H
