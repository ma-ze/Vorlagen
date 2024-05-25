#include "street.h"

Street::Street(City* city1, City* city2)
{
    this->city1 = city1;
    this->city2 = city2;
}
Street::~Street()
{
}
Street::operator QString() const
{
    return QString("Street from %1 to %2").arg(city1->getName()).arg(city2->getName());
}
void Street::draw(QGraphicsScene& scene)
{
    QPen pen;
    pen.setWidth (2);
    pen.setColor (Qt::yellow);
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
}
void Street::drawRed(QGraphicsScene& scene)
{
    QPen pen;
    pen.setWidth (4);
    pen.setColor (Qt::red);
    scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
}
QVector<City*> Street::getCities() const
{
    QVector<City*> cities;
    cities.append(city1);
    cities.append(city2);
    return cities;
}
double Street::getLength() const
{
    return sqrt(pow(city1->getX() - city2->getX(), 2) + pow(city1->getY() - city2->getY(), 2));
}
