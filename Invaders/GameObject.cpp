#include "GameObject.h"

GameObject::GameObject(sf::Texture& texture) : m_Sprite(texture), m_Destroy(false) {
	m_Sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

GameObject::~GameObject() {}

bool GameObject::CheckCollision(GameObject* other) {
	sf::Vector2f distVec = m_Sprite.getPosition() - other->m_Sprite.getPosition();
	float distMag = sqrtf(distVec.x * distVec.x + distVec.y * distVec.y);

	float radius = m_Sprite.getLocalBounds().width / 2.0f;
	float otherRadius = other->m_Sprite.getLocalBounds().width / 2.0f;

	return distMag < (radius + otherRadius);
}

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(m_Sprite);
}

const int32& GameObject::GetCollisionLayer() const {
	return m_CollisionLayer;
}

const bool& GameObject::ShouldDestroy() const {
	return m_Destroy;
}
