/** \file parser.h
 * \brief Contains a class that has various parsing functions.
 */

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>

#include "city.h"


/**
 * \brief A parser that reads in data from file.
 * The "parser" class has no private members:
 *
 * The parser class reads in cities, their respective food items, and distances to other cities from file.
 */

class parser
{
public:

    /**
     * \brief A default constructor for parser.
     *
     */
    parser();


    /**
     * Read in cities and their respective food items from file.
     * @return True if parsing successful. False if parsing failed.
     * @param cities An empty vector of cities
     */
    bool read(std::vector<city*>&);

    /**
     * Read in city distances into the adjacency matrix from file.
     * @return True if parsing successful. False if parsing failed.
     * @param adjacencyMatrix An empty 2D vector of ints to hold the distances to and from each city
     */
    bool readDistances(std::vector<std::vector<int>>& adjacencyMatrix);


    /**
     * Print the adjacency matrix for troubleshooting.
     * @param adjacencyMatrix A 2D vector of ints to hold the distances to and from each city
     */
    void printAdjMatrix(std::vector<std::vector<int>>& adjacencyMatrix);
};

#endif // PARSER_H
