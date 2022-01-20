#include "Chair.h"


Chair::Chair(string texture, sf::Color color, sf::Vector2f size, sf::Vector2f positon)
{
	chairTexture.loadFromFile(texture);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(&chairTexture);
	body.setFillColor(color);
	body.setPosition(positon);
}

Chair::~Chair()
{
} 
void Chair::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
