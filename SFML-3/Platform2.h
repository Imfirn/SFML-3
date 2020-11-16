#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"

class Platform2
{

public:
    Platform2(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y );
    ~Platform2();
    void updateX(float deltaTime);
    void updateY(float deltaTime);
    void draw(sf::RenderWindow& window);
    void MOVE();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }

    

    

private:
    float posiX, posiY;
    int row;
    int counthit;
    int count = 100;
    bool hit;
    float speed;
    float direction;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};