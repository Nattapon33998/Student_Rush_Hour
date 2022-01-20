#include "debouce.h"

debouce::debouce(float sec)
{
	while (Time <= sec) {
		Time = clock.getElapsedTime().asSeconds();
	}
	Time = clock.restart().asSeconds();
}
	
debouce::~debouce()
{
}

