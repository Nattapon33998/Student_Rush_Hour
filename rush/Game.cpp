#include "Game.h"

MainMenu menuScene;
SceneState01 sceneState1;
ScoreState scoreState;

void Game::Run()
{
	static const float VIEW_HEIGHT = 1080.0f;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML", sf::Style::Close | sf::Style::Fullscreen );

	float deltaTime = 0.0f;
	float spairTime = 0.0f;
	sf::Clock clock;

	int ran;

	string playerName = "";

	while (window.isOpen())
	{

		deltaTime = clock.restart().asSeconds();
		spairTime += deltaTime;
		//deltaTime = clock.getElapsedTime().asSeconds();
		//printf("%f\n",spairTime);

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//ResizeView(window, view);
				break;
			}
			if (event.type == sf::Event::TextEntered && sceneState1.firstTime)
			{
				if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 32) {	//typing
					playerName += char(event.text.unicode);
				}
				if (event.text.unicode == 8) {									//delete
					if (!playerName.empty()) {
						playerName.pop_back();
					}
				}
				debouce db(0.05f);
				//cout << playerName;
			}
			
		}
		switch (scene)
		{
		case 0:
			menuScene.MainMenuRun(window,deltaTime,&scene);
			break;
		case 1:
			sceneState1.SceneState01_Run(window,deltaTime,&scene,&playerName);
			break;
		case 2:
			scoreState.ScoreStateRun(window, &scene);
			break;
		case 99:
			window.close();
			break;
		}
		window.display();
	}

}

/*void ResizeView(const sf::RenderWindow& window, sf::View& view) {
	float aspectRation = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRation, VIEW_HEIGHT);
}*/