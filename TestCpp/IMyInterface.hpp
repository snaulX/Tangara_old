#ifndef TANGARA_IMYINTERFACE_HPP
#define TANGARA_IMYINTERFACE_HPP
#include "TangaraDefines.hpp"

class IMyInterface {
public:
    IMyInterface();

    ~IMyInterface();

    virtual void VirtualFunc() = 0;

private:

TANGARA_INTERFACE(IMyInterface)
    TANGARA_METHOD(VirtualFunc)
TANGARA_END()
};

#endif //TANGARA_IMYINTERFACE_HPP
