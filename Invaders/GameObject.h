#pragma once

#include "shared_defs.h"

struct GameObject {
	enum			CollisionLayers { NONE, PLAYER, ENEMY, OTHER };

					GameObject(sf::Texture& texture);
	virtual			~GameObject() {}

	virtual void	HandleEvents();
	virtual void	Update(float dt) = 0;
	virtual bool	CheckCollision(GameObject* other);
	void			Draw(sf::RenderWindow& window);

	void			SetPositionByVec2(const sf::Vector2f& vec);
	void			SetPositionByValues(const float& x, const float& y);
	void			SetCollisionLayer(const CollisionLayers& layer);

	const int32&	GetCollisionLayer() const;
	const bool&		ShouldDestroy() const;

	virtual void	Destroy();


protected:
	sf::Sprite		m_Sprite;
	bool			m_Destroy;
	int32			m_CollisionLayer;
	int32			m_HealthPoints;
};