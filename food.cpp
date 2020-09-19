#include "food.h"



food::food(const food& other) : name{other.name}, price{other.price}
{

}

~food()
{

}


QString food::getName() const {
    return name;
}

double food::getPrice() const {
    return price;
}

void setName(Qstring name)
{
    this->name = name;
}

void setPrice(double price)
{
    this->price = price;
}

