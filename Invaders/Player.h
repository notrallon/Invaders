#pragma once

#include "GameObject.h"

struct Player : public GameObject {
					Player(sf::Texture& texture);
					~Player();

	virtual void	HandleEvents();
	virtual void	Update(float dt);
};