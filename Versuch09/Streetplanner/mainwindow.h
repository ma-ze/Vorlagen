#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QMessageBox>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionEixt_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_btn_test_draw_city_clicked();

    void on_btn_test_more_cities_clicked();

    void on_btn_test_street_clicked();

    void on_toggle_test_btns_toggled(bool checked);

    void on_btn_addcity_clicked();

    void on_btn_fill_map_clicked();

    void on_btn_test_abstractmap_clicked();

    void testAbstractMap();

    void on_actionClear_Map_triggered();

    void on_btn_test_dijkstra_clicked();

    void on_comboBox_start_currentIndexChanged(int index);

    void on_comboBox_goal_currentIndexChanged(int index);

    void on_btn_addstreet_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapio;
};
#endif // MAINWINDOW_H
