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

/**
 * \brief A form to display the execution of the trip.
 */
/*! The "executeTrip" class has seven private members:\n
 * ui                           :   MainWindow*................main ui form.\n
 * trip                         :   std::vector<city*>................vector storing all cities in the trip.\n
 * distances                    :   const std::vector<int>..........current index of the city.\n
 * current_city_index           :   int..........total purchases at each city.\n
 * total                        :   double..........city distance.\n
 * distance                     :   int..........city distance.\n
 * foods                        :   std::vector<std::vector<food>*>..........Price and number of food items at each city.\n\n
 * The executeTrip class provides ui, trip, distances, current_city_index, total, distance, foods and is used for\n
 * executing a trip.
 */
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
     * Purchased foods list and dislpays total cost of all of the food items selected.
     * @param row current food item selected
     */
    void on_tableWidget_cellDoubleClicked(int row);

    /**
     * @brief on_boughtfoods_doubleClicked Removes foods that are purchased from the
     * Purchased foods list. Displays the total cost after removing the selected food items.
     * @param index current index of food item
     */
    void on_boughtfoods_doubleClicked(const QModelIndex &index);

    /**
     * @brief Go to next city (or trip summary).
     * on_nexCity_clicked Displays information for each city that you visit. Food items,\n
     * current city, distance traveled etc. If trip.size() - 2 (The city before the last) the push\n
     * buttons text will be set to "Go to trip summary". If trip.size() - 1 is reached (The last city)\n
     * once clicked pushButton will display a summary of the trip.\n
     */
    void on_nextCity_clicked();

    /**
     * @brief on_sum_End_clicked end of trip, initialize all variables to empty and clear the execute trip window.
     */
    void on_sum_End_clicked();

    /**
     * @brief on_visited_List_currentRowChanged clears current list of purchased foods, adds new item to food list.
     * @param currentRow current row of food.
     */
    void on_visited_List_currentRowChanged(int currentRow);

private:
    /** MainWindow *
     * @brief ui
     * Main ui form.
     */
    Ui::executeTrip *ui;

    /** std::vector<city*> & trip
     * @brief trip
     * Vector storing all cities in the trip.
     */
    const std::vector<city*>& trip;

    /** std::vector<int>& distances
     * @brief Distances vector to store the distance.
     * From the starting city for each of the cities in the trip.
     */
    const std::vector<int>& distances;

    /** int
     * @brief current_city_index
     * current index of the city
     */
    int current_city_index;

    /** double
     * @brief Total.
     * Total purchases at each city.
     */
    double total;

    /** int
     * @brief City distances.
     * City distances of each city in the index.
     */
    int distance;

    /** std::vector<std::vector<food*>>
     * @brief Food Items.
     * Price and number of food items at each city.
     */
    std::vector<std::vector<food>*> foods;

};
#endif // EXECUTETRIP_H
