#ifndef DISTANCETABLE_CLASS_H
#define DISTANCETABLE_CLASS_H

#include <vector>
#include <initializer_list>

#include "city.h"

const int DUMMY = -1;

class distanceTable_class
{
public:

    distanceTable_class();

    distanceTable_class& operator=(std::vector<std::vector<int>>& other){
        vec = other;
        return *this;
    }

    int getDistance(int Xcity, int Ycity);
    int getClosestCityDistance(int Xcity);
    int getClosestCityIndex(int Xcity);
    int customClosestCityDistance (int Xcity, const std::vector<int> &allowed);
    int customClosestCityIndex (int Xcity, const std::vector<int> &allowed);

    void setDistance(int Xcity, int Ycity, int dist);
    void addCity(const std::vector<int> city_distances, int index);
    //Riley
    std::vector<std::vector<int>> getAdjMatrix();



private:

    std::vector<std::vector<int>> vec;
};

int getCity_index(const std::vector<city*>& cities, city* k);

#endif // DISTANCETABLE_CLASS_H
