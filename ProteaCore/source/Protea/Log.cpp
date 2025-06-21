#include "ProteaPCH.h"
#include "Log.h"

#include <spdlog/pattern_formatter.h>
#include <spdlog/sinks/stdout_color_sinks-inl.h>

#include <filesystem>

namespace Protea {
    // TODO: Working on a customized logging format
    class colored_source_file_formatter : public spdlog::custom_flag_formatter {
    public:
        void format(const spdlog::details::log_msg& msg,
                    const std::tm&,
                    spdlog::memory_buf_t& dest) override {
            namespace fs = std::filesystem;
            std::string fullpath = msg.source.filename ? msg.source.filename : "unknown";
            std::string filename = fs::path(fullpath).filename().string();

            fmt::format_to(std::back_inserter(dest), "\033[36m[{}]\033[0m", filename);
        }

        [[nodiscard]] std::unique_ptr<custom_flag_formatter> clone() const override {
            return spdlog::details::make_unique<colored_source_file_formatter>();
        }
    };

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init() {
        /*auto formatter = std::make_unique<spdlog::pattern_formatter>();
        formatter->add_flag<colored_source_file_formatter>('x');
        formatter->set_pattern("[%T] %^[%=17n] %x %v%$");
        spdlog::set_formatter(std::move(formatter));*/

        spdlog::set_pattern("%^[%T] [%=17n] [%s] %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("PROTEA_CORE_LOG");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APPLICATION_LOG");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
