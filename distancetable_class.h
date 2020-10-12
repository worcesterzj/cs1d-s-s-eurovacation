#ifndef DISTANCETABLE_CLASS_H
#define DISTANCETABLE_CLASS_H

#include <vector>
#include <initializer_list>

#include "city.h"

const int DUMMY = -1;
int getCity_index(const std::vector<city*>& cities, city* k);

class distanceTable_class
{
public:

    distanceTable_class();

    distanceTable_class& operator=(std::vector<std::vector<int>>& other){
        vec = other;
        return *this;
    }

    int getDistance(int Xcity, int Ycity) const;
    int getClosestCityDistance(int Xcity) const;
    int getClosestCityIndex(int Xcity) const;
    int customClosestCityDistance (int Xcity, const std::vector<int> &allowed) const;
    int customClosestCityIndex (const std::vector<city*>& cities, city* Xcity, const std::vector<city*> &allowed) const;
    void getShortestTrip(const std::vector<city*> cities, std::vector<city*>& trip, std::vector<city*>& allowed) const;	//trip will hold the sorted cities, addedCities is a vector of cities that have already been added to the trip(addedCities should just be an empty vector passed in, iteration is the current iteration of the recursive function(a 1 should be passed in for iteration when called)

    //void sortTrip(const std::vector<city*>& cities, std::vector<city*> &trip);      // takes vector of cities that corresponds to this adjacency matrix, a trip to be sorted, and the address of the new generated adjacency matrix



    void setDistance(int Xcity, int Ycity, int dist);
    void addCity(const std::vector<int> city_distances, int index);

private:
    void sortRecTrip(const std::vector<city*>& cities, std::vector<city*>& trip ,int& iterations, distanceTable_class& newMatrix);

    std::vector<std::vector<int>> vec;
};

#endif // DISTANCETABLE_CLASS_H
