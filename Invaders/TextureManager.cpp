#include "TextureManager.h"

TextureManager* TextureManager::s_Instance = 0;

TextureManager::~TextureManager() {}

void TextureManager::LoadTexture(const std::string& path, std::string id) {
	auto mit = m_TextureMap.find(id);

	if (mit != m_TextureMap.end()) {
		std::cout << "Duplicate texture " << id <<" found!" << std::endl;
		return;
	} else {
		sf::Texture* text = new sf::Texture;
		
		if (!text->loadFromFile(path)) {
			std::cout << "Could not load texture: " << id << " at path " << path << ".\n";
		}

		m_TextureMap.insert(make_pair(id, text));
	}
}

sf::Texture& TextureManager::GetTexture(const std::string& id) const {
	auto mit = m_TextureMap.find(id);

	if (mit == m_TextureMap.end()) {
		std::cout << "Could not find texture: " << id << std::endl;
	}

	return (*mit->second);
}
