#include "MainMenu.h"

MainMenu::MainMenu()
{
	bgTexture.loadFromFile("pictures/UI/Menu/menu.png");
	//Background(sf::Vector2f(1920.0f, 1080.0f));
	Background.setTexture(&bgTexture);
	Background.setPosition(0.0f, 0.0f);
	Background.setSize(sf::Vector2f(1920.0f, 1080.0f));

	hilightTexture.loadFromFile("pictures/UI/Menu/hilight.png");
	hilightGrayTexture.loadFromFile("pictures/UI/Menu/hilightGray.png");

	playButton = new Button(sf::Vector2f(200,50),sf::Vector2f(750,230),sf::Vector2f(220,40),sf::Vector2f(750, 270),&hilightTexture,1);
	howToPlayButton = new Button(sf::Vector2f(400,50),sf::Vector2f(650,340),sf::Vector2f(420,40),sf::Vector2f(650, 385),&hilightTexture,0);
	scoreButton = new Button(sf::Vector2f(400,50),sf::Vector2f(650,460),sf::Vector2f(420,50),sf::Vector2f(650, 500),&hilightTexture,2);
	exitButton = new Button(sf::Vector2f(100,50),sf::Vector2f(300,510),sf::Vector2f(100,30),sf::Vector2f(300, 540),&hilightTexture,99);

	teacherTexture.loadFromFile("pictures/Characters/Teachers/teacherAnimation01.png");
	teacherMenu = new Teacher(&teacherTexture, sf::Vector2u(5, 3), 0.7f, sf::Vector2f(1400.0f, 550.0f), sf::Vector2f(466.0f, 500.0f));

	if (!howToPlayTexture.loadFromFile("pictures/UI/Menu/howTo.png"))
		cout << "error";
	howToPlay.setTexture(&howToPlayTexture);
	howToPlay.setPosition(sf::Vector2f(0, 0));
	howToPlay.setSize(sf::Vector2f(1920, 1080));
	backButton = new Button(sf::Vector2f(200,70),sf::Vector2f(870,930),sf::Vector2f(220,15),sf::Vector2f(870, 1000),&hilightGrayTexture,0);

	bufferBg.loadFromFile("musics/musics/music_menu.wav");
	bgFx.setBuffer(bufferBg);
	bgFx.setLoop(true);
}

void MainMenu::MainMenuRun(sf::RenderWindow& window, float deltatime, int* scene)
{

	if (firstTime) {
		bgFx.play();//*************************************
	}
	firstTime = false;

	teacherMenu->teacherMenuUpdaye(deltatime);
	//*scene = this->scene;
	//this->scene = *scene;
	/*mousePosWindow = sf::Mouse::getPosition(window);  
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		*scene = 1; 
	}
	playButton->updateButtonChangeScene(window,&this->scene);*/
	window.draw(Background);
	if (!howTo) {
		playButton->updateButtonChangeScene(window,scene);
		howToPlayButton->updateButtonChangeScene(window,scene);
		scoreButton->updateButtonChangeScene(window,scene);
		exitButton->updateButtonChangeScene(window,scene);
	}

	teacherMenu->Draw(window);

	if (howToPlayButton->checkClick() && !howTo) {
		howTo = true;
		backButton->click = false;
	}

	if (howTo) {
		window.draw(howToPlay);
		backButton->updateButtonChangeScene(window,scene);
		if (backButton->checkClick() && howTo) {
			howTo = false;
			howToPlayButton->click = false;
		}
	}


	if (playButton->checkClick()) {
		bgFx.stop();
		playButton->click = false;
		firstTime = true;
	}
}
