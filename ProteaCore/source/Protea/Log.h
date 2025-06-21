#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include "spdlog/spdlog.h"
////////////////////////////////////////////////////////
/// DO NOT REMOVE EVENTFORMATTER.H /////////////////////
////////////////////////////////////////////////////////
#include "Events/EventFormatter.h"

namespace Protea {
    class PROTEA_API Log {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

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
#define PROTEA_CORE_TRACE(...)      SPDLOG_LOGGER_TRACE(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
#define PROTEA_CORE_DEBUG(...)      SPDLOG_LOGGER_DEBUG(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
#define PROTEA_CORE_INFO(...)       SPDLOG_LOGGER_INFO(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
#define PROTEA_CORE_WARN(...)       SPDLOG_LOGGER_WARN(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
#define PROTEA_CORE_ERROR(...)      SPDLOG_LOGGER_ERROR(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
#define PROTEA_CORE_CRITICAL(...)   SPDLOG_LOGGER_CRITICAL(::Protea::Log::GetCoreLogger(), __VA_ARGS__)
////////////////////////////////////////////////////////
/// CLIENT LOG MACROS: /////////////////////////////////
////////////////////////////////////////////////////////
#define PROTEA_TRACE(...)           SPDLOG_LOGGER_TRACE(::Protea::Log::GetClientLogger(), __VA_ARGS__)
#define PROTEA_DEBUG(...)           SPDLOG_LOGGER_DEBUG(::Protea::Log::GetClientLogger(), __VA_ARGS__)
#define PROTEA_INFO(...)            SPDLOG_LOGGER_INFO(::Protea::Log::GetClientLogger(), __VA_ARGS__)
#define PROTEA_WARN(...)            SPDLOG_LOGGER_WARN(::Protea::Log::GetClientLogger(), __VA_ARGS__)
#define PROTEA_ERROR(...)           SPDLOG_LOGGER_ERROR(::Protea::Log::GetClientLogger(), __VA_ARGS__)
#define PROTEA_CRITICAL(...)        SPDLOG_LOGGER_CRITICAL(::Protea::Log::GetClientLogger(), __VA_ARGS__)

#endif //LOG_H
