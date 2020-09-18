#include "city.h"

city::city(const city& other) : name{ other.name }, parentCountry{ other.parentCountry } {
/*    if(!other.foodItems.empty())                                     // uncomment when food exists :)
        for(int i = 0; i < other.foodItems.size(); i++)
            this->foodItems.push_back(other.foodItems[i]);             */
}

QString city::getName() const {
    return name;
}
