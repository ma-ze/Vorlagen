#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "dialog.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "streetdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    ui->testButtonContainer->hide();
    ui->comboBox_start->addItem("");
    ui->comboBox_goal->addItem("");
    scene.addEllipse(100, 100, 4, 4, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QPen pen;
    pen.setWidth (5);
    pen.setColor (Qt::yellow);
    scene.addLine (10, 10, 190, 10, pen);
    mapio = new MapIoNrw();
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

void MainWindow::on_actionClear_Map_triggered()
{
    map.clear();
}
//////////////////////////////////////////
//TEST BUTTONS
//////////////////////////////////////////
City* city1 = new City("Hamburg", 100, 100);
City* city2 = new City("Berlin", 200, 120);
City* city3 = new City("Köln", 150, 300);
City* city4 = new City("Düsseldorf", 100, 250);

void MainWindow::on_btn_test_draw_city_clicked()
{
    city1->draw(scene);
    city2->draw(scene);
}

void MainWindow::on_btn_test_more_cities_clicked()
{

    map.addCity(city1);
    map.addCity(city2);
    map.addCity(city3);
    map.addCity(city4);
    map.draw(scene);
}


void MainWindow::on_btn_test_street_clicked()
{
    Street* street1 = new Street(city1, city2);
    map.addStreet(street1);
    map.draw(scene);
}


void MainWindow::on_toggle_test_btns_toggled(bool checked)
{
    if(checked)
    {
        ui->testButtonContainer->show();
    }
    else
    {
        ui->testButtonContainer->hide();
    }
}


void MainWindow::on_btn_addcity_clicked()
{
    Dialog *addcity = new Dialog();
    if(addcity->exec() == QDialog::Accepted)
    {
        City* city = new City(addcity->getCityName(), addcity->getX(), addcity->getY());
        map.addCity(city);
        map.draw(scene);
        ui->comboBox_start->addItem(city->getName());
        ui->comboBox_goal->addItem(city->getName());
    }

}


void MainWindow::on_btn_fill_map_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
    ui->comboBox_start->addItems(map.getCityNames());
    ui->comboBox_goal->addItems(map.getCityNames());
}


void MainWindow::on_btn_test_abstractmap_clicked()
{
    testAbstractMap();
}

void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_btn_test_dijkstra_clicked()
{
    QVector<Street*> path = Dijkstra::search(map, "Aachen", "Bonn");
    for(auto street : path )
    {
        qDebug() << *street;
        street->drawRed(scene);
    }
}


void MainWindow::on_comboBox_start_currentIndexChanged(int index)
{
    if(index != 0)
    {
        if(index ==  ui->comboBox_goal->currentIndex())
        {
            ui->comboBox_start->setCurrentIndex(0);//avoid setting start and end to the same city
            scene.clear();
            map.draw(scene);
            return;
        }
        ui->comboBox_goal->setEnabled(true);
        scene.clear();
        map.draw(scene);
        map.findCity(ui->comboBox_start->currentText())->drawHighlight(scene);
        if(ui->comboBox_goal->currentIndex() != 0)
        {
            map.findCity(ui->comboBox_goal->currentText())->drawHighlight(scene);
            QVector<Street*> path = Dijkstra::search(map, ui->comboBox_start->currentText(), ui->comboBox_goal->currentText());
            for(auto street : path )
            {
                qDebug() << *street;
                street->drawRed(scene);
            }
        }
    }
    else
    {
        ui->comboBox_goal->setEnabled(false);
    }
}


void MainWindow::on_comboBox_goal_currentIndexChanged(int index)
{
    if(index != 0)
    {
        if(index ==  ui->comboBox_start->currentIndex())
        {
            ui->comboBox_goal->setCurrentIndex(0);//avoid setting start and end to the same city
            scene.clear();
            map.draw(scene);
            return;
        }
        scene.clear();
        map.draw(scene);
        map.findCity(ui->comboBox_start->currentText())->drawHighlight(scene);
        map.findCity(ui->comboBox_goal->currentText())->drawHighlight(scene);
        QVector<Street*> path = Dijkstra::search(map, ui->comboBox_start->currentText(), ui->comboBox_goal->currentText());
        for(auto street : path )
        {
            qDebug() << *street;
            street->drawRed(scene);
        }
    }
    else
    {

    }
}


void MainWindow::on_btn_addstreet_clicked()
{
    StreetDialog *addstreet = new StreetDialog();
    addstreet->setCityNames(map.getCityNames());
    if(addstreet->exec() == QDialog::Accepted)
    {
        map.addStreet(new Street(map.findCity(addstreet->getCityName1()), map.findCity(addstreet->getCityName2())));
        map.draw(scene);
    }
}
