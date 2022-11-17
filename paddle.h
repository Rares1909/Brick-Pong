#pragma once
#include "entity.h"

class paddle :public moving_entity {
	sf::Texture texture;
public:
	paddle(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& window);
};

