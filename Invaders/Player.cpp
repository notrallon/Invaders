#include "Player.h"
#include "Bullet.h"
#include "Game.h"

Player::Player(sf::Texture& texture) : GameObject(texture) {
	m_CollisionLayer = PLAYER;
	m_Sprite.setPosition(300, 300);
}

Player::~Player(){}

void Player::HandleEvents() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		sf::Texture* bulletTex = new sf::Texture;
		if (!bulletTex->loadFromFile("assets/sprites/bullet.png")) {
			std::cout << "Could not load bullet.png!\n";
		}

		Bullet* bullet = new Bullet(*bulletTex, m_Sprite.getPosition());
		bullet->SetCollisionLayer(ENEMY);


		Game::Instance()->AddGameObject(bullet);
	}
}

void Player::Update(float dt) {

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
}