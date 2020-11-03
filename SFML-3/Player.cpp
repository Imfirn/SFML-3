#include "Player.h"
#include<iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHigh) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHigh = jumpHigh;

	row = 0;
	face = 1;
	bullet = false;
	body.setSize(sf::Vector2f(90.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(626.0f, 360.0f);
	body.setTexture(texture);
}
Player::~Player() {

}
void Player::Update(float deltaTime) {
	//sf::Vector2f movement(0.0f, 0.0f);

	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		bullet = true;
		row = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed*2;
		face = -1;
		//std::cout << face;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed*2;
		face = 1;
		//std::cout << face;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHigh);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		bullet = true;

	}


	velocity.y += 981.0f * deltaTime;
	row =0;
	if (velocity.x== 0.0f) {
		
		if (face == -1) {

			row = 2;
		}
	}
	else
	{
		if (velocity.x > 0.0f) {
			row = 1;
		}
		else if(velocity.x < 0.0f)
			row = 3;
	}
	/*if (velocity.x == 0.0f) {
		row = 0;
	}

	else {
		row = 2;
		if (velocity.x > 0.0f){
			row = 3;
			face = 1;
	}
		else
			face = -1;
			row = 1;
	}*/
	if (body.getPosition().x < 0)
		body.setPosition(0, body.getPosition().y);

	if (899<=body.getPosition().x && body.getPosition().x<=960) {
		body.setPosition(body.getPosition().x,300);
	}

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
	
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f) {

		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {

		velocity.y = 0.0f;

	}
}

