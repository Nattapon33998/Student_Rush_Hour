#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class SoundManager
{
private:
	sf::SoundBuffer bgMusic;
	sf::Sound bg_Sound;
public:
	SoundManager(int changebgSound);
	void playbgSound();
};

