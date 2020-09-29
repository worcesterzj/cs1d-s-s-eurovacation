#include "presettripform.h"
#include "ui_presettripform.h"

presettripform::presettripform(const std::vector<city*>& cities, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::presettripform),
    cities(cities)
{
    ui->setupUi(this);

    refreshTripComboBox();
}

presettripform::~presettripform()
{
    delete ui;
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
