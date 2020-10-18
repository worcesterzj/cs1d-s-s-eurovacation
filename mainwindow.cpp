#include "mainwindow.h"
#include "ui_mainwindow.h"

bool compareCits(const city* lhs, const city* rhs) { return lhs->getName() <= rhs->getName(); } // Compare the names of two cities to order them lexically.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //Riley 10/10/2020
    std::vector<std::vector<int>> adjacencyMatrix;

    parser p;
    if (!p.read(cities)){
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "Bruh.", "The cit.sas file failed to read.", QMessageBox::StandardButtons(QMessageBox::StandardButton::Ignore | QMessageBox::StandardButton::Abort));
        if (reply == QMessageBox::StandardButton::Abort)
            exit(-1);
    }
      
    if (!p.readDistances(adjacencyMatrix)){
        QMessageBox::warning(this, "Critical read Error.", "The cit.sas file was read, but the dist.sas file failed to read.\nCheck data/cities in the program directory.",
                             QMessageBox::Ok);
        exit(-1);
    }

    distances = adjacencyMatrix;

    std::sort(cities.begin(), cities.end(), compareCits); // sorts the cities alphabetically.


    // Setup UI
    ui->setupUi(this);

    // Setup other widgets and add them to the stackedWidget.
    sel = new selectForm(this);
    pl = new planTripForm(cities, distances, this);
    pt = new presettripform(cities, distances, this);
    adm = new addCities(cities, distances);
    lgn = new Login();

    usr.name = "[Guest]";
    usr.isAdmin = false;

    setWindowTitle("S&S Vacation Planner - Logged in as: " + usr.name);

    // Signals
    connect(sel, SIGNAL(planButton_clicked()), this, SLOT(on_recievePlanSignal()));
    connect(sel, SIGNAL(tripButton_clicked()), this, SLOT(on_recieveTripSignal()));
    connect(pl, SIGNAL(backButton_clicked()), this, SLOT(on_recieveBackSignal()));
    connect(pt, SIGNAL(backButton_clicked()), this, SLOT(on_recieveBackSignal()));
    connect(adm, SIGNAL(refresh_UI()), this, SLOT(refreshUI()));
    connect(lgn, SIGNAL(loginSuccess(QString)), this, SLOT(on_recieveLogin(QString)));

    ui->stackedWidget->addWidget(sel);
    ui->stackedWidget->addWidget(pl);
    ui->stackedWidget->addWidget(pt);
    ui->stackedWidget->setCurrentWidget(sel);

    refreshUI();

    ui->foodTableWidget->setRowCount(0);
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
    delete lgn;
    delete adm;

    for(int i = 0; i < int(cities.size()); i++){
        city* a = cities.back();
        cities.pop_back();
        delete a;
    }

}

void MainWindow::refreshUI(){
    ui->cityListWidget->clear();
    city *temp = nullptr;
    pl->refreshList();


    for(int j = 0; j < static_cast<int>(cities.size()); j++)
    {
        if(cities[j]->getName().toLower() == "berlin")
        {
            temp = cities[j];
        }
    }

    if(temp != nullptr){
        for(int j = 0; j < static_cast<int>(cities.size()); j++)
        {
            if(cities[j]->getName().toLower() == "berlin")
            {
                ui->cityListWidget->addItem(cities[j]->getName());
                continue;
            }
            city* tempCity = cities[j];
            ui->cityListWidget->addItem(cities[j]->getName() + " (Distance to Berlin: " + QString::number(distances.getDistance(getCity_index(cities, temp), getCity_index(cities, tempCity))) + "km)");
        }
    }
    else{
        for(int j = 0; j < static_cast<int>(cities.size()); j++)
        {
            ui->cityListWidget->addItem(cities[j]->getName());
        }
    }
}

void MainWindow::on_cityListWidget_itemSelectionChanged()
{
    ui->foodTableWidget->clearContents();

    int numFoodz = cities[ui->cityListWidget->currentRow()]->getNumFood();

    ui->foodTableWidget->setRowCount(numFoodz);

    for(int i = 0; i < numFoodz; i++){
        ui->foodTableWidget->setItem(i, 0, new QTableWidgetItem(cities[ui->cityListWidget->currentRow()]->getFood(i).getName()));
        ui->foodTableWidget->setItem(i, 1, new QTableWidgetItem("$ " + QString::number(cities[ui->cityListWidget->currentRow()]->getFood(i).getPrice(), 'f', 2)));
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
    pt->refreshTripComboBox();
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
    if(lgn->loggedIn())
    {
        adm->show();

    }
    else
    {
        lgn->show();
        lgn->raise();
    }

}

void MainWindow::on_recieveLogin(QString name)
{
    usr.name = name;
    usr.isAdmin = true;

    setWindowTitle("S&S Vacation Planner - Logged in as: " + name);

    if(name == "monkey") {
        usr.isMonkey = true;
        QMessageBox monkeybox("Ooo OooO aaaA",
            "A monkey has been detected on the system.",
            QMessageBox::NoIcon,
            QMessageBox::Ok | QMessageBox::Default,
            QMessageBox::No,
            QMessageBox::Cancel);

        monkeybox.setStandardButtons(QMessageBox::Ok | QMessageBox::Default);

        QPixmap monkey(":images/images/monkey_warn.png");
        QIcon banana(":images/images/banana.png");
        monkeybox.setIconPixmap(monkey);
        monkeybox.setWindowIcon(banana);
        monkeybox.exec();

    }
    else
        usr.isMonkey = false;

    adm->show();
}
