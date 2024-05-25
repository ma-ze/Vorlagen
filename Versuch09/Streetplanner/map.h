#ifndef MAP_H
#define MAP_H

#include "city.h"
#include "street.h"
#include "abstractmap.h"

class Map : public AbstractMap
{
public:
    Map();
    ~Map();
    void addCity(City*);
    void draw(QGraphicsScene& scene);
    bool addStreet(Street*);
    City* findCity(const QString cityName) const;
    QVector<City*> getCities() const;
    QStringList getCityNames() const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    void clear();

private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
