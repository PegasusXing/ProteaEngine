
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



#endif //LOG_H
