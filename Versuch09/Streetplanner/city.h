#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class City
{
public:
    City(QString name, int x, int y);
    ~City(void);
    void draw(QGraphicsScene& scene);
private:
    QString name;
    int x;
    int y;
};

#endif // CITY_H
