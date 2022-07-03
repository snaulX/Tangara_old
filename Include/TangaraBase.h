#ifndef TANGARA_TANGARABASE_H
#define TANGARA_TANGARABASE_H

#ifdef TANGARA_DLL
#   ifdef _WIN32
#       ifdef TANGARA_EXPORTS
#           define TANGARA_API __declspec(dllexport)
#       else
#           define TANGARA_API __declspec(dllimport)
#       endif
#   elif
#       define TANGARA_API
#endif
#else
#   define TANGARA_API
#endif

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif
static const uint32_t TG_CLASS_SEED = 0;

#endif //TANGARA_TANGARABASE_H
