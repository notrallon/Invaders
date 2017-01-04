#pragma once

#include "shared_defs.h"
#include "GameObject.h"

struct Game {
						Game();
						~Game();

	void				HandleEvents();
	void				Update();
	void				LateUpdate();
	void				Draw();
	void				Quit();

	const bool&			IsRunning() const;

private:
	sf::RenderWindow			m_Window;
	sf::Clock					m_Clock;
	sf::Time					m_ElapsedTime;

	bool						m_FullScreen;
	bool						m_Running;

	std::vector<GameObject*>	m_gos;

	void						RestartClock();
};