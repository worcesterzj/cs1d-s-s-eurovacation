#pragma once
#include <vector>
#include <QString>
#include "food.h"


class city
{
public:
    city() : name{ "Defualt City" }, parentCountry{ "Default Country" } {}
    city(QString name, QString parentCountry) : name{ name }, parentCountry{ parentCountry } {}
    city(const city& other);
    ~city();

    // getters

    QString getName() const;
    QString getParentCountry() const;
    food getFood( int index ) const;   // uncomment when food exists :) You can still write it by looking at the UML diagram tho
    std::vector<food*>& getFoodRef();
    int getNumFood() const;


    // setters

    void setName(QString name);
    void setParentCountry(QString parentCountry);
    void addFoodItem(food* foodItem);

private:
    QString name;
    QString parentCountry;
    std::vector<food*> foodItems; // uncomment when food exists :)
};
