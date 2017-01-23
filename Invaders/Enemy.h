#pragma once

#include "GameObject.h"

struct Enemy : public GameObject {
					Enemy(sf::Texture& texture);
					~Enemy();

	virtual void	Update(float dt);

private:
	int32			m_Dir;
	float			m_ReloadTime;
	float			m_LastShot;
};