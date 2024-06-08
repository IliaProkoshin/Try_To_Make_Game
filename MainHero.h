#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Field.h"
#include <windows.h>


extern sf::Color MASK_COLOR;
extern unsigned int STEP_LEN;
extern unsigned int WIDTH;
extern unsigned int HEIGHT;
extern double STEP;

class MainHero {
private:
	std::string path_up = "data/images/main_hero/hero_up.png";
	std::string path_down = "data/images/main_hero/hero_down.png";
	std::string path_left = "data/images/main_hero/hero_left.png";
	std::string path_right = "data/images/main_hero/hero_right.png";

	std::string path_up_move1 = "data/images/main_hero/hero_up_move1.png";
	std::string path_down_move1 = "data/images/main_hero/hero_down_move1.png";
	std::string path_left_move1 = "data/images/main_hero/hero_left_move1.png";
	std::string path_right_move1 = "data/images/main_hero/hero_right_move1.png";

	std::string path_up_move2 = "data/images/main_hero/hero_up_move2.png";
	std::string path_down_move2 = "data/images/main_hero/hero_down_move2.png";
	std::string path_left_move2 = "data/images/main_hero/hero_left_move2.png";
	std::string path_right_move2 = "data/images/main_hero/hero_right_move2.png";

	std::string path_up_swipe = "data/images/main_hero/hero_up_swipe.png";
	std::string path_down_swipe = "data/images/main_hero/hero_down_swipe.png";
	std::string path_left_swipe = "data/images/main_hero/hero_left_swipe.png";
	std::string path_right_swipe = "data/images/main_hero/hero_right_swipe.png";

	sf::Image image_up, image_down, image_left, image_right;
	sf::Image image_up_move1, image_down_move1, image_left_move1, image_right_move1;
	sf::Image image_up_move2, image_down_move2, image_left_move2, image_right_move2;
	sf::Image image_up_swipe, image_down_swipe, image_left_swipe, image_right_swipe;

	sf::Texture texture_up, texture_down, texture_left, texture_right;
	sf::Texture texture_up_move1, texture_down_move1, texture_left_move1, texture_right_move1;
	sf::Texture texture_up_move2, texture_down_move2, texture_left_move2, texture_right_move2;
	sf::Texture texture_up_swipe, texture_down_swipe, texture_left_swipe, texture_right_swipe;

	sf::Sprite sprite;

	unsigned int state = 0;
	int X, Y, wheat_counter = 0, potato_counter = 0, tomato_counter = 0;

public:
	MainHero(Field* field) {
		image_up.loadFromFile(path_up);
		image_down.loadFromFile(path_down);
		image_left.loadFromFile(path_left);
		image_right.loadFromFile(path_right);

		image_up_move1.loadFromFile(path_up_move1);
		image_down_move1.loadFromFile(path_down_move1);
		image_left_move1.loadFromFile(path_left_move1);
		image_right_move1.loadFromFile(path_right_move1);

		image_up_move2.loadFromFile(path_up_move2);
		image_down_move2.loadFromFile(path_down_move2);
		image_left_move2.loadFromFile(path_left_move2);
		image_right_move2.loadFromFile(path_right_move2);

		image_up_swipe.loadFromFile(path_up_swipe);
		image_down_swipe.loadFromFile(path_down_swipe);
		image_left_swipe.loadFromFile(path_left_swipe);
		image_right_swipe.loadFromFile(path_right_swipe);

		image_up.createMaskFromColor(MASK_COLOR);
		image_down.createMaskFromColor(MASK_COLOR);
		image_left.createMaskFromColor(MASK_COLOR);
		image_right.createMaskFromColor(MASK_COLOR);

		image_up_move1.createMaskFromColor(MASK_COLOR);
		image_down_move1.createMaskFromColor(MASK_COLOR);
		image_left_move1.createMaskFromColor(MASK_COLOR);
		image_right_move1.createMaskFromColor(MASK_COLOR);

		image_up_move2.createMaskFromColor(MASK_COLOR);
		image_down_move2.createMaskFromColor(MASK_COLOR);
		image_left_move2.createMaskFromColor(MASK_COLOR);
		image_right_move2.createMaskFromColor(MASK_COLOR);

		image_up_swipe.createMaskFromColor(MASK_COLOR);
		image_down_swipe.createMaskFromColor(MASK_COLOR);
		image_left_swipe.createMaskFromColor(MASK_COLOR);
		image_right_swipe.createMaskFromColor(MASK_COLOR);

		texture_up.loadFromImage(image_up);
		texture_down.loadFromImage(image_down);
		texture_left.loadFromImage(image_left);
		texture_right.loadFromImage(image_right);

		texture_up_move1.loadFromImage(image_up_move1);
		texture_down_move1.loadFromImage(image_down_move1);
		texture_left_move1.loadFromImage(image_left_move1);
		texture_right_move1.loadFromImage(image_right_move1);

		texture_up_move2.loadFromImage(image_up_move2);
		texture_down_move2.loadFromImage(image_down_move2);
		texture_left_move2.loadFromImage(image_left_move2);
		texture_right_move2.loadFromImage(image_right_move2);

		texture_up_swipe.loadFromImage(image_up_swipe);
		texture_down_swipe.loadFromImage(image_down_swipe);
		texture_left_swipe.loadFromImage(image_left_swipe);
		texture_right_swipe.loadFromImage(image_right_swipe);

		X = field->get_hero_x();
		Y = field->get_hero_y();
		state = field->get_hero_way();

		switch (state) {
		case 0:
			sprite.setTexture(texture_down);
			break;
		case 1:
			sprite.setTexture(texture_up);
			state = 1;
			break;
		case 2:
			sprite.setTexture(texture_left);
			state = 2;
			break;
		case 3:
			sprite.setTexture(texture_right);
			state = 3;
			break;
		}
		sprite.setPosition(WIDTH / 2 - STEP / 2, HEIGHT / 2 - STEP / 2);
	}

