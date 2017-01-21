#pragma once

#include "GameObject.h"

struct Enemy : public GameObject {
					Enemy(sf::Texture& texture);
					~Enemy();

	virtual void	Update(float dt);
	virtual bool	CheckCollision(GameObject* other);

private:
	int32 m_Dir;
	float m_ReloadTime;
	float m_LastShot;

	sf::Sound		m_ShootSound;
	sf::SoundBuffer m_ShootBuffer;
};