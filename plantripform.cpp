#include "plantripform.h"
#include "ui_plantripform.h"
#include "city.h"
#include <iostream>
#include <QDebug>
#include <iostream>
#include <QMessageBox>

planTripForm::planTripForm(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::planTripForm),
    cities(cities),
    dist( dist )
{
    ui->setupUi(this);

    refreshList();
    tp = new executeTrip(trip, trip_distances);
}

planTripForm::~planTripForm()
{
    delete tp;
    delete ui;
}

void planTripForm::refreshList() {
    ui->listWidget->clear();
    ui->comboBox->clear();
    ui->comboBox->addItem("None");

    for (int j = 0; j < static_cast<int>(cities.size()); j++){
        ui->comboBox->addItem(cities[j]->getName());
    }

    for(int i = 0; i < static_cast<int>(cities.size()); i++){
        ui->listWidget->addItem(cities[i]->getName());
        ui->listWidget->item(i)->setFlags(ui->listWidget->item(i)->flags() | Qt::ItemIsUserCheckable);
        ui->listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
}

void planTripForm::on_backButton_clicked()
{
    emit backButton_clicked();
}

void planTripForm::on_comboBox_currentIndexChanged(int index)
{
    for(int i = 0; i < ui->listWidget->count(); i++){
        if(ui->listWidget->item(i)->isHidden()){
            ui->listWidget->item(i)->setHidden(false);
            ui->listWidget->item(i)->setFlags(ui->listWidget->item(i)->flags() | Qt::ItemIsEnabled);
            break;
        }
    }
    if (index > 0){
        ui->listWidget->item(index - 1)->setCheckState(Qt::Unchecked);
        ui->listWidget->item(index - 1)->setHidden(true);

        ui->listWidget->item(index - 1)->setFlags(ui->listWidget->item(index - 1)->flags() & ~Qt::ItemIsEnabled);

    }
}

void planTripForm::on_executeButton_clicked()
{
    std::vector<city *> checkedCity;
    QString dupCity;

    qInfo() << dupCity;

    if(ui->comboBox->currentIndex() == 0)
    {
        QMessageBox::information(this, "ERROR", "Please select a city from the dropdown menu.");
        return;
    }

    checkedCity.push_back(cities[ui->comboBox->currentIndex() - 1]);
    dupCity = checkedCity[0]->getName();


    for(int i = 0; i < static_cast<int>(cities.size()); i++)
    {
        if(dupCity == cities[i]->getName())
        {
            continue;
        }
        else if(ui->listWidget->item(i)->checkState())
        {
            checkedCity.push_back(cities[i]);
        }
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

void planTripForm::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if(ui->listWidget->item(index.row())->checkState() == Qt::Checked)
        ui->listWidget->item(index.row())->setCheckState(Qt::Unchecked);
    else
        ui->listWidget->item(index.row())->setCheckState(Qt::Checked);
}
