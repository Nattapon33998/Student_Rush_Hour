#include "Inventory.h"

Inventory::Inventory(string texture, sf::Color color, sf::Vector2f size, sf::Vector2f positon, bool secoundInventory)
{
	inventoryTexture.loadFromFile(texture);
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(positon);
	body.setTexture(&inventoryTexture);

	this->secoundInventory = secoundInventory;

	itemChipTexture.loadFromFile("pictures/UI/snacks/chip.png");
	chip.setTexture(&itemChipTexture);
	chip.setSize(sf::Vector2f(80, 90));
	chip.setPosition(sf::Vector2f(1000.0f, 935.0f));

	itemCokeTexture.loadFromFile("pictures/UI/snacks/coke.png");
	coke.setTexture(&itemCokeTexture);
	coke.setSize(sf::Vector2f(50, 90));
	coke.setPosition(sf::Vector2f(1015.0f, 935.0f)); 

	itemDounutTexture.loadFromFile("pictures/UI/snacks/dounut.png");
	dounut.setTexture(&itemDounutTexture);
	dounut.setSize(sf::Vector2f(100, 80));
	dounut.setPosition(sf::Vector2f(990.0f, 940.0f));
}

void Inventory::UpdatePhoneInventory(float deltatime)
{
	body.setFillColor(sf::Color(255, 255, 255, opacitySlot01));
	opacitySlot01 += deltatime * 10;
}

void Inventory::UdateSecoundInventory(int whichItem, bool secoundInventoryInUse)
{
	secoundInventoryCode = whichItem;
	secoundInventory = secoundInventoryInUse;
}

void Inventory::UseThisItem()
{
	body.setFillColor(sf::Color(255, 255, 255, 100));
}

void Inventory::ReuseThisItem()
{
	body.setFillColor(sf::Color(255, 255, 255, 255));
}

void Inventory::Draw(sf::RenderWindow& window)
{
	if (!secoundInventory) {
		window.draw(body);
	}
	else
	{
		window.draw(body);
		if (secoundInventoryCode == 1)
			window.draw(chip);
		else if (secoundInventoryCode == 2)
			window.draw(coke);
		else if (secoundInventoryCode == 3)
			window.draw(dounut);
	}
}