#pragma once

#include <memory>
#include <spdlog/spdlog.h>

class Logger
{
public:
    static void init();

    static std::shared_ptr<spdlog::logger>& get();

private:
    static std::shared_ptr<spdlog::logger> logger;
};

#define LOG_INFO(...)  Logger::get()->info(__VA_ARGS__)
#define LOG_ERROR(...) Logger::get()->error(__VA_ARGS__)
