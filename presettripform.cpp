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

    ui->presetTripComboBox->addItem("Select a Trip");
    ui->presetTripComboBox->addItem("Berlin Trip A");
    ui->presetTripComboBox->addItem("Berlin Trip B");
    ui->presetTripComboBox->addItem("Paris Trip");

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
    case 1: checkedCity.push_back(cities[1]);
        checkedCity.push_back(cities[4]);
        checkedCity.push_back(cities[0]);
        checkedCity.push_back(cities[2]);
        checkedCity.push_back(cities[8]);
        checkedCity.push_back(cities[6]);
        checkedCity.push_back(cities[9]);
        checkedCity.push_back(cities[3]);
        checkedCity.push_back(cities[10]);
        checkedCity.push_back(cities[7]);
        checkedCity.push_back(cities[5]);
        break;
     case 2:
        checkedCity.push_back(cities[1]);
        dupCity = checkedCity[0]->getName();
        for(int i = 0; i < static_cast<int>(cities.size()); i++)
        {
            if(dupCity == cities[i]->getName())
            {
                continue;
            }
            else
            {
                checkedCity.push_back(cities[i]);
            }
        }
        break;
    case 3: checkedCity.push_back(cities[8]);
        checkedCity.push_back(cities[2]);
        checkedCity.push_back(cities[0]);
        checkedCity.push_back(cities[4]);
        checkedCity.push_back(cities[1]);
        checkedCity.push_back(cities[9]);
        checkedCity.push_back(cities[3]);
        checkedCity.push_back(cities[10]);
        checkedCity.push_back(cities[6]);
        checkedCity.push_back(cities[7]);
        checkedCity.push_back(cities[5]);
        break;

    default: QMessageBox::information(this, "ERROR", "Please select a trip from the preset trip options.");
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
    case 1: ui->presetTripTextEdit->setPlainText("With this Berlin trip you will be able to visit our 11 orginal cities all over the European countryside");
            break;
    case 2:ui->presetTripTextEdit->setPlainText("The Berlin trip B package offers to take you on a wonderful trip to all of the available cities");
        break;
    case 3:ui->presetTripTextEdit->setPlainText("The Paris trip brings you across the European countryside visiting the orginal 11 cities to be visited");
            break;
    default: ui->presetTripTextEdit->setPlainText("Please select a trip!");
    }
}
