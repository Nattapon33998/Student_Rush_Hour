#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <map>
#include "Button.h"
#include "Teacher.h"

using namespace std;

class MainMenu
{
public:
	MainMenu();
	void MainMenuRun(sf::RenderWindow& window, float deltatime, int* scene);

	bool firstTime = true;
private:
	sf::RectangleShape Background;
	sf::Texture bgTexture;
	sf::Texture hilightTexture;

	sf::RectangleShape howToPlay;
	sf::Texture howToPlayTexture;
	bool howTo = false;
	Button* backButton;
	sf::Texture hilightGrayTexture;

	Teacher* teacherMenu;
	sf::Texture teacherTexture;
	
	Button* playButton;
	Button* howToPlayButton;
	Button* scoreButton;
	Button* exitButton;

	sf::Vector2i mousePosWindow;

	int scene;

	sf::SoundBuffer bufferBg;
	sf::Sound bgFx;
};

