#include "Game.h"

using namespace std;

static const float VIEW_HEIGHT = 1080.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRation = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRation, VIEW_HEIGHT);
}

int SceneNow = 0;

Game game;

int main() 
{
	srand(time(NULL));
	game.Run();

	return 0;
} 