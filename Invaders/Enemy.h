#pragma once

#include "GameObject.h"

struct Enemy : public GameObject {
					Enemy(sf::Texture& texture);
					~Enemy();

	virtual void	Update(float dt);
};