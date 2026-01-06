#include "Engine.h"
#include "Log.h"


Engine::Engine()
{
    LOG_INFO("Enter Engine::Engine()");    
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    //RenderWindow
    m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas was late", Style::Fullscreen);
    //MainView
    m_MainView.setSize(resolution);
    //HudView
    m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));

    // Left and Right View
    m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_RightView.setViewport(FloatRect(0.5f,  0.001f, 0.499f, 0.998f));
    m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_BGRightView.setViewport(FloatRect(0.5f,  0.001f, 0.499f, 0.998f));

    if(!sf::Shader::isAvailable())
    {
        m_Window.close();
    }
    m_BackgroundTexture = TextureHolder::getTexture("graphics/background.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    m_TextureTiles = TextureHolder::getTexture("graphics/tiles_sheet.png");

}

void Engine::run()
{
    LOG_INFO("Enter Engine::run()");
    Clock clock;
    while(m_Window.isOpen())
    {
        Time dt = clock.restart();
        m_GameTimeTotal += dt;
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
        
    }
}
