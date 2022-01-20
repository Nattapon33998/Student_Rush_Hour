#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h" 

using namespace std;

class items
{
public:
	items(string texture, sf::Vector2f size, sf::Vector2f positon,int item,float itemPower);
	void Draw(sf::RenderWindow& window);
	float power;
	int whichItem;

	void itemUpdate(float deltatime);
	float deltatime;

	void changePositionToClear();
	void newPosition(sf::Vector2f newPosition);
	bool needReSpwan = false;

	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	sf::Texture itemTexture;

	bool coolDownToSpwan = false;
	float coolDown = 0.0f;
};

