#pragma once

#include "GameObject.h"

#define BULLET_SPEED 250.0f;

struct Bullet : public GameObject {
					Bullet(sf::Texture& texture, const sf::Vector2f& pos, direction_t dir);
					Bullet(sf::Texture& texture, int32 x, int32 y, direction_t dir);
					~Bullet();

	virtual void	Update(float dt);

private:
	direction_t m_Dir;
};