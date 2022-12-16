#include "Proprietate.h"

Proprietate::Proprietate() {
    adresa="";
    suprafata=0;
    chirie=0;
}
istream &Proprietate::read(istream &is) {
    IoBase::read(is);

    cout << "Adresa completa a locuitei:\n";
    is.get();
    getline(is,adresa);
    cout << "Suprafata locuibila(mp):\n";
    is >> suprafata;
    cout << "Chirie per mp:\n";
    is >> chirie;

    return is;
}

ostream &Proprietate::write(ostream &os) {
    IoBase::write(os);

    os << "Adresa locuintei:\n";
    os << adresa << '\n';
    os << "Suprafata locuibila:\n";
    os << suprafata << '\n';
    os << "Chiria per mp:\n";
    os << chirie << '\n';

    return os;
}

Proprietate::Proprietate(const string &adresa, double suprafata, double chirie) : adresa(adresa), suprafata(suprafata),
                                                                                  chirie(chirie) {}

Proprietate &Proprietate::operator=(const Proprietate &rhs) {
    if (this != &rhs) {
        adresa = rhs.adresa;
        suprafata = rhs.suprafata;
        chirie = rhs.chirie;
    }
    return *this;
}

double Proprietate::getSuprafata() const {
    return suprafata;
}

double Proprietate::getChirie() const {
    return chirie;
}
