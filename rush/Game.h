#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "PLayer.h"
#include "SoundManager.h"
#include "Platform.h"
#include "Trigger.h"
#include "Chair.h"
#include "debouce.h"
#include "SceneState01.h"
#include "MainMenu.h"
#include "ScoreState.h"

using namespace std;

class Game
{
public:
	void Run();
	int scene = 0;

private:
};

 