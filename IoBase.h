#ifndef CARUNTU_IOBASE_H
#define CARUNTU_IOBASE_H

#include <iostream>
using namespace std;

class IoBase {
private:
public:

    virtual istream &read(istream &is) {
        return is;
    }
    virtual ostream &write(ostream &os) {
        return os;
    }

    friend ostream &operator<<(ostream &os, IoBase &base) {
        return base.write(os);
    }

    friend istream &operator>>(istream &is, IoBase &base) {
        return base.read(is);
    }
};

#endif //CARUNTU_IOBASE_H


