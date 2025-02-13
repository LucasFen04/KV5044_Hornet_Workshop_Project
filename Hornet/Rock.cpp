#include "Rock.h"

Rock::Rock(): GameObject(ObjectType::ROCK)
{
}

void Rock::Update(double frametime)
{
    m_position = m_position + m_velocity * frametime;


    if ((m_position.XValue > 1600) && (m_velocity.XValue > 0))
    {
        m_velocity.XValue = -(m_velocity.XValue);
    }
    if ((m_position.XValue < -1600) && (m_velocity.XValue < 0))
    {
        m_velocity.XValue = -(m_velocity.XValue);
    }
    if ((m_position.YValue > 1000) && (m_velocity.YValue > 0))
    {
        m_velocity.YValue = -(m_velocity.YValue);
    }
    if ((m_position.YValue < -1000) && (m_velocity.YValue < 0))
    {
        m_velocity.YValue = -(m_velocity.YValue);
    }
}

void Rock::ProcessCollision(GameObject& other)
{
}

void Rock::Initialise()
{
    LoadImage("assets/rock1.bmp");
    int X = (rand() % 3200) - 1600;
    int Y = (rand() % 2001) - 1000;
    m_position = Vector2D(X, Y);

    m_angle = rand() % 361;
    m_speed = 40 + rand() % 111;
    m_velocity.setBearing(m_angle, m_speed);
    SetCollidable();
}
