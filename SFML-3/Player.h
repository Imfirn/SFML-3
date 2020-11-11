#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include"Collider.h"
#include"Item2.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHigh);
	~Player();
	void Update(float deltaTime, std::vector<Item2>& itemslowVector);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	//void set(float x, float y);

//void updateitem(float detaTime, std::vector<Item2>& itemslowVector);
	sf::Vector2f getPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	int face;
	float itemTimer;
	int v;
	bool bullet;
	bool buffslow;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHigh;
	float time;
	int l = 0;
	

};

