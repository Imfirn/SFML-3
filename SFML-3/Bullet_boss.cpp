#include "Bullet_boss.h"

void Bullet_boss::updatebb(float deltaTime, Player player)
{

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
        //player.set(2000, 400);
    }

}
float Bullet_boss:: getposix() {

    shape.getPosition().x;
    return shape.getPosition().x;

}
void Bullet_boss::del()
{
    shape.setPosition(NULL - 100, NULL - 100);
}