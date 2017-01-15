#include "Player.h"
#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Player::Player(sf::Texture& texture) : GameObject(texture), m_ReloadTime(0.5f), m_LastShot(0.0f) {
	m_CollisionLayer = PLAYER;
	m_Sprite.setPosition(300, 300);
	m_HealthPoints = 2;
}

Player::~Player(){}

void Player::HandleEvents() {
 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_LastShot >= m_ReloadTime) {
		Bullet* bullet = new Bullet(TextureManager::Instance()->GetTexture("Bullet"), m_Sprite.getPosition(), direction_t::UP);
		bullet->SetCollisionLayer(PLAYER);

		Game::Instance()->AddGameObject(bullet);
		m_LastShot = 0;
	}
}

void Player::Update(float dt) {
	if (m_HealthPoints <= 0) {
		m_Destroy = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		m_Sprite.move(0, -PLAYER_MOVE_SPEED * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_Sprite.move(0, PLAYER_MOVE_SPEED * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		m_Sprite.move(PLAYER_MOVE_SPEED * dt, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		m_Sprite.move(-PLAYER_MOVE_SPEED * dt, 0);
	}
	if (m_LastShot < m_ReloadTime) {
		m_LastShot += dt;
	}
}