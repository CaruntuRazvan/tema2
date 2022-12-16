#ifndef CARUNTU_PROPRIETATE_H
#define CARUNTU_PROPRIETATE_H

#include "IoBase.h"

using namespace std;

class Proprietate : public IoBase{
protected:
    string adresa;
    double suprafata;
    double chirie;

public:
    istream &read(istream &is) override;

    ostream &write(ostream &os) override;

    Proprietate();

    Proprietate(const string &adresa, double suprafata, double chirie);

    Proprietate& operator=(const Proprietate& rhs);

    double getSuprafata() const;

    double getChirie() const;

};
#endif //CARUNTU_PROPRIETATE_H
