#include "Trigger.h"

Trigger::Trigger()
{
}

Trigger::~Trigger()
{
}

bool Trigger::CheckSpriteTrigger(sf::RectangleShape sprite1, sf::RectangleShape sprite2)
{
	/*sf::Rect<float> rect1 = sprite1.getGlobalBounds();
	sf::Rect<float> rect2 = sprite2.getGlobalBounds();
	*/
	/*if (rect1.intersects(rect2))
	{
		return true;
	}*/
	if (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds())) {
		return true;
	}
	else
	{
		return false;
	}
}
