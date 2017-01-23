#pragma once

#include "GameObject.h"

struct Player : public GameObject {
					Player(sf::Texture& texture);
	virtual			~Player();

	virtual void	Update(float dt);
	virtual void	Destroy();

	const int32&	GetLife() const;
private:
	float m_ReloadTime;
	float m_LastShot;

	sf::Sound m_ShootSound;
	sf::SoundBuffer m_ShootBuffer;
};