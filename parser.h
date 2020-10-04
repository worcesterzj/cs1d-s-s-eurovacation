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
};

#endif // PARSER_H
