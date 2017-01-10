#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game::Game() : m_FullScreen(false), m_Running(true) {
	uint32 style = (m_FullScreen ? sf::Style::Fullscreen : sf::Style::Close);
	m_Window.create({ 1280, 720, 32 }, "Invaders", style);
	m_Window.setFramerateLimit(125);

	sf::Texture* playerTexture = new sf::Texture;
	if (!playerTexture->loadFromFile("assets/sprites/ship.png")) {
		std::cout << "Could not load playertexture!\n";
	}

	Player* player = new Player(*playerTexture);
	m_gos.push_back(player);

	sf::Texture* enemyTexture = new sf::Texture;
	if (!enemyTexture->loadFromFile("assets/sprites/enemy.png")) {
		std::cout << "Could not load enemytexture!\n";
	}

	Enemy* enemy = new Enemy(*enemyTexture);
	m_gos.push_back(enemy);

	enemy = new Enemy(*enemyTexture);
	enemy->SetPositionByValues(250, 250);
	m_gos.push_back(enemy);
}

Game::~Game() {
}

void Game::HandleEvents() {
	sf::Event evnt;

	while (m_Window.pollEvent(evnt)) {
		switch (evnt.type) {
			case sf::Event::Closed: {
				m_Running = false;
			} break;
			
			default: {
			} break;
		}
	}
}

void Game::Update() {
	std::vector<GameObject*>::iterator itr;

	for (itr = m_gos.begin(); itr != m_gos.end(); itr++) {
		(*itr)->Update(m_ElapsedTime.asSeconds());
	}
}

void Game::LateUpdate() {
	RestartClock();
}

void Game::Draw() {
	m_Window.clear();
	std::vector<GameObject*>::iterator itr;

	for (itr = m_gos.begin(); itr != m_gos.end(); itr++) {
		(*itr)->Draw(m_Window);
	}
	m_Window.display();
}

void Game::Quit() {
	m_Running = false;
}

const bool& Game::IsRunning() const {
	return m_Running;
}

const sf::RenderWindow& Game::GetWindow() const {
	return m_Window;
}

void Game::RestartClock() {
	m_ElapsedTime = m_Clock.restart();
}
