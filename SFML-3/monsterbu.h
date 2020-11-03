
#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"monsterbu.h"
#include "monster.h"
#include <iostream>
    using namespace std;

    class monsterbu
{
public:
    monsterbu(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos);
    ~monsterbu();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    bool isAvaliable();
    void attack(sf::Vector2f poss);
    void delt();

    int face(int x) {
        if (x > 0)return 1;
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

    sf::Vector2f GetPosition() { return shape.getPosition(); }
    Collider GetCollider() { return Collider(shape); }

private:
    Animation animation;
    float speed;
    sf::RectangleShape shape;
    int LR;
    //bool LR=true;
    unsigned int row;
    sf::Vector2f velocity;
    bool isAva = true;
};
