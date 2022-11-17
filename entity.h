#pragma once
#include <SFML/Graphics.hpp>

// Abstract base class to represent any graphical entity on the screen
class entity {
protected:
	sf::Sprite sprite;
	bool destroyed{ false };
public:
	// Pure virtual functions
	// Concrete graphical entities must implement these functions
	// The update member function will compute the new position, appearance, etc of the object
	// The draw member function will cause the updated object to be displayed in the game window
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;

	// Virtual destructor
	virtual ~entity() {}
	float X() const;
	float Y() const;
	sf::FloatRect get_box()const noexcept;
	sf::Vector2f get_centre() const noexcept;
	void destroy();
	bool is_destroyed();
	float top();
	float bottom();
	float right();
	float left();
};

class moving_entity :public entity {
protected:
	sf::Vector2f velocity;
public:
	void move_up();
	void move_left();
	void move_right();
	void move_down();
};
