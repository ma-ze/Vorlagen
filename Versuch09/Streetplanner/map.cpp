#include "map.h"

Map::Map() 
{

}
Map::~Map()
{
    for(auto city : cities) {
        delete city;
    }
    for(auto street : streets) {
        delete street;
    }
}
void Map::addCity(City* city)
{
    if (std::find(cities.begin(), cities.end(), city) == cities.end()) {//points to the end of the vector if the city is not found
    cities.push_back(city);                                             //note: this only checks if the xact city pointer is in the map, not if a city with the same name or coordinates exists
        qDebug() << "City added" << city->getName();
    } else {
        qDebug() << "City already exists in the map.";
    }
}
bool Map::addStreet(Street* street)
{
    for (City* city : street->getCities()) {
        if (std::find(cities.begin(), cities.end(), city) == cities.end()) {//points to the end of the vector if the city is not found
            qDebug() << "Cannot add street. Not all cities of the street are added to the map.";
            return false;
        }
    }
    streets.push_back(street);
    qDebug() << "added" << *street;
    return true;
}
void Map::draw(QGraphicsScene& scene)
{
    scene.clear();
    for(auto city : cities) {
        city->draw(scene);
    }
    for(auto street : streets) {
        street->draw(scene);
    }
}
City* Map::findCity(const QString cityName) const
{
    for(auto city : cities) {
        if (city->getName() == cityName) {
            return city;
        }
    }
    return nullptr;
}
QVector<City*> Map::getCities() const
{
    return cities;
}
QStringList Map::getCityNames() const
{
    QStringList city_names;
    for(auto city : cities) {
        city_names.push_back(city->getName());
    }
    return city_names;
}
QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> street_list;
    for(auto street : streets) {
        if (street->getCities().contains(city)) {
            street_list.push_back(street);
        }
    }
    return street_list;
}
City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCities().contains(city))
    {
        if (street->getCities()[0] == city)
        {
            return street->getCities()[1];
        }
        else
        {
            return street->getCities()[0];
        }
    }
    return nullptr;
}
double Map::getLength(const Street* street) const
{
    return street->getLength();
}
void Map::clear()
{
    cities.clear();
    streets.clear();
}