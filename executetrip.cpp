#include "executetrip.h"
#include "ui_executetrip.h"

executeTrip::executeTrip(std::vector<city*>& cities, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::executeTrip),
    cities( cities )
{
    ui->setupUi(this);
}

void executeTrip::setCities(std::vector<city*>& cities){
    this->cities = cities;
}

executeTrip::~executeTrip()
{
    delete ui;
}
