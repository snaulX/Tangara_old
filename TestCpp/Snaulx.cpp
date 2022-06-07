
#include "Snaulx.hpp"

Snaulx::Snaulx(char* name): name(name) {}

void Snaulx::PrintName(EnigmaLabs::MyClass* cl) {
    cl->Greetings(name);
}

Snaulx::~Snaulx() = default;