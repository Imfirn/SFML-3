#include "monster.h"
#include<math.h>
#include<vector>
#include<iostream>








monster::monster(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y,float a) :
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->velocity.x = a;
    hpdown = 0;
    
    row = 0;
    faceR = true;
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}

monster::~monster()
{   
   
}

void monster::updatemon(float deltaTime, Bullet bullet1)
{
    animation.updatemon(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
        count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }

 }

void monster::updatemon2(float deltaTime, Player player)
{
   
        if (abs(player.getPosition().x - body.getPosition().x) <= 500.0f)
        {
            velocity.x;
            if (player.getPosition().x < body.getPosition().x) {
                row = 1;
                //std::cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
                animation.Updatefacemon(row, deltaTime, faceR);
                body.move(-velocity * deltaTime);
                


            }
            else if (player.getPosition().x > body.getPosition().x) {
                row = 0;
                animation.updatemon(row, deltaTime);
                body.move(velocity * deltaTime);
               

            }
            else if ((player.getPosition().x > body.getPosition().x) && faceR == false) {
                animation.updatemon(row, deltaTime);
                body.move(velocity * deltaTime);
              
            }
           
            body.setTextureRect(animation.uvRect);
        }
        if (player.GetCollider().CheckCollision(this->GetCollider()))
        {
            hpdown++;
            
        }
    
}
 
void monster::Draw(sf::RenderWindow& window)
{
    window.draw(body);
    
}
void monster::OnCollision(sf::Vector2f direction, float deltaTime)
{
    if (direction.x < 0.0f)
    {
        body.move(-velocity * deltaTime);
    }
    else if (direction.x > 0.0f)
    {
        body.move(velocity * deltaTime);
    }
    
}