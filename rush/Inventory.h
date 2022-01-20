#pragma once
#include  <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace std;

class Inventory
{
public:
	Inventory(string texture, sf::Color color, sf::Vector2f size, sf::Vector2f positon,bool secoundInventory);
	void UpdatePhoneInventory(float deltatime);
	void UdateSecoundInventory(int whichItem,bool secoundInventoryInUse);
	float opacitySlot01 = 155.0f;
	bool useInven01 = false;

	void UseThisItem();
	void ReuseThisItem();

	bool secoundInventory;
	int secoundInventoryCode = 0;


	void Draw(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	sf::Texture inventoryTexture;

	sf::RectangleShape chip;
	sf::RectangleShape coke;
	sf::RectangleShape dounut;
	sf::Texture itemChipTexture;
	sf::Texture itemCokeTexture;
	sf::Texture itemDounutTexture;
};
