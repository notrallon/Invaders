#pragma once

#include "shared_defs.h"
#include "GameObject.h"

struct Game {
								~Game();

	static Game* Instance() {
		if (!s_Instance) {
			s_Instance = new Game();
		}
		return s_Instance;
	}

	void						HandleEvents();
	void						Update();
	void						LateUpdate();
	void						Draw();
	void						Quit();

	void						AddGameObject(GameObject* object);

	const bool&					IsRunning() const;
	const sf::RenderWindow&		GetWindow() const;

private:
								Game();

	static Game*				s_Instance;
	sf::RenderWindow			m_Window;
	sf::Clock					m_Clock;
	sf::Time					m_ElapsedTime;

	bool						m_FullScreen;
	bool						m_Running;

	std::vector<GameObject*>	m_gos;
	std::vector<GameObject*>	m_AddingObjects;

	void						RestartClock();
};