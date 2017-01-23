#include <ctime>
#include <sstream>

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"

Game* Game::s_Instance = 0;

#define DIFFICULTY_INCREASE_RATE 15.0f

Game::Game() : 
	m_FullScreen(false), 
	m_Running(true), 
	m_Restart(false), 
	m_Shake(1) {
	uint32 style = (m_FullScreen ? sf::Style::Fullscreen : sf::Style::Close);
	m_Window.create({ 1280, 720, 32 }, "Invaders", style);
	m_Window.setFramerateLimit(60);
	m_GameView.setSize(sf::Vector2f(m_Window.getSize()));
	m_GameView.setCenter(m_Window.getSize().x / 2.0f, m_Window.getSize().y / 2.0f);
	m_HUDView.setSize(sf::Vector2f(m_Window.getSize()));
	m_HUDView.setCenter(m_Window.getSize().x / 2.0f, m_Window.getSize().y / 2.0f);

	// Load all the textures we're going to need
	TextureManager::Instance()->LoadTexture("assets/sprites/playerShip1_orange.png", "PlayerShip");
	TextureManager::Instance()->LoadTexture("assets/sprites/enemyBlack2.png", "EnemyShip");
	TextureManager::Instance()->LoadTexture("assets/sprites/laserRed01.png", "EnemyBullet");
	TextureManager::Instance()->LoadTexture("assets/sprites/laserGreen11.png", "PlayerBullet");

	m_DefaultX = m_Window.getSize().x / 2.0f;
	m_DefaultY = m_Window.getSize().y / 2.0f;

	if (!m_FontHUD.loadFromFile("assets/fonts/kenvector_future.ttf")) {
		std::cout << "Could not load font kenvector_future.ttf\n";
	}

	m_TextLife.setFont(m_FontHUD);
	m_TextLife.setPosition(sf::Vector2f(45, 30));
	m_TextLife.setString("Life: ");
	m_TextScore.setFont(m_FontHUD);
	m_TextScore.setPosition(sf::Vector2f(m_Window.getSize().x / 2.0f, 30.0f));
	m_TextScore.setString("Score: ");

	Init();
}

Game::~Game() {
}

void Game::Init() {
	srand(time(NULL));
	m_RespawnRate		= 3.0f;
	m_LastEnemySpawn	= 0.0f;
	m_IncreaseDiffRate	= 15.0f;
	m_DifficultyTimer	= 0.0f;
	m_Score				= 0;
	m_Restart			= false;
	m_Player			= new Player(TextureManager::Instance()->GetTexture("PlayerShip"));
	m_GameObjects.push_back(m_Player);

}

void Game::Restart() {
	m_Restart = true;
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
	std::vector<GameObject*>::iterator itr; // GameObject iterator
	float dt = m_ElapsedTime.asSeconds();
	m_DifficultyTimer += dt;

	// Spawn Enemy
	if (SpawnEnemy(dt)) {
		Enemy* enemy = new Enemy(TextureManager::Instance()->GetTexture("EnemyShip"));
		enemy->SetPosition(rand() % m_Window.getSize().x, 0);
		AddGameObject(enemy);
		m_LastEnemySpawn = 0;
	}

	// Check if we should reduce the respawnrate
	if (m_DifficultyTimer > DIFFICULTY_INCREASE_RATE) {
		m_DifficultyTimer -= DIFFICULTY_INCREASE_RATE;
		m_RespawnRate *= 0.9f; // Decrease the time between spawning enemies by 10 percent
	}

	std::stringstream strstream;
	strstream << "Life: " << m_Player->GetLife() << std::endl;
	m_TextLife.setString(strstream.str());

	strstream.str("");

	strstream << "Score: " << m_Score;
	m_TextScore.setString(strstream.str());

	// Add shake if shake is greater than 0
	if (m_Shake > 0) {
		m_ShakeX = rand() % (m_Shake * 2) - m_Shake;
		m_ShakeY = rand() % (m_Shake * 2) - m_Shake;
		m_Shake--;
	}

	// Calculate view
	float ViewX = m_GameView.getViewport().width;
	float ViewY = m_GameView.getViewport().height;
	
	ViewX += m_ShakeX;
	ViewY += m_ShakeY;

	sf::FloatRect pos(ViewX / 2.0f,
					  ViewY / 2.0f,
					  m_Window.getSize().x,
					  m_Window.getSize().y);
	m_GameView.reset(pos);

	// Update all objects
	for (itr = m_GameObjects.begin(); itr != m_GameObjects.end(); itr++) {
		(*itr)->Update(dt);
	}

	// Check all objects for collision
	for (itr = m_GameObjects.begin(); itr != m_GameObjects.end(); itr++) {
		for (auto itr2 = itr + 1; itr2 != m_GameObjects.end(); itr2++) {
			if ((*itr)->CheckCollision(*itr2)) {
				(*itr)->TakeDamage(1);
				(*itr2)->TakeDamage(1);
				AddShake(5);
			}
		}
	}
}

void Game::LateUpdate() {
	std::vector<GameObject*>::iterator itr;

	for (itr = m_GameObjects.begin(); itr != m_GameObjects.end();) {
		if ((*itr)->ShouldDestroy()) {
			(*itr)->Destroy();
			itr = m_GameObjects.erase(itr);
		} else {
			itr++;
		}
	}

	for (itr = m_ObjectsToAdd.begin(); itr != m_ObjectsToAdd.end(); itr++) {
		m_GameObjects.push_back(*itr);
	}
	m_ObjectsToAdd.clear();

	if (m_Restart) {
		// Delete all objects before restarting the game
		for (itr = m_GameObjects.begin(); itr != m_GameObjects.end(); ) {
			(*itr)->Destroy();
			itr = m_GameObjects.erase(itr);
		}
		m_GameObjects.clear();
		// Run init to start the game from scratch
		Init();
	}

	RestartClock();
}

void Game::Draw() {
	m_Window.clear();
	std::vector<GameObject*>::iterator itr;
	m_Window.setView(m_GameView);

	for (itr = m_GameObjects.begin(); itr != m_GameObjects.end(); itr++) {
		(*itr)->Draw(m_Window);
	}

	m_Window.setView(m_HUDView);
	m_Window.draw(m_TextLife);
	m_Window.draw(m_TextScore);

	m_Window.display();
}

void Game::Quit() {
	m_Running = false;
}

void Game::AddGameObject(GameObject* object) {
	m_ObjectsToAdd.push_back(object);
}

void Game::AddShake(int32 val) {
	m_Shake += val;
}

void Game::AddScore(int32 val) {
	m_Score += val;
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

bool Game::SpawnEnemy(const float& dt) {
	m_LastEnemySpawn += dt;

	return m_LastEnemySpawn > m_RespawnRate;
}
