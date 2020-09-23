#include "city.h"

city::city(const city& other) : name{ other.name }, parentCountry{ other.parentCountry } 
{
    if(!other.foodItems.empty())                                     // uncomment when food exists :)
        for(int i = 0; i < static_cast<int>(other.foodItems.size()); i++)
            this->foodItems.push_back(other.foodItems[i]);
}


QString city::getName() const 
{
    return name;
}

QString city::getParentCountry() const
{
        return parentCountry;
}

food* city::getFood(int index) const
{
                return foodItems.at(index);
}

void city::setName(QString name)
{
        this->name = name;
}

void city::setParentCountry(QString parentCountry)
{
        this->parentCountry = parentCountry;
}

void city::addFoodItem(food* foodItem)
{
        foodItems.push_back(foodItem);
}

int city::getNumFood() const {
    return foodItems.size();
}
