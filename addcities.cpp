#include "addcities.h"
#include "ui_addcities.h"

bool compareCities(const city* lhs, const city* rhs) { return lhs->getName() <= rhs->getName(); } // Compare the names of two cities to order them lexically.

addCities::addCities(std::vector<city*>& cities, distanceTable_class& distances, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addCities),
    cities(cities),
    distances(distances)
{
    ui->setupUi(this);

    setWindowTitle("S&S Administrator Area");

    ui->edit_foodTable->setColumnCount(2);
    ui->edit_foodTable->horizontalHeader()->setStretchLastSection( true );

    ui->edit_foodTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->edit_foodTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price ($)"));
    ui->edit_foodTable->setItemDelegateForColumn(1, new price_delegator);

    ui->add_foodTable->setColumnCount(2);
    ui->add_foodTable->horizontalHeader()->setStretchLastSection( true );

    ui->add_foodTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->add_foodTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price ($)"));
    ui->add_foodTable->setItemDelegateForColumn(1, new price_delegator);

    ui->edit_Table->setColumnCount(1);
    ui->edit_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Distance"));
    ui->edit_Table->setItemDelegate(new distance_delegator);

    ui->distance_Table->setColumnCount(1);
    ui->distance_Table->setHorizontalHeaderItem(0, new QTableWidgetItem("Distance"));
    ui->distance_Table->setItemDelegate(new distance_delegator);


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

            cities.erase(cities.begin() + ui->cities_listWidget->currentRow());
            distances.deleteCity(ui->cities_listWidget->currentRow());
            refreshLists();
        }
    }
}

void addCities::on_edit_Cancel_clicked()
{
    setWindowTitle("S&S Administrator Area");
    edit_row_index = -1;
    ui->stackedWidget->setCurrentIndex(0);
}

void addCities::on_editCity_pushButton_clicked()
{
    if(ui->cities_listWidget->currentItem() == nullptr)
        QMessageBox::information(this, "Uh oh!", "No selection made.");
    else{
        setWindowTitle("Edit Existing City");

        edit_row_index = ui->cities_listWidget->row(ui->cities_listWidget->currentItem());

        ui->editCities_namelineEdit->setText(cities[edit_row_index]->getName());
        ui->editCities_countrylineEdit->setText(cities[edit_row_index]->getParentCountry());

        ui->edit_foodTable->clearContents();

        int numFoodz = cities[edit_row_index]->getNumFood();

        ui->edit_foodTable->setRowCount(numFoodz);

        for(int i = 0; i < numFoodz; i++){
            ui->edit_foodTable->setItem(i, 0, new QTableWidgetItem(cities[edit_row_index]->getFood(i).getName()));
            ui->edit_foodTable->setItem(i, 1, new QTableWidgetItem(QString::number(cities[edit_row_index]->getFood(i).getPrice(), 'f', 2)));
            ui->edit_foodTable->resizeColumnToContents(0);
        }
        ui->edit_Table->setRowCount(int(cities.size() - 1));
        int modifier = 0;
        for(int i = 0; i < int(cities.size()); i++){
            if(i != edit_row_index){
                ui->edit_Table->setVerticalHeaderItem(i - modifier, new QTableWidgetItem(cities[i]->getName()));
                ui->edit_Table->setItem(0, i - modifier, new QTableWidgetItem(QString::number(distances.getDistance(getCity_index(cities, cities[edit_row_index]),getCity_index(cities, cities[i])))));
            }
            else{
                modifier = 1;
            }
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
    for(int i = 0; i < ui->edit_Table->rowCount(); i++){
        if(!ui->edit_Table->item(i,0) || ui->edit_Table->item(i,0)->text() == "") {
            QMessageBox::information(this, "Uh oh!", "Be sure to fill out all of the distances.");
            return;
        }
    }

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

        for(auto e : cities){
            if(e->getName() == ui->editCities_namelineEdit->text()){
                edit_row_index = getCity_index(cities, e);
                break;
            }
        }
        int modifier = 0;
        for(int i = 0; i < int(cities.size()); i++){
            if(i == edit_row_index){
                distances.setDistance(i, edit_row_index, -1);
                modifier = 1;
            }
            else{
                distances.setDistance(i, edit_row_index, ui->edit_Table->item(i - modifier, 0)->text().toInt());
                distances.setDistance(edit_row_index, i, ui->edit_Table->item(i - modifier, 0)->text().toInt());
            }
        }

        edit_row_index = -1;
        setWindowTitle("S&S Administrator Area");

        refreshLists();

        ui->stackedWidget->setCurrentIndex(0);
    }
}

void addCities::on_addCity_pushButton_clicked()
{
    setWindowTitle("Add New City");

    ui->distance_Table->setRowCount(int(cities.size()));

    for(int i = 0; i < int(cities.size()); i++)
        ui->distance_Table->setVerticalHeaderItem(i, new QTableWidgetItem(cities[i]->getName()));

    ui->stackedWidget->setCurrentIndex(1);
}

void addCities::on_add_Cancel_clicked()
{
    setWindowTitle("S&S Administrator Area");
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


void addCities::on_add_back_clicked()
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

    for(int i = 0; i < ui->distance_Table->rowCount(); i++){
        if(!ui->distance_Table->item(i,0) || ui->distance_Table->item(i,0)->text() == "") {
            QMessageBox::information(this, "Uh oh!", "Be sure to fill out all of the distances.");
            return;
        }
    }

    city temp;

    temp.setName(ui->add_setName->text());
    temp.setParentCountry(ui->add_setCountry->text());

    for(int i = 0; i < ui->add_foodTable->rowCount(); i++)
        temp.addFoodItem(new food(ui->add_foodTable->item(i, 0)->text(), ui->add_foodTable->item(i, 1)->text().toDouble()));

    cities.push_back(new city(temp));

    std::sort(cities.begin(), cities.end(), compareCities);

    std::vector<int> temp_distances;

    int index_of_this_city = 0;

    for(int i = 0; i < int(cities.size()); i++){
        if(i == int(cities.size() - 1)){
            temp_distances.push_back(-1);
        }
        else{


            for(auto e : cities){
                if(e->getName() == ui->add_setName->text()){
                    index_of_this_city = getCity_index(cities, e);
                    break;
                }
            }

            temp_distances.push_back(ui->distance_Table->item(i, 0)->text().toInt());
        }
    }

    distances.addCity(temp_distances, index_of_this_city);

    setWindowTitle("S&S Administrator Area");

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
        //Riley
        s.writeDistances(distances.getAdjMatrix());

        QMessageBox::information(this, "Saved.", "The data was saved.", QMessageBox::Ok);
    }
}

void addCities::on_edit_editDistance_clicked()
{
    ui->editCitiesStack->setCurrentIndex(1);
}

void addCities::on_editCities_distBack_clicked()
{
    ui->editCitiesStack->setCurrentIndex(0);
}
