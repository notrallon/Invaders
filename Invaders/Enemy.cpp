#include "Enemy.h"

Enemy::Enemy(sf::Texture& texture) : GameObject(texture), m_Dir(1) {
	m_Sprite.setPosition(200, 200);
	m_CollisionLayer = ENEMY;
}

Enemy::~Enemy() {}

void Enemy::Update(float dt) {
	//m_Sprite.move(sf::Vector2f(m_Dir * (ENEMY_SHIP_MOVE_SPEED * dt), 0.0f * dt));

	if ((m_Sprite.getPosition().x + (m_Sprite.getTexture()->getSize().x / 2.0f)) >= 1280) {
		m_Dir = -1;
	}
	else if ((m_Sprite.getPosition().x - (m_Sprite.getTexture()->getSize().x / 2.0f)) <= 0) {
		m_Dir = 1;
	}

	if (m_LastShot < m_ReloadTime) {
		m_LastShot += dt;
	}
}

bool Enemy::CheckCollision(GameObject* other) {
	if (other->GetCollisionLayer() != PLAYER) {
		return false;
	}

	m_Destroy = GameObject::CheckCollision(other);
	return m_Destroy;
}