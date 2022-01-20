#include "SceneState01.h"

SceneState01::SceneState01()
{
	playerTexture.loadFromFile("pictures/Characters/Player/playerAnimation.png");
	player = new Player(&playerTexture, sf::Vector2u(4, 8), 0.3f, 150.0f,sf::Vector2f(950.0f,540.0f),sf::Vector2f(110.0f, 132.0f));

	font.loadFromFile("font/Brush_Script_Regular.ttf");
	previewName.setFont(font);
	previewName.setFillColor(sf::Color::White);
	previewName.setPosition(sf::Vector2f(930,530));
	previewName.setCharacterSize(50);

	showScore.setFont(font);
	showScore.setFillColor(sf::Color::White);
	showScore.setPosition(sf::Vector2f(1250, 505));
	showScore.setCharacterSize(80);
	//*****Time*****//

	time = new timeBar("pictures/UI/State01/timeStatus.png",sf::Vector2f(60,70),sf::Vector2f(1350, 85));//statr 1350,85 :: rushHour 848,85 :: End 600,85
	rushHourTexture.loadFromFile("pictures/UI/State01/rushHour.png");
	rushHour.setTexture(&rushHourTexture); 
	rushHour.setSize(sf::Vector2f(1920, 1080));
	rushHour.setPosition(sf::Vector2f(0,0));
	rushHour.setFillColor(sf::Color(255, 255, 255, 0));

	bufferRush.loadFromFile("musics/effects/rushFx.wav");
	rushFx.setBuffer(bufferRush);
	rushFx.setVolume(20.0f);
	
	//redBg.setPosition(sf::Vector2f(960, 540));
	//redBg.setSize(sf::Vector2f(1920, 1080));
	//redBg.setFillColor(sf::Color(220,31,38,0));

	//////////////////

	//*****BlackFace*****//

	faceBlackBg.setFillColor(sf::Color(0, 0, 0, 0));
	faceBlackBg.setPosition(0, 0);
	faceBlackBg.setSize(sf::Vector2f(1920, 1080));

	///////////////////////
	

	//*****Pause*****//
	pauseBgTexture.loadFromFile("pictures/UI/Menu/pause.png");
	pauseBg.setTexture(&pauseBgTexture);
	pauseBg.setPosition(sf::Vector2f(0, 0));
	pauseBg.setSize(sf::Vector2f(1920, 1080));

	hilightTexture.loadFromFile("pictures/UI/Menu/hilight.png");
	exitButton = new Button(sf::Vector2f(130, 50), sf::Vector2f(1050, 550), sf::Vector2f(150, 30), sf::Vector2f(1050, 590), &hilightTexture, 99);
	menuButton = new Button(sf::Vector2f(130, 50), sf::Vector2f(750, 550), sf::Vector2f(150, 30), sf::Vector2f(750, 590), &hilightTexture, 0);

	/////////////////////

	//*****Items*****//
/*	for (int i = 0; i < 3; i++) {
		itemPositionSet[i] = 0;
	}*/


	int x;
	x = ramdomPositionSpwan(0);
	//printf("%d",x);
	item[0] = new items("pictures/UI/snacks/chip.png",sf::Vector2f(70,80),sf::Vector2f(spwanX[x],spwanY[x]),1,10);
	x = ramdomPositionSpwan(1);
	//printf("%d",x);
	item[1] = new items("pictures/UI/snacks/coke.png",sf::Vector2f(30,50),sf::Vector2f(spwanX[x],spwanY[x]),2,10);
	x = ramdomPositionSpwan(2);
	//printf("%d\n",x);
	item[2] = new items("pictures/UI/snacks/dounut.png",sf::Vector2f(60,50),sf::Vector2f(spwanX[x],spwanY[x]),3,10);
	 
	///////////////////

	//*****SoundFx*****//

	bufferSitStand.loadFromFile("musics/effects/sitStandFx.wav");
	sitStandFx.setBuffer(bufferSitStand);

	bufferBg.loadFromFile("musics/musics/music_gameState.wav");
	bgFx.setBuffer(bufferBg);
	bgFx.setVolume(50.0f);
	bgFx.setLoop(true);


	/////////////////////


	//*****Students*****//

	studentTexture01.loadFromFile("pictures/Characters/Students/Animation/Boy01.png");
	student01 = new Player(&studentTexture01, sf::Vector2u(10, 1), 2.7f, 150.0f, sf::Vector2f(412.0f, 460.0f),sf::Vector2f(70.0f,132.0));

	studentTexture02.loadFromFile("pictures/Characters/Students/Animation/Boy02.png");
	student02 = new Player(&studentTexture02, sf::Vector2u(10, 1), 2.82f, 150.0f, sf::Vector2f(517.0f, 460.0f), sf::Vector2f(70.0f, 132.0));

	studentTexture03.loadFromFile("pictures/Characters/Students/Animation/Boy03.png");
	student03 = new Player(&studentTexture03, sf::Vector2u(10, 1), 1.5f, 150.0f, sf::Vector2f(412.0f, 680.0f), sf::Vector2f(70.0f, 132.0));

	studentTexture04.loadFromFile("pictures/Characters/Students/Animation/Boy04.png");
	student04 = new Player(&studentTexture04, sf::Vector2u(12, 1), 2.3f, 150.0f, sf::Vector2f(412.0f, 910.0f), sf::Vector2f(100.0f, 140.0));

	studentTexture05.loadFromFile("pictures/Characters/Students/Animation/Girl02.png");
	student05 = new Player(&studentTexture05, sf::Vector2u(12, 1), 2.1f, 150.0f, sf::Vector2f(517.0f, 900.0f), sf::Vector2f(70.0f, 132.0));
	
	studentTexture06.loadFromFile("pictures/Characters/Students/Animation/Girl01.png");
	student06 = new Player(&studentTexture06, sf::Vector2u(7, 1), 2.1f, 150.0f, sf::Vector2f(772.0f, 460.0f), sf::Vector2f(70.0f, 132.0));
	
	studentTexture07.loadFromFile("pictures/Characters/Students/Animation/Boy05.png");
	student07 = new Player(&studentTexture07, sf::Vector2u(12, 1), 1.9f, 150.0f, sf::Vector2f(768.0f, 665.0f), sf::Vector2f(90.0f, 142.0));

	studentTexture08.loadFromFile("pictures/Characters/Students/Animation/Girl03.png");
	student08 = new Player(&studentTexture08, sf::Vector2u(6, 1), 1.7f, 150.0f, sf::Vector2f(877.0f, 665.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture09.loadFromFile("pictures/Characters/Students/Animation/Girl04.png");
	student09 = new Player(&studentTexture09, sf::Vector2u(12, 1), 1.7f, 150.0f, sf::Vector2f(775.0f, 890.0f), sf::Vector2f(70.0f, 142.0));
	
	studentTexture10.loadFromFile("pictures/Characters/Students/Animation/Boy06.png");
	student10 = new Player(&studentTexture10, sf::Vector2u(10, 1), 2.0f, 150.0f, sf::Vector2f(880.0f, 890.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture11.loadFromFile("pictures/Characters/Students/Animation/Boy03.png");
	student11 = new Player(&studentTexture11, sf::Vector2u(10, 1), 2.5f, 150.0f, sf::Vector2f(1137.0f, 460.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture12.loadFromFile("pictures/Characters/Students/Animation/Girl04.png");
	student12 = new Player(&studentTexture12, sf::Vector2u(12, 1), 2.3f, 150.0f, sf::Vector2f(1242.0f, 460.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture13.loadFromFile("pictures/Characters/Students/Animation/Boy01.png");
	student13 = new Player(&studentTexture13, sf::Vector2u(10, 1), 2.0f, 150.0f, sf::Vector2f(1137.0f, 670.0f), sf::Vector2f(70.0f, 132.0));
	
	studentTexture14.loadFromFile("pictures/Characters/Students/Animation/Boy04.png");
	student14 = new Player(&studentTexture14, sf::Vector2u(12, 1), 2.7f, 150.0f, sf::Vector2f(1242.0f, 670.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture15.loadFromFile("pictures/Characters/Students/Animation/Boy05.png");
	student15 = new Player(&studentTexture15, sf::Vector2u(12, 1), 2.7f, 150.0f, sf::Vector2f(1245.0f, 895.0f), sf::Vector2f(80.0f, 142.0));
	
	studentTexture16.loadFromFile("pictures/Characters/Students/Animation/Girl03.png");
	student16 = new Player(&studentTexture16, sf::Vector2u(6, 1), 2.4f, 150.0f, sf::Vector2f(1495.0f, 630.0f), sf::Vector2f(70.0f, 132.0));
	
	studentTexture17.loadFromFile("pictures/Characters/Students/Animation/Girl01.png");
	student17 = new Player(&studentTexture17, sf::Vector2u(7, 1), 2.7f, 150.0f, sf::Vector2f(1500.0f, 840.0f), sf::Vector2f(70.0f, 132.0));
	
	studentTexture18.loadFromFile("pictures/Characters/Students/Animation/Girl02.png");
	student18 = new Player(&studentTexture18, sf::Vector2u(12, 1), 2.5f, 150.0f, sf::Vector2f(1605.0f, 840.0f), sf::Vector2f(70.0f, 132.0));


	//////////////////////
	

	/////////Object//////////////////////
	sf::CircleShape shape(50.f);
	sf::FloatRect shapeCollider = shape.getGlobalBounds();
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(50.f, 30.f);
	//*********************************//

	/////////Background//////////////////

	bgTexture.loadFromFile("pictures/UI/State01/state01.png");
	//Background(sf::Vector2f(1920.0f, 1080.0f));
	Background.setTexture(&bgTexture);
	Background.setPosition(0.0f, 0.0f);
	Background.setSize(sf::Vector2f(1920.0f, 1080.0f));

	//*********************************//

	//*****Status*****//

	zTexture.loadFromFile("pictures/UI/State01/z01.png");
	z01.setTexture(&zTexture);
	z01.setSize(sf::Vector2f(50.0f,50.0f));
	z02.setTexture(&zTexture);
	z02.setSize(sf::Vector2f(75.0f,75.0f));
	z03.setTexture(&zTexture);
	z03.setSize(sf::Vector2f(100.0f,100.0f));
	z04.setTexture(&zTexture);
	z04.setSize(sf::Vector2f(50.0f,50.0f));
	z05.setTexture(&zTexture);
	z05.setSize(sf::Vector2f(75.0f,75.0f));
	z06.setTexture(&zTexture);
	z06.setSize(sf::Vector2f(100.0f,100.0f));

	z01.setPosition(1470.0f,75.0f);
	z02.setPosition(1515.0f,51.0f);
	z03.setPosition(1580.0f,27.0f);
	z04.setPosition(1675.0f,75.0f);
	z05.setPosition(1720.0f,51.0f);
	z06.setPosition(1785.0f,27.0f);

	angryTexture.loadFromFile("pictures/UI/State01/angry.png");

	angry01.setTexture(&angryTexture);
	angry01.setSize(sf::Vector2f(50.0f, 100.0f));
	angry02.setTexture(&angryTexture);
	angry02.setSize(sf::Vector2f(50.0f, 100.0f));
	angry03.setTexture(&angryTexture);
	angry03.setSize(sf::Vector2f(50.0f, 100.0f));
	angry04.setTexture(&angryTexture);
	angry04.setSize(sf::Vector2f(50.0f, 100.0f));
	angry05.setTexture(&angryTexture);
	angry05.setSize(sf::Vector2f(50.0f, 100.0f));
	angry06.setTexture(&angryTexture);
	angry06.setSize(sf::Vector2f(50.0f, 100.0f));
	angry07.setTexture(&angryTexture);
	angry07.setSize(sf::Vector2f(50.0f, 100.0f));
	angry08.setTexture(&angryTexture);
	angry08.setSize(sf::Vector2f(50.0f, 100.0f));


	angry01.setPosition(45.0f, 30.0f);
	angry02.setPosition(95.0f, 30.0f);
	angry03.setPosition(145.0f, 30.0f);
	angry04.setPosition(195.0f, 30.0f);
	angry05.setPosition(245.0f, 30.0f);
	angry06.setPosition(295.0f, 30.0f);
	angry07.setPosition(345.0f, 30.0f);
	angry08.setPosition(395.0f, 30.0f);

	////////////////////

	int opacity = 0;

	//************Wall************


	wall_left = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 1080.0f), sf::Vector2f(80.0f, 540.0f));
	wall_right = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 1080.0f), sf::Vector2f(1840.0f, 540.0f));
	wall_top = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(1920.0f, 100.0f), sf::Vector2f(960.0f, 150.0f));
	wall_bottom = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(1920.0f, 100.0f), sf::Vector2f(960.0f, 1120.0f));

	///////////////////////////////////

	//**********Chair CanSit***************

	chair_platform01 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(517.0f, 640.0f));
	chair01 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(517.0f, 725.0f));

	chair_platform02 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(877.0f, 420.0f));
	chair02 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(877.0f, 505.0f));

	chair_platform03 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1140.0f, 855.0f));
	chair03 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1140.0f, 940.0f));

	chair_platform04 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1600.0f, 590.0f));
	chair04 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1600.0f, 675.0f));

	//////////////////////////////////////

	//*****Chair Block*****// //  insame row y +  85, x + 105 : other row y + 220

	chair_block_platform01 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(412.0f, 420.0f));
	chair_block01 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(412.0f, 505.0f));
	chair_block_platform02 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(517.0f, 420.0f));
	chair_block02 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(517.0f, 505.0f));

	chair_block_platform03 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(412.0f, 640.0f));
	chair_block03 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(412.0f, 725.0f));

	chair_block_platform04 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(412.0f, 860.0f));
	chair_block04 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(412.0f,945.0f));
	chair_block_platform05 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(517.0f, 860.0f));
	chair_block05 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(517.0f, 945.0f));

	chair_block_platform06 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(772.0f, 420.0f));
	chair_block06 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(772.0f, 505.0f));

	chair_block_platform07 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(772.0f, 630.0f));
	chair_block07 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(772.0f, 715.0f));
	chair_block_platform08 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(877.0f, 630.0f));
	chair_block08 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(877.0f, 715.0f));

	chair_block_platform09 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(775.0f, 855.0f));
	chair_block09 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(775.0f, 940.0f));
	chair_block_platform10 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(880.0f, 855.0f));
	chair_block10 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(880.0f, 940.0f));
	
	chair_block_platform11 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1137.0f, 420.0f));
	chair_block11 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1137.0f, 505.0f));
	chair_block_platform12 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1242.0f, 420.0f));
	chair_block12 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1242.0f, 505.0f));

	chair_block_platform13 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1137.0f, 630.0f));
	chair_block13 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1137.0f, 715.0f));
	chair_block_platform14 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1242.0f, 630.0f));
	chair_block14 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1242.0f, 715.0f));

	chair_block_platform15 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1242.0f, 855.0f));
	chair_block15 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1245.0f, 940.0f));

	chair_block_platform16 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1495.0f, 590.0f));
	chair_block16 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1495.0f, 675.0f));

	chair_block_platform17 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1500.0f, 800.0f));
	chair_block17 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1500.0f, 885.0f));
	chair_block_platform18 = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(100.0f, 40.0f), sf::Vector2f(1605.0f, 800.0f));
	chair_block18 = new Chair("pictures/Object/StudentChair/StudentChairBack.png", sf::Color(255, 255, 255, 255), sf::Vector2f(70.0f, 70.0f), sf::Vector2f(1605.0f, 885.0f));

	teacher_Table = new Platform(nullptr, sf::Color(255, 255, 255, opacity), sf::Vector2f(300.0f, 20.0f), sf::Vector2f(1650.0f, 300.0f));

	///////////////////////// 

	//////////Sound//////////////////////

	//SoundManager* sound = new SoundManager(2);

	/////////////////////////////////////

	//*****Inventory*****//

	inventory01 = new Inventory("pictures/UI/State01/inventory01.png", sf::Color(255, 255, 255, 255),sf::Vector2f(120.0f,150.0f),sf::Vector2f(880.0f,1000.0f),false);
	inventory02 = new Inventory("pictures/UI/State01/inventory02.png", sf::Color(255, 255, 255, 255),sf::Vector2f(120.0f,150.0f),sf::Vector2f(1040.0f,1000.0f),true);

	///////////////////////

	//*****Teacher*****//
	teacherTexture.loadFromFile("pictures/Characters/Teachers/teacherAnimation01.png");
	teacher = new Teacher(&teacherTexture, sf::Vector2u(5, 3), 0.5f, sf::Vector2f(800.0f, 270.0f), sf::Vector2f(142.0f, 160.0));

	////////////////////

	//*****Items*****//
	//item01 = new items();

	//*****End*****//

	endBgTexture.loadFromFile("pictures/UI/Menu/cer.png");
	endBg.setTexture(&endBgTexture);
	endBg.setPosition(sf::Vector2f(0, 0));
	endBg.setSize(sf::Vector2f(1920, 1080));
	menuEndButton = new Button(sf::Vector2f(250, 50), sf::Vector2f(1180, 670), sf::Vector2f(250, 30), sf::Vector2f(1180, 710), &hilightTexture, 0);

	bufferComplet.loadFromFile("musics/effects/successFx.wav");
	completFx.setBuffer(bufferComplet);

	////////////////

	//*****EnterName****///
	enterNameTexture.loadFromFile("pictures/UI/Menu/enterName.png");
	enterNameBg.setTexture(&enterNameTexture);
	enterNameBg.setPosition(sf::Vector2f(0, 0));
	enterNameBg.setSize(sf::Vector2f(1920, 1080));
	okButton = new Button(sf::Vector2f(80, 30), sf::Vector2f(950, 650), sf::Vector2f(80, 30), sf::Vector2f(950, 675), &hilightTexture, 1);
	//////////////////////

	//*****Game Over*****//

	overBgTexture.loadFromFile("pictures/UI/Menu/over.png");
	overBg.setTexture(&overBgTexture);
	overBg.setPosition(sf::Vector2f(0, 0));
	overBg.setSize(sf::Vector2f(1920, 1080));
	overButton = new Button(sf::Vector2f(80, 30), sf::Vector2f(950, 650), sf::Vector2f(80, 30), sf::Vector2f(950, 675), &hilightTexture, 0);
	
	bufferOver.loadFromFile("musics/effects/failFx.wav");
	overFx.setBuffer(bufferOver);

	///////////////////////
}


