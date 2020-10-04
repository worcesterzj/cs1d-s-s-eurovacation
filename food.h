#ifndef FOOD_H
#define FOOD_H

#include <QString>

class food
{
public:
    food(): name{"Default Food"}, price{0.00} {}
    food(QString name, double price) : name{ name }, price{ price } {}
    food(const food& other);

    //getters
    
    QString getName() const;
    double  getPrice() const;
    
    void setName(QString name);
    void setPrice(double price);

    double buy(int numItems);
    
private:
    QString name;
    double  price;
};

#endif // FOOD_H
