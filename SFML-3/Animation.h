#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	void Update(int row, float deltaTime);
	void updateBu(int row, float deltaTime);	
	void updatemon(int row, float deltaTime);
	void updateboss(int row, float deltaTime);
	void Updatefacemon(int row, float deltaTime,bool faceR);
	void Updateplat(int row, float deltaTime);

public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	int face = 1;
	bool faceR;
	float totalTime;
	float switchTime;
};


