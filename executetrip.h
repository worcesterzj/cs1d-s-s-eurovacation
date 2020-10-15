/** \file executetrip.h
 * \brief A file that contains the class executeTrip
  */

#ifndef EXECUTETRIP_H
#define EXECUTETRIP_H

#include <QWidget>
#include <vector>
#include <QMessageBox>

#include "city.h"
#include "distancetable_class.h"

namespace Ui {
class executeTrip;
}

class executeTrip : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief executeTrip initializes a two new QTableWidgetItem(), cities, distances, and parent.
     * @param cities the vector of cities.
     * @param distances the vector of city distances.
     * @param parent QWidget pointer
     */
    explicit executeTrip(std::vector<city*>& cities, std::vector<int>& distances, QWidget *parent = nullptr);
    ~executeTrip();

    /**
     * @brief Let the trip form know we've begun the trip.
     */
    void initialize_Trip();                                         // Let the trip form know we've begun the trip.

private slots:
    /**
     * @brief on_cancel_Trip_button_clicked initialize all values to empty set and close the window
     */
    void on_cancel_Trip_button_clicked();

    /**
     * @brief on_tableWidget_cellDoubleClicked Adds foods that are purchased to the
     * purchased foods list and dislpays total cost of all of the food items selected.
     * @param row current food item selected
     */
    void on_tableWidget_cellDoubleClicked(int row);

    /**
     * @brief on_boughtfoods_doubleClicked Removes foods that are purchased from the
     * purchased foods list. Displays the total cost after removing the selected food items.
     * @param index current index of food item
     */
    void on_boughtfoods_doubleClicked(const QModelIndex &index);

    /**
     * @brief on_pushButton_clicked Displays information for each city that you visit. Food items,
     * current city, distance traveled etc. If trip.size() - 2 (The city before the last) the push
     * buttons text will be set to "Go to trip summary". If trip.size() - 1 is reached (The last city)
     * once clicked pushButton will display a summary of the trip.
     */
    void on_pushButton_clicked();

    /**
     * @brief on_sum_End_clicked end of trip, initialize all variables to empty and clear the execute
     * trip window
     */
    void on_sum_End_clicked();

    /**
     * @brief on_visited_List_currentRowChanged clears current list of purchased foods, adds new item to food list
     * @param currentRow current row of food
     */
    void on_visited_List_currentRowChanged(int currentRow);

private:
    /** MainWindow *
     * @brief ui
     * main ui form
     */
    Ui::executeTrip *ui;
    /** std::vector<city*> & trip
     * @brief trip
     * vector storing all cities in the trip
     */
    const std::vector<city*>& trip;
    /** std::vector<int>& distances
     * @brief distances vector to store the distance
     * from the starting city for each of the cities in the trip
     */
    const std::vector<int>& distances;

    /** int
     * @brief current_city_index
     * current index of the city
     */
    int current_city_index;

    /** double
     * @brief total
     * total purchases at each city
     */
    double total;                                                                   // Total purchases at each city.
    /** int
     * @brief distance
     * city distance
     */
    int distance;
    /** std::vector<std::vector<food*>>
     * @brief foods
     * Price and number of food items at each city
     */
    std::vector<std::vector<food>*> foods;                                                // Price & number of food items at each city.
};

#endif // EXECUTETRIP_H
