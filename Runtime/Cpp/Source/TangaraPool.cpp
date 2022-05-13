#include "TangaraPool.hpp"
#include "TangaraDefines.hpp"

TangaraPool::TangaraPool() {
    if (!Instance) Instance = new TangaraPool();
}

TangaraPool::~TangaraPool() = default;

void TangaraPool::CreateInterface(const char *name) {

}

void TangaraPool::CreateClass(const char *name) {

}

static Tangara::Entry* Tangara::Runtime::Cpp::GetEntry() {
    return TangaraPool::Instance->GetEntry();
}