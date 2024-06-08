#pragma once
#include <SFML/Window.hpp>
class BaseSquare {
private:
	bool is_movable;
	int X, Y, type = 0;
	sf::Clock clock;  // Таймер - время с последнего изменения стадии или с посадки

public:
	BaseSquare(int pos_x, int pos_y, bool h_is_movable = true, int h_type = 0) {
		is_movable = h_is_movable;
		type = h_type;
		X = pos_x;
		Y = pos_y;
		clock.restart();
	}

	void move(int dX, int dY) {
		X += dX;
		Y += dY;
	}

	int get_type() const{
		return type;
	}

	bool get_is_movable() const{
		return is_movable;
	}

	void set_type(int h_type = 0) {
		type = h_type;
	}

	int get_x() const {
		return X;
	}

	int get_y() const {
		return Y;
	}

	float get_time() const {
		return clock.getElapsedTime().asSeconds();
	}

	void restart_clock() {
		clock.restart();
	}
};