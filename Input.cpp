#include "Engine.h"
#include "Log.h"


void Engine::input()
{
    LOG_INFO("Enter Engine::input()");
    Event event;
    while(m_Window.pollEvent(event))
    {
        if(event.type == Event::KeyPressed)
        {
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                m_Window.close();

            if(Keyboard::isKeyPressed(Keyboard::Return))
               m_Playing = true;

            if(Keyboard::isKeyPressed(Keyboard::Q))
                m_Character1 = !m_Character1;

            if(Keyboard::isKeyPressed(Keyboard::E))
                m_SplitScreen = !m_SplitScreen;
        }
    }

    if(m_Thomas.handleInput())
    {
        LOG_INFO("Enter Thomas handleInput()");
        // play sound        
    }

    if(m_Bob.handleInput())
    {
        LOG_INFO("Enter Bob handleInput()");
        // play sound
    }
    

}