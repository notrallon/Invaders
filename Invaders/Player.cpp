#include "Player.h"
#include "Bullet.h"
#include "Game.h"
#include "TextureManager.h"

Player::Player(sf::Texture& texture) : GameObject(texture), m_ReloadTime(0.3f), m_LastShot(0.0f) {
	m_CollisionLayer = PLAYER;

	
	m_Sprite.setPosition(1280 / 2, 720 * 0.8);
	m_HealthPoints = 4;

	if (!m_ShootBuffer.loadFromFile("assets/sound/sfx/sfx_laser1.ogg")) {
		std::cout << "Could not load sound file\n";
	}
	m_ShootSound.setBuffer(m_ShootBuffer);
}

Player::~Player(){
}

void Player::HandleEvents() {
 	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_LastShot >= m_ReloadTime) {
		Bullet* bullet = new Bullet(TextureManager::Instance()->GetTexture("PlayerBullet"), m_Sprite.getPosition(), direction_t::UP);
		bullet->SetCollisionLayer(PLAYER);

		Game::Instance()->AddGameObject(bullet);
		Game::Instance()->AddShake(10);

		m_LastShot = 0;
		m_ShootSound.play();
	}

}

void Player::Update(float dt) {
	if (m_HealthPoints <= 0) {
		Game::Instance()->Restart();
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

void Player::Destroy() {
	Game::Instance()->Restart();
}