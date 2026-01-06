#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter
{
    protected:           // for inheritance 
        Sprite m_Sprite; // Sprite is protected, because it will be used by Thomas and Bob directly.
        float m_JumpDuration;
        bool m_IsJumping;
        bool m_IsFalling;
        bool m_LeftPressed;
        bool m_RightPressed;
        float m_TimeThisJump;
        bool m_JustJumped = false;


    private:
        float m_Gravity;       // number of pixels
        float m_Speed = 400;   // number of pixels
        Vector2f m_Position;   // character position, position in the world
        FloatRect m_Feet;
        FloatRect m_Head;
        FloatRect m_Right;
        FloatRect m_Left;
        Texture m_Texture; // Texture is private, because it will not be used by Thomas and Bob directly


    public:
        void spawn(Vector2f startPosition, float gravity);
        bool virtual handleInput() = 0;  // virtual

        FloatRect getPosition();
        FloatRect getFeet();
        FloatRect getHead();
        FloatRect getRight();
        FloatRect getLeft();

        Sprite getSprite();

        void stopFalling(float position);
        void stopRight(float position);
        void stopLeft(float position);
        void stopJump();

        Vector2f getCenter();
        void update(float elapsedTime);

};
