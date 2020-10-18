/** \file
 * \brief A file that contains food class
  */
#ifndef FOOD_H
#define FOOD_H

#include <QString>

/**
 * \brief A class that represents a food item.
 */
/*! The "food" class has two private members:\n
 * name                         :   QString................name of the food.\n
 * price                        :   Double................price of the food.\n\n
 * The food class provides name and price. It is used to for food items.
 */
class food
{
public:
    /**
     * @brief food constructor to initialize name to "Default Food" and price to 0.00
     */
    food(): name{"Default Food"}, price{0.00} {}
    /**
     * @brief food contructor to initialize food and price to the values of
     * Food and price being passed in.
     * @param name name of the food
     * @param price price of the food
     */
    food(QString name, double price) : name{ name }, price{ price } {}
    /**
     * @brief Constructor to initialize the values of name and price to the food and price values of a food object.
     * @param other reference to food object
     */
    food(const food& other);

    //getters
    
    /**
     * @brief getName returns the name of a food.
     * @return A QString value of the name of the food
     */
    QString getName() const;
    /**
     * @brief getPrice returns the price of the food.
     * @return The price of the food.
     */
    double  getPrice() const;
    
    /**
     * @brief setName set the name of the food.
     * @param name Name of food to be set.
     */
    void setName(QString name);
    /**
     * @brief setPrice set the price of the food.
     * @param price Price of the food to be set.
     */
    void setPrice(double price);

    double buy(int numItems);
    
private:
    /** QString
     * @brief name
     * Name of the food.
     */
    QString name;
    /** double
     * @brief price
     * Price of the food.
     */
    double  price;
};

#endif // FOOD_H
