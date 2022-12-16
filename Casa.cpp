#include "Casa.h"

Casa::Casa() : Proprietate() {
    niveluri=0;
    curte=0;
}
istream &Casa::read(istream &is) {
    Proprietate::read(is);

    cout << "Numar niveluri:\n";
    is >> niveluri;
    cout << "Suprafata curte:\n";
    is >> curte;

    return is;
}

ostream &Casa::write(ostream &os) {
    Proprietate::write(os);

    os << "Niveluri:\n";
    os << niveluri << '\n';
    os << "Suprafata curtii:\n";
    os << curte << '\n';

    return os;
}

double Casa::getCurte() const {
    return curte;
}

