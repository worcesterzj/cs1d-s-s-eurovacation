#ifndef PRESETTRIPFORM_H
#define PRESETTRIPFORM_H

#include <QWidget>
#include <vector>

#include "city.h"
#include "executetrip.h"

namespace Ui {
class presettripform;
}

class presettripform : public QWidget
{
    Q_OBJECT

public:
    explicit presettripform(std::vector<city*>& cities, QWidget *parent = nullptr);
    ~presettripform();

    void refreshTripComboBox();

private slots:

    void on_pushButton_clicked();

    void on_executeButton_clicked();

signals:
    void backButton_clicked();

private:
    Ui::presettripform *ui;

    std::vector<city*>& cities;

    std::vector<city*> Berlin_trip;                // trip             :   vector<city*>.................Vector cities in a trip, passed to execute trip form (see above).
    std::vector<city*> Paris_trip;

    executeTrip *tp;                            // tp       :   executeTrip&..........Ui for executeTrip.
};

#endif // PRESETTRIPFORM_H
