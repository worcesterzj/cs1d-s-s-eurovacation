/** \file addcities.h
 * \brief Contains two QItemDelegators (distance_delegator and price_delegator) and the addCities class.
 */

#ifndef ADDCITIES_H
#define ADDCITIES_H

#include <QWidget>
#include <vector>
#include <QMessageBox>
#include <iostream>

#include "delegators.h"
#include "city.h"
#include "distancetable_class.h"
#include "serializer.h"


namespace Ui {
class addCities;
}

/**
 * \brief A QWidget window to add cities in.
 * ui               :   addCities*................................Pointer to the ui parent.
 * edit_row_index   :   int.......................................Index of the current city being edited.
 * cities           :   vector<city*>&............................Reference to the vector of cities from MainWindow.
 * distances        :   distanceTable_class&......................Reference to the distance table from MainWindow.
 */
class addCities : public QWidget
{
    Q_OBJECT

public:
    /**
     * \brief addCities
     * Default constructor. Assigns cities and distances to cities and distances member data.
     * @param cities The vector of cities being passed to this window.
     * @param distances The adjacency matrix being passed to this window.
     * @param parent The parent widget (for ui).
     */
    explicit addCities(std::vector<city*>& cities, distanceTable_class& distances, QWidget *parent = nullptr);
    /**
      *\brief ~addCities
      * Destructor. Does nothing of note.
      */
    ~addCities();

private slots:
    /**
     * \brief on_close_pushButton_clicked
     * Closes the window. Emits a signal to refresh the UI inside of MainWindow.
     */
    void on_close_pushButton_clicked();

    /**
     * \brief on_deleteCity_pushButton_clicked
     * Delete the city in the cities vector at the selected index in this window's QListWidget view of the cities.
     */
    void on_deleteCity_pushButton_clicked();

    /**
     * \brief on_edit_Cancel_clicked
     * Stop editing the current city without saving the changes.
     */
    void on_edit_Cancel_clicked();

    /**
     * \brief on_edit_Cancel_clicked
     * Switch to the editor window add the index of the currently selected city in this window's QListWidget view of the cities.
     */
    void on_editCity_pushButton_clicked();

    /**
     * \brief on_edit_deleteFood_clicked
     * Delete the food selected in the edit window's QTableWidget view of the foods within the city.
     */
    void on_edit_deleteFood_clicked();

    /**
     * \brief refreshLists
     * Refresh the lists in this ui (as well emitting the signal as the ones in MainWindow).
     */
    void refreshLists();

    /**
     * \brief on_edit_addFood_clicked
     * Add a food item to the currenlty edited city. Starts as "Default Food" at the price '0.99'.
     */
    void on_edit_addFood_clicked();

    /**
     * \brief on_edit_Save_clicked
     * Save the currently edited city.
     */
    void on_edit_Save_clicked();

    /**
     * \brief on_addCity_pushButton_clicked
     * Switch to the add city portion of this window.
     */
    void on_addCity_pushButton_clicked();

    /**
     * \brief on_add_Cancel_clicked
     * Cancel the add city operation without adding the city to the cities.
     */
    void on_add_Cancel_clicked();

    /**
     * \brief on_add_addDistances_clicked
     * Switch to the add city distance menu in the add city menu.
     */
    void on_add_addDistances_clicked();

    /**
     * \brief on_add_back_clicked
     * Go back to the main add city window.
     */
    void on_add_back_clicked();

    /**
     * \brief on_add_deleteFood_clicked
     * Delete the food selected in the add city window's food QTableWidget.
     */
    void on_add_deleteFood_clicked();

    /**
     * \brief on_add_addFood_clicked
     * Add food to the add city window's food QTableWidget. Starts as "Default Food" with a price of '0.99'.
     */
    void on_add_addFood_clicked();

    /**
     * \brief on_save_City_clicked
     * Save the new city to be added to the vector.
     */
    void on_save_City_clicked();

    /**
     * \brief on_write_Button_clicked
     * Write the current state of the cities vector and adjacency matrix to the .sas file (see parser).
     */
    void on_write_Button_clicked();

    /**
     * \brief on_edit_editDistance_clicked
     * Switch the form to edit the distances of a city in the edit window.
     */
    void on_edit_editDistance_clicked();

    /**
     * \brief on_editCities_distBack_clicked
     * Go back to edit cities form from edit distances form.
     */
    void on_editCities_distBack_clicked();

signals:

    /**
     * \brief refresh_UI
     * Refresh the UI in MainWindow when emitted.
     */
    void refresh_UI();

private:
    /**
     * \brief ui
     * Window UI.
     */
    Ui::addCities *ui;

    /**
     * \brief edit_row_index
     * int Index of the current city being edited.
     */
    int edit_row_index;

    /**
     * \brief cities
     * vector<city*>& Reference to the vector of cities from MainWindow.
     */
    std::vector<city*>& cities;

    /**
     * \brief distances
     * distanceTable_class& Reference to the distance table from MainWindow.
     */
    distanceTable_class& distances;
};

#endif // ADDCITIES_H
