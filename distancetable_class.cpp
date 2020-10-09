#include "distancetable_class.h"

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

int distanceTable_class::getDistance(int Xcity, int Ycity)
{
    // goes to paticular ind
    return vec[Xcity][Ycity];
}

void distanceTable_class::setDistance(int Xcity, int Ycity, int dist){
    vec[Xcity][Ycity] = dist;
    return;
}


int distanceTable_class::getClosestCityDistance(int Xcity)
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
int distanceTable_class::getClosestCityIndex(int Xcity)
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
int distanceTable_class::customClosestCityDistance (int Xcity, const std::vector<int> &allowed)
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
int distanceTable_class::customClosestCityIndex (int Xcity, const std::vector<int> &allowed)
{
    int closestDistance = 999999;
    int returnedIndex = Xcity;
    int currentCity = -1;
    //std::vector <2, 4, 6>
    for (int j = 0; j < int(allowed.size()); j++)
    {
        currentCity = allowed[j];
            if (vec[Xcity][currentCity] < closestDistance && vec[Xcity][currentCity] != DUMMY)
            {
                    closestDistance = vec[Xcity][currentCity];
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
