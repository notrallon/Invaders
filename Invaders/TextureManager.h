#pragma once

#include "shared_defs.h"
#include <map>

struct TextureManager {
	~TextureManager();

	static TextureManager* Instance() {
		if (!s_Instance) {
			s_Instance = new TextureManager();
		}
		return s_Instance;
	}

	const sf::Texture& GetTexture(const std::string& key) const;

private:
	TextureManager();

	static TextureManager*					s_Instance;
	std::map<std::string, sf::Texture&>		m_TextureMap;
};