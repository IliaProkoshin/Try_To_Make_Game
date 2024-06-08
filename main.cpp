#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "MainHero.h"
#include "Field.h"
//#include <iostream>
#include <cstdlib>


sf::VideoMode resolution = sf::VideoMode::getDesktopMode();  // Получение разрешения экрана
sf::Color MASK_COLOR = sf::Color(255, 0, 247);  // Задание цвета маски, т.е. такого цвета, который будет заменяться на прозрачный

unsigned int WIDTH = resolution.width, HEIGHT = resolution.height, STEP_LEN = 300;
double STEP = 132.0;
std::string PATH_TO_MAP = "data/maps/map_test.txt", PATH_TO_ICON = "data/images/icon.png";  // Задание констант

int main(){
    sf::RenderWindow window(resolution, "Darkest Seedling DEMO", sf::Style::Fullscreen);

    sf::Image icon;
    icon.loadFromFile(PATH_TO_ICON);
    window.setIcon(64, 64, icon.getPixelsPtr());
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false); //Можно отключить, тогда игрок будет двигаться при зажатии клавиш
    Field field = Field(PATH_TO_MAP);
    MainHero hero = MainHero(&field);
    while (window.isOpen())  // Основной цикл игры
    {
        hero.GlobalRender(window, field);  // Отрисовка игры
        sf::Event event;
        field.field_tick();
        while (window.pollEvent(event))  // Цикл обработки событий
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))  // Закрытие окна по нажатию Escape
            {
                window.close();
            }
            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
            {
                hero.setOrientation(2, window, field);
            }
            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
            {
                hero.setOrientation(3, window, field);
            }
            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
            {
                hero.setOrientation(1, window, field);
            }
            else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
            {
                hero.setOrientation(0, window, field);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                hero.move(-1, 0, window, field);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                hero.move(1, 0, window, field);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                hero.move(0, -1, window, field);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                hero.move(0, 1, window, field);
            }
            else if ((event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)) {
                hero.dig(window, field);
            }
        }
    }
    return 0;
}