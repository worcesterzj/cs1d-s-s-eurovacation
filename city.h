#ifndef CITY_H
#define CITY_H

#include <QMainWindow> // <|
#include <QObject>     // <+----- I dunno maybe we'll need them...
#include <QWidget>     // <|
#include <QString>
//#include "food.h"

class city
{
public:
    city() : name{ "Defualt City" }, parentCountry{ "Default Country" } {}
    city(const city& other);

    // getters

    QString getName() const;
    QString getParentCountry() const;
//    food* getFoodItem( int index );   // uncomment when food exists :) You can still write it by looking at the UML diagram tho


    // setters

    void setName();
    void setParentCoutnry();
    void setFood(int index);

private:
    QString name;
    QString parentCountry;
//    std::vector<food*> foodItems; // uncomment when food exists :)
};

#endif // CITY_H
