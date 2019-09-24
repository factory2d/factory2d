/**
 * @license
 */

 /**
  * @fileoverview Asset Manager Header for Factory2D Game Engine.
  *
  * Here we manage the assets to make sure we didn't load more than one
  * instance of each files to make the memory happy :)
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#include <locale>
#include <algorithm>

#include "AssetManager.h"

namespace F2D
{
	std::map <std::string, Asset*> AssetManager::__assets = {};

	void AssetManager::PushAsset(std::string key, Asset * asset) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// if we didn't have this asset yet we register it
		if(__assets[k] == NULL) {
			__assets[k] = asset;
		}
	}

	Asset * AssetManager::PullAsset(std::string key) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// get the asset from our "cache"
		return __assets[k];
	}
}