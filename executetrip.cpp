#include "executetrip.h"
#include "ui_executetrip.h"

executeTrip::executeTrip(std::vector<city*>& trip, std::vector<int>& distances, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::executeTrip),
    trip( trip ),
    distances( distances ),
    current_city_index( 0 )
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Name"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
}

void executeTrip::initialize_Trip()
{
    ui->tripStack->setCurrentIndex(0);
    if(int(trip.size()) == 1)
        ui->pushButton->setText("Go To Trip Summary");
    else
        ui->pushButton->setText("Go To Next City");

    current_city_index = 0;
    total = 0;
    distance = 0;

    for (auto e : foods){
        e->clear();
        delete e;
    }

    foods.clear();
    total = 0;

    for(int i = 0; i < int(trip.size()); i++)
        foods.push_back(new std::vector<food>);

    ui->welcome->setText("Welcome to " + trip[current_city_index]->getName() + '!');

    ui->cityName->setText("Current City: " + trip[current_city_index]->getName());
    ui->parentCountry_label->setText("Country: " + trip[current_city_index]->getParentCountry());

    QString foodsLabel = "Food available:\n";

    for(int i = 0; i < int(trip[current_city_index]->getFoodRef().size()); i++)
        foodsLabel.append(" - " + trip[current_city_index]->getFoodRef()[i]->getName() + ": $" + QString::number(trip[current_city_index]->getFoodRef()[i]->getPrice(), 'f', 2) + '\n');

    ui->food_Label->setText(foodsLabel);

    int numFoodz = trip[current_city_index]->getNumFood();

    ui->tableWidget->setRowCount(numFoodz);

    for(int i = 0; i < numFoodz; i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(trip[current_city_index]->getFood(i).getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("$ " + QString::number(trip[current_city_index]->getFood(i).getPrice(), 'f', 2)));
        ui->tableWidget->resizeColumnToContents(0);
    }

    ui->distanceLabel->setText("Distance traveled: 0km");
    ui->costLabel->setText("Total Cost: $0.00");

}

executeTrip::~executeTrip()
{
    delete ui;

    for (auto e : foods){
        e->clear();
        delete e;
    }
}

void executeTrip::on_cancel_Trip_button_clicked()
{
    for (auto e : foods){
        e->clear();
        delete e;
    }

    foods.clear();
    current_city_index = 0;
    total = 0;
    distance = 0;

    ui->tableWidget->clear();
    ui->boughtfoods->clear();
    close();
}

void executeTrip::on_tableWidget_cellDoubleClicked(int row)
{
    foods[current_city_index]->push_back(trip[current_city_index]->getFood(row));
    total += trip[current_city_index]->getFood(row).getPrice();

    ui->boughtfoods->addItem(trip[current_city_index]->getFood(row).getName() + " ($" + QString::number(trip[current_city_index]->getFood(row).getPrice(), 'f', 2) + ')');

    ui->costLabel->setText("Total Cost: " + QString::number(total, 'f', 2));

}

void executeTrip::on_boughtfoods_doubleClicked(const QModelIndex &index)
{
    total -= foods[current_city_index]->at(index.row()).getPrice();
    foods[current_city_index]->erase(foods[current_city_index]->begin() + index.row());
    ui->boughtfoods->takeItem(index.row());

    ui->costLabel->setText("Total Cost: " + QString::number(total, 'f', 2));
}

void executeTrip::on_pushButton_clicked()
{
    if(current_city_index == int(trip.size() - 1)){

        for(int i = 0; i < int(trip.size()); i++){
            double price = 0;
            for(int j = 0; j < int(foods[i]->size()); j++){
                price += foods[i]->at(j).getPrice();
            }
            ui->visited_List->addItem(trip[i]->getName() + "($" + QString::number(price, 'f', 2) + ')');
        }

        ui->sum_costLabel->setText("Total Cost of Trip: $" + QString::number(total, 'f', 2));
        ui->visited_List->setCurrentRow(0);

        ui->sum_distLabel->setText("Distance Traveled: " + QString::number(distance) + "km");

        ui->tripStack->setCurrentIndex(1);

    }
    else
    {
        if(current_city_index == int(trip.size() - 2))
            ui->pushButton->setText("Go To Trip Summary");

        distance += distances[current_city_index];
        current_city_index += 1;


        ui->boughtfoods->clear();

        ui->welcome->setText("Welcome to " + trip[current_city_index]->getName() + '!');

        ui->cityName->setText("Current City: " + trip[current_city_index]->getName());
        ui->parentCountry_label->setText("Country: " + trip[current_city_index]->getParentCountry());

        QString foodsLabel = "Food available:\n";

        for(int i = 0; i < int(trip[current_city_index]->getFoodRef().size()); i++)
            foodsLabel.append(" - " + trip[current_city_index]->getFoodRef()[i]->getName() + ": $" + QString::number(trip[current_city_index]->getFoodRef()[i]->getPrice(), 'f', 2) + '\n');

        ui->food_Label->setText(foodsLabel);

        int numFoodz = trip[current_city_index]->getNumFood();

        ui->tableWidget->setRowCount(numFoodz);

        for(int i = 0; i < numFoodz; i++){
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(trip[current_city_index]->getFood(i).getName()));
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem("$ " + QString::number(trip[current_city_index]->getFood(i).getPrice(), 'f', 2)));
            ui->tableWidget->resizeColumnToContents(0);
        }

        ui->distanceLabel->setText("Distance traveled: " + QString::number(distance) + "km");
    }
}

void executeTrip::on_sum_End_clicked()
{
    for (auto e : foods){
        e->clear();
        delete e;
    }

    foods.clear();
    current_city_index = 0;
    total = 0;
    distance = 0;

    ui->tableWidget->clear();
    ui->boughtfoods->clear();
    close();
}

void executeTrip::on_visited_List_currentRowChanged(int currentRow)
{
    ui->purchased_list->clear();
    for(int i = 0; i < int(foods[currentRow]->size()); i++){
        ui->purchased_list->addItem(foods[currentRow]->at(i).getName() + "($" + QString::number(foods[currentRow]->at(i).getPrice(), 'f', 2) + ')');
    }
}
