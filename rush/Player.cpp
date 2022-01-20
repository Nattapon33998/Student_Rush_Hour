#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f positon, sf::Vector2f size):
	animation(texture,imageCount,switchTime)
{
	startPosition = positon;
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(size);//110.0f, 132.0f
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(positon);
	body.setTexture(texture);

	bufferWalk.loadFromFile("musics/effects/walkFx.wav");
	walkFx.setBuffer(bufferWalk);
	walkFx.setLoop(true);
	///nwalkFx.setVolume(100.0f);

	bufferPhone.loadFromFile("musics/effects/phoneFx.wav");
	phoneFx.setBuffer(bufferPhone);

	bufferChip.loadFromFile("musics/effects/snackFx.wav");
	chipFx.setBuffer(bufferChip);

	bufferCoke.loadFromFile("musics/effects/cokeFx.wav");
	cokeFx.setBuffer(bufferCoke);

	bufferDounut.loadFromFile("musics/effects/dounutFx.wav");
	dounutFx.setBuffer(bufferDounut);
/*	phoneTexture.loadFromFile("pictures/Object/phone/Phone01.png");
	phone.setTexture(&phoneTexture);
	phone.setSize(sf::Vector2f(20,30));
	//phone.setPosition(body.getPosition);*/
} 

Player::~Player() 
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (!playerSit) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			movement.x -= speed * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			movement.x += speed * deltaTime;
		}
 		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			movement.y -= speed * deltaTime;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			movement.y += speed * deltaTime;
		}

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			speed = 300;
		}
		if (not sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			speed = 150;
		}*/

		if (movement.x == 0.0f) {
			row = 0;
			walkFx.pause();
		}
		if (movement.y == 0.0f) {
			walkFx.pause();
		}
		if (movement.y <= -0.05f) {
			row = 2;
		}
		if (movement.y != 0.0f) {
			walkFx.play();
		}
		if (movement.x != 0.0f)
		{
			walkFx.play();
			row = 1;

			if (movement.x > 0.0f) {
				faceRight = true;
			}
			else
			{
				faceRight = false;
			}
		}
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}
	if(playerSit&&!useItem01) {
		row = 2;

		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}

	if(useItem01)
	{
		row = 3;
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}
	if(useItem02)
	{
		row = secoundItem + 3;
		//printf("%d\n", row);
		
		animation.Update(row, deltaTime, faceRight);
		body.setTextureRect(animation.uvRect);
		body.move(movement);
	}

	//phone.setPosition(sf::Vector2f(body.getPosition.x));

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);

	//window.draw(phone);
}

void Player::UpdateStu(float deltatime)
{
	animation.Update(row, deltatime, faceRight);
	body.setTextureRect(animation.uvRect);
}

void Player::SleepStatus(float deltatime)
{
	if (playerSit&&study) {
		Sleep += deltatime*1.2;
		//printf("%f\n", Sleep);
	}
	else
	{
		Sleep += deltatime / 0.8;
		//printf("%f\n",Sleep);
	}
}

void Player::useItemUpdate(float deltatime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && !useItem01 && !useItem02) {
		phoneFx.play();
		this->playerUseItem = true;// ใช้เทียบไป fn หลัก
		if (Sleep < 8.0f) {
			Sleep = 0.0f;
		}
		else
		{
			Sleep -= 8.0f;
		}
		useItem01 = true;
		coolDownItem01 = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2) && !useItem02 && !useItem01 && haveSecoundItem) {
		this->playerUseItem = true;// ใช้เทียบไป fn หลัก

		printf("%d\n", secoundItem);

		if (secoundItem == 1)
			chipFx.play();
		if (secoundItem == 2)
			cokeFx.play();
		if (secoundItem == 3)
			dounutFx.play();

		if (Sleep < itemPower) {
			Sleep = 0.0f;
		}
		else
		{
			Sleep -= itemPower;
		}
		useItem02 = true;
		coolDownItem02 = true;
		
		//secoundItem = 0;
		itemPower = 0;
		
	}


	if (coolDownItem01) {
		spairTime1 += deltatime;
		if (spairTime1 > 15.0f) {
			coolDownItem01 = false;
			spairTime1 = 0.0f;
		}
		if (spairTime1 > 3.0f) {
			useItem01 = false;
			this->playerUseItem = false;
		}
	}
	if (coolDownItem02) {
		spairTime2 += deltatime;
		if (spairTime2 > 3.0f) {
			useItem02 = false;
			haveSecoundItem = false;
			coolDownItem02 = false;
			this->playerUseItem = false;
			secoundItem = 0;
			spairTime2 = 0.0f;
		}
	}
}

void Player::PlayerSit()
{
	walkFx.pause();
	playerSit = true;
	switch (whichChair)
	{
	case 1:
		body.setPosition(517.0f, 680.0f); // y - 45
		break;
	case 2:
		body.setPosition(877.0f, 460.0f);	
		break;
	case 3:
		body.setPosition(1140.0f, 895.0f);
		break;	
	case 4:
		body.setPosition(1600.0f, 630.0f);
		break;
	}
}

void Player::PlayerStand()
{
	playerSit = false;
	switch (whichChair)
	{
	case 1:
		body.setPosition(517.0f, 725.0f);
		break;
	case 2:
		body.setPosition(877.0f, 505.0f);
		break;	
	case 3:
		body.setPosition(1140.0f, 940.0f);
		break;
	case 4:
		body.setPosition(1600.0f, 675.0f);
		break;
	}
}

void Player::playerReset()
{
	this->Sleep = 0.0f;
	this->playerSit = false;
	this->study = false;
	this->whichChair = 0;
	this->body.setPosition(startPosition);
	this->spairTime1 = 0.0f;
	this->spairTime2 = 0.0f;
	this->playerUseItem = false;
	this->useItem01 = false;
	this->coolDownItem01 = false;
	this->itemPower = 0.0f;
	this->useItem02 = false;
	this->haveSecoundItem = false;
	this->secoundItem = 0;
	this->coolDownItem02 = false;
}
