#include "adddistances.h"
#include "ui_adddistances.h"

addDistances::addDistances(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addDistances)
{
    ui->setupUi(this);
}

addDistances::~addDistances()
{
    delete ui;
}
