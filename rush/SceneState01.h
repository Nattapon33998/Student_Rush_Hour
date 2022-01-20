#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "PLayer.h"
#include "SoundManager.h"
#include "Platform.h"
#include "Trigger.h"
#include "Chair.h"
#include "debouce.h"
#include "Student.h"
#include "Inventory.h"
#include "Teacher.h"
#include "items.h"
#include "timeBar.h"
#include "Button.h"
#include <sstream>
#include <fstream>
//#include "Game.h"

using namespace std;

class SceneState01
{
public:
	SceneState01();
	~SceneState01();

	Player *player;
	sf::Texture playerTexture;


	bool firstTime = true;
	//bool gameStart = false;

	sf::RectangleShape enterNameBg;
	sf::Texture enterNameTexture;
	Button* okButton;

	//*****Time*****//

	timeBar* time;
	float rushAnimation = 0.0f;
	float rushOpacity = 0.0f;
	bool stopRushStatue = false;
	bool incress = true;
	sf::RectangleShape rushHour;
	sf::Texture rushHourTexture;

	sf::SoundBuffer bufferRush;
	sf::Sound rushFx;
	bool sound = false;

	//sf::RectangleShape redBg;

	//////////////////


	//*****Students*****//

	Player* student01;
	sf::Texture studentTexture01;	

	Player* student02;
	sf::Texture studentTexture02;

	Player* student03;
	sf::Texture studentTexture03;

	Player* student04;
	sf::Texture studentTexture04;

	Player* student05;
	sf::Texture studentTexture05;

	Player* student06;
	sf::Texture studentTexture06;

	Player* student07;
	sf::Texture studentTexture07;

	Player* student08;
	sf::Texture studentTexture08;

	Player* student09;
	sf::Texture studentTexture09;

	Player* student10;
	sf::Texture studentTexture10;

	Player* student11;
	sf::Texture studentTexture11;
	
	Player* student12;
	sf::Texture studentTexture12;
	
	Player* student13;
	sf::Texture studentTexture13;
	
	Player* student14;
	sf::Texture studentTexture14;
	
	Player* student15;
	sf::Texture studentTexture15;

	Player* student16;
	sf::Texture studentTexture16;
	
	Player* student17;
	sf::Texture studentTexture17;
	
	Player* student18;
	sf::Texture studentTexture18;

	//////////////////////

	//*****Wall*****//

	Platform* wall_left;
	Platform* wall_right;
	Platform* wall_top;
	Platform* wall_bottom;

	//////////////////

	//*****Chair*****//

	Platform* chair_platform01;
	Chair* chair01;

	Platform* chair_platform02;
	Chair* chair02;

	Platform* chair_platform03;
	Chair* chair03;

	Platform* chair_platform04;
	Chair* chair04;

	///////////////////

	//*****Chair Block*****//

	Platform* chair_block_platform01;
	Chair* chair_block01;
	Platform* chair_block_platform02;
	Chair* chair_block02;

	Platform* chair_block_platform03;
	Chair* chair_block03;

	Platform* chair_block_platform04;
	Chair* chair_block04;
	Platform* chair_block_platform05;
	Chair* chair_block05;

	Platform* chair_block_platform06;
	Chair* chair_block06;

	Platform* chair_block_platform07;
	Chair* chair_block07;
	Platform* chair_block_platform08;
	Chair* chair_block08;	
	
	Platform* chair_block_platform09;
	Chair* chair_block09;
	Platform* chair_block_platform10;
	Chair* chair_block10;	
	
	Platform* chair_block_platform11;
	Chair* chair_block11;
	Platform* chair_block_platform12;
	Chair* chair_block12;

	Platform* chair_block_platform13;
	Chair* chair_block13;
	Platform* chair_block_platform14;
	Chair* chair_block14;

	Platform* chair_block_platform15;
	Chair* chair_block15;
	Platform* chair_block_platform16;
	Chair* chair_block16;	
	
	Platform* chair_block_platform17;
	Chair* chair_block17;
	Platform* chair_block_platform18;
	Chair* chair_block18;


	Platform* teacher_Table;

	/////////////////////////

	//*****Status*****//

	sf::RectangleShape z01;
	sf::RectangleShape z02;
	sf::RectangleShape z03;
	sf::RectangleShape z04;
	sf::RectangleShape z05;
	sf::RectangleShape z06;
	sf::Texture zTexture;

	sf::RectangleShape angry01;
	sf::RectangleShape angry02;
	sf::RectangleShape angry03;
	sf::RectangleShape angry04;
	sf::RectangleShape angry05;
	sf::RectangleShape angry06;
	sf::RectangleShape angry07;
	sf::RectangleShape angry08;
	sf::RectangleShape angry09;
	sf::Texture angryTexture;

	////////////////////

	sf::RectangleShape Background;
	sf::Texture bgTexture;

	//*****Inventory*****//

	Inventory* inventory01;
	Inventory* inventory02;
	//sf::Texture inventoryTexture01;
	bool useSomeItem = false;

	///////////////////////

	//*****Teacher*****//

	Teacher* teacher;
	sf::Texture teacherTexture;

	/////////////////////

	//*****Items*****//

	float clearX = -100;
	float clearY = 0;

	float spwanX[17] = { 200,650,650,250,230,650,1000,250,230,1350,650,1360,1700,980,970,1680,1670 };
	float spwanY[17] = { 600,400,600,900,700,800,500 ,400,800,850 ,700,700 ,750 ,650,800,600 ,950 };
	bool itemInScene[3] = { true,true,true };
	int itemPositionSet[3];
	
	items* item[3];

	int ramdomPositionSpwan(int itemNum);

	///////////////////

	//*****SoundFx*****//

	sf::SoundBuffer bufferSitStand;
	sf::Sound sitStandFx;

	sf::SoundBuffer bufferBg;
	sf::Sound bgFx;

	/////////////////////

	//*****Pause*****//


	bool pause = false;
	sf::RectangleShape pauseBg;
	sf::Texture pauseBgTexture;

	sf::Texture hilightTexture;

	Button* exitButton;
	Button* menuButton;

	////////////////////

	//*****EndState****//

	string playerName;
	int score = 0;

	sf::SoundBuffer bufferComplet;
	sf::Sound completFx;

	sf::RectangleShape endBg;
	sf::Texture endBgTexture;
	Button* menuEndButton;

	bool firstComplet = true;
	bool writeComplet = false;

	sf::Text showScore;

	////////////////////

	//*****Game Over*****//

	sf::RectangleShape overBg;
	sf::Texture overBgTexture;
	bool gameOver = false;
	Button* overButton;

	sf::SoundBuffer bufferOver;
	sf::Sound overFx;
	///////////////////////

	//*****PlayerName*****//

	//stringstream ss;
	sf::Text previewName;
	sf::Font font;

	string clearStr = "";

	////////////////////////

	//*****FaceBack*****//

	sf::RectangleShape faceBlackBg;
	float faceBlackAnimation = 0.0f;
	bool faceBlack = false;
	bool faceBlackIncress = true;

	//////////////////////

	void SceneState01_Run(sf::RenderWindow& window,float deltatime,int *scene,string* playerName);
	bool SceneState01Active = false;

	void reset(string* playerName);
};

