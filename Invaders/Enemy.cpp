#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture) : GameObject(texture) {
	m_Sprite.setPosition(200, 200);
}

Enemy::~Enemy() {}

void Enemy::Update(float dt) {
	m_Sprite.move(sf::Vector2f(50.0f * dt, 0.0f * dt));
}