#include "ResourceLoader.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <vector>



ResourceLoader::ResourceLoader() {}
ResourceLoader::~ResourceLoader() {}

int ResourceLoader::setRenderer(SDL_Renderer* renderer) {
	if (renderer != nullptr) {
		m_renderer = renderer;
		return 1;
	}
	else {
		return 0;
	}
}

int ResourceLoader::loadTexture(std::string filepath, int loadAt) {
	std::cout << "LOAD TEXTURE AT " << filepath <<": ";
	SDL_Texture* loadedTexture = nullptr;
	// Load the image from the path to a surface
	SDL_Surface* loadedSurface = IMG_Load(filepath.c_str());
	if (loadedSurface == nullptr) {
		printf("FAILED; SDL_image Error: %s\n", IMG_GetError());
		return 1;
	}
	if (m_renderer == nullptr) {
		printf("FAILED; Renderer is unset.\n");
		return 1;
	}
	loadedTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);

	if (loadedTexture == nullptr) {
		printf("FAILED; SDL_image Error: %s\n", IMG_GetError());
		return 1;
	}

	SDL_FreeSurface(loadedSurface);

	m_textures[loadAt] = loadedTexture;
	printf("SUCCESS\n");
	return 0;

}

int ResourceLoader::readTextureRegistry(std::string filepath) {
	std::string line;
	std::ifstream textureRegistry(filepath);

	getline(textureRegistry, line); // skip header.
	while (getline(textureRegistry, line)) {
		m_texturesMetaData.emplace_back("", "", 0, 0, 0, 0);
		if (splitTextureRegistryString(line, ",", &m_texturesMetaData[m_texturesMetaData.size() - 1])) {
			return 1;
		}
	}
	return 0;
}

int ResourceLoader::splitTextureRegistryString(std::string &input, std::string delimiter, TextureMetaData* output) {
	std::cout << "REGISTER TEXTURE ";
	// Splits the texture registry string as read directly from the texture registry into values in a TextureMetaData object.
	int column = 0;

	// lpos stores the previous position of a delimiter
	// rpos stores the next position of a delimiter
	int lPos = 0;
	int rPos = 0;
	std::string subString;
	while (rPos  != input.size()) {
		if (rPos) {
			lPos = rPos + 1;
		}
		rPos = input.find(delimiter, lPos);
		if (rPos == std::string::npos) {
			rPos = input.size();
		}
		subString = input.substr(lPos, rPos-lPos);
		switch (column) {
		case 0: // Name
			output->name = subString;
			break;
		case 1: // Path
			output->path = subString;
			break;
		case 2: // Rest are (four) integers, in order nSubtexturesX/Y then textureSizeX/Y
			output->nSubtexturesX = std::stoi(subString);
			break;
		case 3:
			output->nSubtexturesY = std::stoi(input.substr(lPos, rPos));
			break;
		case 4:
			output->textureSizeX = std::stoi(subString);
			break;
		case 5:
			output->textureSizeY = std::stoi(subString);
			break;
		default:
			std::cout << input << " FAILED\n";
			return 1;
		}

		++column;
	}
	std::cout << output->name << ": SUCCESS\n";
	return 0;
}

void ResourceLoader::addTextureRegistry(std::string path) {
	m_textureRegistryPaths.push_back(path);
	std::cout << "ADD TEXTURE REGISTRY  " << path << ": SUCCESS\n";
}

int ResourceLoader::loadTextures() {
	// read texture registries
	for (int i = 0; i < m_textureRegistryPaths.size(); ++i) {
		if (readTextureRegistry(m_textureRegistryPaths[i])) {
			std::cout << "READ TEXTURE REGISTRIES: FAILED\n";
			return 1;
		};
	}
	std::cout << "READ TEXTURE REGISTRIES: SUCCESS\n";

	// now load textures
	m_textures.resize(m_texturesMetaData.size());
	for (int i = 0; i < m_texturesMetaData.size(); ++i) {
		loadTexture(m_texturesMetaData[i].path, i);
	}
	return 0;
}