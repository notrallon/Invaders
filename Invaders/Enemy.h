#pragma once

#include "GameObject.h"

struct Enemy : public GameObject {
					Enemy(sf::Texture& texture);
					~Enemy();

	virtual void	Update(float dt);

private:
	int m_Dir;
};