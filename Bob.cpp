#include "Bob.h"
#include "TextureHolder.h"
#include "Log.h"

Bob::Bob()
{
    LOG_INFO("Enter Bob::Bob()");
    m_Sprite = Sprite(TextureHolder::getTexture("graphics/bob.png"));
    m_JumpDuration = 0.25;
}

bool Bob::handleInput()
{
    LOG_INFO("Enter Bob::handleInput()");
    m_JustJumped = false;

    if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        LOG_INFO("Keyboard::Up pressed");
        if( !m_IsJumping && !m_IsFalling)
        {
            m_IsJumping = true;
            m_TimeThisJump = 0;
            m_JustJumped = true;
        }
    }
    else
    {
        m_IsJumping = false;
        m_IsFalling = true;
    }


    if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        LOG_INFO("Keyboard::Left pressed");
        m_LeftPressed = true;
    }
    else
    {
        m_LeftPressed = false;
    }

    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        LOG_INFO("Keyboard::Right pressed");
        m_RightPressed = true;
    }
    else
    {
        m_RightPressed = false;
    }

    return m_JustJumped;
}