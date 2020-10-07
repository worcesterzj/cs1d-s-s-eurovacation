#ifndef ADDCITIES_H
#define ADDCITIES_H

#include <QWidget>
#include <vector>
#include <QMessageBox>

#include "city.h"
#include "DistanceTable.h"
#include "serializer.h"

namespace Ui {
class addCities;
}

class addCities : public QWidget
{
    Q_OBJECT

public:
    explicit addCities(std::vector<city*>& cities, std::vector<std::vector<int>>& distances, QWidget *parent = nullptr);
    ~addCities();

private slots:
    void on_close_pushButton_clicked();

    void on_deleteCity_pushButton_clicked();

    void on_edit_Cancel_clicked();

    void on_editCity_pushButton_clicked();

    void on_edit_deleteFood_clicked();

    void refreshLists();

    void on_edit_addFood_clicked();

    void on_edit_Save_clicked();

    void on_addCity_pushButton_clicked();

    void on_add_Cancel_clicked();

    void on_add_addDistances_clicked();

    void on_pushButton_3_clicked();

    void on_add_deleteFood_clicked();

    void on_add_addFood_clicked();

    void on_save_City_clicked();

    void on_write_Button_clicked();

    void on_edit_editDistance_clicked();

    void on_editCities_distBack_clicked();

signals:

    void refresh_UI();

private:
    Ui::addCities *ui;

    int edit_row_index;

    std::vector<city*>& cities;
    std::vector<std::vector<int>>& distances;
};

#endif // ADDCITIES_H
