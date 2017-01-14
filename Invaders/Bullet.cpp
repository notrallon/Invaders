#include "Bullet.h"

#define BULLET_SPEED 400

Bullet::Bullet(sf::Texture& texture, const sf::Vector2f& pos, direction_t dir) : GameObject(texture) {
	m_Sprite.setPosition(pos);
	m_Dir = dir;
}

Bullet::Bullet(sf::Texture& texture, int32 x, int32 y, direction_t dir) : GameObject(texture) {
	m_Sprite.setPosition(sf::Vector2f(x, y));
}

Bullet::~Bullet() {
	delete m_Sprite.getTexture();
}

void Bullet::Update(float dt) {

	// Destroy the bullet if it's outside the screen
	if (m_Sprite.getPosition().x < 0 || m_Sprite.getPosition().x > 1280 ||
		m_Sprite.getPosition().y < 0 || m_Sprite.getPosition().y > 720) {
		m_Destroy = true;
	}

	switch (m_Dir) {
		case direction_t::UP: {
			m_Sprite.move(sf::Vector2f(0.0f, -BULLET_SPEED * dt));
		} break;
		
		case direction_t::DOWN: {
			m_Sprite.move(sf::Vector2f(0.0f, BULLET_SPEED * dt));
		} break;
		
		case direction_t::LEFT: {
			m_Sprite.move(sf::Vector2f(-BULLET_SPEED * dt, 0.0f));
		} break;
		
		case direction_t::RIGHT: {
			m_Sprite.move(sf::Vector2f(BULLET_SPEED * dt, 0.0f));
		} break;

		default: {
		} break;
	}
}