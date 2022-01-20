#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"


class Platform
{
public:
	Platform(sf::Texture* texture,sf::Color color, sf::Vector2f size, sf::Vector2f positon);
	~Platform();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }  
	sf::RectangleShape GetSprite() { return body; }//*****
private:
	sf::RectangleShape body;
};

