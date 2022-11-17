#include "paddle.h"
#include "constants.h"
paddle::paddle(float x, float y) :moving_entity() {
	texture.loadFromFile("C:/Users/rares/Desktop/paddle.png");
	sprite.setTexture(texture);

	sprite.setPosition(x, y);
	velocity = { 0.0f,0.0f };
	sprite.setOrigin(get_centre());
 }

void paddle::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		if (X() > 0)
			velocity.x = -constants::paddle_speed;
		else
			velocity.x = 0;
	else
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
			if (X() < constants::window_width)
				velocity.x = constants::paddle_speed;
			else
				velocity.x = 0;
		else
			velocity.x = 0;
	sprite.move(velocity);
}

void paddle::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}