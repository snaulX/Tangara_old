#ifndef TANGARA_TANGARABASE_H
#define TANGARA_TANGARABASE_H

#ifdef _WIN32
#    ifdef TANGARA_EXPORTS
#        define TANGARA_API __declspec(dllexport)
#    else
#        define TANGARA_API
#    endif
#elif
#    define TANGARA_API
#endif

static const uint32_t TG_HASH_SEED = 0;

#endif //TANGARA_TANGARABASE_H
