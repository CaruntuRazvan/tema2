#include "Exception1.h"
const char *Exception1::what() const noexcept {
    return "Ati ales un numar prea mare.\nIncercati din nou.\n";
}
void Exception1::Print(std::ostream &os) const {
    os << this->what();
}
