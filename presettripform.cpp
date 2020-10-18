#include "presettripform.h"
#include "ui_presettripform.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>

presettripform::presettripform(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presettripform),
    cities(cities),
    dist( dist )
{
    ui->setupUi(this);

    refreshTripComboBox();
    ui->numberCities_lineEdit->setValidator(new QIntValidator(0, 2147483647, this));

    std::vector<int> deleteMe;
    tp = new executeTrip(trip, trip_distances);
}

presettripform::~presettripform()
{
    delete ui;
    delete tp;
}

void presettripform::refreshTripComboBox(){
    ui->presetTripComboBox->clear();

    ui->numberCities_lineEdit->clear();
    ui->numberCities_Label->setVisible(false);
    ui->numberCities_lineEdit->setVisible(false);

    ui->presetTripComboBox->addItem("Select a Trip");
    ui->presetTripComboBox->addItem("Berlin Trip A");
    ui->presetTripComboBox->addItem("Berlin Trip B");
    ui->presetTripComboBox->addItem("Paris Trip");
    ui->presetTripComboBox->setCurrentIndex(0);

}

void presettripform::on_pushButton_clicked()
{
    emit backButton_clicked();
}

void presettripform::on_executeButton_clicked()
{
    std::vector<city *> checkedCity;
    QString dupCity;

    qInfo() << dupCity;

    //checkedCity.push_back(cities[ui->comboBox->currentIndex() - 1]);
    //dupCity = checkedCity[0]->getName();


    switch(ui->presetTripComboBox->currentIndex())
    {
    case 1: {
        for(int i = 0; i < int(cities.size()); i++){
            if (cities[i]->getName().toLower() == "berlin"){
                checkedCity.push_back(cities[i]);
            }
        }

        if(int(checkedCity.size()) != 0) {
            for(int i = 0; i < int(cities.size()); i++){
                if(cities[i]->getName().toLower() == "amsterdam" ||
                        cities[i]->getName().toLower() == "brussels" ||
                        cities[i]->getName().toLower() == "budapest" ||
                        cities[i]->getName().toLower() == "hamburg" ||
                        cities[i]->getName().toLower() == "lisbon" ||
                        cities[i]->getName().toLower() == "london" ||
                        cities[i]->getName().toLower() == "madrid" ||
                        cities[i]->getName().toLower() == "paris" ||
                        cities[i]->getName().toLower() == "prague" ||
                        cities[i]->getName().toLower() == "rome"
                        ) {
                    checkedCity.push_back(cities[i]);
                }
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Berlin was not found. Could not execute the trip.");
            return;
        }

        if(int(checkedCity.size()) < 11){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Cities Missing", "Some cities were missing.\nWould you still like to go on the trip?");
            if (reply == QMessageBox::No){
                return;
            }
        }

        break; }
    case 2: {
        for(int i = 0; i < int(cities.size()); i++){
            if (cities[i]->getName().toLower() == "berlin"){
                checkedCity.push_back(cities[i]);
            }
        }

        if(int(checkedCity.size()) != 0) {
            for(int i = 0; i < int(cities.size()); i++){
                if(cities[i]->getName() == "amsterdam" ||
                        cities[i]->getName().toLower() == "brussels" ||
                        cities[i]->getName().toLower() == "budapest" ||
                        cities[i]->getName().toLower() == "hamburg" ||
                        cities[i]->getName().toLower() == "lisbon" ||
                        cities[i]->getName().toLower() == "london" ||
                        cities[i]->getName().toLower() == "madrid" ||
                        cities[i]->getName().toLower() == "paris" ||
                        cities[i]->getName().toLower() == "prague" ||
                        cities[i]->getName().toLower() == "rome" ||
                        cities[i]->getName().toLower() == "stockholm" ||
                        cities[i]->getName().toLower() == "vienna"
                        ) {
                    checkedCity.push_back(cities[i]);
                }
            }
        }
        else{
            QMessageBox::warning(this, "Error", "Berlin was not found. Could not execute the trip.");
            return;
        }

        if(int(checkedCity.size()) < 13){
            QMessageBox::StandardButton reply = QMessageBox::question(this, "Cities Missing", "Some cities were missing.\nWould you still like to go on the trip?");
            if (reply == QMessageBox::No){
                return;
            }
        }

        break; }
    case 3: {
        if(ui->numberCities_lineEdit->text().isEmpty() || ui->numberCities_lineEdit->text().toInt() <= 0){
            QMessageBox::information(this, "Incomplete Form", "Please fill out the \"Number of Cities\" field to continue.");
            return;
        }
        if(ui->numberCities_lineEdit->text().toInt() > int(cities.size())){
            QMessageBox::information(this, "Woah there!", "There are not enough cities available to go on that trip!");
            return;
        }

        for(int i = 0; i < int(cities.size()); i++){
            if (cities[i]->getName().toLower() == "paris"){
                checkedCity.push_back(cities[i]);
            }
        }

        if(int(checkedCity.size()) != 0) {
            for(int i = 0; i < int(cities.size()); i++)
                checkedCity.push_back(cities[i]);
        }
        else{
            QMessageBox::warning(this, "Error", "Paris was not found. Could not execute the trip.");
            return;
        }

        std::vector<city*> temp1;
        std::vector<city*> temp2;
        dist.getShortestTrip(cities, temp1, checkedCity);

        for(int i = 0; i < ui->numberCities_lineEdit->text().toInt(); i++)
            temp2.push_back(temp1[i]);


        trip = temp2;

        trip_distances.clear();
        std::vector<int> allowed;
        for(int i = 0; i < int(cities.size()); i++){
            for(auto e : trip){
                if(e->getName() == cities[i]->getName())
                    allowed.push_back(getCity_index(cities, cities[i]));
            }
        }

        for(int i = 0; i < int(trip.size() - 1); i++){
            for(auto e : cities){
                if(e->getName() == trip[i]->getName()){
                    trip_distances.push_back(dist.customClosestCityDistance(getCity_index(cities, e), allowed));
                    break;
                }
            }
        }

        tp->initialize_Trip();

        tp->show();
        return;
        break; }

    default: QMessageBox::information(this, "No trip selected", "Please select a trip from the preset trip options.");
        return;
    }

    std::vector<city*> temp;

    dist.getShortestTrip(cities, temp, checkedCity);

    for(int i = 0; i < static_cast<int>(temp.size()); i++)
    {
        qInfo() << temp[i]->getName();
    }

    trip = temp;

    trip_distances.clear();
    std::vector<int> allowed;
    for(int i = 0; i < int(cities.size()); i++){
        for(auto e : trip){
            if(e->getName() == cities[i]->getName())
                allowed.push_back(getCity_index(cities, cities[i]));
        }
    }

    for(int i = 0; i < int(trip.size() - 1); i++){
        for(auto e : cities){
            if(e->getName() == trip[i]->getName()){
                trip_distances.push_back(dist.customClosestCityDistance(getCity_index(cities, e), allowed));
                break;
            }
        }
    }

    tp->initialize_Trip();

    tp->show();
}

void presettripform::on_presetTripComboBox_currentIndexChanged(int index)
{
    switch(index)
    {
    case 1: ui->presetTripTextEdit->setPlainText("With this Berlin trip you will be able to visit our 11 orginal cities all over the European countryside.");
            ui->numberCities_Label->setVisible(false);
            ui->numberCities_lineEdit->setVisible(false);
            break;
    case 2: ui->presetTripTextEdit->setPlainText("The Berlin trip B package offers to take you on a wonderful trip to all of the available cities.");
            ui->numberCities_Label->setVisible(false);
            ui->numberCities_lineEdit->setVisible(false);
            break;
    case 3: ui->presetTripTextEdit->setPlainText("The Paris trip brings you across the European countryside visiting a number of cities you choose!");
            ui->numberCities_Label->setVisible(true);
            ui->numberCities_lineEdit->setVisible(true);
            break;
    default: ui->presetTripTextEdit->setPlainText("Please select a trip!");
            ui->numberCities_Label->setVisible(false);
            ui->numberCities_lineEdit->setVisible(false);
    }
}
