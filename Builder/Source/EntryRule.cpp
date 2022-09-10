#include "EntryRule.hpp"

namespace Tangara {
    EntryRule::EntryRule() = default;

    EntryRule::~EntryRule() = default;

    EntryRule::EntryRule(EntryRule *parentRule) {
        _parent = parentRule;
        parentRule->_child = this;
    }

    void EntryRule::Free() {
        _parent->_child = nullptr;
        _parent = nullptr;
    }

    std::string EntryRule::GetTypeName(const char *tn) {
        if (_child && _child->_nameSpace) {
            return GetTypeNameWithNS(_child->_nameSpace, tn);
        } else if (_nameSpace) {
            return GetTypeNameWithNS(_nameSpace, tn);
        } else {
            return {tn};
        }
    }
}