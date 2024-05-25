#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
QString Dialog::getCityName()
{
    return ui->input_name->text();
}
int Dialog::getX()
{
    return ui->input_x->text().toInt();
}
int Dialog::getY()
{
    return ui->input_y->text().toInt();
}
void Dialog::on_input_name_textChanged(const QString &arg1)
{
    cityName = arg1;
}


void Dialog::on_input_x_textChanged(const QString &arg1)
{
    x = arg1.toInt();
}


void Dialog::on_input_y_textChanged(const QString &arg1)
{
    y = arg1.toInt();
}