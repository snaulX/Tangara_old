#ifndef TANGARA_ENTRYRULE_HPP
#define TANGARA_ENTRYRULE_HPP

#include <vector>
#include <string>
#include <sstream>
#include "tg_enums.h"

namespace Tangara {

    struct EntryRule {
    public:
        EntryRule();

        explicit EntryRule(EntryRule *parentRule);

        ~EntryRule();

        void Namespace(const char *ns) { _nameSpace = ns; }
        void TypeAccess(tgAccessModifier am) { _typeAccess = am; }
        void UsingNamespace(const char *ns) { _usingNameSpaces.push_back(ns); }
        void Enable() { _parent->_child = this; }
        void Disable() { _parent->_child = nullptr; }
        void Free();

        std::string GetTypeName(const char* tn);
        [[nodiscard]] tgAccessModifier GetTypeAccess() const { return _typeAccess; }
    private:
        EntryRule* _parent{};
        EntryRule* _child{};

        const char* _nameSpace{};
        tgAccessModifier _typeAccess = AccessModifier_Internal;
        std::vector<const char*> _usingNameSpaces;

        static inline std::string GetTypeNameWithNS(const char* ns, const char* name)
        {
            return (std::stringstream() << ns << '.' << name).str();
        }
    };

} // Tangara

#endif //TANGARA_ENTRYRULE_HPP
