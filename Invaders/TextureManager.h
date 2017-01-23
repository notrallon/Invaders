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

	void			LoadTexture(const std::string& path, std::string id);
	sf::Texture&	GetTexture(const std::string& id) const;

private:
	TextureManager() {}

	static TextureManager*					s_Instance;
	std::map<std::string, sf::Texture*>		m_TextureMap;

};