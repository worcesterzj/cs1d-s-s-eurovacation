#ifndef SELECTFORM_H
#define SELECTFORM_H

#include <QWidget>
#include "executetrip.h"

namespace Ui {
class selectForm;
}

class selectForm : public QWidget
{
    Q_OBJECT

public:
    explicit selectForm(QWidget *parent = nullptr);     // Default constructor only sets up ui in this case.
    ~selectForm();

private slots:
    void on_planButton_clicked();           // Slot that recieves a signal when Custom Trip menu button is pressed. Emits planButton_clicked();

    void on_tripButton_clicked();           // Slot that recieves a signal when Preset Trip menu button is pressed. Emits tripButton_clicked();

signals:
    void planButton_clicked();              // Signal that emits when Custom Trip menu button is pressed.
    void tripButton_clicked();              // Singal that emits when Preset Trip menu button is pressed.

private:
    Ui::selectForm *ui;                         // ui       :   selectForm*...........Ui for selectForm.
};

#endif // SELECTFORM_H
