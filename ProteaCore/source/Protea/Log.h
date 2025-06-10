
#ifndef LOG_H
#define LOG_H

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Protea {
    class PROTEA_API Log {
    public:

        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger()   { return s_CoreLogger;   }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

////////////////////////////////////////////////////////
/// MACROS CAN BE STRIPPED FOR DIST: ///////////////////
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
/// CORE LOG MACROS: ///////////////////////////////////
////////////////////////////////////////////////////////
#define PROTEA_CORE_TRACE(...)      ::Protea::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PROTEA_CORE_DEBUG(...)      ::Protea::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define PROTEA_CORE_INFO(...)       ::Protea::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PROTEA_CORE_WARN(...)       ::Protea::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PROTEA_CORE_ERROR(...)      ::Protea::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PROTEA_CORE_CRITICAL(...)   ::Protea::Log::GetCoreLogger()->critical(__VA_ARGS__)
////////////////////////////////////////////////////////
/// CLIENT LOG MACROS: /////////////////////////////////
////////////////////////////////////////////////////////
#define PROTEA_TRACE(...)           ::Protea::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PROTEA_DEBUG(...)           ::Protea::Log::GetClientLogger()->debug(__VA_ARGS__)
#define PROTEA_INFO(...)            ::Protea::Log::GetClientLogger()->info(__VA_ARGS__)
#define PROTEA_WARN(...)            ::Protea::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PROTEA_ERROR(...)           ::Protea::Log::GetClientLogger()->error(__VA_ARGS__)
#define PROTEA_CRITICAL(...)        ::Protea::Log::GetClientLogger()->critical(__VA_ARGS__)

#endif //LOG_H
