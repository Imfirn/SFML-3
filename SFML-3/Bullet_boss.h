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
#include <fstream>
#include"Animation.h"
#include "Player.h"
#include"Boss.h"
class Bullet_boss {


public:
    RectangleShape shape;
    Texture texture;
    

    Vector2f currVelocity;
    float maxSpeed;

    void updatebb(float deltaTime, Player player);
    Collider GetCollider() { return Collider(shape); }
    Bullet_boss(float radius = 50.f)
        :currVelocity(0.f, 0.f), maxSpeed(20.f)
    {
        this->shape.setSize(sf::Vector2f(radius, radius));
       // this->shape.setFillColor(Color::Red);

        texture.loadFromFile("pic/bb.png ");
        this->shape.setTexture(&texture);
       
    }
    int check() {
        if (hpdown == 1) {
            hpdown--;
            return 1;
        }
    }
private:
    int count = 0;
    int hpdown;

};

