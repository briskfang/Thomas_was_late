#include "Log.h"

// instance()
Logger& Logger::instance()
{
    static Logger logger; // implicit constructor is called
    return logger;        // "return &logger;" is wrong, because &logger is of type pointer: Logger*.
                          // if changing Logger& to Logger*, then it is OK to "return &logger".
                          // however Logger& is better than Logger*, in the context of singleton. because
                          // 1) it cannot be nullptr
                          // 2) less error-prone
}

// levelToString()
std::string Logger::levelToString(LogLevel level)
{
    switch(level)
    {
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::DEBUG:   return "DEBUG";
    }
    return "UNKNOWN";
}

// timestamp()
std::string Logger::timestamp()
{
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));   // string format time
    return buf;
}



// init()
void Logger::init(const std::string& filename, LogLevel level = LogLevel::ERROR)
{
    instance().file.open(filename, std::ios::out | std::ios::app); // write(output) and append to the end(app), avoid overwriting
    instance().currentLevel = level;
}

void Logger::setLevel(LogLevel level)
{
    instance().currentLevel = level;
}

void Logger::log(LogLevel level, const std::string& message)
{
    if(level > instance().currentLevel) // eg, DEBUG is 4, INFO is 3, if level is DEBUG and currentLevel is INFO, can ignore DEBUG.
        return ;
    std::string line = timestamp() + "[" + levelToString(level) + "]" + message;

    if(instance().file.is_open())
    {
        instance().file << line << std::endl;
    }
    else
    {
        std::cout << line << std::endl;
    }
    
}

