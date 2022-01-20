#pragma once
#include <SFML/Graphics.hpp>
class debouce
{
public:
	debouce(float sec);
	~debouce();
private:
	sf::Clock clock;
	float Time = 0.0f;	
};

