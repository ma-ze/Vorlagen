#include "streetdialog.h"
#include "ui_streetdialog.h"

StreetDialog::StreetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StreetDialog)
{
    ui->setupUi(this);
}

StreetDialog::~StreetDialog()
{
    delete ui;
}
void StreetDialog::setCityNames(QStringList names)
{
    ui->comboBox_city1->addItems(names);
    ui->comboBox_city2->addItems(names);
}
QString StreetDialog::getCityName1()
{
    return ui->comboBox_city1->currentText();
}
QString StreetDialog::getCityName2()
{
    return ui->comboBox_city2->currentText();
}