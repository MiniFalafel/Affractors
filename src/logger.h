#pragma once

#include <iostream>
#include <signal.h>

enum class LogLevel
{
    ERROR = 0,
    WARN,
    INFO,
    TRACE
};

class Logger
{
    LogLevel m_LogLevel;
    
public:
    Logger(LogLevel logLevel)
        : m_LogLevel(logLevel) {}
    
private: // PRIVATE METHODS
    inline void LogMessage(const char* header, const char* message, LogLevel level) const
    {   // Check if we should log this message
        if (level <= m_LogLevel)
        {
            std::cout << header << message << "\n";
        }
    }
        
public: // PUBLIC METHODS
    inline void LogTrace(const char* message) const
    {   // Use private method to display the log message
        LogMessage("TRACE: ", message, LogLevel::INFO);
    }
    
    inline void LogInfo(const char* message) const
    {   // Use private method to display the log message
        LogMessage("INFO: ", message, LogLevel::INFO);
    }
    
    inline void LogWarn(const char* message) const
    {   // Use private method to display the log message
        LogMessage("WARN: ", message, LogLevel::INFO);
    }
    
    inline void LogError(const char* message) const
    {   // Use private method to display the log message
        LogMessage("ERROR: ", message, LogLevel::INFO);
        // Break
        raise(SIGTRAP);
    }
};
