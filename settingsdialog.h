#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QIntValidator>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog // New Class inherited from QDialog
{
    Q_OBJECT

public:
    // Default Constructor & Destructor
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

    // Variable Declarations used to temporarily store data within the settings dialog
    int imgIterations;
    int imgWidth;
    int imgHeight;
    int rendIterations;

signals:
    // Sends local variables back to plotWindow
    void sendSettingsData(const int& imgiterations, const int& imgWidth, const int& imgHeight, const int& renderIterations);

private slots:
    void on_buttonBox_accepted();
public slots:
    // Populates settings fields with variables from plotWindow
    void receiveCurrentSettings(const int& imgWidth,const int& imgHeight, const int& imgIterations, const int&renderIterations);

private:
    Ui::SettingsDialog *ui;

};

#endif // SETTINGSDIALOG_H