SceneState01::~SceneState01()
{
	delete player;
}


int SceneState01::ramdomPositionSpwan(int itemNum)
{
	int count = 0;
	bool redyToSpwan = false;
	while (!redyToSpwan) {
		int randomNumber = rand() % 17;
		for (int i = 0; i < 3; i++) {
			if (randomNumber == itemPositionSet[0]) {
				count = 0;
				printf("fuck");
				break;
			}
			if (randomNumber == itemPositionSet[1]) {
				count = 0;
				printf("fuck");
				break;
			}
			if (randomNumber == itemPositionSet[2]) {
				count = 0;
				printf("fuck");
				break;
			}
			if (count == 3) {
				redyToSpwan = true;
				itemPositionSet[itemNum] = randomNumber;
				for (int i = 0; i < 3; i++) {
					printf("%d\n", itemPositionSet[i]);
				}
				return randomNumber;
			}
			if (randomNumber != itemPositionSet[i]) {
				count++;
				printf("hi\n");
			}
		}
	}
	//return 0;
}

void SceneState01::SceneState01_Run(sf::RenderWindow& window, float deltatime,int *scene, string* playerName)
{
	window.clear(sf::Color(168, 204, 195));
	window.draw(Background);

	//*****Time*****//

	this->time->Draw(window);

	//////////////////

	//*****Items*****//

	for (int i = 0; i <= 2; i++) {
		/*if (itemInScene[i]) {
		}*/
		item[i]->Draw(window);
		if (!pause) {
			item[i]->itemUpdate(deltatime);
		}
		if (player->GetCollider().CheckTrigger(item[i]->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&!player->haveSecoundItem) {

			player->haveSecoundItem = true;
			player->itemPower = item[i]->power;
			player->secoundItem = item[i]->whichItem;// เอาไปanimate 
			item[i]->changePositionToClear();
		}
		if (item[i]->needReSpwan) {
			//Random Position
			int x;
			x = ramdomPositionSpwan(i);
			//printf("%d", x);
			if(item[i]->whichItem==1)
				item[i] = new items("pictures/UI/snacks/chip.png", sf::Vector2f(70, 80), sf::Vector2f(spwanX[x], spwanY[x]), 1, 10);
			if(item[i]->whichItem==2)
				item[i] = new items("pictures/UI/snacks/coke.png", sf::Vector2f(30, 50), sf::Vector2f(spwanX[x], spwanY[x]), 2, 10);
			if(item[i]->whichItem==3)
				item[i] = new items("pictures/UI/snacks/dounut.png", sf::Vector2f(60, 50), sf::Vector2f(spwanX[x], spwanY[x]), 3, 10);
			item[i]->needReSpwan = false;
		}
	}

	///////////////////

	//****Status*****//

	if(player->Sleep>8)
		window.draw(z01);
	if(player->Sleep>16)
		window.draw(z02);
	if(player->Sleep>24)
		window.draw(z03);
	if (player->Sleep > 32) {
		window.draw(z04);
	}
	if(player->Sleep>40)
		window.draw(z05);
	if(player->Sleep>50)
		window.draw(z06);

	if(teacher->angryStatus>12)
		window.draw(angry01);
	if (teacher->angryStatus > 24)
		window.draw(angry02);
	if (teacher->angryStatus > 36)
		window.draw(angry03);
	if (teacher->angryStatus > 48)
		window.draw(angry04);
	if (teacher->angryStatus > 60)
		window.draw(angry05);
	if (teacher->angryStatus > 72)
		window.draw(angry06);
	if (teacher->angryStatus > 84)
		window.draw(angry07);
	if (teacher->angryStatus > 100)
		window.draw(angry08);
	///////////////////

	//*****Wall*****//

	player->GetCollider().CheckCollision(wall_left->GetCollider(), 0.0f);
	wall_left->Draw(window);

	player->GetCollider().CheckCollision(wall_right->GetCollider(), 0.0f);
	wall_right->Draw(window);

	player->GetCollider().CheckCollision(wall_top->GetCollider(), 0.0f);
	wall_top->Draw(window);

	player->GetCollider().CheckCollision(wall_bottom->GetCollider(), 0.0f);
	wall_bottom->Draw(window);

	//////////////////

	//*****Student*****//

	student01->Draw(window);
	student02->Draw(window);

	student03->Draw(window);

	student04->Draw(window);

	student05->Draw(window);

	student06->Draw(window);

	student07->Draw(window);

	student08->Draw(window);

	student09->Draw(window);

	student10->Draw(window);

	student11->Draw(window);

	student12->Draw(window);

	student13->Draw(window);
	
	student14->Draw(window);
	
	student15->Draw(window);
	
	student16->Draw(window);
	
	student17->Draw(window);
	
	student18->Draw(window);

	/////////////////////

	//*****Chair Block*****//


	player->GetCollider().CheckCollision(teacher_Table->GetCollider(), 0.0f);
	teacher_Table->Draw(window);
	teacher_Table->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform01->GetCollider(), 0.0f);
	chair_block_platform01->Draw(window);
	chair_block01->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform02->GetCollider(), 0.0f);
	chair_block_platform02->Draw(window);
	chair_block02->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform03->GetCollider(), 0.0f);
	chair_block_platform03->Draw(window);
	chair_block03->Draw(window);	
	
	player->GetCollider().CheckCollision(chair_block_platform04->GetCollider(), 0.0f);
	chair_block_platform04->Draw(window);
	chair_block04->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform05->GetCollider(), 0.0f);
	chair_block_platform05->Draw(window);
	chair_block05->Draw(window);
	
	player->GetCollider().CheckCollision(chair_block_platform06->GetCollider(), 0.0f);
	chair_block_platform06->Draw(window);
	chair_block06->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform07->GetCollider(), 0.0f);
	chair_block_platform07->Draw(window);
	chair_block07->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform08->GetCollider(), 0.0f);
	chair_block_platform08->Draw(window);
	chair_block08->Draw(window);	
	
	player->GetCollider().CheckCollision(chair_block_platform09->GetCollider(), 0.0f);
	chair_block_platform09->Draw(window);
	chair_block09->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform10->GetCollider(), 0.0f);
	chair_block_platform10->Draw(window);
	chair_block10->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform11->GetCollider(), 0.0f);
	chair_block_platform11->Draw(window);
	chair_block11->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform12->GetCollider(), 0.0f);
	chair_block_platform12->Draw(window);
	chair_block12->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform13->GetCollider(), 0.0f);
	chair_block_platform13->Draw(window);
	chair_block13->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform14->GetCollider(), 0.0f);
	chair_block_platform14->Draw(window);
	chair_block14->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform15->GetCollider(), 0.0f);
	chair_block_platform15->Draw(window);
	chair_block15->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform16->GetCollider(), 0.0f);
	chair_block_platform16->Draw(window);
	chair_block16->Draw(window);

	player->GetCollider().CheckCollision(chair_block_platform17->GetCollider(), 0.0f);
	chair_block_platform17->Draw(window);
	chair_block17->Draw(window);
	player->GetCollider().CheckCollision(chair_block_platform18->GetCollider(), 0.0f);
	chair_block_platform18->Draw(window);
	chair_block18->Draw(window);

	/////////////////////////

	////////***** Chair Control *******//////////

	chair_platform01->Draw(window);
	chair_platform02->Draw(window);
	chair_platform03->Draw(window);
	chair_platform04->Draw(window);


	if (player->GetCollider().CheckTrigger(chair01->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->playerSit) {
		sitStandFx.play();
		player->whichChair = 1;
		player->PlayerSit();
		std::cout << "Sit \n";
		debouce debouce(0.2f);
	}
	if (player->GetCollider().CheckTrigger(chair01->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->playerSit) {
		sitStandFx.play();
		player->whichChair = 1;
		player->PlayerStand();
		std::cout << "stand \n";
		debouce debouce(0.2f);
	}
	
	if (player->GetCollider().CheckTrigger(chair02->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->playerSit) {
		sitStandFx.play();
		player->whichChair = 2;
		player->PlayerSit();
		std::cout << "Sit \n";
		debouce debouce(0.2f);
	}
	if (player->GetCollider().CheckTrigger(chair02->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->playerSit) {
		sitStandFx.play();
		player->whichChair = 2;
		player->PlayerStand();
		std::cout << "stand \n";
		debouce debouce(0.2f);
	}

	if (player->GetCollider().CheckTrigger(chair03->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->playerSit) {
		sitStandFx.play();
		player->whichChair = 3;
		player->PlayerSit();
		std::cout << "Sit \n";
		debouce debouce(0.2f);
	}
	if (player->GetCollider().CheckTrigger(chair03->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->playerSit) {
		sitStandFx.play();
		player->whichChair = 3;
		player->PlayerStand();
		std::cout << "stand \n";
		debouce debouce(0.2f);
	}

	if (player->GetCollider().CheckTrigger(chair04->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !player->playerSit) {
		sitStandFx.play();
		player->whichChair = 4;
		player->PlayerSit();
		std::cout << "Sit \n";
		debouce debouce(0.2f);
	}
	if (player->GetCollider().CheckTrigger(chair04->GetCollider()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player->playerSit) {
		sitStandFx.play();
		player->whichChair = 4;
		player->PlayerStand();
		std::cout << "stand \n";
		debouce debouce(0.2f);
	}
	//////////////////////////////////////////

	//*****Teacher*****//

	teacher->Draw(window);

	/////////////////////
	
	//*****Sleep*****//


	//Sit
	if (player->playerSit) {
		player->Draw(window);
		player->study = true;

		chair01->Draw(window);
		chair02->Draw(window);		
		chair03->Draw(window);
		chair04->Draw(window);
	}

	///////

	//Stand
	if (!player->playerSit) {

		player->GetCollider().CheckCollision(chair_platform01->GetCollider(), 0.0f);
		player->GetCollider().CheckCollision(chair_platform02->GetCollider(), 0.0f);
		player->GetCollider().CheckCollision(chair_platform03->GetCollider(), 0.0f);
		player->GetCollider().CheckCollision(chair_platform04->GetCollider(), 0.0f);

		chair01->Draw(window);
		chair02->Draw(window);
		chair03->Draw(window);
		chair04->Draw(window);

		player->Draw(window);
	}

	///////

	//*****Inventory*****//

	if (player->coolDownItem01) {
		inventory01->UseThisItem();
	}
	if (!player->coolDownItem01) {
		inventory01->ReuseThisItem();
	}
	//useSomeItem = player->playerUseItem;

	inventory02->UdateSecoundInventory(player->secoundItem, player->haveSecoundItem);
	
	inventory01->Draw(window);
	inventory02->Draw(window);

	///////////////////////

	//*****RushHour*****//

	if (time->rushHour&&!stopRushStatue) {
		printf("rush\n");
		if (rushAnimation < 4.0f) {
			if (!sound) {
				rushFx.play();
				sound = true;
			}
			rushAnimation += deltatime;
			printf("%f\n", rushOpacity);
			if (incress) {
				rushOpacity += deltatime * 200;
				if (rushOpacity >= 255) {
					incress = false;
				}
			}
			if (!incress) {
				rushOpacity -= deltatime * 200;
				if (rushOpacity <= 50) {
					incress = true;
				}
			}
		}
		else {
			stopRushStatue = true;
		}
		rushHour.setFillColor(sf::Color(255, 255, 255, rushOpacity));
		//window.draw(redBg);
		window.draw(rushHour);
	}

	/////////////////////

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		time->completState = true;
	}*/

	if (faceBlack) {
		if (faceBlackIncress) {
			faceBlackAnimation += deltatime * 100;
			cout << "faceBlack";
			if (faceBlackAnimation >= 150.0f) {
				faceBlackIncress = false;
			}
		}
		else
		{
			faceBlackAnimation -= deltatime * 100;
			if (faceBlackAnimation <= 10) {
				faceBlackIncress = true;
			}
		}
		faceBlackBg.setFillColor(sf::Color(0, 0, 0, faceBlackAnimation));
		window.draw(faceBlackBg);
	}

	if (player->Sleep >= 35) {
		faceBlack = true;
	}
	if (player->Sleep < 35) {
		faceBlack = false;
	}


	if (firstTime&&!time->completState) {
		faceBlack = false;

		bgFx.play(); 
		window.draw(enterNameBg);///*********************************************
		//ss << playerName;
		previewName.setString(*playerName);
		window.draw(previewName);
		okButton->updateButtonChangeScene(window, scene);
		if (okButton->checkClick()) {
			firstTime = false;
			okButton->click = false;
		}
		//cout << playerName;
		//*playerName = "";
	}

	//*****Update*****//


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)&&!pause) {
		pause = true;
		debouce debounce(0.2f);
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)&&pause) {
		pause = false;
		debouce debounce(0.2f);
	}
	if (pause) {
		window.draw(pauseBg);
		exitButton->updateButtonChangeScene(window, scene);
		menuButton->updateButtonChangeScene(window, scene);
		if (menuButton->checkClick()) {
			reset(playerName);
		}
	}

	if (!pause&&!time->completState&&!firstTime && !gameOver) {


		teacher->Update(deltatime, player->playerSit, player->playerUseItem,time->rushHour);
		 
		student01->UpdateStu(deltatime);
		student02->UpdateStu(deltatime);
		student03->UpdateStu(deltatime);
		student04->UpdateStu(deltatime);
		student05->UpdateStu(deltatime);
		student06->UpdateStu(deltatime);
		student07->UpdateStu(deltatime);
		student08->UpdateStu(deltatime);
		student09->UpdateStu(deltatime);
		student10->UpdateStu(deltatime);
		student11->UpdateStu(deltatime);
		student12->UpdateStu(deltatime);
		student13->UpdateStu(deltatime);
		student14->UpdateStu(deltatime);
		student15->UpdateStu(deltatime);
		student16->UpdateStu(deltatime);
		student17->UpdateStu(deltatime);
		student18->UpdateStu(deltatime);


		player->Update(deltatime);
		player->useItemUpdate(deltatime);
		this->time->UpdateTime(deltatime);

		player->SleepStatus(deltatime);
	}
	////////////////////

	if (teacher->angryStatus >= 100||player->Sleep >= 50) {
		gameOver = true;
	}
	if (gameOver) {
		faceBlack = false;
		window.draw(overBg);
		overButton->updateButtonChangeScene(window, scene);
		if (firstComplet) {
			overFx.play();
			firstComplet = false;
		}
		if (overButton->checkClick()) {
			reset(playerName);
			overButton->click = false;
			firstComplet = true;
			gameOver = false;
		}
	}
	
	
	if (time->completState&&!gameOver) {
		faceBlack = false; 
		score = 100.0f - teacher->angryStatus;
		window.draw(endBg);
		menuEndButton->updateButtonChangeScene(window, scene);
		cout << score;
		cout << "\n";

		showScore.setString(to_string(score));
		window.draw(showScore);

		if (!writeComplet) {
			std::fstream scorefile("Data/Score.data", std::ios::app);// เขียน
			scorefile << "\n" << *playerName;
			scorefile << "\t\t" << score;
			scorefile.close();
			writeComplet = true;
		}
		score = 0;
		*playerName = "";

		if (firstComplet) {
			completFx.play();
		}
		if (menuEndButton->checkClick()) {
			reset(playerName);
			menuEndButton->click = false;
			firstComplet = true;
			writeComplet = false;
		}
		firstComplet = false;
	}



}


void SceneState01::reset(string* playerName)
{

	playerName->clear();
	item[0]->needReSpwan = true;
	item[1]->needReSpwan = true;
	item[2]->needReSpwan = true;

	faceBlack = false;

	for (int i = 0; i < 3; i++) {
		if (item[i]->needReSpwan) {
			//Random Position
			int x;
			x = ramdomPositionSpwan(i);
			//printf("%d", x);
			if (item[i]->whichItem == 1)
				item[i] = new items("pictures/UI/snacks/chip.png", sf::Vector2f(70, 80), sf::Vector2f(spwanX[x], spwanY[x]), 1, 10);
			if (item[i]->whichItem == 2)
				item[i] = new items("pictures/UI/snacks/coke.png", sf::Vector2f(30, 50), sf::Vector2f(spwanX[x], spwanY[x]), 2, 10);
			if (item[i]->whichItem == 3)
				item[i] = new items("pictures/UI/snacks/dounut.png", sf::Vector2f(60, 50), sf::Vector2f(spwanX[x], spwanY[x]), 3, 10);
			item[i]->needReSpwan = false;
		}
	}
	bgFx.stop();
	firstTime = true;

	pause = false;
	menuButton->click = false;

	player->playerReset();
	teacher->teacherReset();
	time->timeBarReset();

	/*cout << playerName;
	playerName = "\n";
	previewName.setString("");

	cout << playerName;*/
}
