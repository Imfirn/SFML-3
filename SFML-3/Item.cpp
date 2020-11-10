#include "Item.h"
#include<math.h>
#include<vector>
#include<iostream>


Item::Item(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->hpup = 0;
    //this-> monsterVector.push_back(monster(nullptr, sf::Vector2u(6, 2), 0.2f, 200.0f, 545.0f));
    row = 0;
    body.setSize(sf::Vector2f(50.0f, 45.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

Item::~Item()
{
}

void Item::updateitem(float deltaTime, Player player)
{
    animation.updatemon(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        this->hpup++;
        body.setPosition(-1000.0f, 350.0f);
    }

}


void Item::Draw(sf::RenderWindow& window)
{
    window.draw(body);

}