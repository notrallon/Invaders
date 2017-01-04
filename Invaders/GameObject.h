#pragma once

#include "shared_defs.h"

struct GameObject {
					GameObject(sf::Texture& texture);
					~GameObject();

	virtual void	Update(float dt) = 0;
	virtual bool	CheckCollision(GameObject* other);
	void			Draw(sf::RenderWindow& window);

	const int32&	GetCollisionLayer() const;
	const bool&		ShouldDestroy() const;

	enum CollisionLayers { PLAYER = 1, ENEMY, OTHER };

protected:
	sf::Sprite		m_Sprite;
	bool			m_Destroy;
	int32			m_CollisionLayer;
};