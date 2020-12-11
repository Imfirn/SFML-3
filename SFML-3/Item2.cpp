#include "Item2.h"
#include<iostream>
using namespace sf;

Item2::Item2(Texture* texture, Vector2u imageCount, float switchTime, float x, float y):
animation(texture, imageCount, switchTime)
{

	row = 0;
	body.setSize(Vector2f(50.0f, 45.0f));
	body.setOrigin(body.getSize()/2.0f);
	body.setPosition(x, y);
	body.setTexture(texture);

}
Item2::~Item2()
{
}

void Item2::update(float deltaTime)
{
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
}
/*void Item2::updateHP(monster Mon)
{
	body.setPosition(Mon.getPo(),Mon.getPoy());
}*/
void Item2::draw(RenderWindow& window) 
{
	window.draw(body);
}
void Item2::setPosition(float x, float y)
{
	body.setPosition(x, y);
}