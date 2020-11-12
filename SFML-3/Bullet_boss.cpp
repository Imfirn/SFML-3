#include "Bullet_boss.h"

void Bullet_boss::updatebb(float deltaTime, Player player)
{

    if (player.GetCollider().CheckCollision(this->GetCollider()))
    {
        hpdown++;
        //player.set(2000, 400);
    }

}
