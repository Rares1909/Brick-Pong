#pragma once
#include "entity.h"
#include "constants.h"
class ball :public moving_entity {
	static sf::Texture texture;
public:
	ball(float x, float y);
	void update();
	void draw(sf::RenderWindow& window);
};
