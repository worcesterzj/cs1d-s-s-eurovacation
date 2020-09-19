#ifndef FOOD_H
#define FOOD_H

#include <QMainWindow> // <|
#include <QObject>     // <|
#include <QWidget>     // <|
#include <QString>

class food
{
public:
    food(): name{"Default Food"}, price{0.00} {}
    food(const food& other);
    
    //getters
    
    Qstring getName() const;
    double  getPrice() const;
    
    double buy(int numItems);
    
private:
    Qstring name;
    double  price;


}

#endif // FOOD_H
