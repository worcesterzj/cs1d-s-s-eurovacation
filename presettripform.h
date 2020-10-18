/** \file presettripform.H
 * \brief contains information for the UI and logic for plantripform implementation
 */
#ifndef PRESETTRIPFORM_H
#define PRESETTRIPFORM_H

#include <QWidget>
#include <vector>

#include "city.h"
#include "executetrip.h"
#include "distancetable_class.h"

namespace Ui {
class presettripform;
}

/**
 * \brief A QWidget window to plan a preset trip.
 */
/*! ui               :   planTripForm*..........Plan Trip form\n
 * cities           :   const vector<city*>&...Reference to the vector, passed from MainWindow.\n
 * Berlin_Trip_A    :   vector<city*>...........Vector cities in a trip, passed to execute trip form.\n
 * Berlin_Trip_B    :   vector<city*>...........Vector cities in a trip, passed to execute trip form.\n
 * Paris_Trip       :   vector<city*>...........Vector cities in a trip, passed to execute trip form.\n
 * trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form.\n
 * distances        :   distanceTable_class&......................Reference to the distance table from MainWindow.\n
 * trip_distances   :   vector<int>.....................vectors of ints used to determine distances between cities.\n
 * tp               :   executeTrip&..........Ui for executeTrip.\n\n
 * presettripform provides functionality for preset trip selection.
 */
class presettripform : public QWidget
{
    Q_OBJECT

public:
    /**
     *\brief presetTripForm
     * overloaded constructor to initialize all needed data members
     * @param cities The vector of cities being passed to this window.
     * @param distances The adjacency matrix being passed to this window.
     * @param parent The parent widget (for ui).
     */
    explicit presettripform(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent = nullptr);
    /**
      *\brief ~presettripform
      * Destructor. Does nothing of note. simply deallocates used vectors
      */
    ~presettripform();

    /**
      *\brief refreshTripComboBox
      * Refresh the combobox in this ui
      */
    void refreshTripComboBox();

private slots:

    /**
      *\brief on_pushButton_clicked
      * clicks button to push
      */
    void on_pushButton_clicked();

    /**
      *\brief on_executeButton_clicked
      * opens the execute trip UI along with the all the neccesary variables to complete said trip (trip & trip_distances)
      */
    void on_executeButton_clicked();

    /**
      *\brief on_presetTripComboBox_currentIndexChanged
      * detects when the combobox to show the various preset trips has been changed and changes the Qplaintext trip descprition
      * also used to determine which trip is going to be executed
      * @param index the current slot the combobox is on to complete above uses
      */
    void on_presetTripComboBox_currentIndexChanged(int index);

signals:
    /**
      *\brief Signal for backButton.
      * closes the presettripwindow and goes back to the main window UI
      */
    void backButton_clicked();

private:
    /**
     * \brief ui
     * plantripform window UI.
     */
    Ui::presettripform *ui;
    
    /**
     * \brief cities
     * vector<city*>& Reference to the vector of cities from MainWindow.
     */
    const std::vector<city*>& cities;
    /**
     * \brief dist
     * distanceTable_class& Reference to the distance table from MainWindow.
     */
    const distanceTable_class& dist;
    /**
     * \brief Berlin_trip_a
     * vectors of city pointers used to execute a particular trip
     */
    std::vector<city*> Berlin_trip_a;                // trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form (see above).
    /**
     * \brief Berlin_trip_b
     * vectors of city pointers used to execute a particular trip
     */
    std::vector<city*> Berlin_trip_b;
    /**
     * \brief Paris_trip
     * vectors of city pointers used to execute a particular trip
     */
    std::vector<city*> Paris_trip;
    /**
     * \brief trip_distances
     * vectors of ints used to determine distances between cities
     */
    std::vector<int> trip_distances;
    /**
     * \brief trip
     * vector<city*> passed on to execute trip to show what cities are being visited
     */
    std::vector<city*> trip;
    /**
     * \brief tp
     * UI for execute trip
     */
    executeTrip *tp;                            // tp       :   executeTrip&..........Ui for executeTrip.
};

#endif // PRESETTRIPFORM_H
