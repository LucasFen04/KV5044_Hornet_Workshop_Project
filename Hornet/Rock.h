#pragma once
#include "GameObject.h"


class Rock : public GameObject
{
public:
    Rock();

    void Update(double frametime) override;

    void ProcessCollision(GameObject& other) override;

    void Initialise();


private:
    Vector2D m_velocity; // Will be used to store the velocity of the object
    double m_speed; // Used for the speed wasn't created yet
};

