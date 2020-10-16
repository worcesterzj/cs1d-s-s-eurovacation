#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMouseEvent>

#include "serializer.h"
#include "city.h"
#include "selectform.h"
#include "plantripform.h"
#include "presettripform.h"
#include "parser.h"
#include "addcities.h"
#include "distancetable_class.h"
#include "user.h"

#include "login.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
* \brief MainWindow.
* mainwindow has 9 private members all to help run the various windows and behind the scenes action
* ui               :   MainWindow*...................Main Ui Form.
* sel              :   selectForm*...................Form to select between custom trip and preset trip forms.
* pl               :   planTripForm*.................Custom trip form.
* pt               :   presettripform*...............Preset trip form.
* adm              :   addCities*....................Admin area.
* lgn              :   Login*........................Login window
* usr              :   User*.........................User status
* cities           :   vector<city*>.................Vector of cities, read in at the begining of the program.
* distances        :   vector<vector<int>>...........Vector of vector of int. Stores the distances between cities.
*
* The mainwindow helps contain all of the other windows and governs the entire programm. This provides the intial ui and 
* well as the other ui when they are called.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * \brief An overloaded constructor for mainwindow.
     * Initializes and reads in the various cities (from a file) and instantiates the UI windows
     */
    MainWindow(QWidget *parent = nullptr);              // Default constructor reads in all of the cities and instantiates all of UI.
     /**
     * \brief A destructor for mainwindow.
     * Deallocs the contents of the varioius window/vectors to prevent memory leaks.
     */
    ~MainWindow();

private slots:
    void on_cityListWidget_itemSelectionChanged();      // Slot that recieves the signal when an item in the list of cities (see cityListWidget, mainwindow.ui) is changed.

    void on_recievePlanSignal();                        // Slot that recieves the signal to switch to Custom Trip form.
    void on_recieveTripSignal();                        // Slot that recieves the signal to switch to Preset Trip form.
    void on_recieveBackSignal();                        // Slot that recieves the signal to switch back to Form Select from Custom Trip or Preset Trip form.
    void refreshUI();                                   // Slot that recieves the signal to refresh ui lists.

    void on_exitButton_clicked();                       // Exit the program.

    void on_toolButton_clicked();

    void on_recieveLogin(QString name);                             // Slot that recieves the signal that indicates a successful login.

private:
    /** MainWindow
     * \brief ui
     * A pointer to the mainwindow ui.
     */
    Ui::MainWindow *ui;                     // ui               :   MainWindow*...................Main Ui Form.
     /** selectForm
     * \brief sel
     * A pointer to the selectForms ui.
     */
    selectForm *sel;                        // sel              :   selectForm*...................Form to select between custom trip and preset trip forms.
     /**  planTripForm
     * \brief pl
     * A pointer to the planTripForm ui.
     */
    planTripForm *pl;                       // pl               :   planTripForm*.................Custom trip form.
    /** presettripform
     * \brief pt
     * A pointer to the presettripform ui.
     */
     presettripform *pt;                     // pt               :   presettripform*...............Preset trip form.
    /** addCities
     * \brief adm
     * A pointer to the addCities ui.
     */
    addCities *adm;                         // adm              :   addCities*....................Admin area.
    /** Login
     * \brief lgn
     * A pointer to the Login ui.
     */
    Login *lgn;                             // lgn              :   Login*........................Login window
    /** user
     * \brief usr
     * determins users status as an admin or not and what capabilites they have.
     */
    user usr;                               // usr              :   User*.........................User status

     /** vector<city*>
     * \brief cities
     * reads in from file, with the help of a parser, to initialize all of the cities to be offered in the trips.
     */
    std::vector<city*> cities;              // cities           :   vector<city*>.................Vector of cities, read in at the begining of the program.
     /** distanceTable_class
     * \brief distances
     * reads in from file, with the help of a parser, to initialize all of the distances that the cities and trips will use to determine distances
     */    
    distanceTable_class distances;          // distances        :   vector<vector<int>>...........Vector of vector of int. Stores the distances between cities.
};
#endif // MAINWINDOW_H
