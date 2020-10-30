#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"


class monster
{
public:
    monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~monster();
    void updatemon(float deltaTime, Bullet bullet1);
    void updatemon2(float deltaTime, Player player);
    void Draw(sf::RenderWindow& window);
    Collider GetCollider() { return Collider(body); }

    int hit()
    {
        if (count == 1) {
            count--;
            return 1;
        }
    }
private:
    int row;
    int count = 0;
    bool faceR;
    float speed;
    sf::RectangleShape body;
    Animation animation;
    sf::Vector2f velocity;
};