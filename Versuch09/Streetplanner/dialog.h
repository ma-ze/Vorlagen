#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString getCityName();
    int getX();
    int getY();

private slots:
    void on_input_name_textChanged(const QString &arg1);

    void on_input_x_textChanged(const QString &arg1);

    void on_input_y_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    QString cityName;
    int x;
    int y;
};

#endif // DIALOG_H
