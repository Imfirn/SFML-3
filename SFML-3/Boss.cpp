#include "Boss.h"


Boss::Boss(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float x, float y) :
    animation(texture, imageCount, switchTime)
{    
    this->speed = speed;
    hpdown = 0;
    //this-> monsterVector.push_back(monster(nullptr, sf::Vector2u(6, 2), 0.2f, 200.0f, 545.0f));
    row = 0;
  
    faceR = true;
    body.setSize(sf::Vector2f(300.0f, 300.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(x, y);
    body.setTexture(texture);
}
Boss::~Boss()
{
    //for(int i=0;i<monsterVector.size();i++)
   // delete this -> monsterVector[i];
}

void Boss:: updateboss(float deltaTime, Bullet bullet1)
{
    animation.updateboss(row, deltaTime);
    body.setTextureRect(animation.uvRect);

    if (bullet1.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
        count++;
        row = 1;
        body.setPosition(-1000.0f, 350.0f);
    }

}

void Boss::updateboss2(float deltaTime, Player player)
{

    if (abs(player.getPosition().x - body.getPosition().x) <= 500.0f)
    {
        velocity.x = 50;
        if (player.getPosition().x < body.getPosition().x) {
            row = 1;
            //std::cout << "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
            animation.Updatefacemon(row, deltaTime, faceR);
           // body.move(-velocity * deltaTime);



        }
        else if (player.getPosition().x > body.getPosition().x) {
            row = 0;
            animation.updateboss(row, deltaTime);
            //body.move(velocity * deltaTime);
          

        }
        else if ((player.getPosition().x > body.getPosition().x) && faceR == false) {
            animation.updateboss(row, deltaTime);
            //body.move(velocity * deltaTime);
            
        }

        body.setTextureRect(animation.uvRect);
    }
    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
        //player.set(2000, 400);
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