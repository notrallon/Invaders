#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(sf::Texture& texture) : 
	m_Sprite(texture), 
	m_Destroy(false) {
	m_Sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}

bool GameObject::CheckCollision(GameObject* other) {
	if (m_CollisionLayer == other->GetCollisionLayer() || 
		m_CollisionLayer == NONE || 
		other->GetCollisionLayer() == NONE) {
		return false;
	}

	return m_Sprite.getGlobalBounds().intersects(other->m_Sprite.getGlobalBounds());;
}

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(m_Sprite);
}

void GameObject::SetPositionVec2(const sf::Vector2f& vec) {
	m_Sprite.setPosition(vec);
}

void GameObject::SetPosition(const float& x, const float& y) {
	m_Sprite.setPosition(sf::Vector2f(x, y));
}

void GameObject::SetCollisionLayer(const collisionLayer_t& layer) {
	m_CollisionLayer = layer;
}

void GameObject::TakeDamage(const int32& damage) {
	m_HealthPoints -= damage;
}

const collisionLayer_t& GameObject::GetCollisionLayer() const {
	return m_CollisionLayer;
}

const bool& GameObject::ShouldDestroy() const {
	return (m_HealthPoints <= 0) || m_Destroy;
}

void GameObject::Destroy() {
	delete this;
}
