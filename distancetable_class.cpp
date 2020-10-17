#include "distancetable_class.h"
#include <algorithm>

int getCity_index(const std::vector<city*>& cities, city* k) {

   auto it = std::find(cities.begin(), cities.end(), k);   // Find index of XCity
   if(it != cities.end()){
       return std::distance(cities.begin(), it);
   }
   else{
       throw "CITY_NOT_FOUND";
   }
}


distanceTable_class::distanceTable_class()
{

}

int distanceTable_class::getDistance(int Xcity, int Ycity) const
{
    // goes to paticular ind
    return vec[Xcity][Ycity];
}

void distanceTable_class::setDistance(int Xcity, int Ycity, int dist){
    vec[Xcity][Ycity] = dist;
    return;
}


int distanceTable_class::getClosestCityDistance(int Xcity) const
{
    int returnedDistance = 999999;
    for (int i = 0; i < int(vec.size()); i++)
    {
        if (vec[Xcity][i] < returnedDistance && vec[Xcity][i] != DUMMY)
        {
            returnedDistance = vec[Xcity][i];
        }
    }
    return returnedDistance;
}
int distanceTable_class::getClosestCityIndex(int Xcity) const
{
    int closestDistance = 999999;
    int returnedIndex = Xcity;
    for (int i = 0; i < int(vec.size()); i++)
    {
        if (vec[Xcity][i] < closestDistance && vec[Xcity][i] != DUMMY)
        {
            closestDistance = vec[Xcity][i];
            returnedIndex = i;
        }
    }
    return returnedIndex;
}
int distanceTable_class::customClosestCityDistance (int Xcity, const std::vector<int> &allowed) const
{
    int returnedDistance = 999999;
    int currentCity = -1;
    //std::vector <2, 4, 6>
    for (int j = 0; j < int(allowed.size()); j++)
    {
        currentCity = allowed[j];
            if (vec[Xcity][currentCity] < returnedDistance && vec[Xcity][currentCity] != DUMMY)
            {
                    returnedDistance = vec[Xcity][currentCity];
            }
    }
    return returnedDistance;
}

void distanceTable_class::getShortestTrip(const std::vector<city*>& cities, std::vector<city*>& trip, std::vector<city*>& allowed) const
    {
        trip.push_back(allowed[0]);

        int nextClosestCity = 0;   //customClosestCityIndex (cities, , allowed);	//define the next closest city

        for(int i = 0; i < int(allowed.size()); i++){
            bool brk = false;
            for(auto e : cities){
                if(e->getName() == allowed[i]->getName()){
                    nextClosestCity = customClosestCityIndex(cities, e, allowed);
                    allowed.erase(allowed.begin());
                    brk = true;
                    break;
                }
            }
            if(brk) break;
        }

        if(allowed.size() == 0)			//if all of the cities have been added to the trip
        {
            return;
        }

        for(int i = 0; i < int(allowed.size()); i++){
            if(cities[nextClosestCity]->getName() == allowed[i]->getName()){
                std::iter_swap(allowed.begin(), allowed.begin() + i);
                break;
            }
        }

        getShortestTrip(cities, trip, allowed); //Call getShortestTrip using the next closest city as the startingCity

    }

int distanceTable_class::customClosestCityIndex(const std::vector<city*>& cities, city* Xcity, const std::vector<city*> &allowed) const
{
    int closestDistance = 999999;
    int returnedIndex = getCity_index(cities, Xcity);
    int currentCity = -1;
    //std::vector <2, 4, 6>
    for (int j = 0; j < int(allowed.size()); j++)
    {
        currentCity = getCity_index(cities, allowed[j]);
            if (vec[getCity_index(cities,Xcity)][currentCity] < closestDistance && vec[getCity_index(cities,Xcity)][currentCity] != DUMMY)
            {
                    closestDistance = vec[getCity_index(cities,Xcity)][currentCity];
                    returnedIndex = currentCity;
            }
    }
    return returnedIndex;
}


void distanceTable_class::addCity(std::vector<int> city_distances, int index){
    for(int i = 0; i < int(vec.size()); i++){
        vec[i].insert(vec[i].begin() + index, city_distances[i]);
    }

    vec.insert(vec.begin() + index, city_distances);
}

void distanceTable_class::deleteCity( int index){
    for(int i = 0; i < int(vec.size()); i++){
        vec[i].erase(vec[i].begin() + index);
    }

    vec.erase(vec.begin() + index);
}

std::vector<std::vector<int>>& distanceTable_class::getAdjMatrix()
{
    return vec;
}
