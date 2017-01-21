#pragma once

#include "shared_defs.h"
#include "GameObject.h"

struct Game {
								~Game();

	static Game* Instance() {
		if (s_Instance == 0) {
			s_Instance = new Game();
		}
		return s_Instance;
	}

	void						Init();
	void						Restart();

	void						HandleEvents();
	void						Update();
	void						LateUpdate();
	void						Draw();
	void						Quit();

	void						AddGameObject(GameObject* object);
	void						AddShake(int32 val);

	const bool&					IsRunning() const;
	const sf::RenderWindow&		GetWindow() const;

private:
								Game();

	static Game*				s_Instance;
	sf::RenderWindow			m_Window;
	sf::Clock					m_Clock;
	sf::Time					m_ElapsedTime;
	sf::View					m_View;

	bool						m_FullScreen;
	bool						m_Running;
	bool						m_Restart;

	// Game object vectors
	std::vector<GameObject*>	m_gos;
	std::vector<GameObject*>	m_ObjectsToAdd; // Temporary holds objects and adds them at the end of each update

	// Screenshake variables
	int32						m_Shake;
	int32						m_ShakeX;
	int32						m_ShakeY;
	float						m_DefaultX;
	float						m_DefaultY;
	const int32					SHAKE_MAX = 10;

	// Enemy spawn variables
	float						m_RespawnTime;
	float						m_LastEnemy;

	void						RestartClock();
	bool						SpawnEnemy(const float& dt);
};