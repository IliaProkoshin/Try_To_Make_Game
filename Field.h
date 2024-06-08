#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "BaseSquare.h"

extern unsigned int WIDTH;
extern unsigned int HEIGHT;
extern sf::Color MASK_COLOR;
extern double STEP;

class Field {
private:
	unsigned int size_X = 0, size_Y = 0, hero_X = 0, hero_Y = 0, hero_way = 0;
	int seconds_wheat1 = 10, seconds_wheat2 = 10, seconds_wheat3 = 10,
		seconds_potato1 = 10, seconds_potato2 = 10, seconds_potato3 = 10,  // Время в секундах для каждой стадии растения
		seconds_tomato1 = 10, seconds_tomato2 = 10, seconds_tomato3 = 10;
	std::vector<std::vector<BaseSquare> > array;  // Двумерный вектор с клетками поля
	std::string path_background = "data/images/background.png";
	std::string path_0 = "data/images/squares/default.png";
	std::string path_stone = "data/images/squares/stone.png";
	std::string path_void = "data/images/squares/void.png";
	std::string path_rock = "data/images/squares/rock.png";
	std::string path_grass = "data/images/squares/grass.png";
	std::string path_dirt = "data/images/squares/dirt.png"; 
	std::string path_garden = "data/images/squares/garden.png";
	std::string path_water = "data/images/squares/water.png";
	std::string path_sand = "data/images/squares/sand.png";
	std::string path_bridge = "data/images/squares/bridge.png";
	std::string path_solo_bridge = "data/images/squares/solo_bridge.png";
	std::string path_wheat1 = "data/images/squares/plants/wheat1.png";
	std::string path_wheat2 = "data/images/squares/plants/wheat2.png";  // Пути к графическим файлам
	std::string path_wheat3 = "data/images/squares/plants/wheat3.png";
	std::string path_wheat4 = "data/images/squares/plants/wheat4.png";
	std::string path_wheat5 = "data/images/squares/plants/wheat5.png";
	std::string path_tomato1 = "data/images/squares/plants/tomato1.png";
	std::string path_tomato2 = "data/images/squares/plants/tomato2.png";
	std::string path_tomato3 = "data/images/squares/plants/tomato3.png";
	std::string path_tomato4 = "data/images/squares/plants/tomato4.png";
	std::string path_tomato5 = "data/images/squares/plants/tomato5.png";
	std::string path_potato1 = "data/images/squares/plants/potato1.png";
	std::string path_potato2 = "data/images/squares/plants/potato2.png";
	std::string path_potato3 = "data/images/squares/plants/potato3.png";
	std::string path_potato4 = "data/images/squares/plants/potato4.png";
	std::string path_potato5 = "data/images/squares/plants/potato5.png";
	sf::Image image_background, image_0, image_rock, image_grass, image_dirt, image_garden, image_water, image_sand, image_solo_bridge,
		image_bridge, image_void, image_stone, image_wheat1, image_wheat2, image_wheat3, image_wheat4, image_wheat5, image_potato1,
		image_potato2, image_potato3, image_potato4, image_potato5, image_tomato1, image_tomato2, image_tomato3, image_tomato4, image_tomato5;
	sf::Texture texture_background, texture_0, texture_rock, texture_grass, texture_dirt, texture_garden, texture_water, texture_sand,
		texture_bridge, texture_solo_bridge, texture_void, texture_stone, texture_wheat1, texture_wheat2, texture_wheat3, texture_wheat4,
		texture_wheat5, texture_potato1, texture_potato2, texture_potato3, texture_potato4, texture_potato5, texture_tomato1, texture_tomato2,
		texture_tomato3, texture_tomato4, texture_tomato5;
	sf::Sprite sprite_background, sprite;

public:
	Field(std::string map_path = "NONE") {
		double x_ren, y_ren;

		image_background.loadFromFile(path_background);
		image_background.createMaskFromColor(MASK_COLOR);
		texture_background.loadFromImage(image_background);  // Обработка заднего фона
		sprite_background.setTexture(texture_background);

		image_0.loadFromFile(path_0);
		image_0.createMaskFromColor(MASK_COLOR);  // Обработка картинки "по умолчанию"
		texture_0.loadFromImage(image_0);

		image_rock.loadFromFile(path_rock);
		image_rock.createMaskFromColor(MASK_COLOR);
		texture_rock.loadFromImage(image_rock);

		image_grass.loadFromFile(path_grass);
		image_grass.createMaskFromColor(MASK_COLOR);
		texture_grass.loadFromImage(image_grass);

		image_dirt.loadFromFile(path_dirt);
		image_dirt.createMaskFromColor(MASK_COLOR);
		texture_dirt.loadFromImage(image_dirt);

		image_garden.loadFromFile(path_garden);
		image_garden.createMaskFromColor(MASK_COLOR);
		texture_garden.loadFromImage(image_garden);

		image_water.loadFromFile(path_water);
		image_water.createMaskFromColor(MASK_COLOR);
		texture_water.loadFromImage(image_water);

		image_sand.loadFromFile(path_sand);
		image_sand.createMaskFromColor(MASK_COLOR);
		texture_sand.loadFromImage(image_sand);

		image_bridge.loadFromFile(path_bridge);
		image_bridge.createMaskFromColor(MASK_COLOR);
		texture_bridge.loadFromImage(image_bridge);

		image_solo_bridge.loadFromFile(path_solo_bridge);
		image_solo_bridge.createMaskFromColor(MASK_COLOR);
		texture_solo_bridge.loadFromImage(image_solo_bridge);

		image_void.loadFromFile(path_void);
		image_void.createMaskFromColor(MASK_COLOR);
		texture_void.loadFromImage(image_void);

		image_stone.loadFromFile(path_stone);
		image_stone.createMaskFromColor(MASK_COLOR);
		texture_stone.loadFromImage(image_stone);

		image_wheat1.loadFromFile(path_wheat1);
		image_wheat1.createMaskFromColor(MASK_COLOR);
		texture_wheat1.loadFromImage(image_wheat1);

		image_wheat2.loadFromFile(path_wheat2);
		image_wheat2.createMaskFromColor(MASK_COLOR);
		texture_wheat2.loadFromImage(image_wheat2);

		image_wheat3.loadFromFile(path_wheat3);
		image_wheat3.createMaskFromColor(MASK_COLOR);
		texture_wheat3.loadFromImage(image_wheat3);

		image_wheat4.loadFromFile(path_wheat4);
		image_wheat4.createMaskFromColor(MASK_COLOR);
		texture_wheat4.loadFromImage(image_wheat4);

		image_wheat5.loadFromFile(path_wheat5);
		image_wheat5.createMaskFromColor(MASK_COLOR);
		texture_wheat5.loadFromImage(image_wheat5);

		image_potato1.loadFromFile(path_potato1);
		image_potato1.createMaskFromColor(MASK_COLOR);
		texture_potato1.loadFromImage(image_potato1);

		image_potato2.loadFromFile(path_potato2);
		image_potato2.createMaskFromColor(MASK_COLOR);
		texture_potato2.loadFromImage(image_potato2);

		image_potato3.loadFromFile(path_potato3);
		image_potato3.createMaskFromColor(MASK_COLOR);
		texture_potato3.loadFromImage(image_potato3);

		image_potato4.loadFromFile(path_potato4);
		image_potato4.createMaskFromColor(MASK_COLOR);
		texture_potato4.loadFromImage(image_potato4);

		image_potato5.loadFromFile(path_potato5);
		image_potato5.createMaskFromColor(MASK_COLOR);
		texture_potato5.loadFromImage(image_potato5);

		image_tomato1.loadFromFile(path_tomato1);
		image_tomato1.createMaskFromColor(MASK_COLOR);
		texture_tomato1.loadFromImage(image_tomato1);

		image_tomato2.loadFromFile(path_tomato2);
		image_tomato2.createMaskFromColor(MASK_COLOR);
		texture_tomato2.loadFromImage(image_tomato2);

		image_tomato3.loadFromFile(path_tomato3);
		image_tomato3.createMaskFromColor(MASK_COLOR);
		texture_tomato3.loadFromImage(image_tomato3);

		image_tomato4.loadFromFile(path_tomato4);
		image_tomato4.createMaskFromColor(MASK_COLOR);
		texture_tomato4.loadFromImage(image_tomato4);

		image_tomato5.loadFromFile(path_tomato5);
		image_tomato5.createMaskFromColor(MASK_COLOR);
		texture_tomato5.loadFromImage(image_tomato5);

		if (map_path == "NONE") {  // Генерация поля по умолчанию, если не передан адрес карты для считывания (Debug)
			size_X = 9;
			size_Y = 9;
			x_ren = (WIDTH - (STEP * size_X)) / 2 + (((double) size_X / 2 - (hero_X)) * STEP) - 0.5 * STEP;
			y_ren = (HEIGHT - (STEP * size_Y)) / 2 + (((double) size_Y / 2 - (hero_Y)) * STEP) - 0.5 * STEP;
			for (unsigned int i = 0; i < size_Y; i++) {
				std::vector<BaseSquare> row;
				for (unsigned int j = 0; j < size_X; j++) {
					if (i == j - 3) {
						row.push_back(BaseSquare(x_ren, y_ren, true, 6));
					}
					else {
						row.push_back(BaseSquare(x_ren, y_ren, true, 6));
					}
					x_ren += STEP;
				}
				y_ren += STEP;
				x_ren = (WIDTH - (STEP * size_X)) / 2 + (((double) size_X / 2 - (hero_X)) * STEP) - 0.5 * STEP;
				array.push_back(row);
			}
		}
		else {  // Генерация поля из файла, если путь до него был передан
			int counter = 0, index = 0;
			bool want_X = true;
			std::ifstream in(map_path);
			std::string line;
			if (in.is_open()) {
				while (std::getline(in, line)) {  // Построчное чтение файла
					if (want_X) {
						want_X = false;
						size_X = line.length();
					}
					index = 0;
					for (auto c : line) {  // Посимвольный разбор строки
						if (c == '<') {
							hero_way = 2;
							hero_X = index;
							hero_Y = counter;
							in.close();
							break;

						}
						else if (c == '>') {
							hero_way = 3;
							hero_X = index;
							hero_Y = counter;
							in.close();
							break;
						}
						else if (c == 'V') {
							hero_way = 0;
							hero_X = index;
							hero_Y = counter;
							in.close();
							break;
						}
						else if (c == 'A') {
							hero_way = 1;
							hero_X = index;
							hero_Y = counter;
							in.close();
							break;
						}
						index += 1;
					}
					if (!in.is_open()) {
						break;
					}
					counter += 1;
				}
			}
			counter = 0;
			std::ifstream field(map_path);
			x_ren = (WIDTH - (STEP * size_X)) / 2 + (((double)size_X / 2 - (hero_X)) * STEP) - 0.5 * STEP;
			y_ren = (HEIGHT - (STEP * size_Y)) / 2 + (((double)size_Y / 2 - (hero_Y)) * STEP) - 0.5 * STEP;
			if (field.is_open())
			{
				while (std::getline(field, line))
				{
					index = 0;
					std::vector<BaseSquare> row;
					for (auto c : line)
					{
						if (c == '<' || c == '>' || c == 'V' || c == 'A' || c == '2') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 2));
						}
						else if (c == '0') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 0));
						}
						else if (c == '1') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 1));
						}
						else if (c == '3') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 3));
						}
						else if (c == '4') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 4));
						}
						else if (c == '5') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 5));
						}
						else if (c == '6') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 6));
						}
						else if (c == '7') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 7));
						}
						else if (c == '8') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 8));
						}
						else if (c == '9') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 9));
						}
						else if (c == 'B') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 10));
						}
						else if (c == 'C') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 11));
						}
						else if (c == 'D') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 12));
						}
						else if (c == 'E') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 13));// Начало для растений
						}
						else if (c == 'F') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 14));
						}
						else if (c == 'G') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 15));
						}
						else if (c == 'H') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 16));
						}
						else if (c == 'I') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 17));
						}
						else if (c == 'J') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 18));
						}
						else if (c == 'K') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 19));
						}
						else if (c == 'L') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 20));
						}
						else if (c == 'M') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 21));
						}
						else if (c == 'N') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 22));
						}
						else if (c == 'O') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 23));
						}
						else if (c == 'P') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 24));
						}
						else if (c == 'Q') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 25));
						}
						else if (c == 'R') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 26));
						}
						else if (c == 'S') {
							row.push_back(BaseSquare(x_ren, y_ren, true, 27));
						}
						else if (c == 'Z') {
							row.push_back(BaseSquare(x_ren, y_ren, false, 99));
						}
						index += 1;
						x_ren += STEP;
					}
					counter += 1;
					array.push_back(row);
					x_ren = (WIDTH - (STEP * size_X)) / 2 + (((double)size_X / 2 - (hero_X)) * STEP) - 0.5 * STEP;
					y_ren += STEP;
				}
			}
			field.close();
			size_Y = counter;
		}
	}
	void render(sf::RenderWindow& Window) {
		sprite_background.scale(WIDTH / 2560 + 1, HEIGHT / 1440 + 1);
		Window.draw(sprite_background);
		for (const auto& inner : array) {
			for (const auto& item : inner) {
				int type = item.get_type();
				int X = item.get_x();
				int Y = item.get_y();
				if (type == 0) {  // Текстура по умолчанию
					sprite.setTexture(texture_0);
				}
				else if (type == 1) {   // Более свежая текстура камня
					sprite.setTexture(texture_stone);
				}
				else if (type == 2) {  // Текстура травы
					sprite.setTexture(texture_grass);
				}
				else if (type == 3) {  // Текстура грязи
					sprite.setTexture(texture_dirt);
				}
				else if (type == 4) {  // Текстура грядки
					sprite.setTexture(texture_garden);
				}
				else if (type == 5) {  // Текстура воды
					sprite.setTexture(texture_water);
				}
				else if (type == 6) {  // Текстура песка
					sprite.setTexture(texture_sand);
				}
				else if (type == 7) {  // Деревянный настил для большого моста
					sprite.setTexture(texture_bridge);
				}
				else if (type == 8) {  // Одиночный мост (1 клетка) слева направо
					sprite.setTexture(texture_water);
					sprite.setPosition(X, Y);
					Window.draw(sprite);
					sprite.setTexture(texture_solo_bridge);
				}
				else if (type >= 9 && type <= 12) {  // Текстуры с глыбой
					if (type == 9) {  // Текстура по умолчанию с глыбой
						sprite.setTexture(texture_0);
					}
					if (type == 10) {  // Текстура камня с глыбой
						sprite.setTexture(texture_stone);
					}
					else if (type == 11) {  // Трава с глыбой
						sprite.setTexture(texture_grass);
					}
					else if (type == 12) {  // Земля с глыбой
						sprite.setTexture(texture_dirt);
					}
					sprite.setPosition(X, Y);
					Window.draw(sprite);
					sprite.setTexture(texture_rock);
				}
				else if (type >= 13 && type <= 27) {  // Растения
					sprite.setTexture(texture_garden);
					sprite.setPosition(X, Y);
					Window.draw(sprite);
					if (type == 13) {  // Саженец пшеницы
						sprite.setTexture(texture_wheat1);
					}
					else if (type == 14) {  // Растущая пшеница
						sprite.setTexture(texture_wheat2);
					}
					else if (type == 15) {  // Выросшая пшеница
						sprite.setTexture(texture_wheat3);
					}
					else if (type == 16) {  // Собранная пшеница
						sprite.setTexture(texture_wheat4);
					}
					else if (type == 17) {  // Испорченная пшеница
						sprite.setTexture(texture_wheat5);
					}
					else if (type == 13) {  // Саженец пшеницы
						sprite.setTexture(texture_wheat1);
					}
					else if (type == 14) {  // Растущая пшеница
						sprite.setTexture(texture_wheat2);
					}
					else if (type == 15) {  // Выросшая пшеница
						sprite.setTexture(texture_wheat3);
					}
					else if (type == 16) {  // Собранная пшеница
						sprite.setTexture(texture_wheat4);
					}
					else if (type == 17) {  // Испорченная пшеница
						sprite.setTexture(texture_wheat5);
					}
					else if (type == 18) {  // Саженец картошки
						sprite.setTexture(texture_potato1);
					}
					else if (type == 19) {  // Растущая картошка
						sprite.setTexture(texture_potato2);
					}
					else if (type == 20) {  // Выросшая картошка
						sprite.setTexture(texture_potato3);
					}
					else if (type == 21) {  // Собранная картошка
						sprite.setTexture(texture_potato4);
					}
					else if (type == 22) {  // Испорченная картошка
						sprite.setTexture(texture_potato5);
					}
					else if (type == 23) {  // Саженец томата
						sprite.setTexture(texture_tomato1);
					}
					else if (type == 24) {  // Растущий томат
						sprite.setTexture(texture_tomato2);
					}
					else if (type == 25) {  // Выросший томат
						sprite.setTexture(texture_tomato3);
					}
					else if (type == 26) {  // Собранный томат
						sprite.setTexture(texture_tomato4);
					}
					else {  // Испорченный томат
						sprite.setTexture(texture_tomato5);
					}
				}
				else if (type == 99) {  // Клетка-"пустышка" - не рендерится, непроходима
					sprite.setTexture(texture_void);
				}
				sprite.setPosition(X, Y);
				Window.draw(sprite);
			}
		}
	}

	void move_field(int dX, int dY) {  // Сместить всё поле на dX по X и dY по Y
		for (int i = 0; i < size_Y; i++) {
			for (int j = 0; j < size_X; j++) {
				array[i][j].move(-dX, -dY);
			}
		}
	}

	unsigned int get_width() const{
		return size_X;
	}

	unsigned int get_height() const {
		return size_Y;
	}

	int get_hero_x() const {
		return hero_X;
	}

	int get_hero_y() const {
		return hero_Y;
	}

	int get_hero_way() const {
		return hero_way;
	}

	bool check_movable(int X, int Y) const {
		return array[Y][X].get_is_movable();
	}

	int check_type(int X, int Y) const {
		return array[Y][X].get_type();
	}

	bool is_diggable(int X, int Y) const {
		if (X >= 0 && Y >= 0 && X < size_X && Y < size_Y) {
			int type = array[Y][X].get_type();
			if (type == 3 || (type > 24 && type < 28) || (type > 14 && type < 18) || (type > 19 && type < 23)) {
				return true;
			}
		}
		return false;
	}

	void set_type(int X, int Y, int type) {
		array[Y][X].set_type(type);
	}

	void field_tick() {
		for (int y = 0; y < size_Y; y++) {
			for (int x = 0; x < size_X; x++) {
				int type = array[y][x].get_type();
				if (type == 13) {  // Саженец пшеницы подрос
					if (array[y][x].get_time() > seconds_wheat1) {
						array[y][x].set_type(14);
						array[y][x].restart_clock();
					}
				}
				else if (type == 14) {  // Растущая пшеница созрела
					if (array[y][x].get_time() > seconds_wheat2) {
						array[y][x].set_type(15);
						array[y][x].restart_clock();
					}
				}
				else if (type == 15) {  // Выросшая пшеница испортилась
					if (array[y][x].get_time() > seconds_wheat3) {
						array[y][x].set_type(17);
						array[y][x].restart_clock();
					}
				}
				else if (type == 18) {  // Саженец картошки подрос
					if (array[y][x].get_time() > seconds_potato1) {
						array[y][x].set_type(19);
						array[y][x].restart_clock();
					}
				}
				else if (type == 19) {  // Растущая картошка созрела
					if (array[y][x].get_time() > seconds_potato2) {
						array[y][x].set_type(20);
						array[y][x].restart_clock();
					}
				}
				else if (type == 20) {  // Выросшая картошка испортилась
					if (array[y][x].get_time() > seconds_potato3) {
						array[y][x].set_type(22);
						array[y][x].restart_clock();
					}
				}
				else if (type == 23) {  // Саженец томата подрос
					if (array[y][x].get_time() > seconds_tomato1) {
						array[y][x].set_type(24);
						array[y][x].restart_clock();
					}
				}
				else if (type == 24) {  // Растущий томат вырос
					if (array[y][x].get_time() > seconds_tomato2) {
						array[y][x].set_type(25);
						array[y][x].restart_clock();
					}
				}
				else if (type == 25) {  // Выросший томат испортился
					if (array[y][x].get_time() > seconds_tomato3) {
						array[y][x].set_type(27);
						array[y][x].restart_clock();
					}
				}
			}
		}
	}
};