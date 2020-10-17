/*#ifndef DISTANCETABLE_H_
#define DISTANCETABLE_H_

#include <iostream>
#include <iomanip>
#include <vector>

#include "city.h"

using std::vector;

const int DUMMY = -1;

    int getCity_index(const vector<city*>& cities, city* k);

    int getDistance(int Xcity, int Ycity, const vector< vector<int> > &vec);

    /*int getClosestCityDistance(int Xcity, const vector< vector<int> > &vec)
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

    int getClosestCityIndex(int Xcity, const vector< vector<int> > &vec)
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

    int customClosestCityDistance (int Xcity, const vector< vector<int> > &vec, const vector<int> &allowed)
    {
        int returnedDistance = 999999;
        int currentCity = -1;
        //Vector <2, 4, 6>

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

    int customClosestCityIndex (int Xcity, const vector< vector<int> > &vec, const vector<int> &allowed)
    {
        int closestDistance = 999999;
        int returnedIndex = Xcity;
        int currentCity = -1;
        //Vector <2, 4, 6>

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

    void printVec (const vector< vector<int> > &vect)
    {
        for (int i = 0; i < int(vect.size()); i++)
        {
            for (int j = 0; j < int(vect[i].size()); j++)
                cout << setw(6) << vect[i][j] << '\t';
            cout << endl;
        }
    }



THIS IS MAIN IF YOU WANT TO TEST OR MODIFY THIS FILE
#include "DistanceTable.h"

int main()
{

    // Initializing 2D vector "vect" with
    // values
    vector<vector<int> > vect;
    vect = {
            { DUMMY, 655, 236, 1395,361,2236,541,1767,430,878,1647},
            { 655, DUMMY, 765,873,288,2779,678,2392,1054,349, 1502},
            { 236, 765, DUMMY, 1353,489,2357,403,1578,313,898,1483},
            {1395,873,1353,DUMMY,1163,3069,1707,2512,1485,525,1274},
            {361,288,489,1163,DUMMY,2121,930,2171,376,640,1658},
            {2236,2279,2357,3069,2121,DUMMY,2189,625,1736,2707,2510},
            {541, 678, 403, 1707, 930, 2189, DUMMY, 1719, 464, 1265, 1866},
            {1767, 2392, 1578, 2512, 2171, 625, 1719, DUMMY, 1633, 2312, 1951},
            {430, 1054, 313, 1485, 376, 1736, 464, 1633, DUMMY, 1030, 1442},
            {878, 349, 898, 525, 640, 2707, 1265, 2312, 1030, DUMMY, 1303},
            {1647, 1502, 1483, 1274, 1658, 2510, 1866, 1951, 1442, 1303, DUMMY}
            };




    printVec(vect); // Displaying the 2D vector

    cout << endl << endl << "Particular Distance: ";
    cout << getDistance(2,4,vect);

    cout << endl << endl << "Closest city(Distance): ";
    cout << getClosestCityDistance(5,vect);
    cout << endl << "Closest city(Index): ";
    cout << getClosestCityIndex(5,vect);

    vector<int> allowedCities {2,4,6};
    cout << endl << endl << "Custom closest city(Distance): ";
    cout << customClosestCityDistance(3, vect, allowedCities);
    cout  << endl << "Custom closest city(Index): ";
    cout << customClosestCityIndex(3, vect, allowedCities);

    return 0;
}
 */

/*#endif /* DISTANCETABLE_H_ */
