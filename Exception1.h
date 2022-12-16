#ifndef CARUNTU_EXCEPTION1_H
#define CARUNTU_EXCEPTION1_H

#include "IOStream.h"

class Exception1 : public std::exception, public IOStream{
public:
    Exception1()=default;

    const char* what() const noexcept override;

    void Print(std::ostream&) const;

};

#endif //CARUNTU_EXCEPTION1_H
