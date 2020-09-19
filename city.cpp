#include "city.h"

city::city(const city& other) : name{ other.name }, parentCountry{ other.parentCountry } 
{
/*    if(!other.foodItems.empty())                                     // uncomment when food exists :)
        for(int i = 0; i < other.foodItems.size(); i++)
            this->foodItems.push_back(other.foodItems[i]);             */
}

~city()
{
        
}

QString city::getName() const 
{
    return name;
}

Qstring city::getname() const
{
        return parentCountry;
}

void setName(Qstring name)
{
        this->name = name;
}

void setparent(Qstring parentCountry)
{
        this->parentCountry = parentCountry;
}

void addFoodItem(food foodItem)
{
        foodItems.pushBack(foodItem);
        // or whatever the funtion call would be
}

food* getFood(int index)
{
                return foodItems.at(index);
}
