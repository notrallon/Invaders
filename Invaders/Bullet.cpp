#include "Bullet.h"

Bullet::Bullet(sf::Texture& texture, const sf::Vector2f& pos) : GameObject(texture) {
}

Bullet::Bullet(sf::Texture& texture, int32 x, int32 y) : GameObject(texture) {

}

Bullet::~Bullet() {}

void Bullet::Update(float dt) {

}