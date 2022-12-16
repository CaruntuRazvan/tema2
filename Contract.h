#ifndef CARUNTU_CONTRACT_H
#define CARUNTU_CONTRACT_H

#include <memory>
#include <vector>
#include "IoBase.h"
#include "Proprietate.h"
#include "Casa.h"
#include "Apartament.h"

class Contract : public IoBase{
protected:
    string numeClient;
    int lunaInceput;
    int lunaSfarsit;
    int anInceput;
    int anSfarsit;
    double chirieTotala;
    vector<shared_ptr<Proprietate> > proprietati;

public:
    istream &read(istream &is) override;

    ostream &write(ostream &os) override;

    // Contract();

    const vector<shared_ptr<Proprietate>> &getProprietati() const;
    virtual double calculeazaChirie();
    void setProprietati(const vector<shared_ptr<Proprietate>> &proprietati);

};
#endif //CARUNTU_CONTRACT_H
