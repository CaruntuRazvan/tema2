#ifndef CARUNTU_IOSTREAM_H
#define CARUNTU_IOSTREAM_H
#include <iostream>
class IOStream {
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const IOStream&);
    friend std::ostream& operator<<(std::ostream &, const IOStream*);

    virtual ~IOStream();
};

#endif //CARUNTU_IOSTREAM_H
