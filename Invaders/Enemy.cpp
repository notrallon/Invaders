#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture) : GameObject(texture), m_Dir(1) {
	m_Sprite.setPosition(200, 200);
}

Enemy::~Enemy() {}

void Enemy::Update(float dt) {
	m_Sprite.move(sf::Vector2f(m_Dir * (50.0f * dt), 0.0f));

	if ((m_Sprite.getPosition().x + (m_Sprite.getTexture()->getSize().x / 2.0f)) >= 1280) {
		m_Dir = -1;
	}
	else if ((m_Sprite.getPosition().x - (m_Sprite.getTexture()->getSize().x / 2.0f)) <= 0) {
		m_Dir = 1;
	}
}