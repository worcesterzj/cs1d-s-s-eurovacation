#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    cities.push_back(new city("Amsterdam", "The Netherlands"));
    cities.push_back(new city("Berlin", "Germany"));
    cities.push_back(new city("Brussels", "Belgium"));
    cities.push_back(new city("Budapest", "Hungary"));
    cities.push_back(new city("Hamburg", "Germany"));
    cities.push_back(new city("Lisbon", "Portugal"));
    cities.push_back(new city("London", "England"));
    cities.push_back(new city("Madrid", "Spain"));
    cities.push_back(new city("Paris", "France"));
    cities.push_back(new city ("Prague", "The Czech Republic"));
    cities.push_back(new city("Rome", "Italy"));
    cities.push_back(new city("Stockhome", "Sweden"));
    cities.push_back(new city("Vienna", "Austria"));

// Fun stuff

    cities.push_back(new city("Waterdeep", "Waterdeep"));
    cities[13]->addFoodItem(new food("Quipper", 56.37));
    cities[13]->addFoodItem(new food("Luiren Spring Cheese", 356.97));
    cities[13]->addFoodItem(new food("Tart", 3.00));
    cities[13]->addFoodItem(new food("Waterdhavian", 698.77));
    cities[13]->addFoodItem(new food("Blackbread", 3.00));

    cities[0]->addFoodItem(new food("Stroopwafel", 5.76));
    cities[0]->addFoodItem(new food("Thick Dutch Fries", 3.21));
    cities[0]->addFoodItem(new food("Kibbeling", 8.65));

    cities[1]->addFoodItem(new food("Pretzels", 4.00));
    cities[1]->addFoodItem(new food("Apfelstrudel", 6.25));
    cities[1]->addFoodItem(new food("Berliner Pfannkuche", 8.23));
    cities[1]->addFoodItem(new food("Schnitzel", 9.79));

    cities[2]->addFoodItem(new food("Waterzooi", 6.45));
    cities[2]->addFoodItem(new food("Luikse Siroop", 4.98));
    cities[2]->addFoodItem(new food("Mosselen-friet", 4.45));
    cities[2]->addFoodItem(new food("Speculoos", 2.79));

    cities[3]->addFoodItem(new food("Goulash", 8.43));
    cities[3]->addFoodItem(new food("Stuffed Cabbage", 6.99));
    cities[3]->addFoodItem(new food("Smoked Meat", 12.99));
    cities[3]->addFoodItem(new food("Dobos Torta", 2.79));

    cities[4]->addFoodItem(new food("Hamburger Hummersuppe", 6.46));
    cities[4]->addFoodItem(new food("Knackwurst", 9.99));
    cities[4]->addFoodItem(new food("Krabbentoast", 6.92));
    cities[4]->addFoodItem(new food("Franzbrötchen", 12.74));

    cities[5]->addFoodItem(new food("Bacalhau", 5.49));
    cities[5]->addFoodItem(new food("Caldeirada", 7.63));
    cities[5]->addFoodItem(new food("Alcatra", 18.66));

    cities[6]->addFoodItem(new food("Yorkshire Pudding", 3.49));
    cities[6]->addFoodItem(new food("Bangers & Mash", 6.63));
    cities[6]->addFoodItem(new food("Sticky Toffee Pudding", 5.66));

    cities[7]->addFoodItem(new food("Bocata de Calamares", 6.96));
    cities[7]->addFoodItem(new food("Oreja a la Plancha", 11.85));
    cities[7]->addFoodItem(new food("Caracoles a la Madrileña", 6.94));

    cities[8]->addFoodItem(new food("Caramels", 4.76));
    cities[8]->addFoodItem(new food("Bordier Butter", 5.65));
    cities[8]->addFoodItem(new food("Baguette", 4.99));
    cities[8]->addFoodItem(new food("Pain au Chocolat", 4.69));

    cities[9]->addFoodItem(new food("Beef Steak Tartare", 18.76));
    cities[9]->addFoodItem(new food("Kulajda", 6.89));
    cities[9]->addFoodItem(new food("Svickova", 5.98));
    cities[9]->addFoodItem(new food("Roast Duck", 14.69));

    cities[10]->addFoodItem(new food("Spaghetti alla Carbonara", 6.73));
    cities[10]->addFoodItem(new food("Bruschetta", 4.85));
    cities[10]->addFoodItem(new food("Scaloppine", 12.99));
    cities[10]->addFoodItem(new food("Rigatoni con la Pajata", 8.79));
    cities[10]->addFoodItem(new food("Carciofi alla Giudia", 15.99));

    cities[11]->addFoodItem(new food("Raggmunk", 6.75));
    cities[11]->addFoodItem(new food("Gravad Lax", 13.76));
    cities[11]->addFoodItem(new food("Husmanskost", 7.98));

    cities[12]->addFoodItem(new food("Wiener Schnitzel", 4.94));
    cities[12]->addFoodItem(new food("Kaiserschmarrn", 7.53));
    cities[12]->addFoodItem(new food("Sachertorte", 5.85));

    ui->setupUi(this);

    for(int j = 0; j < static_cast<int>(cities.size()); j++)
        ui->listWidget->addItem(cities[j]->getName());

    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->horizontalHeader()->setStretchLastSection( true );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
}

MainWindow::~MainWindow()
{    
    delete ui;
}


void MainWindow::on_listWidget_itemSelectionChanged()
{
    int index = -1;
    for(int i = 0; i < static_cast<int>(cities.size()); i++){
        if(cities[i]->getName() == ui->listWidget->currentItem()->text())
            index = i;
    }

    if(index == -1)
        throw "CITY_NOT_FOUND";

    ui->tableWidget->clearContents();

    int numFoodz = cities[index]->getNumFood();

    ui->tableWidget->setRowCount(numFoodz);

    for(int i = 0; i < numFoodz; i++){
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(cities[index]->getFood(i)->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("€" + QString::number(cities[index]->getFood(i)->getPrice())));
        ui->tableWidget->resizeColumnToContents(0);
    }
}
