#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Color color, sf::Vector2f size, sf::Vector2f positon)
{
	body.setSize(size);
	body.setOrigin(size/2.0f);
	body.setTexture(texture);
	body.setFillColor(color);
	body.setPosition(positon);
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
