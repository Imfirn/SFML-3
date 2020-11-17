#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "stdlib.h"
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Animation.h"
#include "Collider.h"
#include "Bullet.h"
using namespace sf;
class Boss{
public:
    Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y);
    ~Boss();
    void updateboss(float deltaTime, Bullet bullet1);
    void updateboss2(float deltaTime, Player player);
    float getposix();
    void Draw(sf::RenderWindow& window);
    void delelet();
    Collider GetCollider() { return Collider(body); }
    

    int hit()
    {
        if (count == 1) {
            count--;
            return 1;
        }
    }
    int check() {
        if (hpdown == 1) {
            hpdown--;
            return 1;
        }
    }

   
    sf::RectangleShape body;
private:
    int row;
    int count = 0;
    int hpdown;
   
    bool faceR;
    float speed;
    bool Monsterbu;
    float x;
    Animation animation;
    sf::Vector2f velocity;
};

