#include "Rock.h"

Rock::Rock(): GameObject(ObjectType::ROCK)
{
}

void Rock::Update(double frametime)
{
    m_position = m_position + m_velocity;
}

void Rock::ProcessCollision(GameObject& other)
{
}

void Rock::Initialise()
{
    LoadImage("assets/rock1.bmp");
    m_position.XValue = rand() % 3200 - 1600;
    m_position.YValue = rand() % 3200 - 2200;
    m_angle = rand() % 360;
    m_velocity.setBearing(m_angle, rand() % 110 + 40);
    SetCollidable();
}
