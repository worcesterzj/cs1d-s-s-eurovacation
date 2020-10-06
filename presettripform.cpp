#include "presettripform.h"
#include "ui_presettripform.h"

presettripform::presettripform(std::vector<city*>& cities, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presettripform),
    cities(cities)
{
    ui->setupUi(this);

    refreshTripComboBox();
    tp = new executeTrip(cities);
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
