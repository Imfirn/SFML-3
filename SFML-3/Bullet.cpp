#include "Bullet.h"
#include<iostream>

Bullet::Bullet(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
   
    body.setSize(sf::Vector2f(20.0f, 10.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(pos);
    body.setTexture(texture);
}
Bullet::~Bullet()
{

}
void Bullet::UpdateR(float deltaTime)
{
  

    if (body.getPosition().x != NULL -100&& body.getPosition().y != NULL - 100) {
        velocity.y = 0;
        velocity.x = speed*2;
       
            
        
            row = 0;
            body.move(velocity * deltaTime);
            animation.updateBu(row, deltaTime);
        
        
        body.setTextureRect(animation.uvRect);
    }
   
}
void Bullet::UpdateL(float deltaTime)
{


    if (body.getPosition().x != NULL - 50 && body.getPosition().y != NULL - 50) {
        velocity.y = 0;
        velocity.x = speed * 1.5;
        
            row = 1;
            body.move(-velocity * deltaTime);
            animation.updateBu(row, deltaTime);
                        
        

        body.setTextureRect(animation.uvRect);
    }

}

void Bullet::attackR(sf::Vector2f pos) {
         
        body.setPosition(pos.x + 53.0f, pos.y + 10.0f);
        isAva = false;
}
void Bullet::attackL(sf::Vector2f pos) {

        body.setPosition(pos.x - 53.0f, pos.y + 10.0f);
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