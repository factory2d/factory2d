/**
 * @license
 */

 /**
  * @fileoverview Asset Manager Header for Factory2D Game Engine.
  *
  * Here we manage the assets to make sure we didn't load more than one
  * instance of each files to make the memory happy :)
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include <locale>
#include <algorithm>

#include "../Debug.h"

#include "AssetManager.h"
#include "Picture.h"

namespace F2D
{
	std::map <std::string, Asset*> AssetManager::__assets = {};

	bool AssetManager::LoadAsset(Picture * asset, std::string path) {
		Picture *p = (Picture*)AssetManager::Get(path);

		if(p == NULL) {
			if(asset->Load(path)) {
				Push(path, asset);
				return true;
			}
			else {
				_ERROR("PICTURE NOT FOUND");
				return false;
			}
		}
		
		// get the picture from cache
		*asset = *p;
		return true;
	}

	void AssetManager::Push(std::string key, Asset * asset) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// if we didn't have this asset yet we register it
		if(__assets[k] == NULL) {
			__assets[k] = asset;
		}
	}

	Asset * AssetManager::Get(std::string key) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// get the asset from our "cache"
		return __assets[k];
	}
}