#include "Thomas.h"
#include "TextureHolder.h"
#include "Log.h"

Thomas::Thomas()
{
    LOG_INFO("Enter Thomas::Thomas()");
    m_Sprite = Sprite(TextureHolder::getTexture("graphics/thomas.png"));
    m_JumpDuration = 0.45;
}


bool Thomas::handleInput()
{
    LOG_INFO("Enter Thomas::handleInput()");
    m_JustJumped = false;

    // W: jump
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        LOG_INFO("Keyboard W pressed");
        if(!m_IsJumping && !m_IsFalling)
        {
            m_IsJumping = true;
            m_TimeThisJump = 0;  //reset jumping time
            m_JustJumped = true;
        }
    }
    else
    {
        m_IsJumping = false;
        m_IsFalling = true;
    }

    // A: Left
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        LOG_INFO("Keyboard A pressed");
        m_LeftPressed = true;
    }
    else
    {
        m_LeftPressed = false;
    }

    // D: right
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        LOG_INFO("Keyboard D pressed");
        m_RightPressed = true;
    }
    else
    {
        m_RightPressed = false;
    }

    return m_JustJumped;  


}