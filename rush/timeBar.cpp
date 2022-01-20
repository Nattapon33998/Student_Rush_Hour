#include "timeBar.h"

timeBar::timeBar(string texture, sf::Vector2f size, sf::Vector2f positon)
{
	timeTexture.loadFromFile(texture);
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(&timeTexture);
	body.setPosition(positon);
}

void timeBar::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void timeBar::UpdateTime(float deltatime)
{
	timeCount += deltatime;
	if(!this->rushHour&&!this->completState)
		positionX -= timeCount*0.0005;
	if(this->rushHour&&!this->completState)
		positionX -= timeCount*0.0002;


	body.setPosition(sf::Vector2f(positionX, 85));
	//printf("%f\n",timeCount);

	if (positionX <= 840.0f) {//848.0
		this->rushHour = true;
		if (positionX <= 600) {
			this->completState = true;
			cout << "END\n";
		}
	}

}

void timeBar::timeBarReset()
{
	this->rushHour = false;
	this->completState = false;
	this->timeCount = 0.0f;
	this->positionX = 1350.0f;
}
