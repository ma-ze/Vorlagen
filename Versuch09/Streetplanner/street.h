#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QGraphicsScene>

class Street
{
public:
    Street(City* city1, City* city2);
    ~Street();
    operator QString() const;
    void draw(QGraphicsScene& scene);
    void drawRed(QGraphicsScene& scene);
    QVector<City*> getCities() const;
    double getLength() const;
private:
    City* city1;
    City* city2;
};

#endif // STREET_H
