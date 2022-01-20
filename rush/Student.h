#pragma once
#include  <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Student
{
public:
	Student(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f positon);

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
};

