#include "brick.h"
#include<random>

std::mt19937 mt(time(0));
std::uniform_int_distribution<>range(1, 3);
sf::Color hit1{ 255,0,0 };
sf::Color hit2{ 0,0,255 };
sf::Color hit3{ 0,255,0 };

brick::brick(float x, float y):entity() {
	texture.loadFromFile("C:/Users/rares/Desktop/brick01.png");
	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	sprite.setOrigin(get_centre());
	strenght = range(mt);
	set_color();
}	

void brick::update() {
	set_color();
	if (strenght == 0)
		destroy();
}

void brick::set_color() {
	if (strenght == 3)
		sprite.setColor(hit1);
	if (strenght == 2)
		sprite.setColor(hit2);
	if (strenght == 1)
		sprite.setColor(hit3);
}

void brick::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void brick::weaken() {
	strenght--;
}