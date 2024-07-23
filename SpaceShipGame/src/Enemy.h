#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(float size, int side, sf::Color color, float angle, float posX, float posY);
	void Move();
	void drawEnemy(sf::RenderWindow& window) const;

private:
	sf::CircleShape enemy;
};