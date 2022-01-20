#include "ScoreState.h"

ScoreState::ScoreState()
{
	bgTexture.loadFromFile("pictures/UI/ScoreState/score.png");
	Background.setTexture(&bgTexture);
	Background.setPosition(sf::Vector2f(0, 0));
	Background.setSize(sf::Vector2f(1920, 1080));

	hilightGrayTexture.loadFromFile("pictures/UI/Menu/hilightGray.png");
	backButton = new Button(sf::Vector2f(180, 70), sf::Vector2f(870, 955), sf::Vector2f(190, 15), sf::Vector2f(870, 1020), &hilightGrayTexture, 0);

	font.loadFromFile("font/Brush_Script_Regular.ttf");
}

void ScoreState::ScoreStateRun(sf::RenderWindow& window, int* scene)
{
	window.draw(Background);
	backButton->updateButtonChangeScene(window, scene);


	std::vector<std::pair<std::string, int>> getScore;
	sf::Text rankNameText;
	sf::Text rankScoreText;

	std::ifstream getdata("Data/Score.data");
	while (getdata.is_open()) {

		std::string name = "";
		std::string score = "";

		getdata >> name;
		getdata >> score;

		std::stringstream string_to_int(score);
		int buff_int;
		string_to_int >> buff_int;

		getScore.push_back(std::make_pair(name, buff_int));

		if (name == "") {
			getdata.close();
		}
	}
	//std::cout << "[LOG] Read File.....Complete!" << "\n";
	int i, j;
	for (i = 0; i < getScore.size() - 1; i++) {
		for (j = 0; j < getScore.size() - 2; j++) {
			if (getScore[j].second < getScore[j + 1].second) {
				swap(getScore[j], getScore[j + 1]);
			}
		}
	}
	//std::cout << "[LOG] Sort File.....Complete!" << "\n";
	//std::cout << "[SYSTEM] Load Score File........Complete!" << "\n";

	// set loop rap
	size_t loop_size = getScore.size() - 1;
	if (loop_size > 5) {
		loop_size = 5;
	}

	//set name text
	std::string name = "";
	std::string name_list = "";
	for (int i = 0; i < loop_size; i++) {
		name = getScore[i].first;
		name_list += name + "\n";
	}
	rankNameText.setString(name_list);

	//set score text
	int score;
	std::string score_list = "";
	for (int i = 0; i < loop_size; i++) {
		score = getScore[i].second;
		std::stringstream int_to_string;
		int_to_string << score;

		score_list += int_to_string.str() + "\n";
	}
	rankScoreText.setString(score_list);

	//set name,score text display
	rankNameText.setCharacterSize(60);
	rankScoreText.setCharacterSize(60);

	rankNameText.setFont(font);
	rankScoreText.setFont(font);

	rankNameText.setLineSpacing(1.45f);
	rankScoreText.setLineSpacing(1.45f);

	rankNameText.setFillColor(sf::Color::Black);
	rankScoreText.setFillColor(sf::Color::Black);

	rankNameText.setPosition(sf::Vector2f(370,360));
	rankScoreText.setPosition(sf::Vector2f(1400, 360));

	window.draw(rankNameText);
	window.draw(rankScoreText);


}
