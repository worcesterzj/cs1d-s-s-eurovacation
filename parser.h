#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>

#include "city.h"


class parser
{
public:
    parser();

    bool read(std::vector<city*>&);

    //Riley 10/10/2020
    bool readDistances(std::vector<std::vector<int>>& adjacencyMatrix);

    void printAdjMatrix(std::vector<std::vector<int>>& adjacencyMatrix);
};

#endif // PARSER_H
