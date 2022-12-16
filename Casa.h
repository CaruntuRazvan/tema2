#ifndef CARUNTU_CASA_H
#define CARUNTU_CASA_H

#include "Proprietate.h"

class Casa : public Proprietate{
private:
    int niveluri;
    double curte;

public:
    istream &read(istream &is) override;

    ostream &write(ostream &os) override;

    Casa();

    double getCurte() const;
};
#endif //CARUNTU_CASA_H
