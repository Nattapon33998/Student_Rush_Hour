#include "items.h"

items::items(string texture, sf::Vector2f size, sf::Vector2f positon,int item,float itemPower)
{
	power = itemPower;
	itemTexture.loadFromFile(texture);
	body.setTexture(&itemTexture);
	body.setPosition(positon);
	body.setSize(size);
	whichItem = item;  
}

void items::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void items::itemUpdate(float deltatime)
{
	this->deltatime = deltatime;
	if (coolDownToSpwan) {
		coolDown += this->deltatime;
		if (coolDown >= 20.0f) {
			coolDownToSpwan = false;
			coolDown = 0.0f;
			needReSpwan = true;
		}
	}
}

void items::changePositionToClear()
{
	body.setPosition(sf::Vector2f(-100, -100));
	coolDownToSpwan = true;
	//itemDelete = true;
}

void items::newPosition(sf::Vector2f newPosition)
{
	body.setPosition(newPosition);
}
