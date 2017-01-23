#pragma once

#include "shared_defs.h"

struct GameObject {
								GameObject(sf::Texture& texture);
	virtual						~GameObject() {}

	virtual void				Update(float dt) = 0;
	virtual bool				CheckCollision(GameObject* other);
	void						Draw(sf::RenderWindow& window);

	void						SetPositionVec2(const sf::Vector2f& vec);
	void						SetPosition(const float& x, const float& y);
	void						SetCollisionLayer(const collisionLayer_t& layer);

	void						TakeDamage(const int32& damage);

	const collisionLayer_t&		GetCollisionLayer() const;
	const bool&					ShouldDestroy() const;

	virtual void				Destroy();

protected:
	sf::Sprite			m_Sprite;
	bool				m_Destroy;
	collisionLayer_t	m_CollisionLayer;
	int32				m_HealthPoints;
};