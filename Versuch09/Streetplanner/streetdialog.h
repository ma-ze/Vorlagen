#ifndef STREETDIALOG_H
#define STREETDIALOG_H

#include <QDialog>

namespace Ui {
class StreetDialog;
}

class StreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StreetDialog(QWidget *parent = nullptr);
    ~StreetDialog();
    void setCityNames(QStringList names);
    QString getCityName1();
    QString getCityName2();

private slots:

private:
    Ui::StreetDialog *ui;
    QString cityname1;
    QString cityname2;
};

#endif // STREETDIALOG_H
