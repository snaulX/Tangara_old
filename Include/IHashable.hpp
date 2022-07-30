#ifndef TANGARA_IHASHABLE_HPP
#define TANGARA_IHASHABLE_HPP
#include "TangaraBase.h"

class IHashable {
public:
    operator uint32_t() const { return hashCode; }

    [[nodiscard]] uint32_t GetHashCode() const { return hashCode; }
protected:
    IHashable(uint32_t hash) : hashCode(hash) { }
private:
    const uint32_t hashCode;
};
inline bool operator >(const IHashable& ls, const IHashable& rs) {
    return ls.GetHashCode() > rs.GetHashCode();
}
inline bool operator <(const IHashable& ls, const IHashable& rs) {
    return ls.GetHashCode() < rs.GetHashCode();
}
inline bool operator ==(const IHashable& ls, const IHashable& rs) {
    return ls.GetHashCode() == rs.GetHashCode();
}
inline bool operator ==(const IHashable& ls, const uint32_t& rs) {
    return ls.GetHashCode() == rs;
}

#endif //TANGARA_IHASHABLE_HPP
