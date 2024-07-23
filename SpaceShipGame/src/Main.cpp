#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <iostream>
#include "Enemy.h"
#include "Ship.h"

sf::Vector2f TiroNormalizado(sf::Vector2f vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;

    return normalizedVector;
}

int main()
{
    int windowWidth = 800;
    int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Space Ship Game");

    sf::Vector2f tiroDirection;

    Ship newShip(40.f, 3, sf::Color::Blue, 0, 360.f, 500.f);
    Enemy newEnemy(40.0f, 4, sf::Color::Yellow, 45.f, 100.f, 100.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }          
        }
        newShip.Move();
        newEnemy.Move();

        window.clear(sf::Color::Black);

        newShip.drawShip(window);
        newEnemy.drawEnemy(window);

        window.display();
    }
    return 0;
}