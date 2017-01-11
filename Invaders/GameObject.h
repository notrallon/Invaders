#pragma once

#include "shared_defs.h"

struct GameObject {
	enum			CollisionLayers { PLAYER = 1, ENEMY, OTHER };

					GameObject(sf::Texture& texture);
					~GameObject();

	virtual void	HandleEvents();
	virtual void	Update(float dt) = 0;
	virtual bool	CheckCollision(GameObject* other);
	void			Draw(sf::RenderWindow& window);

	void			SetPositionByVec2(const sf::Vector2f& vec);
	void			SetPositionByValues(const float& x, const float& y);
	void			SetCollisionLayer(const CollisionLayers& layer);

	const int32&	GetCollisionLayer() const;
	const bool&		ShouldDestroy() const;


protected:
	sf::Sprite		m_Sprite;
	sf::Texture&	m_Texture;
	bool			m_Destroy;
	int32			m_CollisionLayer;
};