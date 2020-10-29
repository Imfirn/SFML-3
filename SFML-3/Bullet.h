#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Bullet
{
public:
    Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
    ~Bullet();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    bool isAvaliable();
    void attack(sf::Vector2f pos);
    void del();
    
    int face(int x) {
        if (x>0)return 1;
        else return 2;
    }
   /*int face(bool x) {
        if (body.getPosition().x)
        {
            x = false;
            return 1;
        }
        else return 2;
    }*/

    sf::Vector2f GetPosition() { return body.getPosition(); }
    Collider GetCollider() { return Collider(body); }

private:
    Animation animation;
    float speed;
    sf::RectangleShape body;
    int LR;
    //bool LR=true;
    unsigned int row;
    sf::Vector2f velocity;
    bool isAva = true;
};

