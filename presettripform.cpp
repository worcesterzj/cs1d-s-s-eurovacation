#include "presettripform.h"
#include "ui_presettripform.h"

presettripform::presettripform(std::vector<city*>& cities, distanceTable_class& dist, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presettripform),
    cities(cities),
    dist( dist )
{
    ui->setupUi(this);

    refreshTripComboBox();

    std::vector<int> deleteMe;
    tp = new executeTrip(cities, deleteMe);
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
    tp->show();
}

void presettripform::on_presetTripComboBox_currentIndexChanged(int index)
{

}
