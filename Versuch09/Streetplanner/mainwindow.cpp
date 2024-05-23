#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    scene.addEllipse(100, 100, 4, 4, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QPen pen;
    pen.setWidth (5);
    pen.setColor (Qt::yellow);
    scene.addLine (10, 10, 190, 10, pen);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x = QRandomGenerator::global()->bounded(scene.width());
    int y = QRandomGenerator::global()->bounded(scene.height());
    scene.addRect(x, y, 20, 20, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
}
void MainWindow::on_actionEixt_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.about(this, "asdf", "This is Aufgabe 9");


}


void MainWindow::on_btn_test_draw_city_clicked()
{
    City city1("Hamburg", 100, 100);
    City city2("Berlin", 200, 200);
    city1.draw(scene);
    city2.draw(scene);
}
