#pragma once
#include "entity.h"
class brick :public entity {
	sf::Texture texture;
	int strenght;
public:
	brick() {}
	brick(float x, float y);
	void update()override;
	void draw(sf::RenderWindow& window);
	void weaken();
	void set_color();
};
