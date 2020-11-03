#include "monsterbu.h"
#include"Player.h"
#include<iostream>

monsterbu::monsterbu(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f pos) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    row = 0;
   
    shape.setSize(sf::Vector2f(50.0f, 50.0f));
    shape.setOrigin(shape.getSize() / 2.0f);
    shape.setPosition(pos);
    shape.setTexture(texture);
}
monsterbu::~monsterbu()
{

}
void monsterbu::Update(float deltaTime)
{
    

    if (shape.getPosition().x != NULL - 100 && shape.getPosition().y != NULL - 100) {
        velocity.y = 0;
        velocity.x = speed * 1.5;
        if (face(LR) == 1) {

            row = 1;
            shape.move(-velocity * deltaTime);
            animation.updateBu(row, deltaTime);

        }
        else
        {
            row = 0;
           shape.move(velocity * deltaTime);
            animation.updateBu(row, deltaTime);
        }

        shape.setTextureRect(animation.uvRect);
    }

}

void monsterbu::attack(sf::Vector2f pos) {
    if (face(LR) == 1) {
        shape.setPosition(pos.x - 53.0f, pos.y + 10.0f);
    }
    else {
        shape.setPosition(pos.x + 53.0f, pos.y + 10.0f);
    }

    isAva = false;
}

void monsterbu::delt()
{
    shape.setPosition(NULL - 100, NULL - 100);
}

bool monsterbu::isAvaliable() {
    isAva = true;
    return isAva;
}

void monsterbu::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}