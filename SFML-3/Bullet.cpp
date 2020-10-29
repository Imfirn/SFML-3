#include "Bullet.h"
#include<iostream>

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
    LR ;
    body.setSize(sf::Vector2f(50.0f, 50.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos);
    body.setTexture(texture);
}
Bullet::~Bullet()
{
}
void Bullet::Update(float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        //velocity.x -= 30;
        LR = 1;
        //std::cout << LR;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        //velocity.x += 30;
        LR = -1;

    if (body.getPosition().x != NULL - 100 && body.getPosition().y != NULL - 100) {
        velocity.y = 0;
        velocity.x = speed;
        if (face(LR)==1) {

            row = 1;
            body.move(-velocity * deltaTime);
            animation.updateBu(row, deltaTime);
        }
        else 
        {
            row = 0;
            body.move(velocity * deltaTime);
            animation.updateBu(row, deltaTime);
        }
        //animation.updateBu(row, deltaTime,faceRight);
        body.setTextureRect(animation.uvRect);
    }
    /* if (body.getPosition().x > 1920) {
        isAva = true;
    } */
}

void Bullet::attack(sf::Vector2f pos) {
    if (face(LR) == 1) {
        body.setPosition(pos.x - 53.0f, pos.y + 10.0f);
    }
    else {
        body.setPosition(pos.x + 53.0f, pos.y + 10.0f);
    }

    isAva = false;
}

void Bullet::del()
{
    body.setPosition(NULL - 100, NULL - 100);
}

bool Bullet::isAvaliable() {
    isAva = true;
    return isAva;
}

void Bullet::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}