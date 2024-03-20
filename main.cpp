#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

const unsigned int WIDTH = 2560, HEIGHT = 1440, CIRCLE_RADIUS = 50;
float STEP = 10.0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "111");  /*, sf::Style::Fullscreen*/
    window.setVerticalSyncEnabled(true);
    sf::CircleShape shape(CIRCLE_RADIUS);
    shape.setFillColor(sf::Color(255, 255, 255));
    shape.setPosition(WIDTH / 2 - CIRCLE_RADIUS , HEIGHT / 2 - CIRCLE_RADIUS);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                shape.move(-STEP, 0.0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                shape.move(STEP, 0.0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                shape.move(0.0, -STEP);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                shape.move(0.0, STEP);
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}