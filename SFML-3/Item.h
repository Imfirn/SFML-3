#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<math.h>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"



class Item
{
public:
    Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Item();
    void updateitem(float deltaTime, Player player);
    void Draw(sf::RenderWindow& window);
    Collider GetCollider() { return Collider(body); }
    int check() {
        if (hpup == 1) {
            hpup--;
            return 1;
        }
    }
    sf::RectangleShape body;
private:
    int row;
    int hpup;
    float speed;
    Animation animation;
    sf::Vector2f velocity;
};