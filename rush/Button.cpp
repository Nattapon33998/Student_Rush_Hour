#include "Button.h"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Vector2f hilightSize, sf::Vector2f hilightPosition, sf::Texture* hilightTexture,int changeScene)
{
	button.setSize(size);
	button.setPosition(position);
	button.setFillColor(sf::Color(255, 255, 255, 0));

	hilight.setTexture(hilightTexture);
	hilight.setSize(hilightSize);
	hilight.setPosition(hilightPosition);

	this->size = size;
	this->position = position;
	this->hilightSize = hilightSize;
	this->hilightPosition = hilightPosition;

	this->bufferClick.loadFromFile("musics/effects/sitStandFx.wav");
	this->bufferHilight.loadFromFile("musics/effects/grabFx.wav");

	clickFx.setBuffer(this->bufferClick); 
	hilightFx.setBuffer(this->bufferHilight);

	this->changeScene = changeScene;
}

void Button::updateButtonChangeScene(sf::RenderWindow& window, int* scene)
{
	window.draw(this->button);
	if (sf::Mouse::getPosition(window).x >= position.x && sf::Mouse::getPosition(window).x <= position.x + size.x && sf::Mouse::getPosition(window).y >= position.y && sf::Mouse::getPosition(window).y <= position.y+size.y)
	{
	window.draw(this->hilight);
		if (!cursorIn) {
			if (!hilightFx.getStatus()) {
				hilightFx.play();
			}
			//printf("%b",hilightFx.getStatus());
			cout << hilightFx.getStatus();
			cursorIn = true;
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			click = true;
			clickFx.play();
			*scene = this->changeScene;

		}
	}
	else
	{
		cursorIn = false;
	}
}

bool Button::checkClick()
{
	return click;
}
