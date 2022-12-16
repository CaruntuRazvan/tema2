#ifndef CARUNTU_APARTAMENT_H
#define CARUNTU_APARTAMENT_H

#include "Proprietate.h"

class Apartament : public Proprietate{
private:
    int etaj;
    int nrcamere;

public:
    istream &read(istream &is) override;

    ostream &write(ostream &os) override;

    Apartament();

};
#endif //CARUNTU_APARTAMENT_H
