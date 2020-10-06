#ifndef EXECUTETRIP_H
#define EXECUTETRIP_H

#include <QWidget>
#include <vector>
#include "city.h"

namespace Ui {
class executeTrip;
}

class executeTrip : public QWidget
{
    Q_OBJECT

public:
    explicit executeTrip(std::vector<city*>& cities, QWidget *parent = nullptr);
    ~executeTrip();

    void setCities(std::vector<city*>& cities);

private:
    Ui::executeTrip *ui;
    std::vector<city*>& cities;
};

#endif // EXECUTETRIP_H
