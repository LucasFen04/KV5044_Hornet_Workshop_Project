#include "Spaceship.h"
#include "HtKeyboard.h"
Spaceship::Spaceship() : GameObject(ObjectType::SPACESHIP)
{
}
void Spaceship::Update(double frametime)
{
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_LEFT));
    m_angle = m_angle - 0.01;

    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_RIGHT));
    m_angle = m_angle + 0.01;

    Vector2D shipAcceleration;


    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_UP))
    {
        m_velocity.setBearing(m_angle, 0.1);
        m_velocity = m_velocity + shipAcceleration;
        m_position = m_position + m_velocity;
    }

}
void Spaceship::Initialise()
{
    LoadImage("assets/ship.bmp");
    m_position = Vector2D (300, 300);
    m_velocity = Vector2D(0, 0);
    m_scale = 1.5;
}

void Spaceship::ProcessCollision(GameObject& other)
{
}

