#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Collider.h"
#include "Inventory.h"

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed, sf::Vector2f positon,sf::Vector2f size);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	void UpdateStu(float deltatime);

	void SleepStatus(float deltatime);
	float Sleep = 0.0f;

	void useItemUpdate(float deltatime);
	float spairTime1 = 0.0f;
	float spairTime2 = 0.0f;
	bool playerUseItem = false;
	bool useItem01 = false;
	bool coolDownItem01 = false;


	sf::Vector2f GetPosition() {return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	bool CheckSit() { return playerSit; }
	void PlayerSit();
	void PlayerStand();
	
	bool playerSit = false;
	bool study = false;

	int whichChair = 0;

	//****item 2*****//

	float itemPower;
	bool useItem02 = false;
	bool haveSecoundItem = false;
	int secoundItem;	// 1 = snack, 2 = coke, 3 = dounut, 4 = coffe
	bool coolDownItem02 = false;

	///////////////////
	void playerReset();
	

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	//*****Item Show*****//

	sf::RectangleShape phone;
	sf::Texture phoneTexture;

	///////////////////////

	//*****SoundFx*****//

	sf::SoundBuffer bufferWalk;
	sf::Sound walkFx;

	sf::SoundBuffer bufferPhone;
	sf::Sound phoneFx;

	sf::SoundBuffer bufferChip;
	sf::Sound chipFx;

	sf::SoundBuffer bufferCoke;
	sf::Sound cokeFx;

	sf::SoundBuffer bufferDounut;
	sf::Sound dounutFx;

	//walkFx.setBuffer(bufferWalk);
	//walkFx
	/////////////////////
	sf::Vector2f startPosition;
};

