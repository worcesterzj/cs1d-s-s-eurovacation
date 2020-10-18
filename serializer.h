/** \file serializer.h
 * \brief Contains a class that has various serializer functions.
 */

#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>

#include "city.h"


/**
 * \brief A serializer to write data to and from a .sas file found in data/cities.
 */
/*! The "city" class has no private members.\n\n
 * The serializer class contains functions to write the cities, their respective food items, and their distances to other cities to file.
 */
class serializer
{
public:

    /**
     * \brief A default constructor for parser.
     *
     */
    serializer();

    /**
     * Function to write the cities and their respective food items to file.
     * @param cities A vector of cities.
     */
    void write(const std::vector<city*>&);

    /**
     * Function to write the adjacency matrix to file.
     * @param adjacencyMatrix A 2D vector of ints representing the distances to and from each city.
     */
void writeDistances(const std::vector<std::vector<int>>& adjacencyMatrix);

private:

};

#endif // SERIALIZER_H
