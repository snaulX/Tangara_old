#include "Class.hpp"

namespace Tangara {
    Class::Class(const char *_name) : name(_name), hashcode(XXHash32::hash(this, sizeof(Class), TG_HASH_SEED))
    { }

    TgObj *Class::New(const TgParams &params) {
        for (Constructor* ctor : ctors) {
            try {
                // Run constructor with type-checking
                return ctor->RunSafe(params);
            } catch (const std::exception &e) {
                // This constructor doesn't match ours parameters
                continue;
            }
        }
        throw std::exception("Constructor with these parameters not sound in this class");
    }

    Class::~Class() = default;
}