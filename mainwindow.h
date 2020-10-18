  
/** \file mainwindow.h
 * \brief Contains the implementation of mainwindow.
 */
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
* \brief Main Window form. Provides a hub for accessing all other functionality.
*/
/*! MainWindow has 9 private members all to help run the various windows and behind the scenes action\n
* ui               :   MainWindow*...................Main Ui Form.\n
* sel              :   selectForm*...................Form to select between custom trip and preset trip forms.\n
* pl               :   planTripForm*.................Custom trip form.\n
* pt               :   presettripform*...............Preset trip form.\n
* adm              :   addCities*....................Admin area.\n
* lgn              :   Login*........................Login window.\n
* usr              :   User*.........................User status.\n
* cities           :   vector<city*>.................Vector of cities, read in at the begining of the program.\n
* distances        :   vector<vector<int>>...........Vector of vector of int. Stores the distances between cities.\n\n
* The mainwindow helps contain all of the other windows and governs the entire programm. This provides the intial ui and \n
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
    /**
     * \brief on_cityListWidget_itemSelectionChanged
     * takes signal when a different item in the cities list is changed then refreshes
     */
    void on_cityListWidget_itemSelectionChanged();      // Slot that recieves the signal when an item in the list of cities (see cityListWidget, mainwindow.ui) is changed.
    
    /**
     * \brief on_recievePlanSignal
     * switchs to the custom trip form to show its UI
     */
    void on_recievePlanSignal();                        // Slot that recieves the signal to switch to Custom Trip form.
    
    /**
     * \brief on_recieveTripSignal
     * switches to the preset trip form to show its ui
     */
    void on_recieveTripSignal();                        // Slot that recieves the signal to switch to Preset Trip form.
    
     /**
     * \brief on_recieveBackSignal
     * receives signal in order to switch back to the main window (from custom/trip UI)
     */
    void on_recieveBackSignal();                        // Slot that recieves the signal to switch back to Form Select from Custom Trip or Preset Trip form.
    
     /**
     * \brief refreshUI
     * Refresh the UI in MainWindow
     */
    void refreshUI();                                   // Slot that recieves the signal to refresh ui lists.

    /**
     * \brief on_exitButton_clicked
     * Simply terminates the program.
     */
    void on_exitButton_clicked();                       // Exit the program.
    
    /**
     * \brief on_toolButton_clicked
     * If user is logged in, goes to admin area. Otherwise first goes to login screen.
     */
    void on_toolButton_clicked();
    
    /**
     * \brief on_recieveLogin
     * Used to display the login UI and determine a succesful login (of an administrator)
     * @param name The name of the login info to see succesful login
     */
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
