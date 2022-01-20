#include "SoundManager.h"

using namespace std;

SoundManager::SoundManager(int changebgSound)
{
	switch (changebgSound) {
	case 1:
		if (!bgMusic.loadFromFile("musics/musics/music_menu.wav")) {
			cout << "error";
		}
		cout << "menu sound \n";
	case 2:
		if (!bgMusic.loadFromFile("musics/musics/music_gameState.wav")) {
			cout << "error";
			cout << "game State sound \n";
		}
	}

	playbgSound();

}

void SoundManager::playbgSound()
{
	bg_Sound.setBuffer(bgMusic);
	bg_Sound.play();
	cout << "Sound BG Play \n";
}
 