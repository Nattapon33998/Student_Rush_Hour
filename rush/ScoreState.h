#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Button.h"
#include <fstream>
#include <sstream>
using namespace std;

class ScoreState
{
public:
	ScoreState();
	void ScoreStateRun(sf::RenderWindow& window, int* scene);

private:
	sf::RectangleShape Background;
	sf::Texture bgTexture;
	sf::Texture hilightGrayTexture;
	Button* backButton;

	sf::Font font;

};

