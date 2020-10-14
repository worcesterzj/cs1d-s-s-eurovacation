/** \file distancetable_class.h
 * \brief A file that contains getCity_index() and distanceTable_class.
 */

#ifndef DISTANCETABLE_CLASS_H
#define DISTANCETABLE_CLASS_H

#include <vector>
#include <initializer_list>

#include "city.h"

/**
 * \brief DUMMY
 * A dummy value for the distance table. -1 is used here.
 */
const int DUMMY = -1;

/**
 * \brief getCity_index
 * Get the index of a city in a given vector.
 * @param cities The vector of cities to search.
 * @param k The city to search for.
 * @return An integer value of the city's index in the given vector.
 */
int getCity_index(const std::vector<city*>& cities, city* k);

/**
 * \brief The distance table (adjacency matrix) class
 * The distanceTable_class class has one private data member:
 * vec  :   vector<vector<int>>.................A vector of vectors of ints that represent the distances between two cities.
 *
 * distanceTable_class provides an adjacency matrix that can retrieve city distances from. You can add, delete, or even set
 * specific distances between two cities. Some functions rely on indeces rather than cities.
 */
class distanceTable_class
{
public:

    /**
     * \brief distanceTable_class
     * Default constructor for distanceTable_class. Does nothing of particular note.
     */
    distanceTable_class();

    /**
     * \brief operator=
     * Overloaded assignment operator to assign the distanceTable to a vector of ints.
     * @param other A refrence to a two-dimensional vector to be copied into the vec data member.
     * @return This class in order to allow for chained assignment.
     */
    distanceTable_class& operator=(std::vector<std::vector<int>>& other){
        vec = other;
        return *this;
    }

    /**
     * \brief getDistance
     * Getter for the distance at the specified indeces.
     * @param Xcity The city at X index.
     * @param Ycity The city at Y index.
     * @return The integer value at [Xcity][Ycity].
     */
    int getDistance(int Xcity, int Ycity) const;

    /**
     * \brief getClosestCityDistance
     * Getter for the distance of the closest city at index Xcity.
     * @param Xcity The index of the city you want to inspect.
     * @return The distance of the closest city to [Xcity].
     */
    int getClosestCityDistance(int Xcity) const;

    /**
     * \brief getClosestCityIndex
     * Getter for the index of the closest city in the adjacency matrix to the city at index Xcity.
     * @param Xcity The index of the city you wish to inspect.
     * @return The index of the closest city to [Xcity].
     */
    int getClosestCityIndex(int Xcity) const;

    /**
     * \brief customClosestCityDistance
     * Getter for the distance of the closest city in the adjacency matrix to the city at index Xcity, only allowing cities in allowed.
     * @param Xcity The index of the city you wish to inspect.
     * @param allowed A reference to a vector of ints that contains the indeces of the cities you wish to allow to be inspected.
     * @return The distance to the closest city to [Xcity] only allowing cities in allowed.
     */
    int customClosestCityDistance (int Xcity, const std::vector<int> &allowed) const;

    /**
     * \brief customClosestCityIndex
     * Getter for the index of the closest city in the adjacency matrix to the city at index Xcity, only allowing cities in allowed.
     * @param cities A constant reference to the vector of cities.
     * @param Xcity A pointer to the city you wish to inspect.
     * @param allowed A constant reference to a vector of cities that contains only the allowed cities.
     * @return The index of the closest city within the adjacency matrix at [Xcity]
     */
    int customClosestCityIndex (const std::vector<city*>& cities, city* Xcity, const std::vector<city*> &allowed) const;

    /**
     * @brief getShortestTrip
     * Recursively sort the trip vector in order to be ordered by shortest distance from the starting city.
     * @param cities A constant reference to a vector of cities allowed cities.
     * @param trip A reference to a non-constant vector of cities that is to be sorted.
     * @param allowed A non-constant vector of allowed cities. The cities in allowed will be empty after execution.
     */
    void getShortestTrip(const std::vector<city*>& cities, std::vector<city*>& trip, std::vector<city*>& allowed) const;


    /**
     * \brief setDistance
     * Set the distance of [Xcity][Ycity] to dist in the vec data member.
     * @param Xcity The index of the city at X.
     * @param Ycity The index of the city at Y.
     * @param dist The distance to be set at [Xcity][Ycity]
     */
    void setDistance(int Xcity, int Ycity, int dist);

    /**
     * \brief addCity
     * Add a city to the adjacency matrix.
     * @param city_distances A constant vector of ints containing the distances between the new city and the existing cities (sorted in alphabetical order).
     * @param index An index to place the new city at. (Should be alphabetical).
     */
    void addCity(const std::vector<int> city_distances, int index);

    /**
     * \brief deleteCity
     * Delete a city at the given index from the adjacency matrix.
     * @param index The index of the city to delete.
     */
    void deleteCity(int index);

private:

    /**
     * \brief vec
     * A two dimensional vector of ints. Acts as an adjacency matrix.
     */
    std::vector<std::vector<int>> vec;
};

#endif // DISTANCETABLE_CLASS_H
