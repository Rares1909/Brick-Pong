#ifndef CONSTANTS_H
#define CONSTANTS_H

// Code for a "breakout" game
// Based on a talk by Vittorio Romeo
// Uses the SFML graphics library

struct constants {
	static constexpr int window_width{ 520 };
	static constexpr int window_height{ 450 };
	static constexpr float ball_speed{ 5.0f };
	static constexpr float paddle_speed{ 7.0f };
	static constexpr float paddle_width{ 90.0f };
	static constexpr float paddle_height{ 9.0f };
	static constexpr float brick_width{43.0f};
	static constexpr float brick_height{20.0f};
	static int game;
	static int level;
};

#endif // CONSTANTS_H
#pragma once
