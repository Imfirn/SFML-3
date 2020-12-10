#include "Boss.h"


Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{    
    this->speed = speed;
    hpdown = 0;
   
    row = 0;
  
    faceR = true;
    body.setSize(sf::Vector2f(450.0f, 400.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}
Boss::~Boss()
{
   
}

void Boss:: updateboss(float deltaTime, Bullet bullet1)
{
    animation.updateboss(row, deltaTime);
    body.setTextureRect(animation.uvRect);

   

}

void Boss::updateboss2(float deltaTime, Player player)
{

    if (abs(player.getPosition().x - body.getPosition().x) <= 500.0f)
    {
        velocity.x = 50;
        if (player.getPosition().x < body.getPosition().x) {
            row = 1;
           
            animation.Updatefacemon(row, deltaTime, faceR);
           



        }
        else if (player.getPosition().x > body.getPosition().x) {
            row = 0;
            animation.updateboss(row, deltaTime);
           
          

        }
        else if ((player.getPosition().x > body.getPosition().x) && faceR == false) {
            animation.updateboss(row, deltaTime);
           
            
        }

        body.setTextureRect(animation.uvRect);
    }
    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
       
    }

}

void Boss::Draw(sf::RenderWindow& window)
{
    window.draw(body);

}
float Boss::getposix() {
   
    body.getPosition().x;
    return body.getPosition().x;
}
float Boss::getposiy()
{
    body.getPosition().y;
    return body.getPosition().y;
}
void Boss::delelet() {
     
    body.setPosition(-1000,800);
  
}