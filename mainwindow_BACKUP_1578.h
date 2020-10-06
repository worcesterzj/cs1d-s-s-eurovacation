#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "serializer.h"
#include "city.h"
#include "selectform.h"
#include "plantripform.h"
#include "presettripform.h"
<<<<<<< HEAD
#include "parser.h"
=======
#include "login.h"

struct user
{
    QString name;
    bool isAdmin;
};
>>>>>>> 9957f95e0732d74044b108ba4ecb86f959a91859

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);              // Default constructor reads in all of the cities and instantiates all of UI.
    ~MainWindow();

private slots:
    void on_cityListWidget_itemSelectionChanged();      // Slot that recieves the signal when an item in the list of cities (see cityListWidget, mainwindow.ui) is changed.

    void on_recievePlanSignal();                        // Slot that recieves the signal to switch to Custom Trip form.
    void on_recieveTripSignal();                        // Slot that recieves the signal to switch to Preset Trip form.
    void on_recieveBackSignal();                    // Slot that recieves the signal to switch back to Form Select from Custom Trip or Preset Trip form.

    void on_exitButton_clicked();                       // Exit the program.

    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;                     // ui               :   MainWindow*...................Main Ui Form.
    selectForm *sel;                        // sel              :   selectForm*...................Form to select between custom trip and preset trip forms.
    planTripForm *pl;                       // pl               :   planTripForm*.................Custom trip form.
    presettripform *pt;                     // pt               :   presettripform*...............Preset trip form.
    Login *lgn;                             // lgn              :   Login*........................Login window
    user *usr;                              // usr              :   User*.........................User status

    std::vector<city*> cities;              // cities           :   vector<city*>.................Vector of cities, read in at the begining of the program.
};
#endif // MAINWINDOW_H