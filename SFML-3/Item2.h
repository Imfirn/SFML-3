#pragma once
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include"Collider.h"
using namespace sf;
class Item2
{
	public:
	Item2(Texture* texture, Vector2u imageCount, float switchTime, float x, float y);
	~Item2();

	void update(float deltaTime);
	void draw(RenderWindow& window);
	void setPosition(float x, float y);
	Collider GetCollider() { return Collider(body); }
private:
	int row;
	RectangleShape body;
	Animation animation;

};

