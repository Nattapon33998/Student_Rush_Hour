#pragma once
#include  <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Collider.h"
//#include "timeBar.h"

class Teacher
{
public:
	Teacher(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f positon, sf::Vector2f size);
	~Teacher();


	void Update(float deltaTime,bool studentSit,bool useItem,bool rush);
	void Draw(sf::RenderWindow& window);

	void TeachUpdate(float deltatime,bool studentStudy,bool rush);
	void DrawAngryStatus(float angey);
	bool teach = true;
	bool studentStudy = false;
	bool alert = false;
	float flip = 0.0f;

	float angryStatus = 0.0f;

	void teacherMenuUpdaye(float deltatime);
	void teacherReset();

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	bool checkStudentSit = true;

	int rowMenu = 0;

	sf::Sound warn;
	sf::SoundBuffer bufferWarn;
	
	int teachTime = 13;
};

