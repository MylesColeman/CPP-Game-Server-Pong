#include "Ball.h"
#include "Constants.h"
#include <random>
#include <cmath>

Ball::Ball(float worldWidth, float worldHeight)
    : m_worldWidth(worldWidth), m_worldHeight(worldHeight)
{
    reset();
}

void Ball::update(float delta)
{
    position.x  += velocity.x * delta * Constants::BALL_SPEED;
    position.y += velocity.y * delta * Constants::BALL_SPEED;

    if (position.x >= m_worldWidth - 0.5f || position.x <= 0.5f) 
    {
        velocity.x = -velocity.x;
        position.x += velocity.x * delta * Constants::BALL_SPEED;
    }
}

void Ball::reset() 
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> angleDist(-30.f, 30.f);
    std::uniform_int_distribution<int> sideDist(0, 1);

    position.x = m_worldWidth * 0.5f;
    float angleDeg;

    if(sideDist(gen) == 0)
    {
        angleDeg = -90.f + angleDist(gen);
        position.y = m_worldHeight - 1.f;
    }
    else
    {
        angleDeg = 90.f + angleDist(gen);
        position.y = 1.15f;
    }

    float angleRad = angleDeg * 3.14159f / 180.f;
    velocity.x = std::cos(angleRad);
    velocity.y = std::sin(angleRad);
}