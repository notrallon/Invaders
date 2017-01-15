#include "GameObject.h"

GameObject::GameObject(sf::Texture& texture) : 
	m_Sprite(texture), 
	m_Destroy(false) {
	m_Sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}

GameObject::~GameObject() {
}

void GameObject::HandleEvents(){}

bool GameObject::CheckCollision(GameObject* other) {
	if (m_CollisionLayer == other->GetCollisionLayer()) {
		return false;
	}

	/*sf::Vector2f distVec = m_Sprite.getPosition() - other->m_Sprite.getPosition();
	float distMag = sqrtf(distVec.x * distVec.x + distVec.y * distVec.y);

	float radius = m_Sprite.getLocalBounds().width / 2.0f;
	float otherRadius = other->m_Sprite.getLocalBounds().width / 2.0f;

	return distMag < (radius + otherRadius);*/

	bool collision = m_Sprite.getGlobalBounds().intersects(other->m_Sprite.getGlobalBounds());

	if (collision) {
		m_HealthPoints--;
	}

	return m_Sprite.getGlobalBounds().intersects(other->m_Sprite.getGlobalBounds());;
}

void GameObject::Draw(sf::RenderWindow& window) {
	window.draw(m_Sprite);
}

void GameObject::SetPositionByVec2(const sf::Vector2f& vec) {
	m_Sprite.setPosition(vec);
}

void GameObject::SetPositionByValues(const float& x, const float& y) {
	m_Sprite.setPosition(sf::Vector2f(x, y));
}

void GameObject::SetCollisionLayer(const CollisionLayers& layer) {
	m_CollisionLayer = layer;
}

const int32& GameObject::GetCollisionLayer() const {
	return m_CollisionLayer;
}

const bool& GameObject::ShouldDestroy() const {
	return m_Destroy;
}
