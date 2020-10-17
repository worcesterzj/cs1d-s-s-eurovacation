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
    explicit executeTrip(std::vector<city*>& cities, std::vector<int>& distances, QWidget *parent = nullptr);
    ~executeTrip();

    void initialize_Trip();                                         // Let the trip form know we've begun the trip.

private slots:
    void on_cancel_Trip_button_clicked();

    void on_tableWidget_cellDoubleClicked(int row);

    void on_boughtfoods_doubleClicked(const QModelIndex &index);

    void on_nextCity_clicked();

    void on_sum_End_clicked();

    void on_visited_List_currentRowChanged(int currentRow);

private:
    Ui::executeTrip *ui;
    const std::vector<city*>& trip;
    const std::vector<int>& distances;

    int current_city_index;

    double total;                                                                   // Total purchases at each city.
    int distance;
    std::vector<std::vector<food>*> foods;                                                // Price & number of food items at each city.
};

#endif // EXECUTETRIP_H
