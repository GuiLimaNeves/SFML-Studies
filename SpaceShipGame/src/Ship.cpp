#include "Ship.h"
#include <iostream>

Ship::Ship(float size, int side, sf::Color color, float angle, float posX, float posY) : windowWidth(800), windowHeight(600)
{
    ship.setRadius(size);
    ship.setPointCount(side);
    ship.setFillColor(color);
    ship.setPosition(posX, posY);
    ship.setRotation(angle);
}
void Ship::Move()
{
    sf::Vector2f position = ship.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sf::Vector2f position = ship.getPosition();
        ship.setPosition(position + sf::Vector2f(-speed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sf::Vector2f position = ship.getPosition();
        ship.setPosition(position + sf::Vector2f(speed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        sf::Vector2f position = ship.getPosition();
        ship.setPosition(position + sf::Vector2f(0, -speed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        sf::Vector2f position = ship.getPosition();
        ship.setPosition(position + sf::Vector2f(0, speed));
    }
    //-------------------------------------colisao-----------------------------------------------
    if (ship.getPosition().x < 0.f)
    {
        ship.setPosition(0.f, ship.getPosition().y);
    }
    if (ship.getPosition().y < 0.f)
    {
        ship.setPosition(ship.getPosition().x, 0.f);
    }
    if (ship.getPosition().x + ship.getGlobalBounds().width > windowWidth)
    {
        ship.setPosition(windowWidth - ship.getGlobalBounds().width, ship.getPosition().y);
    }
    if (ship.getPosition().y + ship.getGlobalBounds().height > windowHeight)
    {
        ship.setPosition(ship.getPosition().x, windowHeight - ship.getGlobalBounds().height);
    }
    //----------------------------------------tiro-------------------------------------------------
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        std::cout << "space key is pressed" << std::endl;
        tiros.push_back(sf::RectangleShape(sf::Vector2f(6.0f, -30.0f)));
        int i = tiros.size() - 1;
        tiros[i].setPosition(ship.getPosition().x + ship.getRadius() - 3, ship.getPosition().y);
        tiroDirection = sf::Vector2f(0.0f, -40.0f);
        //tiroDirection = TiroNormalizado(tiroDirection);
    }
    for (size_t i = 0; i < tiros.size(); i++)
    {
        tiros[i].setPosition(tiros[i].getPosition() + tiroDirection * speed);
    } 
}
void Ship::drawShip(sf::RenderWindow& window) 
{
    window.draw(ship);
    for (size_t i = 0; i < tiros.size(); i++)
    {
        tiros[i].setFillColor(sf::Color::Red);
        window.draw(tiros[i]); //APAGAR A BALA
    }
}
