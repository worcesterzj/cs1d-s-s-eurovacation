#ifndef ADDDISTANCES_H
#define ADDDISTANCES_H

#include <QWidget>

namespace Ui {
class addDistances;
}

class addDistances : public QWidget
{
    Q_OBJECT

public:
    explicit addDistances(QWidget *parent = nullptr);
    ~addDistances();

private:
    Ui::addDistances *ui;
};

#endif // ADDDISTANCES_H
