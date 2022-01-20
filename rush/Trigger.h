#pragma once
#include <SFML/Graphics.hpp>

class Trigger
{
public:
	Trigger();
	~Trigger();

	bool CheckSpriteTrigger(sf::RectangleShape sprite1, sf::RectangleShape sprite2);
};