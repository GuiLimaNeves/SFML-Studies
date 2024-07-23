#include "Enemy.h"

Enemy::Enemy(float size, int side, sf::Color color, float angle, float posX, float posY)
{
    enemy.setRadius(size); 
    enemy.setPointCount(side); 
    enemy.setFillColor(color);
    enemy.setPosition(posX, posY);
    enemy.setRotation(angle);
}
void Enemy::Move()
{

}
void Enemy::drawEnemy(sf::RenderWindow &window) const
{
	window.draw(enemy);
}
