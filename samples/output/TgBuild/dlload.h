#ifndef TGBUILD_DLLOAD_H
#define TGBUILD_DLLOAD_H

#ifdef __linux__
#define DLIB void*
#define dlload(libname) dlopen((libname), RTLD_LAZY)
#define dlfunc(lib, fn) dlsym((lib), (fn))
#elif WIN32
#define DLIB HINSTANCE
#define dlload(libname) LoadLibraryW(L ## libname)
#define dlfunc(lib, fn) GetProcAddress((lib), (fn))
#endif


#endif //TGBUILD_DLLOAD_H
