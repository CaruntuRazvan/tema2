#include "Apartament.h"

Apartament::Apartament() : Proprietate() {
    etaj=0;
    nrcamere=0;
}
istream &Apartament::read(istream &is) {
    Proprietate::read(is);

    cout << "Etajul la care se afla:\n";
    is >> etaj;
    cout << "Numarul de camere:\n";
    is >> nrcamere;

    return is;
}

ostream &Apartament::write(ostream &os) {
    Proprietate::write(os);

    os << "Etaj:\n";
    os << etaj << '\n';
    os << "Camere:\n";
    os << nrcamere << '\n';

    return os;
}


