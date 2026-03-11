#ifndef BALL_H
#define BALL_H

#include <SFML/System/Vector2.hpp>

class Ball {
public:
    sf::Vector2f position;
    sf::Vector2f velocity;

    Ball(float worldWidth, float worldHeight);
    void update(float delta);
    void reset();

private:
float m_worldWidth;
float m_worldHeight;
};

#endif