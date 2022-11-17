#include "entity.h"
#include "constants.h"
float entity:: X() const {
	return sprite.getPosition().x;
}

float entity::Y() const{
	return sprite.getPosition().y;
}

void moving_entity::move_up() {
	velocity.y = -constants::ball_speed;
}

void moving_entity::move_left() {
	velocity.x = -constants::ball_speed;
}

void moving_entity::move_right() {
	velocity.x = constants::ball_speed;
}

void moving_entity::move_down() {
	velocity.y = constants::ball_speed;
}


sf::FloatRect entity::get_box() const noexcept {
	return sprite.getGlobalBounds();
}

sf::Vector2f entity::get_centre()const noexcept {
	auto box = get_box();
	return { box.width / 2.0f,box.height / 2.0f };
}

void entity::destroy() {
	destroyed = true;
}

bool entity::is_destroyed() {
	return destroyed;
}

float entity::left() {
	return X() - constants::brick_width / 2.0;
}

float entity::right() {
	return X() + constants::brick_width / 2.0;
}

float entity::top() {
	return Y() - constants::brick_height / 2.0;
}

float entity::bottom() {
	return Y() + constants::brick_height / 2.0;
}