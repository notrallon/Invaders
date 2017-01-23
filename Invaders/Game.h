#pragma once

#include "shared_defs.h"
#include "GameObject.h"

struct Player;

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
	void						AddScore(int32 val);

	const bool&					IsRunning() const;
	const sf::RenderWindow&		GetWindow() const;

private:
								Game();

	static Game*				s_Instance;
	sf::RenderWindow			m_Window;
	sf::Clock					m_Clock;
	sf::Time					m_ElapsedTime;
	sf::View					m_GameView;
	sf::View					m_HUDView;

	bool						m_FullScreen;
	bool						m_Running;
	bool						m_Restart;

	Player*						m_Player;

	uint32						m_Score;

	// Game object vectors
	std::vector<GameObject*>	m_GameObjects;
	std::vector<GameObject*>	m_ObjectsToAdd; // Temporary holds objects and adds them at the end of each update

	// Screenshake variables
	int32						m_Shake;
	int32						m_ShakeX;
	int32						m_ShakeY;
	float						m_DefaultX;
	float						m_DefaultY;

	// Enemy spawn variables
	float						m_RespawnRate;
	float						m_LastEnemySpawn;

	// Variables to increase difficulty over time
	float						m_IncreaseDiffRate;
	float						m_DifficultyTimer;

	// Font & Text
	sf::Font					m_FontHUD;
	sf::Text					m_TextScore;
	sf::Text					m_TextLife;

	void						RestartClock();
	bool						SpawnEnemy(const float& dt);
};