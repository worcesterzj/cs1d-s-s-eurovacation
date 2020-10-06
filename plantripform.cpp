#include "plantripform.h"
#include "ui_plantripform.h"
#include <iostream>

planTripForm::planTripForm(const std::vector<city*>& cities, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::planTripForm),
    cities(cities)
{
    ui->setupUi(this);

    refreshList();
    tp = new executeTrip(trip);
}

planTripForm::~planTripForm()
{
    delete starting_city;
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
    tp->show();
}
