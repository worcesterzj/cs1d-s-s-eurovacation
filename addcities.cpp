#include "addcities.h"
#include "ui_addcities.h"

bool compareCities(const city* lhs, const city* rhs) { return lhs->getName() <= rhs->getName(); } // Compare the names of two cities to order them lexically.

addCities::addCities(std::vector<city*>& cities, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addCities),
    cities( cities )
{
    ui->setupUi(this);

    ui->edit_foodTable->setColumnCount(2);
    ui->edit_foodTable->horizontalHeader()->setStretchLastSection( true );

    ui->edit_foodTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->edit_foodTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price ($)"));

    ui->add_foodTable->setColumnCount(2);
    ui->add_foodTable->horizontalHeader()->setStretchLastSection( true );

    ui->add_foodTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->add_foodTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price ($)"));

    refreshLists();

}

addCities::~addCities()
{
    delete ui;
}

void addCities::refreshLists() {
    ui->cities_listWidget->clear();

    for(auto e : cities)
        ui->cities_listWidget->addItem(e->getName());

    emit refresh_UI();

}

void addCities::on_close_pushButton_clicked()
{
    emit refresh_UI();
    close();
}


void addCities::on_deleteCity_pushButton_clicked()
{
    if(ui->cities_listWidget->currentItem() == nullptr)
        QMessageBox::information(this, "Uh oh!", "No selection made.");
    else{
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure?", "Are you sure you would like to delete \""
                                                                                         + ui->cities_listWidget->currentItem()->text() + "\"?");

        if(reply == QMessageBox::Yes) {
            cities.erase(cities.begin() + ui->cities_listWidget->row(ui->cities_listWidget->currentItem()));
            refreshLists();
        }
    }
}

void addCities::on_edit_Cancel_clicked()
{    
    edit_row_index = -1;
    ui->stackedWidget->setCurrentIndex(0);
}

void addCities::on_editCity_pushButton_clicked()
{
    if(ui->cities_listWidget->currentItem() == nullptr)
        QMessageBox::information(this, "Uh oh!", "No selection made.");
    else{
        edit_row_index = ui->cities_listWidget->row(ui->cities_listWidget->currentItem());

        ui->editCities_namelineEdit->setText(cities[edit_row_index]->getName());
        ui->editCities_countrylineEdit->setText(cities[edit_row_index]->getParentCountry());

        ui->edit_foodTable->clearContents();

        int numFoodz = cities[edit_row_index]->getNumFood();

        ui->edit_foodTable->setRowCount(numFoodz);

        for(int i = 0; i < numFoodz; i++){
            ui->edit_foodTable->setItem(i, 0, new QTableWidgetItem(cities[edit_row_index]->getFood(i)->getName()));
            ui->edit_foodTable->setItem(i, 1, new QTableWidgetItem(QString::number(cities[edit_row_index]->getFood(i)->getPrice(), 'f', 2)));
            ui->edit_foodTable->resizeColumnToContents(0);
        }

        ui->stackedWidget->setCurrentIndex(2);
    }
}

void addCities::on_edit_deleteFood_clicked()
{

    if(ui->edit_foodTable->currentRow() == -1)
        QMessageBox::information(this, "Uh oh!", "No selection made.");
    else{
        ui->edit_foodTable->removeRow(ui->edit_foodTable->currentRow());

        ui->edit_foodTable->setCurrentCell(-1, -1);
    }
}

void addCities::on_edit_addFood_clicked()
{
    ui->edit_foodTable->setRowCount(ui->edit_foodTable->rowCount() + 1);
    int index = ui->edit_foodTable->rowCount() - 1;

    ui->edit_foodTable->setItem(index, 0, new QTableWidgetItem("Default Food"));
    ui->edit_foodTable->setItem(index, 1, new QTableWidgetItem("0.99"));

}

void addCities::on_edit_Save_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure?", "Would you really like to overwrite this city?");


    if (reply == QMessageBox::Yes){
        cities[edit_row_index]->setName(ui->editCities_namelineEdit->text());
        cities[edit_row_index]->setParentCountry(ui->editCities_countrylineEdit->text());


        for(auto e : cities[edit_row_index]->getFoodRef())
            delete e;

        cities[edit_row_index]->getFoodRef().clear();

        for(int i = 0; i < ui->edit_foodTable->rowCount(); i++)
            cities[edit_row_index]->getFoodRef().push_back(new food(ui->edit_foodTable->item(i, 0)->text(), ui->edit_foodTable->item(i, 1)->text().toDouble() ));

        std::sort(cities.begin(), cities.end(), compareCities);

        refreshLists();

        ui->stackedWidget->setCurrentIndex(0);
    }
}

void addCities::on_addCity_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void addCities::on_add_Cancel_clicked()
{
    ui->add_foodTable->clear();
    ui->add_setName->clear();
    ui->add_setCountry->clear();
    ui->add_foodTable->setRowCount(0);

    ui->stackedWidget->setCurrentIndex(0);
}

void addCities::on_add_addDistances_clicked()
{
    ui->add_Stack->setCurrentIndex(1);
}

void addCities::on_pushButton_3_clicked()
{
    ui->add_Stack->setCurrentIndex(0);
}

void addCities::on_add_deleteFood_clicked()
{
    if(ui->add_foodTable->currentRow() == -1)
        QMessageBox::information(this, "Uh oh!", "No selection made.");
    else{
        ui->add_foodTable->removeRow(ui->edit_foodTable->currentRow());

        ui->add_foodTable->setCurrentCell(-1, -1);
    }
}

void addCities::on_add_addFood_clicked()
{
    ui->add_foodTable->setRowCount(ui->add_foodTable->rowCount() + 1);
    int index = ui->add_foodTable->rowCount() - 1;

    ui->add_foodTable->setItem(index, 0, new QTableWidgetItem("Default Food"));
    ui->add_foodTable->setItem(index, 1, new QTableWidgetItem("0.99"));
}

void addCities::on_save_City_clicked()
{
    city temp;

    temp.setName(ui->add_setName->text());
    temp.setParentCountry(ui->add_setCountry->text());

    for(int i = 0; i < ui->add_foodTable->rowCount(); i++)
        temp.addFoodItem(new food(ui->add_foodTable->item(i, 0)->text(), ui->add_foodTable->item(i, 1)->text().toDouble()));

    cities.push_back(new city(temp));

    std::sort(cities.begin(), cities.end(), compareCities);

    refreshLists();

    ui->add_Stack->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);
}

void addCities::on_write_Button_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure?", "Would you really like to save the cities to the disk?");


    if (reply == QMessageBox::Yes){
        serializer s;

        s.write(cities);

        QMessageBox::information(this, "Saved.", "The data was saved.", QMessageBox::Ok);
    }
}
