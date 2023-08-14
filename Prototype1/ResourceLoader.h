#pragma once

#include <string>
#include <SDL.h>
#include <vector>

struct TextureMetaData {
	std::string name = "";
	std::string path = "";
	int nSubtexturesX = 0; int nSubtexturesY = 0; int textureSizeX = 0; int textureSizeY = 0;
	TextureMetaData(std::string name, std::string path, int nSubtexturesX, int nSubtexturesY, int textureSizeX, int textureSizeY) :
	name(name), path(path), nSubtexturesX(nSubtexturesX), nSubtexturesY(nSubtexturesY), textureSizeX(textureSizeX), textureSizeY(textureSizeY) {}
};

class ResourceLoader
	/* The resource loader is responsibe for loading and storing texture resources, including texture meta data. Currently, this is used for assets which have numerous subtextures, e.g. for an autotiling system.
	The workflow of loading textures is to 1) Read a file registry which describes texture meta data including a filepath and texture name, 2) Populate the meta data vector. The index of the texture meta data in this vector is
	used as its unique texture identifier, and is deterministic assuming no changes in ordering of loading texture registries or their contents themselves. 3) Loading the textures from the files specified in their meta data, and
	converting them to renderable SDL_Texture objects. The file registry is a simple CSV file where the columns are name, filepath, number of subtextures in X, number of subtextures in Y, individual texture size in X, individual texture size in Y.*/
{
public:
	ResourceLoader();
	~ResourceLoader();

	
	std::vector<SDL_Texture*> m_textures;
	std::vector<TextureMetaData> m_texturesMetaData;

	int setRenderer(SDL_Renderer* renderer);
	int loadTexture(std::string filepath, int loadAt);
	void addTextureRegistry(std::string path);
	int loadTextures();

private:
	SDL_Renderer* m_renderer = nullptr;
	std::vector<std::string> m_textureRegistryPaths;
	int splitTextureRegistryString(std::string& input, std::string delimiter, TextureMetaData* output);
	int readTextureRegistry(std::string filepath);


};

