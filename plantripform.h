#ifndef PLANTRIPFORM_H
#define PLANTRIPFORM_H

#include <QWidget>
#include <vector>

#include "city.h"
#include "executetrip.h"

namespace Ui {
class planTripForm;
}

class planTripForm : public QWidget
{
    Q_OBJECT

public:
    explicit planTripForm(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent = nullptr); // Default constructor populates comboBox and listWidget with the vector from cities.
    ~planTripForm();

    void refreshList();

private slots:
    void on_backButton_clicked();                           // Slot that recieves a signal when the backButton is clicked, emits backButton_clicked() to MainWindow.

    void on_comboBox_currentIndexChanged(int index);        // Slot that recieves an index being selected in plantripform.ui's comboBox.

    void on_executeButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

signals:
    void backButton_clicked();                              // Signal that emits when the backButton is clicked.

private:
    Ui::planTripForm *ui;                               // ui       :   planTripForm*..........Plan Trip form.

    const std::vector<city*>& cities;                   // cities   :   const vector<city*>&...Reference to the vector, passed from MainWindow.
    const distanceTable_class& dist;

    std::vector<city*> trip;                            // trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form (see above).
    std::vector<int> trip_distances;
    executeTrip *tp;                                    // tp       :   executeTrip&..........Ui for executeTrip.
};

#endif // PLANTRIPFORM_H
