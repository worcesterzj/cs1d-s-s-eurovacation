/** \file plantripform.H
 * \brief contains information for the UI and logic for plantripform implementation
 */
#ifndef PLANTRIPFORM_H
#define PLANTRIPFORM_H

#include <QWidget>
#include <vector>

#include "city.h"
#include "executetrip.h"

namespace Ui {
class planTripForm;
}


/**
 * \brief A QWidget window to plan a custom trip.
 */
/*! ui               :   planTripForm*..........Plan Trip form.\n
 * cities           :   const vector<city*>&...Reference to the vector, passed from MainWindow.\n
 * trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form.\n
 * distances        :   distanceTable_class&......................Reference to the distance table from MainWindow.\n
 * trip_distances   :   vector<int>.....................vectors of ints used to determine distances between cities.\n
 * tp               :   executeTrip&..........Ui for executeTrip.\n\n
 * planTripForm provides a functionality for custom trips.
 */
class planTripForm : public QWidget
{
    Q_OBJECT

public:
     /**
     *\brief planTripForm
     * Overloaded constructor to initialize all needed data members.
     * @param cities The vector of cities being passed to this window.
     * @param distances The adjacency matrix being passed to this window.
     * @param parent The parent widget (for ui).
     */
    explicit planTripForm(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent = nullptr); // Default constructor populates comboBox and listWidget with the vector from cities.
     /**
      *\brief ~planTripForm
      * Destructor. Does nothing of note. simply deallocates used vectors
      */
      ~planTripForm();
      /**
      *\brief refreshList
      * Refresh the lists in this ui (as well emitting the signal as the ones in MainWindow).
      */
    void refreshList();

private slots:
      /**
      *\brief on_backButton_clicked
      * Closes the plan trip window and goes back to the main window UI.
      */
    void on_backButton_clicked();                           // Slot that recieves a signal when the backButton is clicked, emits backButton_clicked() to MainWindow.

      /**
      *\brief on_comboBox_currentIndexChanged
      * Used to select the starting city (and eliminate duplicate selection) and then is used in execute_trip.
      * @param index the current number the Qcombobox is on to preform the aformentioned functions
      */
    void on_comboBox_currentIndexChanged(int index);        // Slot that recieves an index being selected in plantripform.ui's comboBox.
    
    /**
      *\brief on_executeButton_clicked
      * Opens the execute trip UI along with the all the neccesary variables to complete said trip (trip & trip_distances).
      */
    void on_executeButton_clicked();

    /**
      *\brief on_listWidget_doubleClicked
      * When an entry is double clicked it becomes checked or unchecked. used to determine what cites will be traveled to.
      * @param index Which entry out of list that becomes checked or unchecked.
      */
    void on_listWidget_doubleClicked(const QModelIndex &index);

signals:
    /**
      *\brief Signal for ackButton
      * Closes the plantripform UI and sends user back to the main window.
      */
    void backButton_clicked();                              // Signal that emits when the backButton is clicked.

private:
     /**
     * \brief ui
     * plantripform window UI.
     */
    Ui::planTripForm *ui;                               // ui       :   planTripForm*..........Plan Trip form.
    /**
     * \brief cities
     * vector<city*>& Reference to the vector of cities from MainWindow.
     */
    const std::vector<city*>& cities;                   // cities   :   const vector<city*>&...Reference to the vector, passed from MainWindow.
    
    /**
     * \brief dist
     * distanceTable_class& Reference to the distance table from MainWindow.
     */
    const distanceTable_class& dist;

    /**
     * \brief trip
     * vector<city*> passed on to execute trip to show what cities are being visited
     */
    std::vector<city*> trip;                            // trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form (see above).
    
    /**
     * \brief trip_distances
     * vectors of ints used to determine distances between cities
     */
    std::vector<int> trip_distances;
    
    /**
     * \brief tp
     * UI for execute trip
     */
    executeTrip *tp;                                    // tp       :   executeTrip&..........Ui for executeTrip.
};

#endif // PLANTRIPFORM_H
