#ifndef CARUNTU_EXCEPTION2_H
#define CARUNTU_EXCEPTION2_H

#include "IOStream.h"

class Exception2 : public std::exception, public IOStream{
public:
    Exception2()=default;

    const char* what() const noexcept override;

    void Print(std::ostream&) const;

};

#endif //CARUNTU_EXCEPTION2_H
