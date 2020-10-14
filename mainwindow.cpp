#include "mainwindow.h"
#include "ui_mainwindow.h"

bool compareCits(const city* lhs, const city* rhs) { return lhs->getName() <= rhs->getName(); } // Compare the names of two cities to order them lexically.

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // START OF DEBUG STUFF!

    std::vector<std::vector<int>> temp_distances = {
            { -1, 655, 236, 1395,361,2236,541,1767,430,878,1647, 1435, 1147},
            { 655, -1, 765,873,288,2779,678,2392,1054,349, 1502, 1084, 640},
            { 236, 765, -1, 1353,489,2357,403,1578,313,898,1483, 1564, 1104},
            {1395,873,1353,-1,1163,3069,1707,2512,1485,525,1274, 1951, 243},
            {361,288,489,1163,-1,2121,930,2171,376,640,1658, 1079, 930},
            {2236,2279,2357,3069,2121,-1,2189,625,1736,2707,2510, 3610, 2867},
            {541, 678, 403, 1707, 930, 2189, -1, 1719, 464, 1265, 1866, 1902, 1461},
            {1767, 2392, 1578, 2512, 2171, 625, 1719, -1, 1633, 2312, 1951, 3141, 2401},
            {430, 1054, 313, 1485, 376, 1736, 464, 1633, -1, 1030, 1442, 1185, 1236},
            {878, 349, 898, 525, 640, 2707, 1265, 2312, 1030, -1, 1303, 1428, 331},
            {1647, 1502, 1483, 1274, 1658, 2510, 1866, 1951, 1442, 1303, -1, 2546, 1120},
            {1435, 1084, 1564, 1951, 1079, 3610, 1902, 3141, 1885, 1428, 2546, -1, 1758},
            {1147, 640, 1104, 243, 930, 2867, 1461, 2401, 1236, 331, 1120, 1758, -1}
            };

    distances = temp_distances;

    // END OF DEBUG STUFF!

    parser p;
    if (!p.read(cities)){
        QMessageBox::StandardButton reply = QMessageBox::warning(this, "Bruh.", "The cit.sas file failed to read.", QMessageBox::StandardButtons(QMessageBox::StandardButton::Ignore | QMessageBox::StandardButton::Abort));
        if (reply == QMessageBox::StandardButton::Abort)
            exit(-1);
    }

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
        if(cities[j]->getName() == "Berlin")
        {
            temp = cities[j];
        }
    }

    for(int j = 0; j < static_cast<int>(cities.size()); j++)
    {
        if(cities[j]->getName() == "Berlin")
        {
            ui->cityListWidget->addItem(cities[j]->getName());
            continue;
        }
        city* tempCity = cities[j];
        ui->cityListWidget->addItem(cities[j]->getName() + " (Distance to Berlin: " + QString::number(distances.getDistance(getCity_index(cities, temp), getCity_index(cities, tempCity))) + "km)");
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
