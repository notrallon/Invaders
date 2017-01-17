#include "Enemy.h"
#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Enemy::Enemy(sf::Texture& texture) : GameObject(texture), m_Dir(1) {
	m_Sprite.setPosition(200, 200);
	m_CollisionLayer = ENEMY;
	m_HealthPoints = 1;
	m_ReloadTime = 1.0f;
	m_LastShot = 0.0f;
}

Enemy::~Enemy() {}

void Enemy::Update(float dt) {
	m_Sprite.move(sf::Vector2f(m_Dir * (ENEMY_SHIP_MOVE_SPEED * dt), (ENEMY_SHIP_MOVE_SPEED / 10) * dt));

	if (m_HealthPoints <= 0) {
		m_Destroy = true;
	}

	if ((m_Sprite.getPosition().x + (m_Sprite.getTexture()->getSize().x / 2.0f)) >= Game::Instance()->GetWindow().getSize().x) {
		m_Dir = -1;
	}
	else if ((m_Sprite.getPosition().x - (m_Sprite.getTexture()->getSize().x / 2.0f)) <= 0) {
		m_Dir = 1;
	}

	if (m_LastShot < m_ReloadTime) {
		m_LastShot += dt;
	} else {
		Bullet* bullet = new Bullet(TextureManager::Instance()->GetTexture("Bullet"), m_Sprite.getPosition(), direction_t::DOWN);
		bullet->SetCollisionLayer(ENEMY);

		Game::Instance()->AddGameObject(bullet);
		m_LastShot = 0;
	}
}

bool Enemy::CheckCollision(GameObject* other) {
	if (other->GetCollisionLayer() != PLAYER) {
		return false;
	}

	//m_Destroy = GameObject::CheckCollision(other);
	return GameObject::CheckCollision(other);
}