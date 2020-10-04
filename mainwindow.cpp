#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // START OF DEBUG STUFF!

// Cities
/*    cities.push_back(new city("Amsterdam", "The Netherlands"));
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

// Food Items
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

    // END OF DEBUG STUFF!

    serializer s;
    s.write(cities); */

    parser p;
    if (!p.read(cities)){
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "Bruh.", "The cit.sas file failed to read.", QMessageBox::StandardButtons(QMessageBox::StandardButton::Ignore | QMessageBox::StandardButton::Abort));
        if (reply == QMessageBox::StandardButton::Abort)
            exit(-1);
    }
    // Setup UI
    ui->setupUi(this);

    // Setup other widgets and add them to the stackedWidget.
    sel = new selectForm(this);
    pl = new planTripForm(cities, this);
    pt = new presettripform(cities, this);
    lgn = new Login(this);
    usr = new user();

    lgn->hide();
    usr->isAdmin = false;

    // Signals
    connect(sel, SIGNAL(planButton_clicked()), this, SLOT(on_recievePlanSignal()));
    connect(sel, SIGNAL(tripButton_clicked()), this, SLOT(on_recieveTripSignal()));
    connect(pl, SIGNAL(backButton_clicked()), this, SLOT(on_recieveBackSignal()));
    connect(pt, SIGNAL(backButton_clicked()), this, SLOT(on_recieveBackSignal()));

    ui->stackedWidget->addWidget(sel);
    ui->stackedWidget->addWidget(pl);
    ui->stackedWidget->addWidget(pt);
    ui->stackedWidget->setCurrentWidget(sel);

    for(int j = 0; j < static_cast<int>(cities.size()); j++)
        ui->cityListWidget->addItem(cities[j]->getName());

    ui->foodTableWidget->setRowCount(1);
    ui->foodTableWidget->setColumnCount(2);
    ui->foodTableWidget->horizontalHeader()->setStretchLastSection( true );

    ui->foodTableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Food Item"));
    ui->foodTableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));
}

MainWindow::~MainWindow()
{    
    delete sel;
    delete pl;
    delete ui;

    for(int i = 0; i < int(cities.size()); i++){
        city* a = cities.back();
        cities.pop_back();
        delete a;
    }
}

void MainWindow::on_cityListWidget_itemSelectionChanged()
{
    int index = -1;
    for(int i = 0; i < static_cast<int>(cities.size()); i++){
        if(cities[i]->getName() == ui->cityListWidget->currentItem()->text())
            index = i;
    }

    if(index == -1)
        throw "CITY_NOT_FOUND";

    ui->foodTableWidget->clearContents();

    int numFoodz = cities[index]->getNumFood();

    ui->foodTableWidget->setRowCount(numFoodz);

    for(int i = 0; i < numFoodz; i++){
        ui->foodTableWidget->setItem(i, 0, new QTableWidgetItem(cities[index]->getFood(i)->getName()));
        ui->foodTableWidget->setItem(i, 1, new QTableWidgetItem("$ " + QString::number(cities[index]->getFood(i)->getPrice(), 'f', 2)));
        ui->foodTableWidget->resizeColumnToContents(0);
    }
}

void MainWindow::on_recievePlanSignal() {
    pl->refreshList();
    ui->stackedWidget->setCurrentWidget(pl);
}

void MainWindow::on_recieveBackSignal() {
    ui->stackedWidget->setCurrentWidget(sel);
}

void MainWindow::on_recieveTripSignal() {
    // pt->refreshList();
    ui->stackedWidget->setCurrentWidget(pt);
}

void MainWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Are you sure?", "Are you sure you want to quit?");

    if (reply == QMessageBox::Yes)
        QApplication::quit();
}

void MainWindow::on_toolButton_clicked()
{
    if(lgn->getPassword() == "cs1d")
    {
        usr->isAdmin = true;
    }
    else if(usr->isAdmin == false)
    {
        lgn->show();
        lgn->raise();
    }
    //else show settings

}
