#include "Teacher.h"

Teacher::Teacher(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f positon, sf::Vector2f size):
	animation(texture, imageCount, switchTime)
{
	row = 0;
	body.setSize(size);//110.0f, 132.0f
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(positon);
	body.setTexture(texture);

	bufferWarn.loadFromFile("musics/effects/warnFx.wav");
	warn.setBuffer(bufferWarn);
}

void Teacher::Update(float deltaTime,bool studentSit, bool useItem,bool rush)
{
	if (!studentSit || useItem) {
		studentStudy = false;
	}
	if (studentSit && !useItem) {
		studentStudy = true;
	}
	TeachUpdate(deltaTime,studentStudy,rush); 
	if (teach&&!alert) {
		//printf("teach\n");
		row = 1;
		animation.Update(row, deltaTime, true);
		body.setTextureRect(animation.uvRect);
	}	
	if (teach&&alert) {
		//printf("teach\n");
		row = 2;
		animation.Update(row, deltaTime, true);
		body.setTextureRect(animation.uvRect);
	}
	if (!teach) {
		//printf("not Teach\n");
		row = 0;
		animation.Update(row, deltaTime, true);
		body.setTextureRect(animation.uvRect);
	}
}

void Teacher::Draw(sf::RenderWindow& window)
{ 
	window.draw(body);
}

void Teacher::TeachUpdate(float deltatime,bool studentStudy,bool rush)
{
	flip += deltatime;

	if (!rush) {
	//	printf("not rush\n");
		if (teach) {
			if (flip >= teachTime) {
				teach = false;
				flip = 0.0f;
			}
			if (flip >= teachTime - 3) {
				alert = true;
			}
			if (flip >= teachTime - 3.2 && flip <= teachTime - 3) {
				warn.play();
			}
		}
		else
		{
			alert = false;
			if (studentStudy) {
				if (flip >= 4.0f) {
					teach = true;
					flip = 0.0f;
					teachTime = rand() % 6 + 10;
					printf("%d\n", teachTime);
				}
			}
			else// เพิ่ม !
			{ 
				angryStatus += deltatime*4;
				flip = 0.0f;
			}
		}
	}
	else
	{
	//	printf("rush\n");
		if (teach) {
			if (flip >= 7.0f) {
				teach = false;
				flip = 0.0f;
			}
			if (flip >= 4.0f) {
				alert = true;
			}
			if (flip >= 3.8f && flip <= 4.0f) {
				warn.play();
			}
		}
		else
		{
			alert = false;
			if (studentStudy) {
				if (flip >= 3.0f) {
					teach = true;
					flip = 0.0f;
				}
			}
			else// เพิ่ม !
			{
				angryStatus += deltatime * 6;
				flip = 0.0f;
			}
		}
	}
}

void Teacher::DrawAngryStatus(float angry)
{
	
}

void Teacher::teacherMenuUpdaye(float deltatime)
{
	animation.Update(rowMenu, deltatime, true);
	body.setTextureRect(animation.uvRect);
}

void Teacher::teacherReset()
{
	this->teach = true;
	this->studentStudy = false;
	this->alert = false;
	this->flip = 0.0f;

	this->angryStatus = 0.0f;
	this->rowMenu = 0;
}
