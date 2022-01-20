#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
class Button
{
public:
	Button(sf::Vector2f size,sf::Vector2f position,sf::Vector2f hilightSize,sf::Vector2f hilightPosition, sf::Texture* hilightTexture,int changeScene);
	void updateButtonChangeScene(sf::RenderWindow& window,int*scene);

	bool checkClick();
	bool click = false;;
private:
	sf::RectangleShape button;
	sf::RectangleShape hilight;

	sf::Sound clickFx;
	sf::Sound hilightFx;

	sf::SoundBuffer bufferClick;
	sf::SoundBuffer bufferHilight;

	sf::Vector2f size;
	sf::Vector2f position;
	sf::Vector2f hilightSize;
	sf::Vector2f hilightPosition;

	bool cursorIn = false;
	int changeScene;
};