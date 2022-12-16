#include "Contract.h"

istream &Contract::read(istream &is) {
    IoBase::read(is);

    cout << "Numele clientului:\n";
    is.get();
    getline(is,numeClient);
    cout << "Data la care a fost semnat contractul:\n";
    cout << "luna:\n";
    is >> lunaInceput;
    cout << "anul:\n";
    is >> anInceput;
    cout << "Data la care se sfarseste contractul:\n";
    cout << "luna:\n";
    is >> lunaSfarsit;
    cout << "anul:\n";
    is >> anSfarsit;


    return is;
}

ostream &Contract::write(ostream &os) {
    IoBase::write(os);

    os << "Numele clientului:\n";
    os << numeClient << '\n';
    os << "Data la care a fost semnat contractul:";
    os << lunaInceput << "." << anInceput << '\n';
    os << "Data la care se sfarseste contractul:";
    os << lunaSfarsit << "." << anSfarsit << '\n';
    os << "Proprietate:\n";
    for(const auto &i: proprietati){
        auto *casa=dynamic_cast<Casa*>(i.get());
        auto *apartament=dynamic_cast<Apartament*>(i.get());
        if(casa)
            os << *casa;
        else if(apartament)
            os << *apartament;
    }
    chirieTotala=calculeazaChirie();
    os << "Chirie totala:\n";
    os << chirieTotala << '\n';
    os << "\n";

    return os;
}

//Contract::Contract() : proprietati() {}

double Contract::calculeazaChirie() {
    double chirie;
    for(const auto &i: proprietati){
        auto *casa=dynamic_cast<Casa*>(i.get());
        auto *apartament=dynamic_cast<Apartament*>(i.get());
        if(casa){
            chirie += casa->getChirie() * (casa->getSuprafata() + 0.2 * casa->getCurte());
        }else if(apartament){
            chirie += casa->getChirie() * casa->getSuprafata() ;
        }
    }
}

const vector<shared_ptr<Proprietate>> &Contract::getProprietati() const {
    return proprietati;
}

void Contract::setProprietati(const vector<shared_ptr<Proprietate>> &proprietati) {
    Contract::proprietati = proprietati;
}