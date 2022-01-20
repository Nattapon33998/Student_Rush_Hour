#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
using namespace std;
class timeBar
{
public:
	timeBar(string texturer, sf::Vector2f size, sf::Vector2f positon);

	void Draw(sf::RenderWindow& window);
	void UpdateTime(float deltatime);
	void timeBarReset();

	bool rushHour = false;
	bool completState = false;

private:
	sf::RectangleShape body;
	sf::Texture timeTexture;
	float timeCount = 0.0f;
	float positionX = 1350.0f;
};

