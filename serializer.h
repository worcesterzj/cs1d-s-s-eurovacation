#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <iostream>

#include "city.h"

class serializer
{
public:
    serializer();

    void write(const std::vector<city*>&);

    //Riley
void writeDistances(const std::vector<std::vector<int>>& adjacencyMatrix);

private:

};

#endif // SERIALIZER_H
