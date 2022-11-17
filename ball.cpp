#include "ball.h"

// Initialize static data
sf::Texture ball::texture;

ball::ball(float x, float y) : moving_entity() {
	// Load the texture
	texture.loadFromFile("C:/Users/rares/Desktop/ball.png");
	sprite.setTexture(texture);

	// Set the initial position and velocity of the ball
	// Use (x, y) for the initial position of the ball
	sprite.setPosition(x, y);
	velocity = { constants::ball_speed, constants::ball_speed };
	sprite.setOrigin(get_centre());
}

// Compute the ball's new position
void ball::update() {
	// Move the position of the ball
	sprite.move(velocity);

	if (X() < 0)
		velocity.x = -velocity.x;
	if (X() > constants::window_width)
		velocity.x = -velocity.x;
	if (Y() < 0)
		velocity.y = -velocity.y;
	if (Y() > constants::window_height)
		constants::game = 0;
}

void ball::draw(sf::RenderWindow& window) {
	// Ask the window to draw the sprite for us
	window.draw(sprite);
}
