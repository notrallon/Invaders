#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, const sf::Vector2f& pos) : GameObject(texture) {
	m_Sprite.setPosition(pos);
}

Bullet::Bullet(sf::Texture& texture, int32 x, int32 y) : GameObject(texture) {
	m_Sprite.setPosition(sf::Vector2f(x, y));
}

Bullet::~Bullet() {}

void Bullet::Update(float dt) {

}