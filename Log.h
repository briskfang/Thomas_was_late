#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <ctime>

enum class LogLevel{ERROR = 0, WARNING, INFO, DEBUG};

class Logger
{
    private:
        std::ofstream file;
        LogLevel currentLevel = LogLevel::INFO;
        
        static Logger& instance();         // Singleton, create a single object, create it only once, return the reference
        static std::string levelToString(LogLevel level);
        static std::string timestamp();

    public:
        static void init(const std::string& filename, LogLevel level);
        static void setLevel(LogLevel level);
        static void log(LogLevel, const std::string& message);
        
};

#define LOG_ERROR(msg)   \
    Logger::log(LogLevel::ERROR,   std::string("[") + __FILE__ + ":" + std::to_string(__LINE__) + "]" + msg);

#define LOG_WARNING(msg) \
    Logger::log(LogLevel::WARNING, std::string("[") + __FILE__ + ":" + std::to_string(__LINE__) + "]" + msg);

#define LOG_INFO(msg)    \
    Logger::log(LogLevel::INFO,    std::string("[") + __FILE__ + ":" + std::to_string(__LINE__) + "]" + msg);

#define LOG_DEBUG(msg)   \
    Logger::log(LogLevel::DEBUG,   std::string("[") + __FILE__ + ":" + std::to_string(__LINE__) + "]" + msg);
