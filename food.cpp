#include "food.h"



food::food(const food& other) : name{other.name}, price{other.price} {}


QString food::getName() const {
    return name;
}

double food::getPrice() const {
    return price;
}

void food::setName(QString name)
{
    this->name = name;
}

void food::setPrice(double price)
{
    this->price = price;
}

