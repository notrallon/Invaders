#pragma once

#include "GameObject.h"

#define BULLET_SPEED 250.0f;

struct Bullet : public GameObject {
	Bullet(sf::Texture& texture, const sf::Vector2f& pos);
	Bullet(sf::Texture& texture, int32 x, int32 y);
	~Bullet();

	virtual void Update(float dt);
};