#ifndef CORE_H
#define CORE_H

#include <memory>

#ifdef PROTEA_PLATFORM_WINDOWS
#if PROTEA_DYNAMIC_LINK
#ifdef PROTEA_BUILD_DLL
#define PROTEA_API __declspec(dllexport)
#else
#define PROTEA_API __declspec(dllimport)
#endif
#else
#define PROTEA_API
#endif

#else
    #error Protea Engine only supports Windows...
#endif

#ifdef PROTEA_DEBUG_BUILD
#define PROTEA_ENABLE_ASSERTS
#endif

#ifdef PROTEA_ENABLE_ASSERTS
#define PROTEA_ASSERT(x, ...) { if(!(x)) { PROTEA_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define PROTEA_CORE_ASSERT(x, ...) { if(!(x)) { PROTEA_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define PROTEA_ASSERT(x, ...)
#define PROTEA_CORE_ASSERT(x, ...)
#endif


// Define BIT X as just 1 shifted by x places
#define BIT(x) (1 << x)

#define PROTEA_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Protea {

    template<typename T>
    using Scope = std::unique_ptr<T>;

    template<typename T>
    using Ref = std::shared_ptr<T>;

}

#endif //CORE_H
