#include "city.h"

City::City(QString name, int x, int y)
{
    this->name = name;
    this->x = x;
    this->y = y;
}
City::~City(void)
{
}
void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 4, 4, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem* namelabel = new QGraphicsTextItem;
    namelabel->setPos(x, y);
    namelabel->setPlainText(name);
    scene.addItem(namelabel);
}
