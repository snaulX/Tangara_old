#include "Class.hpp"
#include "xxhash/xxhash32.h"

namespace Tangara {
    Class::Class(const char *_name) : name(_name), hashcode(XXHash32::hash(this, sizeof(Class), TG_CLASS_SEED))
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

    Method *Class::GetMethod(const char *name) {
        for (Method* m : methods) {
            if (strcmp(m->GetName(), name) == 0) return m;
        }
        return nullptr;
    }

    Constructor *Class::GetConstructor(const TgParamTypes &paramTypes) {
        return nullptr;
    }

    TgObj *Class::Run(TgObj *self, const char *methodName, const TgParams &params) {
        for (Method* m : methods) {
            if (strcmp(m->GetName(), methodName) == 0) {
                try {
                    // Run method with type-checking
                    return m->RunSafe(self, params);
                } catch (const std::exception& e) {
                    // This method doesn't match ours parameters
                    continue;
                }
            }
        }
        throw std::exception("No method with this name and parameters");
    }

    Class::~Class() = default;
}