#include "Student.h"

Student::Student(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f positon):
	animation(texture, imageCount, switchTime)
{
	row = 0;

	body.setSize(sf::Vector2f(80.0f, 132.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(positon);
	body.setTexture(texture);
}

void Student::Update(float deltaTime)
{
	animation.Update(row, deltaTime,true);
	body.setTextureRect(animation.uvRect);
}

void Student::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
