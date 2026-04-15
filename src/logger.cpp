#include "logger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Logger::logger;

void Logger::init()
{
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/app.log", true);

    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};

    logger = std::make_shared<spdlog::logger>("app", sinks.begin(), sinks.end());

    logger->set_level(spdlog::level::debug);
    logger->flush_on(spdlog::level::info);

    spdlog::set_default_logger(logger);
}

std::shared_ptr<spdlog::logger>& Logger::get()
{
    return logger;
}
