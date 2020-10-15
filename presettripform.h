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

class presettripform : public QWidget
{
    Q_OBJECT

public:
    explicit presettripform(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent = nullptr);
    ~presettripform();

    void refreshTripComboBox();

private slots:

    void on_pushButton_clicked();

    void on_executeButton_clicked();

    void on_presetTripComboBox_currentIndexChanged(int index);

signals:
    void backButton_clicked();

private:
    Ui::presettripform *ui;

    const std::vector<city*>& cities;
    const distanceTable_class& dist;

    std::vector<city*> Berlin_trip_a;                // trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form (see above).
    std::vector<city*> Berlin_trip_b;
    std::vector<city*> Paris_trip;

    std::vector<int> trip_distances;
    std::vector<city*> trip;

    executeTrip *tp;                            // tp       :   executeTrip&..........Ui for executeTrip.
};

#endif // PRESETTRIPFORM_H
