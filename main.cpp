#include "Engine.h"
#include "Log.h"

int main()
{
    Logger::init("log/thomas.log", LogLevel::INFO);
    LOG_INFO("Enter Main()");
    Engine engine;

    engine.run();

    return 0;
}

/*
g++ -std=c++20 -c main.cpp
g++ main.o -o output -F/Library/Frameworks -framework sfml-graphics -framework sfml-window -framework sfml-system -framework sfml-audio
*/