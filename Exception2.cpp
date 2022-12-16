#include "Exception2.h"
const char *Exception2::what() const noexcept {
    return "Ati ales un numar prea mic.\nIncercati din nou.\n";
}
void Exception2::Print(std::ostream &os) const {
    os << this->what()<<"\n";
}