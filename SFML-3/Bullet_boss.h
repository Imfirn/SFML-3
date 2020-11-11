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
   class Bullet_boss {


    public:
        CircleShape shape;
        Vector2f currVelocity;
        float maxSpeed;

        Bullet_boss(float radius = 5.f)
            :currVelocity(0.f, 0.f), maxSpeed(15.f)
        {
            this->shape.setRadius(radius);
            this->shape.setFillColor(Color::Red);


        }



    };