	void render(sf::RenderWindow& Window) const{
		Window.draw(sprite);
	}

	void setPosition(int pos_x, int pos_y) {
		X = pos_x;
		Y = pos_y;
	}

	const void GlobalRender(sf::RenderWindow& Window, Field field) const{
		Window.clear();
		field.render(Window);
		Window.draw(sprite);
		Window.display();
	}

	void move(int pos_x, int pos_y, sf::RenderWindow& Window, Field& field) {
		int check_X = field.get_width();
		int check_Y = field.get_height();
		int part = STEP / 4;
		unsigned int partT = STEP_LEN / 4;
		X += pos_x;
		Y += pos_y;
		if (X == check_X) {
			X -= pos_x;
			sprite.setTexture(texture_right);
		}
		else if (X < 0) {
			X -= pos_x;
			sprite.setTexture(texture_left);
		}
		else if (Y < 0) {
			Y -= pos_y;
			sprite.setTexture(texture_up);
		}
		else if (Y == check_Y) {
			Y -= pos_y;
			sprite.setTexture(texture_down);
		}
		else if (field.check_movable(X, Y) == false) {
			if (pos_x > 0) {
				sprite.setTexture(texture_right);
				state = 3;
			}
			else if (pos_x < 0) {
				sprite.setTexture(texture_left);
				state = 2;
			}
			else if (pos_y > 0) {
				sprite.setTexture(texture_down);
				state = 0;
			}
			else {
				sprite.setTexture(texture_up);
				state = 1;
			}
			X -= pos_x;
			Y -= pos_y;
		}
		else if (pos_x > 0) {
			sprite.setTexture(texture_right_move1);
			field.move_field(part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_right_move2);
			field.move_field(part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_right_move1);
			field.move_field(part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_right);
			field.move_field(part, 0);
			state = 3;
		}
		else if (pos_x < 0) {
			sprite.setTexture(texture_left_move1);
			field.move_field(-part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_left_move2);
			field.move_field(-part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_left_move1);
			field.move_field(-part, 0);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_left);
			field.move_field(-part, 0);
			state = 2;
		}
		else if (pos_y > 0) {
			sprite.setTexture(texture_down_move1);
			field.move_field(0, part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_down_move2);
			field.move_field(0, part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_down_move1);
			field.move_field(0, part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_down);
			field.move_field(0, part);
			state = 0;
		}
		else if (pos_y < 0) {
			sprite.setTexture(texture_up_move1);
			field.move_field(0, -part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_up_move2);
			field.move_field(0, -part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_up_move1);
			field.move_field(0, -part);
			GlobalRender(Window, field);
			Sleep(partT);
			sprite.setTexture(texture_up);
			field.move_field(0, -part);
			state = 1;
		}
		else {
			return;
		}
		GlobalRender(Window, field);
	}

	void dig(sf::RenderWindow& Window, Field& field) {
		int hero_X = X, hero_Y = Y, partT = STEP_LEN;
		if (state == 0) {
			hero_Y += 1;
		}
		else if (state == 1) {
			hero_Y -= 1;
		}
		else if (state == 2) {
			hero_X -= 1;
		}
		else {
			hero_X += 1;
		}
		if (field.is_diggable(hero_X, hero_Y)) {
			int type = field.check_type(hero_X, hero_Y);
			if (type == 3) {
				field.set_type(hero_X, hero_Y, 4);
			}
			else {
				if (type == 25) {
					tomato_counter++;
				}
				else if (type == 15) {
					wheat_counter++;
				}
				else if (type == 20){
					potato_counter++;
				}
				field.set_type(hero_X, hero_Y, 3);
			}
			if (state == 0) {
				sprite.setTexture(texture_down_swipe);
				GlobalRender(Window, field);
				Sleep(partT);
				sprite.setTexture(texture_down);
			}
			else if (state == 1) {
				sprite.setTexture(texture_up_swipe);
				GlobalRender(Window, field);
				Sleep(partT);
				sprite.setTexture(texture_up);
			}
			else if (state == 2) {
				sprite.setTexture(texture_left_swipe);
				GlobalRender(Window, field);
				Sleep(partT);
				sprite.setTexture(texture_left);
			}
			else {
				sprite.setTexture(texture_right_swipe);
				GlobalRender(Window, field);
				Sleep(partT);
				sprite.setTexture(texture_right);
			}
		}
		GlobalRender(Window, field);
	}

	void setOrientation(unsigned int item, sf::RenderWindow& Window, Field& field) {
		if (item > 3) {
			throw "Wrong orientation!";
		}
		else {
			state = item;
			switch (state) {
			case 0:
				sprite.setTexture(texture_down);
				break;
			case 1:
				sprite.setTexture(texture_up);
				break;
			case 2:
				sprite.setTexture(texture_left);
				break;
			case 3:
				sprite.setTexture(texture_right);
				break;
			}
		}
		GlobalRender(Window, field);
	}
};