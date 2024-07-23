#pragma once
#include <SFML/Graphics.hpp>

class Ship
{
public:
	Ship(float size, int side, sf::Color color, float angle, float posX, float posY);
	void Move();
	void drawShip(sf::RenderWindow& window);
	
private:
	sf::CircleShape ship;
	std::vector<sf::RectangleShape> tiros;
	sf::Vector2f tiroDirection;
    float speed = 0.25f;
	float windowWidth;
	float windowHeight;
};