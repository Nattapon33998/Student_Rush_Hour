#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "Platform.h"
#include "Trigger.h"
#include "Player.h"
#include "Collider.h"

using namespace std;

class Chair
{
public:
	Chair(string texture, sf::Color color, sf::Vector2f size, sf::Vector2f positon);
	~Chair();

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
	sf::RectangleShape GetSprite() { return body; }//*****
	 

private:
	sf::RectangleShape body;
	sf::Texture chairTexture;

};

