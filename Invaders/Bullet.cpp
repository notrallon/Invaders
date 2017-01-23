#include "Bullet.h"
#include "Game.h"

#define BULLET_SPEED 500

Bullet::Bullet(sf::Texture& texture, const sf::Vector2f& pos, direction_t dir, collisionLayer_t layer) : GameObject(texture) {
	m_Sprite.setPosition(pos);
	m_Dir				= dir;
	m_HealthPoints		= 1;
	m_CollisionLayer	= layer;
}

Bullet::Bullet(sf::Texture& texture, int32 x, int32 y, direction_t dir, collisionLayer_t layer) : GameObject(texture) {
	m_Sprite.setPosition(sf::Vector2f(x, y));
	m_Dir				= dir;
	m_HealthPoints		= 1;
	m_CollisionLayer	= layer;
}

Bullet::~Bullet() {
}

void Bullet::Update(float dt) {
	if (m_HealthPoints <= 0) {
		m_Destroy = true;
	}
	// Destroy the bullet if it's outside the screen
	if (m_Sprite.getPosition().x < 0 || 
		m_Sprite.getPosition().y < 0 || 
		m_Sprite.getPosition().x > Game::Instance()->GetWindow().getSize().x ||
		m_Sprite.getPosition().y > Game::Instance()->GetWindow().getSize().y) {
		m_Destroy = true;
	}

	switch (m_Dir) {
		case direction_t::UP: {
			m_Sprite.move(sf::Vector2f(0.0f, -BULLET_SPEED * dt));
		} break;
		
		case direction_t::DOWN: {
			m_Sprite.move(sf::Vector2f(0.0f, BULLET_SPEED * dt));
			m_Sprite.setRotation(180);
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