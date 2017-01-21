#pragma once

#include "GameObject.h"

struct Player : public GameObject {
					Player(sf::Texture& texture);
	virtual			~Player();

	virtual void	HandleEvents();
	virtual void	Update(float dt);
	virtual void	Destroy();
private:
	float m_ReloadTime;
	float m_LastShot;

	sf::Sound m_ShootSound;
	sf::SoundBuffer m_ShootBuffer;
};