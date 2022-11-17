// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library
#include <SFML/Graphics.hpp>
#include<random>
#include <string>
#include "constants.h"
#include<list>
#include<algorithm>

#include "background.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
using namespace std::literals;
using namespace std;

int constants::game = 1;
int constants::level = 1;
sf::Font font;
sf::Text text;

bool collision(const entity& e1, const entity& e2) {
    auto box1 = e1.get_box();
    auto box2 = e2.get_box();
    return box1.intersects(box2);
}

void handle( const paddle& p, ball& b) {
    if (collision(p, b))
    {
        b.move_up();
        if (b.X() < p.X())
            b.move_left();
        else
            b.move_right();
    }


}

void handle_b(ball& the_ball, brick& block) {
    if (collision(block, the_ball)) {
        // The brick is destroyed
        block.weaken();
        block.update();
       

        // Make the new direction depend on where the collision occurs on the brick
        // If the ball collides on the side of the brick, make the ball bounce to the left/right
        // If the ball collides on the top/bottom of the brick, make the ball bounce upwards/downwards

        // First we find the amount of overlap in each direction
        // The smaller the left overlap, the closer the ball is to the left side of the brick
        // And similarly for the other sides of the brick
        float left_overlap = the_ball.right() - block.left();
        float right_overlap = block.right() - the_ball.left();
        float top_overlap = the_ball.bottom() - block.top();
        float bottom_overlap = block.bottom() - the_ball.top();

        // If the left overlap is smaller than the right overlap, the ball hit the left side
        bool from_left = std::abs(left_overlap) < std::abs(right_overlap);
        bool from_top = std::abs(top_overlap) < std::abs(bottom_overlap);

        // Use the right or left overlap as appropriate
        float min_x_overlap = from_left ? left_overlap : right_overlap;
        float min_y_overlap = from_top ? top_overlap : bottom_overlap;

        // If the ball hit the left or right side of the brick, change its horizontal direction
        // If the ball hit the top or bottom of the brick, change its vertical direction
        if (std::abs(min_x_overlap) < std::abs(min_y_overlap)) {
            if (from_left)
                the_ball.move_left();
            else
                the_ball.move_right();
        }
        else {
            if (from_top)
                the_ball.move_up();
            else
                the_ball.move_down();
        }
    }
}

// The main function for the program
int main() {
    // Create the background object
    background the_background(0.0f, 0.0f);

    ball the_ball(constants::window_width / 2.0f, constants::window_height / 2.0f);


    paddle paddle(constants::window_width / 2.0f - 45.0f, constants::window_height - 15.0f);

    list<brick> bricks;

    font.loadFromFile("C:/Windows/fonts/Verdana.ttf");
    text.setFont(font);
    text.setPosition(constants::window_width / 2.0f, constants::window_height / 2.0f);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::Red);


  for (int i = 0; i < 3; i++)
      for (int j = 0; j < 4; j++)
      {
          float x = constants::brick_width + (i + 1) * constants::brick_width;
          float y = (j + 1) * constants::brick_height;
          bricks.emplace_front(x,y);
      }
  
  // Create the game's window using an object of class RenderWindow
  // The constructor takes an SFML 2D vector with the window dimensions
  // and an std::string with the window title
  // The SFML code is in the sf namespace
  sf::RenderWindow game_window{{constants::window_width, constants::window_height},
			       "Simple Breakout Game Version 1"s,};
  
  // Limit the framerate
  // This allows other processes to run and reduces power consumption
  game_window.setFramerateLimit(60);      // Max rate is 60 frames per second

  // Game loop
  // Clear the screen
  // Check for new events
  // Calculate the updated graphics
  // Display the updated graphics
  while (game_window.isOpen()) {
    // Clear the screen
    game_window.clear(sf::Color::Black);

    // Check for any events since the last loop iteration
    sf::Event event;
    
    // If the user pressed "Escape", or clicked on "close", we close the window
    // This will terminate the program
    while (game_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			game_window.close();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
      game_window.close();

    if (constants::game==1)
    {
        the_background.update();
        paddle.update();
        handle(paddle, the_ball);
        auto it = bricks.begin();
        while (it != bricks.end())
        {
            handle_b(the_ball, *it);
            if (it->is_destroyed())
            {
                bricks.erase(prev(++it));

            }
            else
                ++it;
        }
        if (!bricks.size())
            constants::game = 2;
        the_ball.update();
    }
    if(constants::game==0)
        text.setString("Game Over");
    if (constants::game == 2)
        text.setString("Win");
    // Display the updated graphics
    the_background.draw(game_window);
    the_ball.draw(game_window);
    paddle.draw(game_window);
    for (auto el : bricks)
        el.draw(game_window);
    game_window.draw(text);

    game_window.display();
    
  }
}
