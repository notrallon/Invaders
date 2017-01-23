#include "Enemy.h"
#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Enemy::Enemy(sf::Texture& texture) : GameObject(texture) {
	m_Sprite.setPosition(200, 200);
	m_CollisionLayer = ENEMY;
	m_HealthPoints = 1;
	m_LastShot = 0.0f;
	m_ReloadTime = 0.7f;

	m_Dir = (rand() % 3) - 1; // Set direction between -1 to +1

	if (m_Dir == 0) {
		m_ReloadTime *= 2.0f;
	}
}

Enemy::~Enemy() {
	Game::Instance()->AddScore(25);
	Game::Instance()->AddShake(10);
}

void Enemy::Update(float dt) {
	m_Sprite.move(sf::Vector2f(m_Dir * (ENEMY_SHIP_MOVE_SPEED * dt), (ENEMY_SHIP_MOVE_SPEED / 5) * dt));

	if (m_HealthPoints <= 0) {
		m_Destroy = true;
	}

	// If position is to the far right or far left of the screen
	// Change direction
	if ((m_Sprite.getPosition().x + (m_Sprite.getTexture()->getSize().x / 2.0f)) >= Game::Instance()->GetWindow().getSize().x ||
		(m_Sprite.getPosition().x - (m_Sprite.getTexture()->getSize().x / 2.0f)) <= 0) {
		m_Dir *= -1;
	}

	if (m_LastShot < m_ReloadTime) {
		m_LastShot += dt;
	} else {
		Bullet* bullet = new Bullet(TextureManager::Instance()->GetTexture("EnemyBullet"), m_Sprite.getPosition(), direction_t::DOWN, m_CollisionLayer);

		Game::Instance()->AddGameObject(bullet);
		m_LastShot = 0;
	}
}