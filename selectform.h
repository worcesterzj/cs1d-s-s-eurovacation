/** \file selectform.h
 * \brief Contains a class that handles form selection in the UI.
 */

#ifndef SELECTFORM_H
#define SELECTFORM_H

#include <QWidget>
#include "executetrip.h"

namespace Ui {
class selectForm;
}

/**
 * \brief Handles form selection in the UI using signals and slots.
 */
/*! The "selectForm" class has one private members:\n
 * ui             :   selectForm*...........Ui for selectForm.\n\n
 * The selectForm class contains functions that handle how the UI changes when form buttons are clicked.
 */
class selectForm : public QWidget
{
    Q_OBJECT

public:

    /**
     * \brief A default constructor for selectForm.
     * This default constructor will only set up the ui
     */
    explicit selectForm(QWidget *parent = nullptr);     // Default constructor only sets up ui in this case.

    /**
     * \brief A destructor for selectForm.
     * Deallocs the contents of ui to prevent memory leaks.
     */
    ~selectForm();

private slots:

    /**
     * \brief Slot for the planButton clicked.
     * When the planButton is clicked the planButton_clicked signal is emitted
     */
    void on_planButton_clicked();           // Slot that recieves a signal when Custom Trip menu button is pressed. Emits planButton_clicked();

    /**
     * \breif Slot for the tripButton clicked.
     * When the tripButton is clicked the tripButton_clicked signal is emitted
     */
    void on_tripButton_clicked();           // Slot that recieves a signal when Preset Trip menu button is pressed. Emits tripButton_clicked();

signals:
    /**
     * \brief Signal for the planButton clicked.
     * Emitted when planButton is clicked.
     */
    void planButton_clicked();

    /**
     * \brief Signal for tripButton clicked.
     * Emitted when tripButton is clicked.
     */
    void tripButton_clicked();              // Singal that emits when Preset Trip menu button is pressed.

private:

    /** Ui::selectForm
     * \brief ui
     * UI for selectform
     */
    Ui::selectForm *ui;                         // ui       :   selectForm*...........Ui for selectForm.
};

#endif // SELECTFORM_H
