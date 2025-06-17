
#ifndef CORE_H
#define CORE_H

#ifdef PROTEA_PLATFORM_WINDOWS
    #ifdef PROTEA_BUILD_DLL
        #define PROTEA_API __declspec(dllexport)
    #else
        #define PROTEA_API __declspec(dllimport)
    #endif
#else
    #error Protea Engine only supports Windows...
#endif

// Define BIT X as just 1 shifted by x places
#define BIT(x) (1 << x)

#endif //CORE_H
