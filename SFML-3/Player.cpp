#include "Player.h"
#include<iostream>
Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHigh) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHigh = jumpHigh;
	this-> itemTimer = 0;
	this->v = 3;
	
	float time = 0.0f;
	
	this -> LR=0 ;
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
void Player::Update(float deltaTime, std::vector<Item2>& itemslowVector) {
	//sf::Vector2f movement(0.0f, 0.0f);
	for (int i = 0; i < itemslowVector.size(); i++) {

		if (this->GetCollider().CheckCollision(itemslowVector[i].GetCollider())) {

			this->buffslow = true;
			itemslowVector[i].setPosition(-100.0f, 3000.0f);
			this->v = 1;
		}
	}
	if (this->buffslow == true) {
		
		itemTimer =itemTimer + deltaTime;
		std::cout << deltaTime << '\n';
		if (itemTimer >= 5) {
			std::cout << "uioutreefggcv";
			itemTimer = 0;		
			this->v = 3;
			this->buffslow = false;
		}

	}
	velocity.x = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		bullet = true;
		row = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed * v;
		face = -1;
		this->LR = -1;
		//std::cout << face;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed * v;
		face = 1;
		this->LR = 1;
		//std::cout << face;
	}
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
	
	if (body.getPosition().x < 0)
		body.setPosition(0, body.getPosition().y);

	if (899<=body.getPosition().x && body.getPosition().x<=960) {
		body.setPosition(body.getPosition().x,300);
	}
	/// change Part///
	if (7635 <= body.getPosition().x && body.getPosition().x <= 7700 && body.getPosition().y >= 400) {
		body.setPosition(17960, body.getPosition().y);
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

void Player::setPosition(float x, float y)
{
	body.setPosition(x, y);
}

void Player::Reset()
{
	this->buffslow = false;
	this->v = 3;
}

