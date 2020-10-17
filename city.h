/** \file city.h
 * \brief Contains a class that represents a city.
 */

#pragma once
#include <vector>
#include <QString>
#include "food.h"

/**
 * \brief A city.
 * The "city" class has three private members:
 * name             :   QString................A name of the city.
 * parentCountry    :   QString................A name of the country that the city resides in.
 * foodItems        :   vector<food*>..........A vector of dynamically allocated food (see food.h).
 *
 * The city class provides a name, as well as a list of food to be displayed while inside of a city (going on a trip)
 * and while selected in a list.
 */
class city
{
public:
    /**
     * \brief A default constructor for city.
     * Initializes the name data member with "Default City" and the parentCountry data member
     * with "Default country."
     */
    city() : name{ "Defualt City" }, parentCountry{ "Default Country" } {}

    /**
     * \brief An overloaded constructor for city.
     * Initializes the name and parentCountry data members to the passed parameters.
     * @param name A QString constant
     * @param parentCountry A Qstring constant
     */
    city(const QString name, const QString parentCountry) : name{ name }, parentCountry{ parentCountry }{}

    /**
     * \brief A copy constructor for city.
     * @param other A constant reference to a city.
     */
    city(const city& other);

    /**
     * \brief A destructor for city.
     * Deallocs the contents of foodItems to prevent memory leaks.
     */
    ~city();

    // getters

    /**
     * Getter for name.
     * @return The name of the city.
     */
    QString getName() const;

    /**
     * Getter for parent country.
     * @return The name of the parent country.
     */
    QString getParentCountry() const;

    /**
     * Getter for food at an index
     * @param index The index of a food item.
     * @return The food item at an index.
     */
    food getFood( int index ) const;

    /**
     * Getter for a reference to the food vector.
     * @return A reference to the food vector.
     */
    std::vector<food*>& getFoodRef();

    /**
     * Getter for the number of food items in the vector.
     * @return The number of items in the food vector (as if stl vector size() function was called).
     */
    int getNumFood() const;


    // setters

    /**
     * Setter for the name data member.
     * @param name The name you wish to set name to.
     */
    void setName(const QString name);

    /**
     * Setter for the parentCountry data member.
     * @param parentCountry The name you wish to set parentCountry to.
     */
    void setParentCountry(const QString parentCountry);

    /**
     * Add a food item to the vector of food.
     * @param foodItem A pointer to the food item you wish to add to the vector.
     */
    void addFoodItem(food* foodItem);

private:
    /** QString
     * \brief name
     * A name for the city.
     */
    QString name;

    /** QString
     * \brief parentCountry
     * A name for the country a city belongs to.
     */
    QString parentCountry;

    /** std::vector<food*>
     * \brief foodItems
     * A vector of food items.
     */
    std::vector<food*> foodItems;
};
