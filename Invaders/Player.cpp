#include "Player.h"

#define MOVE_SPEED 50

Player::Player(sf::Texture& texture) : GameObject(texture) {
	m_CollisionLayer = PLAYER;
	m_Sprite.setPosition(300, 300);
}

Player::~Player(){}

void Player::Update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		m_Sprite.move(0, -MOVE_SPEED * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		m_Sprite.move(0, MOVE_SPEED * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		m_Sprite.move(MOVE_SPEED * dt, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		m_Sprite.move(-MOVE_SPEED * dt, 0);
}